#pragma once
#ifndef SWITCH_TO_PLAY_H
#define SWITCH_TO_PLAY_H
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include <iostream>
using namespace std;
class SwitchToPlay :public Action
{
public:
	SwitchToPlay(ApplicationManager* pApp);
	virtual void Execute() override;
	virtual void ReadActionParameters() override;

};
#endif