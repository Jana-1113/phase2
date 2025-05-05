#include "ExitAction.h"
#include"Actions/Action.h"
#include <iostream>
#include <fstream>
#include "Figures/CFigure.h"
#include"ApplicationManager.h"
using namespace std;
void ExitAction::ReadActionParameters()
{
  // No parameters are needed for the exit action.
}
void ExitAction::Execute() {
    delete pManager;
    cout << "All cleaned up" << endl;
}
 ExitAction::ExitAction(ApplicationManager* pApp) : Action(pApp)
{
}