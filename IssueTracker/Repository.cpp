#include "Repository.h"
#include <sstream>


Repository::Repository()
{
	ifstream input,userInput;
	input.open("issues.txt", std::ios::in);
	string line;
	while(getline(input, line))
	{
		auto params = tokenize(line, ',');
		issues.push_back(new Issue{ params[0],params[1],params[2],params[3] });
	}
	input.close();

	userInput.open("users.txt", ios::in);
	while(getline(userInput, line))
	{
		auto params = tokenize(line, ',');
		users.push_back(new User{ params[0], params[1] });
	}
	userInput.close();

}

vector<Issue*> Repository::getIssues()
{
	return issues;
}

vector<User*> Repository::getUsers()
{
	return  users;
}

void Repository::addIssue(string& descr, string& rep)
{
	issues.push_back(new Issue{ descr,rep });
	saveFile();
	sort();
}

void Repository::deleteIssue(string& descr)
{
	int i = 0;
	while (issues[i]->getDescription() != descr)
		i++;
	while (i < issues.size() - 1) {
		issues[i] = issues[i + 1];
		i++;
	}
	issues.pop_back();
	sort();
	saveFile();
}

bool Repository::resolveIssue(string& descr, string& name)
{
	int i = 0;
	while (issues[i]->getDescription() != descr)
		i++;
	if (issues[i]->getStatus() == "done")
		return false;
	else
	{
		issues[i]->solve(name);
		sort();
		saveFile();
		return true;
	}
}

vector<string> Repository::tokenize(string input, char delimiter)
{
	std::stringstream stream(input);

    std::vector<std::string> result;
    std::string token;

    while (getline(stream, token, delimiter))
        result.push_back(token);

    return result;
}

void Repository::saveFile()
{
	ofstream output;
	output.open("issues.txt", ios::out);
	for (int i = 0; i < issues.size(); i++)
		output << issues[i]->toFile();
	output.close();
}

void Repository::sort()
{
	for(int i=0;i < issues.size() - 1;i++)
		for(int j=i+1;j<issues.size();j++)
			if(issues[i]->getStatus() > issues[j]->getStatus() || (issues[i]->getStatus() == issues[j]->getStatus()&& issues[i]->getDescription() > issues[j]->getDescription()))
			{
				auto auxiliary = issues[i];
				issues[i] = issues[j];
				issues[j] = auxiliary;
			}
}
