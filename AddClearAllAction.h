#pragma once
#ifndef ADD_CLEAR_ALL_ACTION_H
#define ADD_CLEAR_ALL_ACTION_H

#include "Actions/Action.h"

//Add Clear Action class
class AddClearAllAction : public Action
{
private:

public:
	AddClearAllAction(ApplicationManager* pApp);

	//Reads  Clear all  parameters
	virtual void ReadActionParameters(); // no parameters but i will keep it written , note delete before submitting if it wans't useful 

	//Add clear all  action  to the ApplicationManager
	virtual void Execute();

};

#endif

