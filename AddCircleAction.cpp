
#include "AddCircleAction.h"
#include "CCircle.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "Actions/Action.h"
AddCircleAction::AddCircleAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at the center ");

	//Read the center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->SetDrawColor(pIn, CircleGfxInfo);




	CircleGfxInfo.isFilled = true;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	//CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	//CircleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircleAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a square  with the parameters read from the user
	CCircle* R = new CCircle(P1, CircleGfxInfo);

	//Add the square to the list of figures
	pManager->AddFigure(R);
}
