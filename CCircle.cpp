#pragma once
# include <string>
# include <iostream>
#include "CCircle.h"
#include "GUI/Input.h"
#include "Figures/CFigure.h"
#include "Figures/CRectangle.h"
#include <fstream> 
using namespace std;

CCircle::CCircle() : CFigure() {
	Center.x = 0;
	Center.y = 0;
}

CCircle::CCircle(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawSquare to draw a Square on the screen	
	pOut->DrawCircle(Center, 70, FigGfxInfo, Selected);
}
bool CCircle::IsIncluded(int x , int y) const {

	int distance_x = x - Center.x;
	int distance_y= y - Center.y;

	if (distance_x * distance_x + distance_y * distance_y <= 70 * 70) {
		return true;
	}
	return false;
}
FigureName CCircle::GetFigureName() const {
	return CIRCLE;
}
void CCircle::PrintFigureInfo(Output* pOut) const {
	string info = "Circle: Center(" + to_string(Center.x) + ", " + to_string(Center.y) +
		"), Radius = " + to_string(70);
	pOut->PrintMessage(info);
}
Point CCircle::getCenter() {
	return Center;
}
void CCircle::Move(Point Center2) {
	Center.x = Center2.x;
	Center.y = Center2.y;
}
void CCircle::Save(ofstream& OutFile)
{
	OutFile << "CIRCLE " << ID << " "
		<< Center.x << " " << Center.y << " " << CFigure::ColorConverter(FigGfxInfo.DrawClr) << " ";
}
void CCircle::Load(ifstream& InFile) {
	InFile >> ID >> Center.x >> Center.y >> colorofFig;
	CFigure::StringConverter(colorofFig);
}