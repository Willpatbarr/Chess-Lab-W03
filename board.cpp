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


   // Pawns
   for (int col = 0; col < 8; ++col)
   {
      board[col][1] = new Pawn(col, 1, true);   // White pawns
      board[col][6] = new Pawn(col, 6, false);  // Black pawns
   }

   // Rooks
   board[0][0] = new Rook(0, 0, true);
   board[7][0] = new Rook(7, 0, true);
   board[0][7] = new Rook(0, 7, false);
   board[7][7] = new Rook(7, 7, false);

   // Knights
   board[1][0] = new Knight(1, 0, true);
   board[6][0] = new Knight(6, 0, true);
   board[1][7] = new Knight(1, 7, false);
   board[6][7] = new Knight(6, 7, false);

   // Bishops
   board[2][0] = new Bishop(2, 0, true);
   board[5][0] = new Bishop(5, 0, true);
   board[2][7] = new Bishop(2, 7, false);
   board[5][7] = new Bishop(5, 7, false);

   // Queens
   board[3][0] = new Queen(3, 0, true);
   board[3][7] = new Queen(3, 7, false);

   // Kings
   board[4][0] = new King(4, 0, true);
   board[4][7] = new King(4, 7, false);

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
   set <Move> moves;


   pgout->drawBoard();
   pgout->drawHover(posHover);
   pgout->drawSelected(posSelect);
   if(posSelect.isValid())
   {
      const Piece& cPiece = (*this)[posSelect];
      cPiece.getMoves(moves, *this);


      for (const Move& m : moves)
      {
         pgout->drawHover(m.getDes());
         //if (posSelect == m.getDes())
         //{
         //   move(m);
         //}
      }
      
   }

  

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

   if (type == Move::MOVE)
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
   else if (type == Move::ENPASSANT)
   {
      PieceType ptNew = (move.getPromotion() == SPACE) ? pSrc->getType()
         : move.getPromotion();

      Piece* pNew = factory(ptNew, d.getCol(), d.getRow());
      *pNew = *pSrc;
      pNew->setLastMove(getCurrentMove());

      Piece* pSpaceSrc = new Space(s.getCol(), s.getRow());
      board[s.getCol()][s.getRow()] = pSpaceSrc;

      Piece* pSpaceCap = new Space(d.getCol(), s.getRow());
      board[d.getCol()][s.getRow()] = pSpaceCap;

      board[d.getCol()][d.getRow()] = pNew;

      numMoves++;
   }

   else if (type == Move::CASTLE_KING)
   {
      // Move the king
      PieceType ptNew = (move.getPromotion() == SPACE) ? pSrc->getType() :
         move.getPromotion();

      Piece* pSpaceK = new Space(s.getCol(), s.getRow());
      Piece* pKing = factory(ptNew, d.getCol(), d.getRow());
      *pKing = *pSrc;
      pKing->setLastMove(getCurrentMove());

      board[s.getCol()][s.getRow()] = pSpaceK;
      board[d.getCol()][d.getRow()] = pKing;

      // Move the rook from h1 (7,0) to f1 (5,0)
      Piece* pRookSrc = board[7][0];
      assert(pRookSrc->getType() == ROOK);

      Piece* pSpaceR = new Space(7, 0);
      Piece* pRook = factory(ROOK, 5, 0);
      *pRook = *pRookSrc;
      pRook->setLastMove(getCurrentMove());

      board[7][0] = pSpaceR;
      board[5][0] = pRook;

      numMoves++;
   }
   else if (type == Move::CASTLE_QUEEN)
   {
      // Move the king
      PieceType ptNew = (move.getPromotion() == SPACE) ? pSrc->getType() :
         move.getPromotion();

      Piece* pSpaceK = new Space(s.getCol(), s.getRow());          
      Piece* pKing = factory(ptNew, d.getCol(), d.getRow());      
      *pKing = *pSrc;
      pKing->setLastMove(getCurrentMove());

      board[s.getCol()][s.getRow()] = pSpaceK;
      board[d.getCol()][d.getRow()] = pKing;

      // Move the rook from a1 (0,0) to d1 (3,0)
      Piece* pRookSrc = board[0][0];
      assert(pRookSrc->getType() == ROOK);

      Piece* pSpaceR = new Space(0, 0);
      Piece* pRook = factory(ROOK, 3, 0);
      *pRook = *pRookSrc;
      pRook->setLastMove(getCurrentMove());

      board[0][0] = pSpaceR;
      board[3][0] = pRook;

      numMoves++;
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
      return new King(c, r, true); 
      break;
   case QUEEN:
      return new Queen(c, r, true); 
      break;
   case ROOK:
      return new Rook(c, r, true); 
      break;
   case BISHOP:
      return new Bishop(c, r, true); 
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
