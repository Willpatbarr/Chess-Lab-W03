/***********************************************************************
 * Header File:
 *    Bishop
 * Author:
 *    <your name here>
 * Summary:
 *    The Bishop class
 ************************************************************************/

#pragma once

#include "piece.h"
#include "pieceType.h"
#include "uiDraw.h"

/***************************************************
 * BISHOP
 * The bishop is a piece that can move diagonally.
 ***************************************************/
class Bishop : public Piece
{
public:
    Bishop(int c, int r, bool isWhite) : Piece(c, r, isWhite) {}
    Bishop(const Position& pos, bool isWhite = true) : Piece(pos, isWhite) {}
    ~Bishop() {}
    PieceType getType()            const { return BISHOP; }
    void getMoves(set <Move>& moves, const Board& board) const;
    void display(ogstream* pgout)  const;

private:
};