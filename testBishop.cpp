/***********************************************************************
 * Source File:
 *    TEST BISHOP
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for a bishop
 ************************************************************************/


#include "testBishop.h"
#include "pieceBishop.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      
using namespace std;


 /*************************************
  * +---a-b-c-d-e-f-g-h---+
  * |                     |
  * 8                     8
  * 7                     7
  * 6                     6
  * 5                     5
  * 4                     4
  * 3     p   p           3
  * 2      (b)            2
  * 1     p   p           1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestBishop::getMoves_blocked()
{
   // SETUP
   BoardEmpty board;

   Bishop bishop(7, 7, true /*white*/);
   bishop.fWhite = true;
   bishop.position.colRow = 0x21;
   board.board[2][1] = &bishop;

   White w1(PAWN);
   board.board[1][0] = &w1;

   White w2(PAWN);
   board.board[1][2] = &w2;

   White w3(PAWN);
   board.board[3][0] = &w3;

   White w4(PAWN);
   board.board[3][2] = &w4;

   set <Move> moves;

   // EXERCISE
   
   bishop.getMoves(moves, board);

   // VERIFY

   //cout << moves.size() << endl;
   assertUnit(moves.size() == 0);

   // TEARDOWN
   board.board[2][1] = nullptr;
   board.board[1][0] = nullptr;
   board.board[1][2] = nullptr;
   board.board[3][0] = nullptr;
   board.board[3][2] = nullptr;

}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 .   7
 * 6               .     6
 * 5             .       5
 * 4   .       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     .   .           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToEnd()
{
   // SETUP
   BoardEmpty board;

   Bishop bishop(7, 7, true /*white*/);
   bishop.fWhite = true;
   bishop.position.colRow = 0x21;
   board.board[2][1] = &bishop;

   set <Move> moves;

   Move c2a4;
   Move c2b3;
   Move c2b1;
   Move c2d1;
   Move c2d3;
   Move c2e4;
   Move c2f5;
   Move c2g6;
   Move c2h7;

   c2a4.source.colRow = c2b3.source.colRow = c2b1.source.colRow =
   c2d1.source.colRow = c2d3.source.colRow = c2e4.source.colRow =
   c2f5.source.colRow = c2g6.source.colRow = c2h7.source.colRow = 0x21;

   c2a4.dest.colRow = 0x03;
   c2b3.dest.colRow = 0x12;
   c2b1.dest.colRow = 0x10;
   c2d1.dest.colRow = 0x30;
   c2d3.dest.colRow = 0x32;
   c2e4.dest.colRow = 0x43;
   c2f5.dest.colRow = 0x54;
   c2g6.dest.colRow = 0x65;
   c2h7.dest.colRow = 0x76;

   // EXERCISE
   bishop.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 9);
   assertUnit(moves.find(c2a4) != moves.end());
   assertUnit(moves.find(c2b3) != moves.end());
   assertUnit(moves.find(c2b1) != moves.end());
   assertUnit(moves.find(c2d1) != moves.end());
   assertUnit(moves.find(c2d3) != moves.end());
   assertUnit(moves.find(c2e4) != moves.end());
   assertUnit(moves.find(c2f5) != moves.end());
   assertUnit(moves.find(c2g6) != moves.end());
   assertUnit(moves.find(c2h7) != moves.end());

   // TEARDOWN
   board.board[2][1] = nullptr;
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 p   7
 * 6               .     6
 * 5             .       5
 * 4   p       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     p   p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToBlock()
{
   // SETUP
   BoardEmpty board;

   Bishop bishop(7, 7, true /*white*/);
   bishop.fWhite = true;
   bishop.position.colRow = 0x21;
   board.board[2][1] = &bishop;

   White w1(PAWN);
   board.board[0][3] = &w1;
      
   White w2(PAWN);
   board.board[1][0] = &w2;

   White w3(PAWN);
   board.board[3][0] = &w3;

   White w4(PAWN);
   board.board[7][6] = &w4;


   set <Move> moves;


   Move c2b3;
   Move c2d3;
   Move c2e4;
   Move c2f5;
   Move c2g6;

   c2b3.source.colRow = c2d3.source.colRow = c2e4.source.colRow =
   c2f5.source.colRow = c2g6.source.colRow = 0x21;

   c2b3.dest.colRow = 0x12;
   c2d3.dest.colRow = 0x32;
   c2e4.dest.colRow = 0x43;
   c2f5.dest.colRow = 0x54;
   c2g6.dest.colRow = 0x65;

	// EXERCISE
	bishop.getMoves(moves, board);

	// VERIFY
	assertUnit(moves.size() == 5);
	assertUnit(moves.find(c2b3) != moves.end());
	assertUnit(moves.find(c2d3) != moves.end());
	assertUnit(moves.find(c2e4) != moves.end());
	assertUnit(moves.find(c2f5) != moves.end());
	assertUnit(moves.find(c2g6) != moves.end());

	// TEARDOWN
	board.board[2][1] = nullptr;
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 P   7
 * 6               .     6
 * 5             .       5
 * 4   P       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     P   P           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToCapture()
{
   // SETUP
   BoardEmpty board;

   Bishop bishop(7, 7, true /*white*/);
   bishop.fWhite = false;
   bishop.position.colRow = 0x21;
   board.board[2][1] = &bishop;

   White w1(PAWN);
   board.board[0][3] = &w1;

   White w2(PAWN);
   board.board[1][0] = &w2;

   White w3(PAWN);
   board.board[3][0] = &w3;

   White w4(PAWN);
   board.board[7][6] = &w4;


   set <Move> moves;


   Move c2b3;
   Move c2d3;
   Move c2e4;
   Move c2f5;
   Move c2g6;
   Move c2b1P;
   Move c2d1P;
   Move c2h7P;
   Move c2a4P;

   c2a4P.capture = c2b1P.capture = c2d1P.capture = 
   c2h7P.capture = PAWN;

   c2a4P.source.colRow = c2b3.source.colRow = c2b1P.source.colRow =
   c2d1P.source.colRow = c2d3.source.colRow = c2e4.source.colRow =
   c2f5.source.colRow = c2g6.source.colRow = c2h7P.source.colRow = 
   0x21;

   c2a4P.dest.colRow = 0x03;
   c2b3.dest.colRow = 0x12;
   c2b1P.dest.colRow = 0x10;
   c2d1P.dest.colRow = 0x30;
   c2d3.dest.colRow = 0x32;
   c2e4.dest.colRow = 0x43;
   c2f5.dest.colRow = 0x54;
   c2g6.dest.colRow = 0x65;
   c2h7P.dest.colRow = 0x76;

   // EXERCISE
   bishop.getMoves(moves, board);


   // VERIFY
   assertUnit(moves.size() == 9);
   assertUnit(moves.find(c2a4P) != moves.end());
   assertUnit(moves.find(c2b3) != moves.end());
   assertUnit(moves.find(c2b1P) != moves.end());
   assertUnit(moves.find(c2d1P) != moves.end());
   assertUnit(moves.find(c2d3) != moves.end());
   assertUnit(moves.find(c2e4) != moves.end());
   assertUnit(moves.find(c2f5) != moves.end());
   assertUnit(moves.find(c2g6) != moves.end());
   assertUnit(moves.find(c2h7P) != moves.end());

   // TEARDOWN
   board.board[2][1] = nullptr;
   board.board[0][3] = nullptr;
   board.board[1][0] = nullptr;
   board.board[3][0] = nullptr;
   board.board[7][6] = nullptr;
}


/*************************************
 * GET TYPE : bishop
 * Input:
 * Output: BISHOP
 **************************************/
void TestBishop::getType()
{
   // SETUP
   Bishop bishop(7, 7, true /*white*/);
   PieceType pt = SPACE;

   // EXERCISE
   pt = bishop.getType();

   // VERIFY
   assertUnit(pt == BISHOP);

   // TEARDOWN
}
