#include "ActionLoad.h"
#include"Actions/Action.h"
#include <iostream>
#include <fstream>
#include "Figures/CFigure.h"
#include"ApplicationManager.h"
#include "Figures/CRectangle.h"
#include "CTriangle.h"
#include "CSquare.h"
#include"CCircle.h"
#include"CHexagon.h"
using namespace std;

ActionLoad::ActionLoad(ApplicationManager* pApp) :Action(pApp)
{
}
void ActionLoad::ReadActionParameters() {
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMessage("Enter filename to load the graph from:");
    FileName = pIn->GetSrting(pOut);  // Get the filename
    FileName += ".txt";               // Add extension if not already included

    pOut->ClearStatusBar();
}
void ActionLoad::Execute() {
	ReadActionParameters();
	ifstream InFile(FileName + ".txt");
	if (!InFile.is_open()) {
		cout << "Can't open file" << endl;
		return;
	}
	pManager->LoadGraph(InFile);
	InFile.close();
}