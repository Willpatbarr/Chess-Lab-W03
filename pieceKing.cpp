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
   Delta deltas[10];

   int deltaCount = 0;

   deltas[deltaCount++] = { -1,  1 };
   deltas[deltaCount++] = {  0,  1 };
   deltas[deltaCount++] = {  1,  1 };
   deltas[deltaCount++] = { -1,  0 };
   deltas[deltaCount++] = {  1,  0 };
   deltas[deltaCount++] = { -1, -1 };
   deltas[deltaCount++] = {  0, -1 };
   deltas[deltaCount++] = {  1, -1 };


   bool canCastleQ = false;
   bool canCastleK = false;

   if (nMoves == 0)
   {
      int row = position.getRow();

      Position qRookPos(0, row);
      Position kRookPos(7, row);

      const Piece& qRPiece = board[qRookPos];
      const Piece& kRPiece = board[qRookPos];

      
      Position b(row, 1);
      Position c(row, 2);
      Position d(row, 3);
      Position e(row, 4);
      Position f(row, 5);
      Position g(row, 6);

      //cout << "  " << qRPiece.getType() << "  qRPiece moves: " << qRPiece.getNMoves() << endl;

      if (position.getCol() == 4)
      {
         if ((board[b].getType() == SPACE || board[b].getType() == KING) &&
            (board[c].getType() == SPACE || board[c].getType() == KING) &&
            (board[d].getType() == SPACE || board[d].getType() == KING))
            if (qRPiece.getNMoves() == 0)
               canCastleQ = true;
         if ((board[f].getType() == SPACE || board[f].getType() == KING) &&
            (board[g].getType() == SPACE || board[g].getType() == KING))
            if (kRPiece.getNMoves() == 0)
               canCastleK = true;

      }         

      
   }

   if (canCastleQ)
   {
      deltas[deltaCount++] = { 0, -2 };  // queenside

   }
   if (canCastleK)
   {
      deltas[deltaCount++] = { 0, 2 };   // kingside
   }
   
   moves = getMovesNoslide(board, deltas, deltaCount);
}

