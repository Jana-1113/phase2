
#include "AddHexagonAction.h"
#include "CHexagon.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "Actions/Action.h"
AddHexagonAction::AddHexagonAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddHexagonAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at the center ");

	//Read the center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->SetDrawColor(pIn, HexagonGfxInfo);

	HexagonGfxInfo.isFilled = true;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	//HexagonGfxInfo.DrawClr = pOut->getCrntDrawColor();
	//HexagonGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexagonAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a square  with the parameters read from the user
	CHexagon* R = new CHexagon(P1, HexagonGfxInfo);

	//Add the square to the list of figures
	pManager->AddFigure(R);
}
