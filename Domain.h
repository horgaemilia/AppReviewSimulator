#pragma once
#include <string>
#include <ostream>
#include <istream>

class User
{
private:
	std::string name;
	std::string type;
public:
	User();
	User(std::string name, std::string type);
	std::string GetName();
	std::string GetType();
	friend std::ostream& operator<<(std::ostream& os, User& element);
	friend std::istream& operator>>(std::istream& is, User& element);
	std::string tostring();
};

class Issue
{
private:
	std::string description;
	std::string status;
	std::string reporter;
	std::string solver;
public:
	Issue();
	Issue(std::string description, std::string status, std::string reporter, std::string solver);
	std::string GetDescription() { return this->description; };
	std::string GetStatus() { return this->status; };
	std::string GetReporter() { return this->reporter; };
	std::string GetSolver() { return this->solver; };
	void SetSolver(std::string solver) { this->solver = solver; };
	void SetStatus(std::string status) { this->status = status; };
	friend std::ostream& operator<<(std::ostream& os, Issue& element);
	friend std::istream& operator>>(std::istream& is, Issue& element);
	bool operator==(const Issue& element);
	bool operator<(const Issue& element);
	std::string tostring();
};