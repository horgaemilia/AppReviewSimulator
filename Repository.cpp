#include "Repository.h"
#include <fstream>
#include <iostream>
#include <exception>
#include <algorithm>

using namespace std;

std::vector<Issue> Repository::readIssuesFromFile()
{
   std::vector<Issue> issue;
   Issue element;
   std::ifstream fin(this->issue_path);
   while (fin >> element)
   {
	   issue.push_back(element);
   }
   fin.close();
   this->issues = issue;
   return issue;
}

std::vector<User> Repository::ReadUsersFromFile()
{
	std::vector<User> users;
	User element;
	std::ifstream fin(this->user_path);
	while (fin >> element)
	{
		users.push_back(element);
	}
	fin.close();
	return users;
}

Repository::Repository()
{
	this->readIssuesFromFile();
}

void Repository::add_issue(Issue issue)
{
	auto it = find(this->issues.begin(), this->issues.end(), issue);
	if (it == this->issues.end())
	{
		this->issues.push_back(issue);
		this->writeToFile();
		return;
	}
	throw exception{ "it already exists" };
}

void Repository::remove_issue(Issue issue)
{
	auto it = find(this->issues.begin(), this->issues.end(), issue);
	if (it != this->issues.end())
	{
		this->issues.erase(it);
		this->writeToFile();
		return;
	}
	throw exception{ "it doesn't exist" };
}

void Repository::resolve_issue(Issue issue)
{
	auto it = find(this->issues.begin(), this->issues.end(), issue);
	if (it != this->issues.end())
	{
		it->SetStatus("solved");
		it->SetSolver(issue.GetSolver());
		this->writeToFile();
		return;
	}
	throw exception{ "it doesn't exists" };
}

std::vector<Issue> Repository::returnIssues()
{
	sort(this->issues.begin(), this->issues.end(), [&](Issue& i, Issue& j) {return i < j;});
	return this->issues;
}

std::vector<User> Repository::returnUsers()
{
	return this->ReadUsersFromFile();
}

void Repository::writeToFile()
{
	std::ofstream fout(this->issue_path);
	for (auto issue : this->issues)
		fout << issue;
	fout.close();
}
