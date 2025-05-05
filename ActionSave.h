#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include <iostream>
class ActionSave:public Action
{
public:
	ActionSave(ApplicationManager* pApp);
	 void Execute() override ;
	 void ReadActionParameters() override ;
private:
	string FileName;
};

