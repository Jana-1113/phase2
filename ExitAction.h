#include"Actions/Action.h"
#include <iostream>
#include <fstream>
#include "Figures/CFigure.h"
#include"ApplicationManager.h"
using namespace std;

class ExitAction : public Action
{
public:
    // Constructor
    ExitAction(ApplicationManager* pApp);

    // Override the Execute method
    virtual void Execute() override;

    // Override the ReadActionParameters method (optional for Exit)
    virtual void ReadActionParameters() override;
};

