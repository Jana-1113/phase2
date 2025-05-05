#include "ActionSave.h"
#include"Actions/Action.h"
#include <iostream>
#include <fstream>
using namespace std;
ActionSave::ActionSave(ApplicationManager* pApp) :Action(pApp)
{
}
void ActionSave::ReadActionParameters() {
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMessage("Enter file name you want to save the graph in :");
    FileName = pIn->GetSrting(pOut);  // get file name from user
    FileName += ".txt";               // append .txt if needed

    pOut->ClearStatusBar();
}
void ActionSave::Execute() {
    ReadActionParameters();  // Step 1: Get filename from user
    ofstream OutFile(FileName + ".txt");
    if (!OutFile.is_open())
    {
        cout << "Error: Could not open file for saving.\n";
        return;
    }
    pManager->SaveAll(OutFile);    // Step 2: Delegate saving to AppManager
    OutFile.close();
    std::cout << "Graph saved successfully!" << endl;
}