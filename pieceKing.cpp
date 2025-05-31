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
   Delta deltas[8];
   int deltaCount = 0;

   // Normal king moves
   deltas[deltaCount++] = { -1,  1 };
   deltas[deltaCount++] = {  0,  1 };
   deltas[deltaCount++] = {  1,  1 };
   deltas[deltaCount++] = { -1,  0 };
   deltas[deltaCount++] = {  1,  0 };
   deltas[deltaCount++] = { -1, -1 };
   deltas[deltaCount++] = {  0, -1 };
   deltas[deltaCount++] = {  1, -1 };

   // Add normal king moves
   moves = getMovesNoslide(board, deltas, deltaCount);

   // Castling logic
   if (nMoves == 0)
   {
      int row = position.getRow();
      Position qRookPos(0, row);
      Position kRookPos(7, row);

      const Piece& qRPiece = board[qRookPos];
      const Piece& kRPiece = board[kRookPos];

      Position b(1, row);
      Position c(2, row);
      Position d(3, row);
      Position f(5, row);
      Position g(6, row);

      if (position.getCol() == 4)
      {
         // Queenside castling
         if (board[b].getType() == SPACE &&
             board[c].getType() == SPACE &&
             board[d].getType() == SPACE &&
             qRPiece.getType() == ROOK &&
             qRPiece.getNMoves() == 0)
         {
            Move castleQ;
            castleQ.setSrc(position);
            castleQ.setDes(c);  // King ends up on c-file (col=2)
            castleQ.setCastle(false);
            moves.insert(castleQ);
         }

         // Kingside castling
         if (board[f].getType() == SPACE &&
             board[g].getType() == SPACE &&
             kRPiece.getType() == ROOK &&
             kRPiece.getNMoves() == 0)
         {
            Move castleK;
            castleK.setSrc(position);
            castleK.setDes(g);  // King ends up on g-file (col=6)
            castleK.setCastle(true);
            moves.insert(castleK);
         }
      }
   }
}


