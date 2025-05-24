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
#include <vector>

 /***************************************************
  * KNIGHT
  * The knight, aka the "Horse"
  ***************************************************/
class Rook : public Piece
{
public:
   Rook(int c, int r, bool isWhite) : Piece(c, r, isWhite)       { }
   Rook(const Position& pos, bool isWhite) : Piece(pos, isWhite) { }
   ~Rook() {                }
   PieceType getType()            const { return ROOK; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;

private:

};
