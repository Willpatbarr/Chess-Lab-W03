/**********************************************************************
* Source File:
*    PAWN
* Author:
*    <your name here>
* Summary:
*   PAWN class
************************************************************************/
#include "pieceQueen.h"
#include "board.h"

/************************************************
 * QUEEN : getMoves()
 * get the possible moves the pawn can make and add them to the moves set
 ***********************************************/
void Queen::getMoves(set <Move>& moves, const Board& board) const
{
   Delta directions[8] = {
      {  0,  1 },  // up            (direction 1)
      {  0, -1 },  // down          (direction 2)
      { -1,  0 },  // left          (direction 3)
      {  1,  0 },  // right         (direction 4)      
      {  1,  1 },  // ++ diagonal   (direction 5)
      {  1, -1 },  // +- diagonal   (direction 6)
      { -1, -1 },  // -- diagonal   (direction 7)
      { -1,  1 }   // -+ diagonal   (direction 8)

   };
   int size = sizeof(directions) / sizeof(directions[0]);
   moves = getMovesSlide(board, directions, size);

}

/************************************************
 * QUEEN : display
 * Show the lady
 ***********************************************/
void Queen::display(ogstream* pgout)  const
{
   pgout->drawQueen(position.getLocation(), !isWhite());

}

