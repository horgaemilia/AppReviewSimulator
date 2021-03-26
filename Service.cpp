#include "Service.h"
#include <exception>
using namespace std;
void Service::AddIssue(const std::string description, const std::string reporter)
{
	Issue issue{description,"open",reporter,""};
	this->repository.add_issue(issue);
	this->notify();
}

void Service::RemoveIssue(const std::string description, const std::string status)
{
	Issue issue{ description,status,"","" };
	if (issue.GetStatus() == "open")
		throw exception("we cannot remove it because it was not solved");
	this->repository.remove_issue(issue);
	this->notify();
}

void Service::ResolveIssue(const std::string description, const std::string status, const std::string reporter, const std::string resolver)
{
	Issue issue{ description, status, reporter, resolver };
	this->repository.resolve_issue(issue);
	this->notify();
}

std::vector<User> Service::GetUsers()
{
	return repository.returnUsers();
}

std::vector<Issue> Service::GetIssues()
{
	return repository.returnIssues();
}
