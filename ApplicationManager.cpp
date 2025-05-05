#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "AddSquareAction.h"
#include "AddCircleAction.h"
#include "AddTriangleAction.h"
#include "AddHexagonAction.h"
#include "AddSelectAction.h"
#include "AddDeleteAction.h"
#include "AddClearAllAction.h"
#include "Swap.h"
#include "ActionSave.h"
#include "ActionLoad.h"
#include "SwitchToPlay.h"
#include "SwitchToDraw.h"
#include "ExitAction.h"
#include "Figures/CRectangle.h"
#include "CTriangle.h"
#include "CSquare.h"
#include "CCircle.h"
#include "CHexagon.h"
#include "RotateAction.h"
# include <iostream>
using namespace std;


#include "Figures/CFigure.h"






//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;
	case DRAW_SQUARE:
		pAct = new AddSquareAction(this);
		break;
	case DRAW_CIRCLE:
		pAct = new AddCircleAction(this);
		break;
	case DRAW_TRIANGLE:
		pAct = new AddTriangleAction(this);
		break;
	case DRAW_HEXAGON:
		pAct = new AddHexagonAction(this);
		break;
	case SELECT:
		pAct = new AddSelectAction(this);
		break;
	case DELETE_FIGURE:
		pAct = new AddDeleteAction(this);
		break;
	case CLEAR_ALL:
		pAct = new AddClearAllAction(this);
		break;
	case SWAP:
		pAct = new Swap(this);
		break;
	case SAVE_GRAPH: //a cclick on save figure
		pAct = new ActionSave(this);
		break;
	case LOAD_GRAPH:// a click on load figure
		pAct = new ActionLoad(this);
		break;
	case TO_PLAY:
		pAct = new SwitchToPlay(this);
		break;
	case TO_DRAW:
		pAct = new SwitchToDraw(this);
		return;
	case ROTATE_FIGURE:
		pAct = new RotateAction(this);
		break;
	case EXIT:
		pAct = new ExitAction(this);
		break;
	case STATUS:	//a click on the status bar ==> no action
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
}


CFigure* ApplicationManager::GetFigure(int x, int y) const
{

	for (int i = FigCount - 1; i >= 0; --i)// to get the most top figure turn the loop from oldest added to the newest 
	{
		if (FigList[i] != NULL && FigList[i]->IsIncluded(x, y))
		{
			return FigList[i];
		}
	}
	return NULL; // No figure contains this point
}
void ApplicationManager::DeleteSeletedFigures() {
	for (int i = 0; i < FigCount;) {
		if (FigList[i] && FigList[i]->IsSelected()) {
			delete FigList[i];           // delete what the pointer is pointing to 
			FigList[i] = NULL;        // make sure that the pointer now is pointing ot nothing 

			// Shift the rest
			for (int j = i; j < FigCount - 1; ++j) {
				FigList[j] = FigList[j + 1];
			}

			FigList[FigCount - 1] = NULL;  // clean the last one instead of the one that was deleted 
			FigCount--;
		}
		else {
			++i; // try to add i outside to take into consideration the shifted object 
		}
	}
}

void ApplicationManager::SaveAll(ofstream& OutFile) {
	// Write all figures to the file
	for (int i = 0; i < FigCount; ++i) {
		if (FigList[i] != nullptr) {
			FigList[i]->Save(OutFile);  // Each figure knows how to save itself
		}
	}
}

void ApplicationManager::LoadGraph(ifstream& InFile) {
	for (int i = 0; i < FigCount; i++) {
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
	int numberOfFigures;
	InFile >> numberOfFigures;

	for (int i = 0; i < numberOfFigures; i++) {
		string figType;
		InFile >> figType;

		CFigure* pFig = nullptr;

		if (figType == "RECTANGLE") pFig = new CRectangle;
		else if (figType == "TRIANGLE") pFig = new CTriangle;
		else if (figType == "CIRCLE") pFig = new CCircle;
		else if (figType == "HEXAGON") pFig = new CHexagon;
		else if (figType == "SQAURE") pFig = new CSquare;
		if (pFig != nullptr) {
			pFig->Load(InFile);
			AddFigure(pFig);
		}
	}
}

//If a figure is found return a pointer to it.
//if this point (x,y) does not belong to any figure return NULL
//Add your code here to search for a figure given a point x,y	
//Remember that ApplicationManager only calls functions do NOT implement it.

	//return NULL;

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const {
	pOut->ClearDrawArea();  // clear the draw area 

	for (int i = 0; i < FigCount; i++) {
		if (FigList[i] != NULL) // redraw all the figures in the figure list again 
			FigList[i]->Draw(pOut);
	}
}

////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}
void ApplicationManager::UnselectAll() {
	for (int i = 0; i < FigCount; ++i) {
		if (FigList[i]->IsSelected()) {
			FigList[i]->SetSelected(false);
		}
	}
}
int ApplicationManager::getFigureCount() { // needed to acsess the fig count in the for loop 
	return FigCount;
}
CFigure** ApplicationManager::GetFigList() {// needed in the select action to get acsess to the figlist without its name as it is private to the class 
	return FigList;
}
void ApplicationManager::ClearAll() {
	pOut->ClearDrawArea();  // clear the draw area 

	for (int i = 0; i < FigCount; i++) {
		delete FigList[i];
		FigList[i] = NULL;
	}
}