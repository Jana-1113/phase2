#include "SwitchToPlay.h"
#include"Actions/Action.h"
#include <iostream>
#include <fstream>
#include "Figures/CFigure.h"
#include"ApplicationManager.h"
using namespace std;
SwitchToPlay::SwitchToPlay(ApplicationManager* pApp) :Action(pApp)
{
}
void SwitchToPlay::Execute() {
	void CreatePlayBar();
	void CreateStatusBar();

}
void SwitchToPlay::ReadActionParameters() {

}
