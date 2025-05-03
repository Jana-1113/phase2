#pragma once
#ifndef CSQUARE_H
#define CSQUARE_H

#include "Figures/CFigure.h"

class CSquare : public CFigure
{
private:
	Point Center;
public:
	CSquare( Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsIncluded(int x , int y)const;
	virtual FigureName GetFigureName() const;
	virtual void PrintFigureInfo(Output* pOut) const;
};

#endif
