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
#include "pieceBishop.h"
#include "pieceRook.h"
#include "piecePawn.h"
#include "pieceKing.h"
#include "pieceQueen.h"
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
   if (fFree)
      free();
      
   // free everything cleaning things
   for (int r = 0; r < 8; r++)
      for (int c = 0; c < 8; c++)
         board[c][r] = nullptr;

   //creat four knights
   board[1][0] = new Knight(1, 0, true);
   board[6][0] = new Knight(6, 0, true);
   board[1][7] = new Knight(1, 7, false);
   board[6][7] = new Knight(6, 7, false);

   //everything else is spacees
   for (int r =0; r < 8; r++)
      for (int c = 0; c < 8; c++)
         if (nullptr == board[c][r])
            board[c][r] = new Space(c,r);
   
   //reset moves
   numMoves = 0;
   assertBoard();
}


/***********************************************
* BOARD : GET
*         Get a piece from a given position.
***********************************************/
const Piece& Board::operator [] (const Position& pos) const
{
   assert(nullptr != board[pos.getCol()][pos.getRow()]);
   return *(board[pos.getCol()][pos.getRow()]);
}
Piece& Board::operator [] (const Position& pos)
{
   assert(nullptr != board[pos.getCol()][pos.getRow()]);
   return *(board[pos.getCol()][pos.getRow()]);
}
 /***********************************************
 * BOARD : DISPLAY
 *         Display the board
 ***********************************************/
void Board::display(const Position & posHover, 
    const Position & posSelect) const
{
   pgout->drawBoard();

   for (int r = 0; r < 8; ++r)          
      for (int c = 0; c < 8; ++c)       
      {
         assert(nullptr != board[c][r]);
         board[c][r]->display(pgout);
      }
}


/************************************************
 * BOARD : CONSTRUCT
 *         Free up all the allocated memory
 ************************************************/
Board::Board(ogstream* pgout, bool noreset) : pgout(pgout), numMoves(0)
{
   if (!noreset)
      reset(false);
   else
      for (int r = 0; r < 8; r++)
         for(int c = 0; c < 8; c++)
            board[c][r] = nullptr;
}


/************************************************
 * BOARD : FREE
 *         Free up all the allocated memory
 ************************************************/
void Board::free()
{
   for (int r = 0; r < 8; r++)
      for (int c = 0; c < 8; c++)
         if (board[c][r] != nullptr)
            delete board[c][r];
}


/**********************************************
 * BOARD : ASSERT BOARD
 *         Verify the board is well-formed
 *********************************************/
void Board::assertBoard()
{
#ifndef NDEBUG
   for (int r = 0; r < 8; r++)
      for (int c = 0; c < 8; c++)
         if (board[c][r] != nullptr)
         {
            Position pos = board[c][r]->getPosition();
            assert(pos.getRow() == r);
            assert(pos.getCol() == c);
            assert(board[c][r]->getType() == SPACE ||
               board[c][r]->getType() == KING ||
               board[c][r]->getType() == QUEEN ||
               board[c][r]->getType() == ROOK ||
               board[c][r]->getType() == BISHOP ||
               board[c][r]->getType() == KNIGHT ||
               board[c][r]->getType() == PAWN);
         }
#endif // NDEBUG
}




/**********************************************
 * BOARD : MOVE
 *         Execute a move according to the contained instructions
 *   INPUT move The instructions of the move
 *********************************************/
void Board::move(const Move& move)
{
   assertBoard();
   Position s = move.getSrc();
   Position d = move.getDes();

   Piece* pSrc = board[s.getCol()][s.getRow()];
   Piece* pDes = board[d.getCol()][d.getRow()];
   assert(pSrc->getType() != SPACE);
   assert(s.isValid());
   assert(d.isValid());

   Move::MoveType type = move.getMoveType();

   if (type == Move::MOVE || type == Move::ENPASSANT)
   {
      PieceType ptNew = (move.getPromotion() == SPACE) ? pSrc->getType() :
         move.getPromotion();

      Piece* pSpace = new Space(s.getCol(), s.getRow());
      Piece* pNew = factory(ptNew, d.getCol(), d.getRow());
      *pNew = *pSrc;
      pNew->setLastMove(getCurrentMove());

      board[s.getCol()][s.getRow()] = pSpace;
      board[d.getCol()][d.getRow()] = pNew;

      numMoves++;
   }
   else if (type == Move::CASTLE_KING || type == Move::CASTLE_QUEEN)
   {
      assert(false); // Castle logic not yet implemented
   }

}
/**********************************************
 * FACTORY
 * A helper function to create pieces
 *********************************************/
Piece* factory(PieceType ptNew, int c, int r)
{
   switch (ptNew)
   {
   case SPACE:
      return new Space(c, r);
   case KING:
      // return new King(c, r); 
      break;
   case QUEEN:
      return new Queen(c, r, true); 
      break;
   case ROOK:
      // return new Rook(c, r); 
      break;
   case BISHOP:
      // return new Bishop(c, r); 
      break;
   case KNIGHT:
      return new Knight(c, r, true); 
   case PAWN:
      return new Pawn(c, r, true); 
      break;
   default:
      break;
   }

   return nullptr; 
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
