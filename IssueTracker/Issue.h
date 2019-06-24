#pragma once
#include <string>
using namespace std;
class Issue
{
private:
	string description;
	string reporter;
	string  status;
	string solver;
public:
	Issue(string& descr, string& rep);
	Issue(string& descr, string& rep, string& status, string& solver);
	Issue(const Issue& i);
	~Issue() = default;
	string getDescription() const;
	string getStatus() const;
	string getReporter() const;
	string getSolver() const;
	string toString() const;
	string toFile() const;
	void solve(string& name);
};

