#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "Figures/CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle();
	CTriangle(Point, Point, Point , GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsIncluded(int x , int y) const;
	virtual FigureName GetFigureName() const;
	virtual void PrintFigureInfo(Output* pOut) const;
	virtual Point getCenter();
	virtual void Move(Point Center2);
	virtual void RotateCW();
	virtual void RotateACW();
	void Save(ofstream& OutFile)  override;
	void Load(ifstream& InFile)  override;
};

#endif