#include "AddDeleteAction.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "Actions/Action.h"

AddDeleteAction::AddDeleteAction(ApplicationManager* pApp) : Action(pApp) {}

void AddDeleteAction::ReadActionParameters() {
    // nothing will happen it may be deleted 
}

void AddDeleteAction::Execute() {
    pManager->DeleteSeletedFigures();
    //pManager->UpdateInterface();
    pManager->GetOutput()->PrintMessage("The selected figures were deleted");
    pManager->UpdateInterface(); // Redraw

}