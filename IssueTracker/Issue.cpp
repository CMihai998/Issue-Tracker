#include "Issue.h"

Issue::Issue(string& descr, string& rep):description(descr),reporter(rep),status("open"),solver("-"){}

Issue::Issue(string& descr, string& rep, string& status, string& solver):description(descr),reporter(rep),status(status),solver(solver){}

Issue::Issue(const Issue& i)
{
	description = i.getDescription();
	reporter = i.getReporter();
	status = i.getStatus();
	solver = i.getSolver();
}

string Issue::getDescription() const
{
	return description;
}

string Issue::getStatus() const
{
	return status;
}

string Issue::getReporter() const
{
	return reporter;
}

string Issue::getSolver() const
{
	return solver;
}

string Issue::toString() const
{
	return description + " status: " + status + " reported by: " + reporter + " solved by: " + solver;
}

string Issue::toFile() const
{
	return description + "," + reporter + "," + status + "," + solver + "\n";
}

void Issue::solve(string& name)
{
	status = "done";
	solver = name;
}

