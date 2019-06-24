#include "Programmer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository* repo = new Repository{};
	Controller* control = new Controller{ repo };
	auto programmers = repo->getUsers();
	vector<Programmer*> windows;
	for (int i = 0; i < programmers.size(); i++) {
		windows.push_back(new Programmer{ programmers[i],control });
		control->addObserver(windows[i]);
	}

	for (int i = 0; i < windows.size(); i++)
		windows[i]->show();
	return a.exec();
}
