#pragma once
/***********************************************************************
 * Header File:
 *    ROOK
 * Author:
*    <your name here>
 * Summary:
 *    The ROOK class
 ************************************************************************/

#include "piece.h"
#include "pieceType.h"
#include "uiDraw.h"


 /***************************************************
  * QUEEN
  * The QUEEN she a lady
  ***************************************************/
class Queen : public Piece
{
public:
   Queen(int c, int r, bool isWhite) : Piece(c, r, isWhite) {}
   Queen(const Position& pos, bool isWhite) : Piece(pos, isWhite) {}
   ~Queen() {}
   PieceType getType()            const { return QUEEN; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;

private:

};
