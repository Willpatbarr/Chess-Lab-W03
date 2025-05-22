/***********************************************************************
 * Header File:
 *    KING
 * Author:
*    <your name here>
 * Summary:
 *    The KING class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * KING
  * The king, kind of a big deal
  ***************************************************/
class King : public Piece
{
public:
   King(int c, int r, bool isWhite) : Piece(c, r, isWhite) {}
   King(const Position& pos, bool isWhite) : Piece(pos, isWhite) {}
   ~King() {}
   PieceType getType()            const { return KING; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;

private:

   bool canCastle(const Board& board) const;

};