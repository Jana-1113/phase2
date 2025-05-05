#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "Figures/CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	
public:
	CCircle();
	CCircle(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsIncluded(int x, int y ) const;
	virtual FigureName GetFigureName() const;
	virtual void PrintFigureInfo(Output* pOut) const;
	virtual Point getCenter();
	virtual void Move(Point Center2);
	void Save(ofstream& OutFile)  override;
	void Load(ifstream& InFile)  override;
};

#endif