/***********************************************************************
 * Source File:
 *    PIECE 
 * Author:
 *    <your name here>
 * Summary:
 *    The Piece base class and all the derived classes:
 *       SPACE, KING, QUEEN, ROOK, KNIGHT, BISHOP, PAWN
 ************************************************************************/

#include "position.h"  // for POSITION
#include "piece.h"     // for all the PIECE class definitions
#include "pieceSpace.h"
#include "pieceKnight.h"
#include "board.h"     // for BOARD
#include "uiDraw.h"    // for draw*()
#include <cassert>     // because we are paranoid
using namespace std;


/************************************************
 * PIECE : ASSIGN
 ***********************************************/
const Piece & Piece::operator = (const Piece & rhs)
{
   fWhite = rhs.fWhite;
   lastMove = rhs.lastMove;
   nMoves = rhs.nMoves;

   return *this;
}



/************************************************
 * PIECE : GET MOVES
 * Iterate through the moves decorator to allow a piece to move
 ***********************************************/
void Piece::getMoves(set <Move> & movesSet, const Board & board) const
{
}

/***************************************************
* PIECE : GEN MOVES NO SLIDE
*         From a list of deltas, find all the
*         possible moves
***************************************************/
set <Move> Piece::getMovesNoslide(const Board& board,
   const Delta deltas[],
   int numDelta) const
{
   set <Move> moves;
   for (int i = 0; i < numDelta; i++)
   {
      Position posMove(position, deltas[i]);
      if (posMove.isValid() &&
         (board[posMove].isWhite() != fWhite || board[posMove] == SPACE))
      {
         Move move;
         move.setSrc(getPosition());
         move.setDes(posMove);
         move.setWhiteMove(isWhite());
         if (board[posMove] != SPACE)
            move.setCapture(board[posMove].getType());
         if (deltas[i].dCol == -2)
            move.setCastle(false);
         if (deltas[i].dCol == 2)
            move.setCastle(true);
         moves.insert(move);
      }
   }

   return moves;
}

/***************************************************
* PIECE : GEN MOVES SLIDE
*         From a vector of directions, find all the
*         possible moves
***************************************************/
set <Move> Piece::getMovesSlide(const Board& board,
   const Delta directions[], int size) const
{
   set <Move> moves;
   for (int i = 0; i <= size; i++)
   {
      bool blocked = false;
      Delta limit = directions[i];
      Position cPos(position, limit);
      while (cPos.isValid() && !blocked)
      {
         const Piece& p = board[cPos];

         if (p.getType() == SPACE)
         {
            Move m;
            m.setSrc(position);
            m.setDes(cPos);
            moves.insert(m);
         }
         else
         {
            if (p.isWhite() != fWhite)
            {
               Move m;
               m.setSrc(position);
               m.setDes(cPos);
               m.setCapture(p.getType());
               moves.insert(m);
            }
            blocked = true; // don't keep going
         }

         if (!blocked)
            cPos = cPos + limit;
      }

   }
   return moves;
}