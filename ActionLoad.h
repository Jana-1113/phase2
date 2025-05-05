#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include <iostream>
using namespace std;
class ActionLoad :public Action
{
public:
	ActionLoad(ApplicationManager* pApp);
	 void Execute() override ;
	 void ReadActionParameters() override;
private:
	string FileName;
};