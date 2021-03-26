#pragma once
#include "Domain.h"
#include <vector>
class Repository
{
private:
	std::vector<Issue> issues;
	std::vector<Issue> readIssuesFromFile();
	std::vector<User> ReadUsersFromFile();
	std::string user_path = "users.txt";
	std::string issue_path = "issues.txt";
public:
	Repository();
	void add_issue(Issue issue);
	void remove_issue(Issue issue);
	void resolve_issue(Issue issue);
	std::vector<Issue> returnIssues();
	std::vector<User> returnUsers();
	void writeToFile();
};

