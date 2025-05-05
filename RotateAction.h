#pragma once
#include "Actions/Action.h"
#include "Figures/CFigure.h"


class RotateAction : public Action
{
private:

	CFigure* selectedFig;
public:
	RotateAction(ApplicationManager* pApp);


	virtual void ReadActionParameters();

	virtual void Execute();


};

