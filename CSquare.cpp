#pragma once
# include <string>
# include <iostream>
using namespace std;
#include "CSquare.h"
#include "GUI/Input.h"
#include "Figures/CFigure.h"
#include "Figures/CRectangle.h"

CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}


void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSquare to draw a Square on the screen	
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}
bool CSquare::IsIncluded(int x , int y)const {

    double leftCorner = Center.x - 50;
    double rightCorner = Center.x + 50;
    double topCorner = Center.y - 50;
    double bottomCorner = Center.y + 50;

    if (x >= leftCorner && x <= rightCorner && y >= topCorner && y <= bottomCorner) {
        return true;
    }
    return false;

}
FigureName CSquare::GetFigureName() const {
    return SQUARE;
}
void CSquare::PrintFigureInfo(Output* pOut) const {
    string info = " This is a square  of Center(" + to_string(Center.x) + ", " + to_string(Center.y) +
        "), and side length is  " + to_string(100);
    pOut->PrintMessage(info);
}
Point CSquare::getCenter() {
    return Center;
 }
void CSquare::Move(Point Center2) {
    Center.x = Center2.x;
    Center.y = Center2.y;
 }







