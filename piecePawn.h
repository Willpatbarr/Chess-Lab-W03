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
#include "board.h"
#include  "move.h"
#include "position.h"

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
   int direction = fWhite ? 1 : -1;
};
