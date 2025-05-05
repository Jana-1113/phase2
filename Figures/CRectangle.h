#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle();
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool IsIncluded(int x , int y)const;
	virtual FigureName CRectangle::GetFigureName() const;
	virtual void PrintFigureInfo(Output* pOut) const;
	virtual Point getCenter();
	virtual void Move(Point Center2);
	virtual void RotateCW();
	virtual void RotateACW();
	void Save(ofstream& OutFile)  override;
	void Load(ifstream& InFile)  override;


};

#endif