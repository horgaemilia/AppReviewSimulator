#pragma once
#include "Service.h"
#include <QWidget>
#include "ui_UserWindow.h"

class UserWindow : public QWidget , public Observer
{
	Q_OBJECT

public:
	UserWindow(Service& service, User user,QWidget *parent = Q_NULLPTR);
	~UserWindow();

private:
	Ui::UserWindow ui;
	Service& service;
	User user;
	void add_operation();
	int get_selected_index() const;
	void remove_operation();
	void resolve_operation();
	void populate_list();
	void make_connection();
	void update() override;
};
