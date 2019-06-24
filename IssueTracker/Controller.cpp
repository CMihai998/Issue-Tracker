#include "Controller.h"

Controller::Controller(Repository* r):repo(r){}

vector<Issue*> Controller::getIssus()
{
	return  repo->getIssues();
}

vector<User*> Controller::getUsers()
{
	return repo->getUsers();
}

void Controller::addIssue(string& descr, string& rep)
{
	repo->addIssue(descr, rep);
	notify();
}

void Controller::deleteIssue(string& descr)
{
	repo->deleteIssue(descr);
	notify();
}

bool Controller::resolveIssue(string& descr, string& name)
{
	auto state = repo->resolveIssue(descr, name);
	notify();
	return state;
}

