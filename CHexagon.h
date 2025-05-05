 #ifndef CHEXAGON_H
#define CHEXAGON_H

#include "Figures/CFigure.h"


class CHexagon : public CFigure
{
private:
	Point Center;
	bool rotated;
public:
	CHexagon();
	CHexagon(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool CHexagon::IsIncluded(int x , int y) const;
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