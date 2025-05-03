#ifndef ADD_Circle_ACTION_H
#define ADD_Circle_ACTION_H

#include "Actions/Action.h"
//Add Square Action class
class AddCircleAction : public Action
{
private:
	Point P1;  //Circle center 
	GfxInfo CircleGfxInfo;
public:
	AddCircleAction(ApplicationManager* pApp);

	//Reads Circle parameters
	virtual void ReadActionParameters();

	//Add Circle to the ApplicationManager
	virtual void Execute();

};

#endif

