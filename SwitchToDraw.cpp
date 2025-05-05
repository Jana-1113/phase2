#include "SwitchToDraw.h"
#include"Actions/Action.h"
#include <iostream>
#include <fstream>
#include "Figures/CFigure.h"
#include"ApplicationManager.h"
using namespace std;
SwitchToDraw::SwitchToDraw(ApplicationManager* pApp) :Action(pApp)
{
}
void SwitchToDraw::Execute() {
	pManager->ClearAll();
	void CreateDrawBar();
	pManager->UpdateInterface();
	void CreateStatusBar();
}
void SwitchToDraw::ReadActionParameters() {

}
