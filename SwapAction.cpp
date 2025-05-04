
/*#include "SwapAction.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "Actions/Action.h"
#include "CCircle.h"
#include "CSquare.h"
#include "CHexagon.h"
#include "DEFS.h"



SwapAction::SwapAction(ApplicationManager* pApp) : Action(pApp)
{
}
int selecteditemsnum = 0;
void SwapAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	
	for (int i = 0; i < pManager->getFigureCount(); ++i) {
		CFigure* fig = pManager->GetFigList()[i]; // i need here the figure list --> make a function to do this in cfigure class 
		if (fig->IsSelected() == true) {
			if (selecteditemsnum == 0) {
				selectedFig1Ptr = fig;
				
			}
			else if (selecteditemsnum == 1) {
				selectedFig2Ptr = fig;
				selectedFig2 = fig;
			}
			selecteditemsnum++;
		}
	}
}

//Execute the action
void SwapAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	//This action needs to read some parameters first
	ReadActionParameters();
	if (selecteditemsnum != 2) {
		pOut->PrintMessage("New Hexagon: Click at the center ");
	else {
		SwapFig(selectedFig1Ptr, selectedFig2);
		SwapFig(selectedFig2Ptr, selectedFig1);
	}

	
		SwapFig(selectedFig1Ptr, selectedFig2);
		SwapFig(selectedFig2Ptr, selectedFig1);
	}

	pManager->UnselectAll();
	pManager->UpdateInterface();
}

void SwapAction::SwapFig(CFigure* fig, CFigure * otherFig)
{
	switch (fig->GetFigureName()) {
	case RECTANGLE:
		getRectangleCorners(fig, otherFig);
			break;
	case TRIANGLE:
		getTriangleCorners(fig, otherFig);
			break;
	case CIRCLE:
		dynamic_cast<CCircle*>(fig)->Center = getCenter(otherFig);
		break;
	case HEXAGON:
		dynamic_cast<CHexagon*>(fig)->Center = getCenter(otherFig);
		break;
	case SQUARE:
		((CSquare*)fig)->Center = getCenter(otherFig);
		break;
	}
}

Point SwapAction::getCenter(CFigure *otherFig)
{
	switch (otherFig->GetFigureName()) {
	case RECTANGLE:
		//get center from the rectangle
		break;
	case TRIANGLE:
		//do something
		break;
	case CIRCLE:
		return dynamic_cast<CCircle*>(otherFig)->Center;
		break;
	case HEXAGON:
		return dynamic_cast<CHexagon*>(otherFig)->Center;
		break;
	case SQUARE:
		return dynamic_cast<CSquare*>(otherFig)->Center;
		break;
	}
}
*/
