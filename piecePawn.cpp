/**********************************************************************
* Source File:
*    PAWN
* Author:
*    <your name here>
* Summary:
*   PAWN class
************************************************************************/

#include "piecePawn.h"

/************************************************
 * PAWN : getMoves()
 * get the possible moves the pawn can make and add them to the moves set
 ***********************************************/
void Pawn::getMoves(set <Move>& moves, const Board& board) const
{
   // initiate the Delta array
   Delta deltas[4]; // only four possible moves max
   int numDeltas = 0;
   int direction = fWhite ? 1 : -1; //determine which direction is considered forward for each color
   
   // if there is no piece blocking the pawn in one square
   Position oneAhead = position;
   oneAhead.adjustRow(direction);
   if (oneAhead.isValid() &&
       board[oneAhead].getType() == SPACE)
   {
      deltas[numDeltas++] = { direction, 0 };
      
      // if no piece is blocking 2 spaces away and the pawn aint moved yet
      Position twoAhead = oneAhead;
      twoAhead.adjustRow(direction);
      if (getNMoves() == 0 &&
          twoAhead.isValid() &&
          board[twoAhead].getType() == SPACE)
      {
         deltas[numDeltas++] = {2 * direction, 0 };
      }
   }
   
   // if the pawn has a piece diagonal to the left or right
   // left
   Position leftCapture = position;
   leftCapture.adjustRow(direction);
   leftCapture.adjustCol(-1);
   if (leftCapture.isValid() &&
       board[leftCapture].getType() != SPACE) // does not check for color because getMovesNoSlide does
   {
      deltas[numDeltas++] = { direction, -1 };
   }
   
   Position rightCapture = position;
   rightCapture.adjustRow(direction);
   rightCapture.adjustCol(1);
   if (rightCapture.isValid() &&
       board[rightCapture].getType() != SPACE)
   {
      deltas[numDeltas++] = { direction, 1 };
   }
      
   // add all of them to the deltas array
   set<Move> generated = getMovesNoslide(board, deltas, numDeltas);
   for (Move m : generated)
   {
      int destRow = m.getDes().getRow();
      if ((fWhite && destRow == 7) || (!fWhite && destRow == 0))
      {
         m.setPromote(QUEEN);
      }
      moves.insert(m);
   }

   
   // if the piece can en passant
   for (int dCol = -1; dCol <= 1; dCol += 2) // use a for loop to check for both side positions
   {
      Position side = position;
      side.adjustCol(dCol);
      if (side.isValid() &&
          board[side].getType() == PAWN &&
          board[side].isWhite() != fWhite &&
          board[side].getNMoves() == 1 &&
          board[side].justMoved(board.getCurrentMove()))
      {
         Position target = position;
         target.adjustRow(fWhite ? 1 : -1);
         target.adjustCol(dCol);
         
         if (target.isValid() && board[target].getType() == SPACE)
         {
            Move m;
            m.setSrc(position);
            m.setDes(target);
            m.setWhiteMove(fWhite);
            m.setEnPassant(); // make it an enpassant
            m.setCapture(PAWN);

            moves.insert(m);
         }
      }
   }
}

/************************************************
 * PAWN : display
 * Show the troops
 ***********************************************/
void Pawn::display(ogstream* pgout)  const
{
   pgout->drawPawn(position.getLocation(), !isWhite());
}

