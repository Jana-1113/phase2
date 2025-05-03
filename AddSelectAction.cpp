#include "AddSelectAction.h"
#include "Figures/CFigure.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "Actions/Action.h"

AddSelectAction::AddSelectAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddSelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Selct Action: Click at any point to select");

	//Read the selected point and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

}

//Execute the action
void AddSelectAction::Execute() {

    ReadActionParameters();
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    CFigure* Selecteditem = pManager->GetFigure(P1.x, P1.y);

    if (Selecteditem == NULL) {
        // if the user click on the draw area the doesn't contain any figure 
        pManager->UnselectAll();
        pOut->PrintMessage("No Selcted figures , All selected figures will be unselected now");
        return;
    }

    // the user clicks on the figure 
    if (Selecteditem->IsSelected()== false ) {
        Selecteditem->SetSelected(true);// if the figure is unselected , select the figure 
        pOut->PrintMessage("This figure became selected");
    }
    else {
        Selecteditem->SetSelected(false); // if the figure us selected unselect the figure 
        pOut->PrintMessage(" This figure became unselected");
    }

    // display the needed information on the status bar 
    int rectangleCount = 0, triangleCount = 0, circleCount = 0, hexagonCount = 0, squareCount = 0;
    int selecteditemsnum= 0;
    string statusbar_content;

    for (int i = 0; i < pManager->getFigureCount(); ++i) {
        CFigure* fig = pManager->GetFigList()[i]; // i need here the figure list --> make a function to do this in cfigure class 
        if (fig->IsSelected()== true) {
            selecteditemsnum++;// i need also to get the name of each shape // i need somtging from each class i can compare 
            if (fig->GetFigureName() == HEXAGON) {
                hexagonCount++;
            }
            if (fig->GetFigureName() == TRIANGLE) {
                triangleCount++;
            }
            if (fig->GetFigureName() == CIRCLE) {
                circleCount++;
            }
            if (fig->GetFigureName() == RECTANGLE) {
                rectangleCount++;
            }
            else {
                squareCount++;
            }
        }
    }

    // know the count and decide if the count is one show the shape info only and if the count is more than one show numbers 
    if (selecteditemsnum == 1) {
        Selecteditem->PrintFigureInfo(pOut);  // Show the selected figure details 
    }
    else {
        // show the number of all the selected figures 
        statusbar_content= "The selected items with their count are : ";
        if (rectangleCount>0) 
        {
            statusbar_content += to_string(rectangleCount) + " Rectangle(s) " + "  ";
        }
        if (triangleCount>0) 
        { 
            statusbar_content += to_string(triangleCount) + " Triangle(s) " + "  ";
        }
        if (circleCount>0) 
        { 
            statusbar_content += to_string(circleCount) + " Circle(s) " + "  ";
        }
        if (hexagonCount>0)
        { 
            statusbar_content += to_string(hexagonCount) + " Hexagon(s) " + "  ";
        }
        if (squareCount>0) 
        { 
            statusbar_content += to_string(squareCount) + " Square(s) " + "  ";
        }
        pOut->PrintMessage(statusbar_content);
    }

    pManager->UpdateInterface();  // to show the updated verions after the action is completed 
}