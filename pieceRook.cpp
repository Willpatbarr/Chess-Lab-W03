/**********************************************************************
* Source File:
*    PAWN
* Author:
*    <your name here>
* Summary:
*   PAWN class
************************************************************************/
#include "pieceRook.h"
#include "board.h"

/************************************************
 * ROOK : getMoves()
 * get the possible moves the pawn can make and add them to the moves set
 ***********************************************/
void Rook::getMoves(set <Move>& moves, const Board& board) const
{
   Delta directions[4] = {
      {  0,  1 },  // up    (direction 1)
      {  0, -1 },  // down  (direction 2)
      { -1,  0 },  // left  (direction 3)
      {  1,  0 }   // right (direction 4)
   };
   int size = sizeof(directions) / sizeof(directions[0]);
   moves = getMovesSlide(board, directions, size);

}

/************************************************
 * PAWN : display
 * Show the troops
 ***********************************************/
void Rook::display(ogstream* pgout)  const
{

}

