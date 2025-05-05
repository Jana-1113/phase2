#pragma once
# include <string>
# include <iostream>
using namespace std;
#include "CHexagon.h"
#include "GUI/Input.h"
#include "Figures/CFigure.h"
#include "Figures/CRectangle.h"
#include "CTriangle.h"


CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}
void CHexagon::Draw(Output* pOut) const
{
    //Call Output::DrawSquare to draw a Square on the screen	
    pOut->DrawHexagon(Center, FigGfxInfo, Selected);
}

bool CHexagon::IsIncluded(int x, int y ) const {
    // first check the max and min x and y coordinates 
    const int max_x = 60;
    const int max_y = 52;

    // the third parameter needed for the two triangles and the rectangle 
    GfxInfo tempGfx;
    tempGfx.DrawClr = BLUE;  // Default color( iam not sure about this part )
    tempGfx.FillClr = BLACK;  // Doesn't matter for inclusion test
    tempGfx.isFilled = false; // Doesn't affect geometry

    // Devide the hexagon into one central rectangle and two other triangles 
    // the first check : check in the central rectangle 
    Point rectangleCorner1 = { Center.x - 30, Center.y - 26 }; // (x-30,y-26)
    Point rectangleCorner2 = { Center.x + 30, Center.y + 26 }; // (x+30,y+26)

    // the second check for the top trinagle 
    Point topTriangleCorners[3] = {
        {Center.x + 60, Center.y},      // (x+60,y+0)
        {Center.x + 30, Center.y + 52}, // (x+30,y+52) // check for these coordinates if there is any logical errors while running 
        {Center.x - 30, Center.y + 52}  // (x-30,y52)
    };

    // the third check : check for the bottom trinagle 
    Point bottomTriangleCorners[3] = {
        {Center.x - 60, Center.y},      // (x-60,y+0)
        {Center.x - 30, Center.y - 52}, // (x-30,y-52)
        {Center.x + 30, Center.y - 52}  // (x+30,y-52)
    };

    // create shapes to be able to call the isincluded functions for these shapes 
    // try to think about the static function before sbmitting to avoid creating shapes for calling and call directly using scoop resolution 
    CRectangle CentralRectangle(rectangleCorner1, rectangleCorner2, tempGfx);
    CTriangle TopTriangle(topTriangleCorners[0], topTriangleCorners[1], topTriangleCorners[2], tempGfx);
    CTriangle BottomTriangle(bottomTriangleCorners[0], bottomTriangleCorners[1], bottomTriangleCorners[2], tempGfx);

    // Check against all components
    if (CentralRectangle.IsIncluded(x,y) || TopTriangle.IsIncluded(x,y) || BottomTriangle.IsIncluded(x,y)) {
        return true;
    }
    return false;
}

FigureName CHexagon::GetFigureName() const {
    return HEXAGON;
}
void CHexagon::PrintFigureInfo(Output* pOut) const {
    string info = " This is a Hexagon of Center(" + to_string(Center.x) + ", " + to_string(Center.y) +
        "), and side length is  " + to_string(60);
    pOut->PrintMessage(info);
}
Point CHexagon::getCenter() {
    return Center;
}
void CHexagon::Move(Point Center2) {
    Center.x = Center2.x;
    Center.y = Center2.y;
}

void CHexagon :: GetPoints() {

    points[0].x = Center.x - 60 / 2; 
    points[0].y = Center.y - 52;
    points[1].x = Center.x + 60 / 2;
    points[1].y = Center.y - 52;
    points[2].x =  Center.x + 60;
    points[2].y = Center.y;
    points[3].y = Center.x + 60 / 2; 
    points[3].y = Center.y + 52;
    points[4].x = Center.x - 60 / 2;
    points[4].y = Center.y + 52;
    points[5].x = Center.x - 60;
    points[5].y = Center.y;
}

void CHexagon::RotateCW() {
    GetPoints();
    for (int i = 0; i < 6; i++) {
        Point temp;
        temp.x = points[i].x;
        temp.y = points[i].y;

        points[i].x = Center.x + (temp.y - Center.y);
        points[i].y = Center.y - (temp.x - Center.x);

    }
 }

void CHexagon::RotateACW() {
    GetPoints();
    for (int i = 0; i < 6; i++) {
        Point temp;
        temp.x = points[i].x;
        temp.y = points[i].y;

        points[i].x = Center.x -(temp.y - Center.y);
        points[i].y = Center.y+ (temp.x - Center.x);

    }
}





