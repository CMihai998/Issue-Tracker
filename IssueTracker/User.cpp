#include "User.h"

User::User(string& n, string& type):name(n), type(type){}

User::User(const User& u)
{
	name = u.getName();
	type = u.getType();
}

string User::getType() const
{
	return type;
}

string User::getName() const
{
	return name;
}

void User::setName(string& n)
{
	name = n;
}

void User::setType(string& t)
{
	type = t;
}

string User::toString() const
{ 
	return name + " - " + type;
}

string User::toFile() const
{
	return name + "," + type + "\n";
}

