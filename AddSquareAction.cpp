
#include "AddSquareAction.h"
#include "CSquare.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "Actions/Action.h"
AddSquareAction::AddSquareAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddSquareAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at the center ");

	//Read the center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->SetDrawColor(pIn, SquareGfxInfo);


	SquareGfxInfo.isFilled = true;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	//SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
	//SquareGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddSquareAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a square  with the parameters read from the user
	CSquare* R = new CSquare(P1, SquareGfxInfo);

	//Add the square to the list of figures
	pManager->AddFigure(R);
}
