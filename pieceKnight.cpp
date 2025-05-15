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
   // each of these pairings represents a direction a knight can move
   static const int dCol[] = { 1,  2,  2,  1, -1, -2, -2, -1 }; //possible changes to the knight's position in the column
   static const int dRow[] = { 2,  1, -1, -2, -2, -1,  1,  2 }; //possible changes
   
   for (int i = 0; i < 8; i++) // iterate through all 8 possible move directions
   {
      int c = position.getCol() + dCol[i];
      int r = position.getRow() + dRow[i];
      
      //create a new position called target. this is where the knight will end up if this move is made
      Position target(c, r);
      
      if (target.isInvalid()) { // skip to next iteration in loop if the position is invalid
         continue;
      }
      
      const Piece& dest = board[target]; // get a reference to the piece at the target position on the board
      
      if (dest.getType() != SPACE && dest.isWhite() == this->isWhite())
      { // skip to nect iteration if there is a piece there and it is the same color as this
         continue;
      }
      
      // create the move and add it to the moves set
      Move move;
      move.source = position;
      
   }
}
