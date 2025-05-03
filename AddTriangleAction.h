#ifndef ADD_Triangle_ACTION_H
#define ADD_Triangle_ACTION_H

#include "Actions/Action.h"
//Add TriangleAction class
class AddTriangleAction : public Action
{
private:
	Point P1;  //first corner 
	Point P2; // second corner 
	Point P3; // Third corner 
	GfxInfo TriangleGfxInfo;
public:
	AddTriangleAction(ApplicationManager* pApp);

	//Reads Triangle parameters
	virtual void ReadActionParameters();

	//Add Triangle to the ApplicationManager
	virtual void Execute();

};

#endif
