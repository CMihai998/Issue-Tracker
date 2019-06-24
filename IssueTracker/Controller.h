#pragma once
#include "Observer.h"
#include "Repository.h"

class Controller :
	public Subject
{
private:
	Repository* repo;
public:
	Controller(Repository* r);
	~Controller() = default;
	vector<Issue*> getIssus();
	vector<User*> getUsers();
	void addIssue(string& descr, string& rep);
	void deleteIssue(string& descr);
	bool resolveIssue(string& descr, string& name);
};

