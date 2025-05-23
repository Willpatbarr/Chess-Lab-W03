#pragma once

/***********************************************************************
 * Header File:
 *    Pawn
 * Author:
 *    <your name here>
 * Summary:
 *    The Pawn class
 ************************************************************************/

#include "piece.h"

/***************************************************
 * PAWN
 ***************************************************/

class Pawn : public Piece
{
public:
   Pawn(int c, int r, bool isWhite) : Piece(c, r, isWhite)       { }
   Pawn(const Position& pos, bool isWhite) : Piece(pos, isWhite) { }
   ~Pawn() {                }
   PieceType getType()            const { return PAWN; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;

private:
   set <Move> getMovesNoslide(const Board& board,
                              const Delta deltas[],
                              int numDelta) const;
};
