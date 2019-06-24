#include "Programmer.h"
#include "QMessageBox"
Programmer::Programmer(User* u, Controller* c, QWidget *parent)
	: QWidget(parent), user(u), control(c)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(user->getName() + "(" + user->getType() + ")"));
	if (user->getType() == "tester")
		ui.solveButton->hide();
	else {
		ui.addButton->hide();
			ui.issueInput->hide();
			ui.label->hide();
	}
	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addSlot()));
	connect(ui.removeButton, SIGNAL(clicked()), this, SLOT(removeSlot()));
	connect(ui.solveButton, SIGNAL(clicked()), this, SLOT(solveSlot()));


	populate();
}

void Programmer::update()
{
	populate();
}

void Programmer::populate()
{
	ui.issuesList->clear();
	auto issues = control->getIssus();
	for(int i=0; i<issues.size();i++)
	{
		QListWidgetItem* newEntry = new QListWidgetItem{ QString::fromStdString(issues[i]->toString()) };
		ui.issuesList->addItem(newEntry);
	}

}

void Programmer::addSlot()
{
	auto text = ui.issueInput->text().toStdString();
	if(text.size() == 0)
	{
		QMessageBox error;
		error.critical(NULL, "Error 404", "Input not found!");
	}
	else
	{
		control->addIssue(text, user->getName());
		ui.issueInput->clear();
	}
}

void Programmer::removeSlot()
{
	if(control->getIssus().size() == 0)
	{
		QMessageBox error;
		error.critical(NULL, "Error 404", "Much good! Very software! No issues here.");
		return;
	}
	int position = ui.issuesList->currentIndex().row();
	auto issue = control->getIssus()[position];
	
	if (issue->getStatus() != "done")
	{
		QMessageBox error;
		error.critical(NULL, "Error", "Issue not resolved! You can't delete it :'(");
	}
	else
	{
		control->deleteIssue(issue->getDescription());
	}
}

void Programmer::solveSlot()
{
	int position = ui.issuesList->currentIndex().row();
	auto issue = control->getIssus()[position];
	auto state = control->resolveIssue(issue->getDescription(),user->getName());
	if (!state)
	{
		QMessageBox error;
		error.critical(NULL, "Error", "Issue already solved! Move on!");
	}
}




