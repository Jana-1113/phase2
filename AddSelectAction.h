#ifndef ADD_SELECT_ACTION_H
#define ADD_SELECT_ACTION_H

#include "Actions/Action.h"

//Add Selct Action class
class AddSelectAction : public Action
{
private:
	Point P1;  // Thee selected point 
	//GfxInfo RectGfxInfo;
public:
	AddSelectAction(ApplicationManager* pApp);

	//Reads Select parameters
	virtual void ReadActionParameters();

	//Add Select to the ApplicationManager
	virtual void Execute();

};

#endif




