#ifndef ROTATE_ACTION_H
#define ROTATE_ACTION_H

#pragma once
#include "Actions/Action.h"
#include "Figures/CFigure.h"


class RotateAction : public Action
{
private:
	int selecteditemsnum = 0;
	CFigure* selectedFig = 0;
public:
	RotateAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Execute();

};
#endif
