#include "RotateAction.h"
#include "Swap.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "ApplicationManager.h"
#include "CTriangle.h"
#include "Figures/CRectangle.h"
#include "CSquare.h"
#include "CHexagon.h"
#include "CCircle.h"
#include "Figures/CFigure.h"
#include "GUI/Output.h"


int selecteditemsnum = 0;
RotateAction::RotateAction(ApplicationManager* pApp) : Action(pApp) {};
void RotateAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	for (int i = 0; i < pManager->getFigureCount(); ++i) {
		CFigure* fig = pManager->GetFigList()[i]; // i need here the figure list --> make a function to do this in cfigure class 
		if (fig->IsSelected()) {
			if (selecteditemsnum == 0) {
				selectedFig = fig;
				selecteditemsnum++;
			}
			
		}
	}
}


void RotateAction::Execute() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if (selecteditemsnum != 1)
		pOut->PrintMessage("Wrong number of figures selected, Select one figure only ");
	else {
		pOut->PrintMessage("Click cw to rotate clockwise, and anw to rotate anticlockwise ");
		string choice = pIn->GetSrting(pOut);

		if (choice == "cw") {
			selectedFig->RotateCW();
		}
		else if (choice == "acw") {
			selectedFig->RotateACW();



		}
	}
}