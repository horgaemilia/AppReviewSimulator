#include "Domain.h"
#include "Utils.h"
User::User()
{
}

User::User(std::string name, std::string type): name{name},type{type}
{
}

std::string User::GetName()
{
	return this->name;
}

std::string User::GetType()
{
	return this->type;
}

std::string User::tostring()
{
	return "the user " + this->name + " is of type " + this->type;
}

std::ostream& operator<<(std::ostream& os, User& element)
{
	os << element.name+","+element.type;
	return os;
}

std::istream& operator>>(std::istream& is, User& element)
{
	std::vector<std::string> tokens;
	std::string line;
	getline(is, line);
	if (line != "")
	{
		tokens = SplitLine(line, ',');
		element.name = tokens[0];
		element.type = tokens[1];
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, Issue& element)
{
	os << element.description << "," << element.status << "," << element.reporter << "," << element.solver;
	return os;
}

std::istream& operator>>(std::istream& is, Issue& element)
{
	std::vector<std::string> tokens;
	std::string line;
	getline(is, line);
	if (line != "")
	{
		tokens = SplitLine(line, ',');
		element.description = tokens[0];
		element.status = tokens[1];
		element.reporter = tokens[2];
		element.solver = tokens[3];
	}
	return is;
}

Issue::Issue()
{
}

Issue::Issue(std::string description, std::string status, std::string reporter, std::string solver)
{
	this->description = description;
	this->status = status;
	this->reporter = reporter;
	this->solver = solver;
}

bool Issue::operator==(const Issue& element)
{
	return this->description == element.description;
}

bool Issue::operator<(const Issue& element)
{
	return this->status< element.status;
}

std::string Issue::tostring()
{
	return this->description + "," + this->status + "," + this->reporter + "," + this->solver;
}
