/***********************************************************************
 * Source File:
 *    KNIGHT
 * Author:
 *    <your name here>
 * Summary:
 *    The knight class
 ************************************************************************/

#include "pieceKnight.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

#include <iostream>

using namespace std;

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Knight::display(ogstream* pgout) const
{
   pgout->drawKnight(position.getLocation(), !isWhite());
}


/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
void Knight::getMoves(set <Move>& moves, const Board& board) const
{
   const Delta deltas[] =
   {
                 {  -1, 2 }, {  1, 2 },
      { -2,  1 },                       {  2,  1 },
      { -2, -1 },                       {  2, -1 },
                 { -1, -2 }, { 1, -2 }
   };

   moves = getMovesNoslide(board,
                           deltas, sizeof(deltas) / sizeof(deltas[0]));

}