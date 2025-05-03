#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	UI.width = 1450;
	//UI.width = 1250;
	UI.height = 800;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.LineUnderTBWidth = 3;
	UI.MenuItemWidth = 70;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = WHITE;		//Messages color
	//UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.BkGrndColor = WHEAT;
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = DARKGREEN;
	UI.PenWidth = 6;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project - Spring 2025");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
/*void Output::ClearToolBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI., 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}*/

//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	//pWind->SetPen(UI.BkGrndColor, 1);
	//pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_SQYARE] = "images\\MenuItems\\Menu_Square.jpg";
	MenuItemImages[ITM_TRINAGLE] = "images\\MenuItems\\Menu_Triangle.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\Menu_Circle.jpg";
	MenuItemImages[ITM_HEXAGON] = "images\\MenuItems\\Menu_Hexagon.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_SWAP] = "images\\MenuItems\\Menu_Swap.jpg";
	MenuItemImages[ITM_ROTATE] = "images\\MenuItems\\Menu_Rotate.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\Menu_Copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Menu_Cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\Menu_Paste.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_CLEARALL] = "images\\MenuItems\\Menu_ClearAll.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_Load.jpg";
	MenuItemImages[ITM_PLAYMODE] = "images\\MenuItems\\Menu_Playmode.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";


	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	//pWind->SetPen(UI.BkGrndColor, 1);
	//pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	UI.InterfaceMode = MODE_PLAY;
	string MenuIteImages[PLAY_ITM_COUNT];
	MenuIteImages[ITM_MATCHING_PAIRS] = "images\\MenuItems\\Menu_Matchingpairs.jpg";
	MenuIteImages[ITM_MISSING_SHAPES] = "images\\MenuItems\\Menu_Missingshape.jpg";
	MenuIteImages[ITM_RESTART_THE_GAME] = "images\\MenuItems\\Menu_Restart.jpg";
	MenuIteImages[ITM_SWITCH_TO_DRAW_MODE] = "images\\MenuItems\\Menu_Drawmode.jpg";
	//MenuIteImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	///TODO: write code to create Play mode menu
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuIteImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight + UI.LineUnderTBWidth, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}
void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const {
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; // Highlight if selected
	else
		DrawingClr = TriGfxInfo.DrawClr; // Use normal drawing color

	pWind->SetPen(DrawingClr, 1); // Respect border width
	drawstyle style;

	if (TriGfxInfo.isFilled) {
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr); // Fill color
	}
	else {
		style = FRAME; // No fill
	}

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}
void Output::DrawHexagon(Point P, GfxInfo HexGfxInfo, bool selected) const
{
	int xx = P.x;
	int yy = P.y;
	int X[6] = { xx + 60, xx + 30 ,xx - 30, xx - 60, xx - 30, xx + 30 };
	int Y[6] = { yy, yy + 52, yy + 52,yy , yy - 52, yy - 52 };

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawPolygon(X, Y, 6, style);

}

void Output::DrawCircle(Point P1, int radius, GfxInfo CirGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)


		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CirGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CirGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CirGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawCircle(P1.x, P1.y, radius, style);

}

void Output::DrawSquare(Point P, GfxInfo SquGfxInfo, bool selected) const
{
	int xx = P.x;
	int yy = P.y;
	int X[4] = { xx + 50, xx - 50, xx - 50, xx + 50};
	int Y[4] = { yy + 50, yy + 50, yy - 50, yy - 50 };


	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = SquGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (SquGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SquGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawPolygon(X, Y, 4, style);

}
void Output::SetDrawColor(Input* Pinput, GfxInfo& shapeinfo) {
	PrintMessage("Enter the first letter of the color: R  for Red, B  for Blue, K  for Black, G for Green, O  for Orange, Y for Yellow");
	string coller = Pinput->GetSrting(this);

	if (coller == "r" || coller == "R") {
		UI.DrawColor = RED;
		shapeinfo.FillClr = RED;
		shapeinfo.isFilled = true;
	}
	else if (coller == "b" || coller == "B") {
		UI.DrawColor = BLUE;
		shapeinfo.FillClr = BLUE;
		shapeinfo.isFilled = true;
	}
	else if (coller == "g" || coller == "G") {
		UI.DrawColor = GREEN;
		shapeinfo.FillClr = GREEN;
		shapeinfo.isFilled = true;
	}
	else if (coller == "k" || coller == "K") {
		UI.DrawColor = BLACK;
		shapeinfo.FillClr = BLACK;
		shapeinfo.isFilled = true;
	}
	else if (coller == "o" || coller == "O") {
		shapeinfo.FillClr = ORANGE;
		shapeinfo.isFilled = true;
		UI.DrawColor = ORANGE;
	}
	else if (coller == "y" || coller == "Y") {
		shapeinfo.FillClr = YELLOW;
		shapeinfo.isFilled = true;
		UI.DrawColor = YELLOW;
	}
	else {
		PrintMessage("The selected color can't be applied. The color of the shape will be unfilled ");
		shapeinfo.isFilled = false;


	}

}
Output::~Output()
{

}
