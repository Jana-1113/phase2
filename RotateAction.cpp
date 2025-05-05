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


RotateAction::RotateAction(ApplicationManager* pApp) : Action(pApp) {};

void RotateAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	for (int i = 0; i < pManager->getFigureCount(); ++i) {
		CFigure* fig = pManager->GetFigList()[i];
		if (fig->IsSelected() == true) {
			if (selecteditemsnum == 0) {
				selectedFig = fig;
			}
			selecteditemsnum++;
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
		FigureName figName = selectedFig->GetFigureName();
		if((figName == SQUARE) || (figName == CIRCLE))
			pOut->PrintMessage("Action has no effect");
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
	pManager->UnselectAll();
}