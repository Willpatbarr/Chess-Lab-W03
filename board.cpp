/***********************************************************************
 * Source File:
 *    BOARD 
 * Author:
 *    <your name here>
 * Summary:
 *    A collection of pieces and a small amount of game state
 ************************************************************************/

#include "board.h"
#include "uiDraw.h"
#include "position.h"
#include "piece.h"
#include "pieceSpace.h"
#include "pieceKnight.h"
#include <cassert>

#include <iostream>
using namespace std;


/***********************************************
 * BOARD : RESET
 *         Just fill the board with the known pieces
 *   +---a-b-c-d-e-f-g-h---+
 *   |                     |
 *   8     N         N     8
 *   7                     7
 *   6                     6
 *   5                     5
 *   4                     4
 *   3                     3
 *   2                     2
 *   1     n         n     1
 *   |                     |
 *   +---a-b-c-d-e-f-g-h---+
 ***********************************************/
void Board::reset(bool fFree)
{
   // free everything
   for (int r = 0; r < 8; r++)
      for (int c = 0; c < 8; c++)
         board[c][r] = nullptr;
}

// we really REALLY need to delete this.
Space space(0,0);

/***********************************************
* BOARD : GET
*         Get a piece from a given position.
***********************************************/
const Piece& Board::operator [] (const Position& pos) const
{
   return *(board[pos.getCol()][pos.getRow()]);
}
Piece& Board::operator [] (const Position& pos)
{

   return *(board[pos.getCol()][pos.getRow()]);
}
 /***********************************************
 * BOARD : DISPLAY
 *         Display the board
 ***********************************************/
void Board::display(const Position & posHover, const Position & posSelect) const
{
   pgout->drawBoard();

   for (int c = 0; c < 8; ++c)          
      for (int r = 0; r < 8; ++r)       
      {
         Piece* p = board[c][r];        // board[col][row] layout
         if (p && p->getType() != SPACE)
            p->display(pgout);
      }
}


/************************************************
 * BOARD : CONSTRUCT
 *         Free up all the allocated memory
 ************************************************/
Board::Board(ogstream* pgout, bool noreset) : pgout(pgout), numMoves(0)
{
   for (int r=0; r<8; r++)
      for(int c=0; c<8; c++)
         board[r][c] = nullptr;

   board[1][0] = new Knight(1, 0, true);  // white knight on b1
   board[6][0] = new Knight(6, 0, true);  // white knight on g1
   board[1][7] = new Knight(1, 7, false);  // black knight on b8
   board[6][7] = new Knight(6, 7, false);  // black knight on g8
}


/************************************************
 * BOARD : FREE
 *         Free up all the allocated memory
 ************************************************/
void Board::free()
{

}


/**********************************************
 * BOARD : ASSERT BOARD
 *         Verify the board is well-formed
 *********************************************/
void Board::assertBoard()
{

}




/**********************************************
 * BOARD : MOVE
 *         Execute a move according to the contained instructions
 *   INPUT move The instructions of the move
 *********************************************/
void Board::move(const Move& move)
{
   Position s = move.getSrc();
   Position d = move.getDes();

   if (s.isInvalid() || d.isInvalid())
      return;

   // board[col][row]  – column first
   Piece*& pSrc = board[s.getCol()][s.getRow()];
   Piece*& pDest = board[d.getCol()][d.getRow()];

   ++numMoves;

   if (move.getMoveType() == Move::MOVE)
   {
      // move the pointer
      pDest = pSrc;

      // leave a Space behind
      pSrc = new Space(s.getCol(), s.getRow());

      // update piece internals
      pDest->setPosition(d);
      pDest->setLastMove(numMoves);
   }
}



/**********************************************
 * BOARD EMPTY
 * The game board that is completely empty.
 * It does not even have spaces though each non-filled
 * spot will report it has a space. This is for unit testing
 *********************************************/
BoardEmpty::BoardEmpty() : BoardDummy(), pSpace(nullptr), moveNumber(0)
{
   pSpace = new Space(0, 0);
}
BoardEmpty::~BoardEmpty() 
{
   delete pSpace;
}
