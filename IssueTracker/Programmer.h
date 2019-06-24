#pragma once

#include <QtWidgets/QWidget>
#include "ui_Programmer.h"
#include "Controller.h"
class Programmer : public QWidget, public Observer
{
	Q_OBJECT

public:
	Programmer(User* u, Controller* c, QWidget *parent = Q_NULLPTR);

private:
	User* user;
	Controller* control;
	Ui::ProgrammerClass ui;
	void update() override;
	void populate();
private slots:
	void addSlot();
	void removeSlot();
	void solveSlot();
};
