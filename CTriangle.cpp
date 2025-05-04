#include "CTriangle.h"
# include <string>
# include <iostream>
using namespace std;

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a Triangle on the screen	
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}
bool CTriangle::IsIncluded(int x , int y) const
{
	Point A = Corner1;
	Point B = Corner2;
	Point C = Corner3;
	double AX = A.x;
	double AY = A.y;
	double BX = B.x;
	double BY = B.y;
	double CX = C.x;
	double CY = C.y;
	double PX = x;
	double PY = y;

	double BA_x = BX - AX;
	double BA_y = BY - AY;	
	double CA_x = CX - AX;
	double CA_y = CY - AY;
	double W1 = (AX * (CA_y)+(PY - AY) * (CA_x)-PX * (CA_y)) / ((BA_y) * (CA_x)-(BA_x) * (CA_y));
	double W2 = (PY - AY - W1 * (BA_y)) / (CA_y);

	if (W1 >= 0) {
		if (W2 >= 0) {
			if ((W1 + W2) <= 1) {
				return true;
			}
		}
	}

	return false;
}
FigureName CTriangle::GetFigureName() const {
	return TRIANGLE;
}
void CTriangle::PrintFigureInfo(Output* pOut) const {
	string info = " This is a Triangle with corner 1 (" + to_string(Corner1.x) + ", " + to_string(Corner1.y) +
		"), and corner2  (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + "), and corner3  (" + to_string(Corner3.x) + ", " + to_string(Corner3.y);
	pOut->PrintMessage(info);
}

Point CTriangle::getCenter() {
	Center.x = (Corner1.x + Corner2.x +Corner3.x) / 3;
	Center.y = (Corner1.y +Corner2.y + Corner3.y) / 3;
	return Center;
 }

 void CTriangle:: Move(Point Center2){
	 Point movevalue;
	 movevalue.x = Center2.x - Center.x;
	 movevalue.y = Center2.y - Center.y;
	 Corner1.x += movevalue.x;
	 Corner1.y += movevalue.y;
	 Corner2.x += movevalue.x;
	 Corner2.y += movevalue.y;
	 Corner3.x += movevalue.x;
	 Corner3.y += movevalue.y;
};
