#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	TO_DRAW,	//	
	TO_PLAY,	//	
	DRAW_RECT,	//	
	DRAW_CIRCLE, //
	DRAW_SQUARE, //
	DRAW_HEXAGON, //
	DRAW_TRIANGLE,//
	//DECIDE_FIGURE_COLOR,// not sure about this part 
	EMPTY,
	DRAWING_AREA,
	STATUS,
	SELECT,
	CUT_FIGURE,
	SWAP,
	COPY_FIGURE,
	DELETE_FIGURE,
	CLEAR_ALL,
	ROTATE_FIGURE,
	PASTE_FIGURE,
	LOAD_GRAPH,
	SAVE_GRAPH,
	EXIT,
	MATCHING_PAIRS,
	MISSING_SHAPES,
	RESTART_THE_GAME,
	UNDO,
	REDO,
	//CHANGE_SHAPE_BOARDER_COLOR,
	//CHANGE_SHAPE_FILL_COLOR,
	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif