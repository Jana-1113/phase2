#include "Swap.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "ApplicationManager.h"
#include "CTriangle.h"
#include "Figures/CRectangle.h"
#include "CSquare.h"
#include "CHexagon.h"
#include "CCircle.h"



Swap::Swap(ApplicationManager* pApp) : Action(pApp)
{
}
int selecteditemsnum = 0;
 
void Swap::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	for (int i = 0; i < pManager->getFigureCount(); ++i) {
		CFigure* fig = (pManager->GetFigList())[i]; // i need here the figure list --> make a function to do this in cfigure class 
		if (fig->IsSelected() == true) {
			if (selecteditemsnum == 0) {
				selectedFig1 = fig;

			}
			else if (selecteditemsnum == 1) {
				selectedFig2 = fig;

			}
			selecteditemsnum++;
		}
	}
}

void Swap::Execute() {
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if(selecteditemsnum!=2)
		pOut->PrintMessage("kld ");
	else {
		Point Center1=selectedFig1->getCenter();
		Point Center2 =selectedFig2->getCenter();
		selectedFig1->Move(Center1);
		selectedFig2->Move(Center2);



	}
}















