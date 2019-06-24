#pragma once
#include <vector>
#include "Issue.h"
#include <fstream>
#include "User.h"
#include <iostream>
class Repository
{

private:
	vector<Issue*> issues;
	vector<User*> users;
public:
	Repository();
	~Repository() = default;
	vector<Issue*> getIssues();
	vector<User*> getUsers();
	void addIssue(string& descr, string& rep);
	void deleteIssue(string& descr);
	bool resolveIssue(string& descr, string& name);
	vector<string> tokenize(string input, char delimiter);
	void saveFile();
	void sort();
};

