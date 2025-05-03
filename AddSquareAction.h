#ifndef ADD_Square_ACTION_H
#define ADD_Square_ACTION_H

#include "Actions/Action.h"
//Add Square Action class
class AddSquareAction : public Action
{
private:
	Point P1;  //Square Center 
	GfxInfo SquareGfxInfo;
public:
	AddSquareAction(ApplicationManager* pApp);

	//Reads square parameters
	virtual void ReadActionParameters();

	//Add square to the ApplicationManager
	virtual void Execute();

};

#endif
