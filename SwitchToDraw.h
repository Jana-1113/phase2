#pragma once
#ifndef SWITCH_TO_DRAW_H
#define SWITCH_TO_DRAW_H
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include <iostream>
using namespace std;
class SwitchToDraw :public Action
{
public:
    SwitchToDraw(ApplicationManager* pApp);
	virtual void Execute() override;
	virtual void ReadActionParameters() override;

};
#endif
