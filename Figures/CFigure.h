#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
enum FigureName { RECTANGLE, TRIANGLE, CIRCLE, HEXAGON, SQUARE };


//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected =false;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	string colorofFig;
	

	/// Add more parameters if needed.

public:

	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const = 0;		//Draw the figure
	virtual bool IsIncluded(int x, int y) const = 0;
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual FigureName GetFigureName() const = 0;
	virtual void PrintFigureInfo(Output* pOut) const = 0;
	virtual Point getCenter()  = 0;
	virtual void Move(Point Center2) = 0;
	virtual void RotateCW() = 0;
	virtual void RotateACW() = 0;
	virtual void Save(ofstream& OutFile) = 0;	// //Save the figure parameters to the file

	virtual void Load(ifstream& Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar

	static string ColorConverter(color C) {
		if (C == RED)   return "RED";
		if (C == GREEN) return "GREEN";
		if (C == BLUE)  return "BLUE";
		if (C == BLACK) return "BLACK";
		if (C == WHITE) return "WHITE";
	}
	static color StringConverter(string Color) {
		if (Color == "RED")   return RED;
		if (Color == "GREEN") return GREEN;
		if (Color == "BLUE")  return BLUE;
		if (Color == "BLACK") return BLACK;
		if (Color == "WHITE") return WHITE;
	}
	GfxInfo GetGfxInfo();
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif