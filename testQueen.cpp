/***********************************************************************
 * Source File:
 *    TEST QUEEN
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the queen
 ************************************************************************/

#include "testQueen.h"
#include "pieceQueen.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      




 /*************************************
  * +---a-b-c-d-e-f-g-h---+
  * |                     |
  * 8                     8
  * 7                     7
  * 6                     6
  * 5                     5
  * 4                     4
  * 3     p p p           3
  * 2     p(q)p           2
  * 1     p p p           1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestQueen::getMoves_blocked()
{
   // SETUP
   BoardEmpty board;

   Queen queen(7, 7, false /*white*/); // we will reset all this.
   queen.fWhite = true;
   queen.position.colRow = 0x34;
   board.board[3][4] = &queen;

   White w1(PAWN);
   board.board[2][5] = &w1;  //uppercase is black, lowercase is white

   White w2(PAWN);
   board.board[3][5] = &w2;

   White w3(PAWN);
   board.board[4][5] = &w3;

   White w4(PAWN);
   board.board[4][4] = &w4;

   White w5(PAWN);
   board.board[4][3] = &w5;

   White w6(PAWN);
   board.board[3][3] = &w6;

   White w7(PAWN);
   board.board[2][3] = &w7;

   White w8(PAWN);
   board.board[2][4] = &w8;

   set <Move> moves;


   // EXERCISE

   queen.getMoves(moves, board);


   // VERIFY
   assertUnit(moves.size() == 0);


   // TEARDOWN
   board.board[3][4] = nullptr;  // queen
   board.board[2][5] = nullptr;
   board.board[3][5] = nullptr;
   board.board[4][5] = nullptr;
   board.board[4][4] = nullptr;
   board.board[4][3] = nullptr;
   board.board[3][3] = nullptr;
   board.board[2][3] = nullptr;
   board.board[2][4] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       .             8
 * 7       .         .   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   .   .   .         4
 * 3     . . .           3
 * 2   . .(q). . . . .   2
 * 1     . . .           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToEnd()
{
   // SETUP
   BoardEmpty board;

   Queen queen(7, 7, false /*white*/); // we will reset all this.
   queen.fWhite = true;
   queen.position.colRow = 0x21;
   board.board[2][1] = &queen;

   set <Move> moves;

   Move c2a2;
   Move c2b2;
   Move c2d2;
   Move c2e2;
   Move c2f2;
   Move c2g2;
   Move c2h2;
   Move c2c1;
   Move c2c3;
   Move c2c4;
   Move c2c5;
   Move c2c6;
   Move c2c7;
   Move c2c8;
   Move c2b1;
   Move c2a4;
   Move c2b3;
   Move c2d1;
   Move c2e4;
   Move c2f5;
   Move c2g6;
   Move c2h7;
   Move c2d3;


   c2a2.source.colRow = c2b2.source.colRow = c2d2.source.colRow =
   c2e2.source.colRow = c2f2.source.colRow = c2g2.source.colRow =
   c2h2.source.colRow = c2c1.source.colRow = c2c3.source.colRow =
   c2c4.source.colRow = c2c5.source.colRow = c2c6.source.colRow =
   c2c7.source.colRow = c2c8.source.colRow = c2b1.source.colRow =
   c2a4.source.colRow = c2b3.source.colRow = c2d1.source.colRow =
   c2e4.source.colRow = c2f5.source.colRow = c2g6.source.colRow =
   c2h7.source.colRow = c2d3.source.colRow = 0x21;

   c2a2.dest.colRow = 0x01;
   c2b2.dest.colRow = 0x11;
   c2d2.dest.colRow = 0x31;
   c2e2.dest.colRow = 0x41;
   c2f2.dest.colRow = 0x51;
   c2g2.dest.colRow = 0x61;
   c2h2.dest.colRow = 0x71;
   c2c1.dest.colRow = 0x20;
   c2c3.dest.colRow = 0x22;
   c2c4.dest.colRow = 0x23;
   c2c5.dest.colRow = 0x24;
   c2c6.dest.colRow = 0x25;
   c2c7.dest.colRow = 0x26;
   c2c8.dest.colRow = 0x27;
   c2b1.dest.colRow = 0x10;
   c2a4.dest.colRow = 0x03;
   c2b3.dest.colRow = 0x22;
   c2d1.dest.colRow = 0x30;
   c2e4.dest.colRow = 0x43;
   c2f5.dest.colRow = 0x54;
   c2g6.dest.colRow = 0x65;
   c2h7.dest.colRow = 0x76;
   c2d3.dest.colRow = 0x32;


   // EXERCISE
   queen.getMoves(moves, board);


   // VERIFY
   assertUnit(moves.size() == 23);
   assertUnit(moves.find(c2a2) != moves.end());
   assertUnit(moves.find(c2b2) != moves.end());
   assertUnit(moves.find(c2d2) != moves.end());
   assertUnit(moves.find(c2e2) != moves.end());
   assertUnit(moves.find(c2f2) != moves.end());
   assertUnit(moves.find(c2g2) != moves.end());
   assertUnit(moves.find(c2h2) != moves.end());
   assertUnit(moves.find(c2c1) != moves.end());
   assertUnit(moves.find(c2c3) != moves.end());
   assertUnit(moves.find(c2c4) != moves.end());
   assertUnit(moves.find(c2c5) != moves.end());
   assertUnit(moves.find(c2c6) != moves.end());
   assertUnit(moves.find(c2c7) != moves.end());
   assertUnit(moves.find(c2c8) != moves.end());
   assertUnit(moves.find(c2b1) != moves.end());
   assertUnit(moves.find(c2a4) != moves.end());
   assertUnit(moves.find(c2b3) != moves.end());
   assertUnit(moves.find(c2d1) != moves.end());
   assertUnit(moves.find(c2e4) != moves.end());
   assertUnit(moves.find(c2f5) != moves.end());
   assertUnit(moves.find(c2g6) != moves.end());
   assertUnit(moves.find(c2h7) != moves.end());
   assertUnit(moves.find(c2d3) != moves.end());

   // TEARDOWN
   board.board[2][1] = nullptr;  // queen
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       p             8
 * 7       .         p   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   p   .   .         4
 * 3     . . .           3
 * 2   p .(q). . . . p   2
 * 1     p p p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToBlock()
{
   // SETUP
   BoardEmpty board;

   Queen queen(7, 7, false /*white*/); // we will reset all this.
   queen.fWhite = true;
   queen.position.colRow = 0x21;
   board.board[2][1] = &queen;

   White w1(PAWN);
   board.board[2][7] = &w1;  //uppercase is black, lowercase is white

   White w2(PAWN);
   board.board[7][6] = &w2;

   White w3(PAWN);
   board.board[7][1] = &w3;

   White w4(PAWN);
   board.board[3][0] = &w4;

   White w5(PAWN);
   board.board[2][0] = &w5;

   White w6(PAWN);
   board.board[1][0] = &w6;

   White w7(PAWN);
   board.board[0][1] = &w7;

   White w8(PAWN);
   board.board[0][3] = &w8;


   set <Move> moves;

   Move c2b2;
   Move c2d2;
   Move c2e2;
   Move c2f2;
   Move c2g2;
   Move c2c3;
   Move c2c4;
   Move c2c5;
   Move c2c6;
   Move c2c7;
   Move c2b3;
   Move c2e4;
   Move c2f5;
   Move c2g6;
   Move c2d3;


   c2b2.source.colRow = c2d2.source.colRow = c2e2.source.colRow = 
   c2f2.source.colRow = c2g2.source.colRow = c2c3.source.colRow =
   c2c4.source.colRow = c2c5.source.colRow = c2c6.source.colRow =
   c2c7.source.colRow = c2b3.source.colRow = c2e4.source.colRow = 
   c2f5.source.colRow = c2g6.source.colRow = c2d3.source.colRow = 0x21;

   c2b2.dest.colRow = 0x11;
   c2d2.dest.colRow = 0x31;
   c2e2.dest.colRow = 0x41;
   c2f2.dest.colRow = 0x51;
   c2g2.dest.colRow = 0x61;
   c2c3.dest.colRow = 0x22;
   c2c4.dest.colRow = 0x23;
   c2c5.dest.colRow = 0x24;
   c2c6.dest.colRow = 0x25;
   c2c7.dest.colRow = 0x26;
   c2b3.dest.colRow = 0x22;
   c2e4.dest.colRow = 0x43;
   c2f5.dest.colRow = 0x54;
   c2g6.dest.colRow = 0x65;
   c2d3.dest.colRow = 0x32;


   // EXERCISE
   queen.getMoves(moves, board);


   // VERIFY
   assertUnit(moves.size() == 15);
   assertUnit(moves.find(c2b2) != moves.end());
   assertUnit(moves.find(c2d2) != moves.end());
   assertUnit(moves.find(c2e2) != moves.end());
   assertUnit(moves.find(c2f2) != moves.end());
   assertUnit(moves.find(c2g2) != moves.end());
   assertUnit(moves.find(c2c3) != moves.end());
   assertUnit(moves.find(c2c4) != moves.end());
   assertUnit(moves.find(c2c5) != moves.end());
   assertUnit(moves.find(c2c6) != moves.end());
   assertUnit(moves.find(c2c7) != moves.end());
   assertUnit(moves.find(c2b3) != moves.end());
   assertUnit(moves.find(c2e4) != moves.end());
   assertUnit(moves.find(c2f5) != moves.end());
   assertUnit(moves.find(c2g6) != moves.end());
   assertUnit(moves.find(c2d3) != moves.end());

   // TEARDOWN
   board.board[2][1] = nullptr;  // queen
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       P             8
 * 7       .         P   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   P   .   .         4
 * 3     . . .           3
 * 2   P .(q). . . . P   2
 * 1     P P P           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToCapture()
{
{
   // SETUP
   BoardEmpty board;

   Queen queen(7, 7, true /*white*/); // we will reset all this.
   queen.fWhite = false;
   queen.position.colRow = 0x21;
   board.board[2][1] = &queen;

   White w1(PAWN);
   board.board[2][7] = &w1;  //uppercase is black, lowercase is white


   White w2(PAWN);
   board.board[7][6] = &w2;

   White w3(PAWN);
   board.board[7][1] = &w3;

   White w4(PAWN);
   board.board[3][0] = &w4;

   White w5(PAWN);
   board.board[2][0] = &w5;

   White w6(PAWN);
   board.board[1][0] = &w6;

   White w7(PAWN);
   board.board[0][1] = &w7;

   White w8(PAWN);
   board.board[0][3] = &w8;



   set <Move> moves;

   Move c2b2;
   Move c2d2;
   Move c2e2;
   Move c2f2;
   Move c2g2;
   Move c2c3;
   Move c2c4;
   Move c2c5;
   Move c2c6;
   Move c2c7;
   Move c2b3;
   Move c2e4;
   Move c2f5;
   Move c2g6;
   Move c2d3;
   Move c2a2P;
   Move c2h2P;
   Move c2c1P;
   Move c2c8P;
   Move c2b1P;
   Move c2a4P;
   Move c2d1P;
   Move c2h7P;

   c2a2P.capture = c2h2P.capture = c2c1P.capture =
   c2c8P.capture = c2b1P.capture = c2a4P.capture =
   c2d1P.capture = c2h7P.capture = PAWN;

   c2a2P.source.colRow = c2b2.source.colRow = c2d2.source.colRow =
   c2e2.source.colRow = c2f2.source.colRow = c2g2.source.colRow =
   c2h2P.source.colRow = c2c1P.source.colRow = c2c3.source.colRow =
   c2c4.source.colRow = c2c5.source.colRow = c2c6.source.colRow =
   c2c7.source.colRow = c2c8P.source.colRow = c2b1P.source.colRow =
   c2a4P.source.colRow = c2b3.source.colRow = c2d1P.source.colRow =
   c2e4.source.colRow = c2f5.source.colRow = c2g6.source.colRow =
   c2h7P.source.colRow = c2d3.source.colRow = 0x21;

   c2a2P.dest.colRow = 0x01;
   c2b2.dest.colRow = 0x11;
   c2d2.dest.colRow = 0x31;
   c2e2.dest.colRow = 0x41;
   c2f2.dest.colRow = 0x51;
   c2g2.dest.colRow = 0x61;
   c2h2P.dest.colRow = 0x71;
   c2c1P.dest.colRow = 0x20;
   c2c3.dest.colRow = 0x22;
   c2c4.dest.colRow = 0x23;
   c2c5.dest.colRow = 0x24;
   c2c6.dest.colRow = 0x25;
   c2c7.dest.colRow = 0x26;
   c2c8P.dest.colRow = 0x27;
   c2b1P.dest.colRow = 0x10;
   c2a4P.dest.colRow = 0x03;
   c2b3.dest.colRow = 0x22;
   c2d1P.dest.colRow = 0x30;
   c2e4.dest.colRow = 0x43;
   c2f5.dest.colRow = 0x54;
   c2g6.dest.colRow = 0x65;
   c2h7P.dest.colRow = 0x76;
   c2d3.dest.colRow = 0x32;


   // EXERCISE
   queen.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 23);
   assertUnit(moves.find(c2a2P) != moves.end());
   assertUnit(moves.find(c2b2) != moves.end());
   assertUnit(moves.find(c2d2) != moves.end());
   assertUnit(moves.find(c2e2) != moves.end());
   assertUnit(moves.find(c2f2) != moves.end());
   assertUnit(moves.find(c2g2) != moves.end());
   assertUnit(moves.find(c2h2P) != moves.end());
   assertUnit(moves.find(c2c1P) != moves.end());
   assertUnit(moves.find(c2c3) != moves.end());
   assertUnit(moves.find(c2c4) != moves.end());
   assertUnit(moves.find(c2c5) != moves.end());
   assertUnit(moves.find(c2c6) != moves.end());
   assertUnit(moves.find(c2c7) != moves.end());
   assertUnit(moves.find(c2c8P) != moves.end());
   assertUnit(moves.find(c2b1P) != moves.end());
   assertUnit(moves.find(c2a4P) != moves.end());
   assertUnit(moves.find(c2b3) != moves.end());
   assertUnit(moves.find(c2d1P) != moves.end());
   assertUnit(moves.find(c2e4) != moves.end());
   assertUnit(moves.find(c2f5) != moves.end());
   assertUnit(moves.find(c2g6) != moves.end());
   assertUnit(moves.find(c2h7P) != moves.end());
   assertUnit(moves.find(c2d3) != moves.end());

   // TEARDOWN
   board.board[2][1] = nullptr;  // queen
   board.board[7][6] = nullptr;
   board.board[7][1] = nullptr;
   board.board[3][0] = nullptr;
   board.board[2][0] = nullptr;
   board.board[1][0] = nullptr;
   board.board[0][1] = nullptr;
   board.board[0][3] = nullptr;
}}


/*************************************
 * GET TYPE : queen
 * Input:
 * Output: QUEEN
 **************************************/
void TestQueen::getType()
{
   // SETUP  
   Queen queen(7, 7, false /*white*/); // we will reset all this.
   PieceType pt = SPACE;

   // EXERCISE
   pt = queen.getType();

   // VERIFY
   assertUnit(pt == QUEEN);
}  // TEARDOWN
