/***********************************************************************
 * Source File:
 *    KING
 * Author:
 *    <your name here>
 * Summary:
 *    The king class
 ************************************************************************/

#include "pieceKing.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

#include <iostream>

using namespace std;

/***************************************************
* PIECE DRAW
* Draw the piece.
***************************************************/
void King::display(ogstream* pgout) const
{
   pgout->drawKing(position.getLocation(), !isWhite());
}


/**********************************************
 * KING : GET POSITIONS
 *********************************************/
void King::getMoves(set <Move>& moves, const Board& board) const
{
   const Delta deltas[] =
   {
      { -1, 1 }, {  0,  1 }, {  1,  1 },
      { -1, 0 },             {  1,  0 },
      { -1,-1 }, {  0, -1 }, {  1, -1 }
   };

   moves = getMovesNoslide(board,
      deltas, sizeof(deltas) / sizeof(deltas[0]));
}

/**********************************************
 * KING : CAN CASTLE
 *********************************************/
bool King::canCastle(const Board& board) const
{
 return true;
}