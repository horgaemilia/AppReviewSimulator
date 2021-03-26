#pragma once
#include "Observer.h"
#include "Repository.h"
class Service : public Subject
{
private:
	Repository& repository;
public:
	Service(Repository& repository) : repository{ repository } {}
	Repository& GetRepository() { return this->repository; }
	void AddIssue(const std::string description, const std::string reporter);
	void RemoveIssue(const std::string description, const std::string status);
	void ResolveIssue(const std::string description, const std::string status, const std::string reporter, const std::string resolver);
	std::vector<User> GetUsers();
	std::vector<Issue> GetIssues();

};

