/***********************************************************************
 * Source File:
 *    Bishop
 * Author:
 *    <your name here>
 * Summary:
 *    The bishop class
 ************************************************************************/

#include "pieceBishop.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

#include <iostream>

using namespace std;

/**********************************************
 * BISHOP : GET POSITIONS
 *          Find all the possible moves for 
 *          a bishop.
 *********************************************/
void Bishop::getMoves(set <Move>& moves, const Board& board) const
{

    Delta directions[4] = {
        {-1,-1}, // down left
        { 1,-1}, // down right
		{ 1, 1}, // up right
		{-1, 1}  // up left
    };

	int size = sizeof(directions) / sizeof(directions[0]);
    moves = getMovesSlide(board,
        directions, size);
}

/************************************************
 * Bishop : display
 * Show the Bishop
 ***********************************************/
void Bishop::display(ogstream* pgout)  const
{
    pgout->drawBishop(position.getLocation(), !isWhite());

}