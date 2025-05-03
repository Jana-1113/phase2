#ifndef ADD_Hexagon_ACTION_H
#define ADD_Hexagon_ACTION_H

#include "Actions/Action.h"
//Add Hexagon Action class
class AddHexagonAction : public Action
{
private:
	Point P1;  //Hexagoncenter 
	GfxInfo HexagonGfxInfo;
public:
	AddHexagonAction(ApplicationManager* pApp);

	//Reads Hexagon parameters
	virtual void ReadActionParameters();

	//Add Hexagon to the ApplicationManager
	virtual void Execute();

};

#endif

