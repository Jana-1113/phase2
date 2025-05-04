#ifndef SWAP_ACTION_H
#define SWAP_ACTION_H

#include "Actions/Action.h"
#include "Figures/CFigure.h"
class Swap : public  Action
{
private:
	int selecteditemsnum = 0;
	CFigure* selectedFig1 = 0;
	CFigure* selectedFig2 = 0;

public:
	Swap(ApplicationManager* pApp);

	//Reads Circle parameters
	virtual void ReadActionParameters();

	//Add Circle to the ApplicationManager
	virtual void Execute();
	

};

#endif