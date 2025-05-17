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

}


/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
void Knight::getMoves(set <Move>& moves, const Board& board) const
{
   const Delta deltas[] =
   {
      {  1, -2 }, {  2, -1 }, {  2,  1 }, {  1,  2 },
      { -1,  2 }, { -2,  1 }, { -2, -1 }, { -1, -2 }
   };
   

   for (int i =0; i <8; i++)
   {
      Position tempPos;
      tempPos = position;
      tempPos += deltas[i];

      if (tempPos.isInvalid())
         continue;

      const Piece* pDes = &board[tempPos];

      // Skip if occupied by a piece of the same color
      if (pDes->getType() != SPACE && pDes->isWhite() == this->isWhite())
         continue;


      Move newMove;
      newMove.setSrc(position);
      newMove.setDes(tempPos);

      // Mark as capture if it’s an enemy piece
      if (pDes->getType() != SPACE && pDes->isWhite() != this->isWhite())
         newMove.setCapture(pDes->getType());
      else
         newMove.setCapture(SPACE);

      moves.insert(newMove);
   }

   

}