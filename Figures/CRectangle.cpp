#include "CRectangle.h"
# include <string>
# include <iostream>
#include "Figures/CFigure.h"
using namespace std;

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::IsIncluded(int x , int y) const {

	if (x >= Corner1.x && x <= Corner2.x &&
		y >= Corner1.y && y <= Corner2.y) {
		return true;
	}
	return false;
}
FigureName CRectangle::GetFigureName() const {
	return RECTANGLE;
}

void CRectangle::PrintFigureInfo(Output* pOut) const {
	string info = "This is a rectnagle with width  : (" + to_string(Corner2.y - Corner1.y) + " and length " + to_string(Corner2.x - Corner1.x);
	pOut->PrintMessage(info);
}

Point CRectangle::getCenter() {
	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y ) / 2;
	return Center;
}

void CRectangle::Move(Point Center2) {
		Point movevalue;
		movevalue.x = Center2.x - Center.x;
		movevalue.y = Center2.y - Center.y;
		Corner1.x += movevalue.x;
		Corner1.y += movevalue.y;
		Corner2.x += movevalue.x;
		Corner2.y += movevalue.y;
}
