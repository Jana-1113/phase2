#include "AddClearAllAction.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "Actions/Action.h"

AddClearAllAction::AddClearAllAction(ApplicationManager* pApp) : Action(pApp) {}

void AddClearAllAction::ReadActionParameters() {
    // nothing will happen it may be deleted 
}

void AddClearAllAction::Execute() {
    pManager->ClearAll();
    pManager->GetOutput()->PrintMessage("All what you have did were cleared up ");
    pManager->UpdateInterface(); // Redraw

}