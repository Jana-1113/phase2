#pragma once
#ifndef ADD_DELETE_ACTION_H
#define ADD_DELETE_ACTION_H

#include "Actions/Action.h"

//Add Delete Action class
class AddDeleteAction : public Action
{
private:
	
public:
	AddDeleteAction(ApplicationManager* pApp);

	//Reads  delete parameters
	virtual void ReadActionParameters(); // no parameters but i will keep it written , note delete before submitting if it wans't useful 

	//Add Delets action  to the ApplicationManager
	virtual void Execute();

};

#endif
