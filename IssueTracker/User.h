#pragma once
#include <string>
using namespace std;
class User
{
private:
	string name;
	string type;
public:
	User() {};
	User(string& n, string& type);
	User(const User& u);
	~User() = default;
	string getType() const;
	string getName() const;
	void setName(string& n);
	void setType(string& t);
	string toString() const;
	string toFile() const;
};

