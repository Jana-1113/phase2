#pragma once

#include "Actions/Action.h"
class Swap:public  Action
{

	CFigure* selectedFig1;
	CFigure* selectedFig2;

public:
	Swap(ApplicationManager* pApp);

	//Reads Circle parameters
	virtual void ReadActionParameters();

	//Add Circle to the ApplicationManager
	virtual void Execute();
	

};

