#include "UserWindow.h"
#include <vector>
#include "qmessagebox.h"
#include <exception>
UserWindow::UserWindow(Service& service, User user, QWidget *parent)
	: QWidget(parent) , service{service}, user{user}
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(user.tostring()));
	this->make_connection();
	this->populate_list();
	if (user.GetType() != "tester")
		this->ui.AddpushButton->setEnabled(false);
	if (user.GetType() == "tester")
		this->ui.SolvepushButton->setEnabled(false);
}

UserWindow::~UserWindow()
{
}

void UserWindow::add_operation()
{
	std::string description = this->ui.DescriptionlineEdit->text().toStdString();
	std::string reporter = user.GetName();
	
	if (description == "")
	{
		QMessageBox::critical(this, "Error", "The description cannot be empty");
		return;
	}
	try
	{
		this->service.AddIssue(description,reporter);
		this->populate_list();
	}
	catch (std::exception& ex)
	{
		std::string message = ex.what();
		QMessageBox::critical(this, "Error", QString::fromStdString(message));
	}
}

int UserWindow::get_selected_index() const
{
	QModelIndexList selectedIndexes = this->ui.IssueslistWidget->selectionModel()->selectedIndexes();
	if (selectedIndexes.size() == 0)
	{
		this->ui.DescriptionlineEdit->clear();
		this->ui.StatelineEdit->clear();
		this->ui.SolverlineEdit->clear();
		this->ui.ReporterlineEdit->clear();
		return -1;
	}
	int SelectedIndex = selectedIndexes.at(0).row();
	return SelectedIndex;
}

void UserWindow::remove_operation()
{
	std::string description = this->ui.DescriptionlineEdit->text().toStdString();
	std::string state = this->ui.StatelineEdit->text().toStdString();
	if (description == "" || state == "")
	{
		QMessageBox::critical(this, "Error", "The description or the state cannot be empty");
		return;
	}
	try
	{
		this->service.RemoveIssue(description, state);
		this->populate_list();
	}
	catch (std::exception& ex)
	{
		std::string message = ex.what();
		QMessageBox::critical(this, "Error", QString::fromStdString(message));
	}

}

void UserWindow::resolve_operation()
{
	std::string description = this->ui.DescriptionlineEdit->text().toStdString();
	std::string state = "closed";
	std::string reporter = this->ui.ReporterlineEdit->text().toStdString();
	std::string solver = user.GetName();
	try
	{
		this->service.ResolveIssue(description, state,reporter,solver);
		this->populate_list();
	}
	catch (std::exception& ex)
	{
		std::string message = ex.what();
		QMessageBox::critical(this, "Error", QString::fromStdString(message));
	}
}

void UserWindow::populate_list()
{
	this->ui.IssueslistWidget->clear();
	std::vector<Issue> issues = this->service.GetIssues();
	for (auto issue : issues)
	{
		QListWidgetItem* item = new QListWidgetItem;
		QString string = QString::fromStdString(issue.tostring());
		if (issue.GetStatus() == "solved")
			item->setBackgroundColor(QColor("#7fc97f"));
		item->setText(string);
		this->ui.IssueslistWidget->addItem(item);
	}
}

void UserWindow::make_connection()
{
	QObject::connect(this->ui.IssueslistWidget, &QListWidget::itemSelectionChanged, [this]() {
		int selectedIndex = this->get_selected_index();
		if (selectedIndex < 0)
			return;
		std::vector<Issue> issues = this->service.GetIssues();
		Issue issue = issues[selectedIndex];
		this->ui.DescriptionlineEdit->setText(QString::fromStdString(issue.GetDescription()));
		this->ui.StatelineEdit->setText(QString::fromStdString(issue.GetStatus()));
		this->ui.ReporterlineEdit->setText(QString::fromStdString(issue.GetReporter()));
		this->ui.SolverlineEdit->setText(QString::fromStdString(issue.GetSolver()));
		if (issue.GetStatus() == "open")
		{
			this->ui.RemovepushButton->setEnabled(false);
		}
		else
			this->ui.RemovepushButton->setEnabled(true);
		if (user.GetType() == "programmer" && issue.GetStatus() == "open")
		{
			this->ui.SolvepushButton->setEnabled(true);
		}
		else
			this->ui.SolvepushButton->setEnabled(false);
		});
	QObject::connect(this->ui.AddpushButton, &QPushButton::clicked, this, &UserWindow::add_operation);
	QObject::connect(this->ui.RemovepushButton, &QPushButton::clicked, this, &UserWindow::remove_operation);
	QObject::connect(this->ui.SolvepushButton, &QPushButton::clicked, this, &UserWindow::resolve_operation);
}

void UserWindow::update()
{
	this->populate_list();
}

