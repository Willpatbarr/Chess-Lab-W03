/***********************************************************************
 * Source File:
 *    TEST ROOK
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the rook
 ************************************************************************/

#include "testRook.h"
#include "pieceRook.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      

#include <iostream>
using namespace std;

 /*************************************
  * +---a-b-c-d-e-f-g-h---+
  * |                     |
  * 8                     8
  * 7                     7
  * 6                     6
  * 5                     5
  * 4                     4
  * 3       p             3
  * 2     p(r)p           2
  * 1       p             1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestRook::getMoves_blocked()
{
   // SETUP
   BoardEmpty board;

   Rook rook(7, 7, false /*white*/); // we will reset all this.
   rook.fWhite = true;
   rook.position.colRow = 0x21;
   board.board[2][1] = &rook;

   White w1(PAWN);
   board.board[2][2] = &w1;  

   White w2(PAWN);
   board.board[3][1] = &w2;

   White w3(PAWN);
   board.board[2][0] = &w3;

   White w4(PAWN);
   board.board[1][1] = &w4;

   set <Move> moves;


   // EXERCISE
   rook.getMoves(moves, board);

   // VERIFY

   assertUnit(moves.size() == 0);


   // TEARDOWN
   board.board[2][1] = nullptr;  // rook
   board.board[2][2] = nullptr;
   board.board[3][1] = nullptr;
   board.board[2][0] = nullptr;
   board.board[1][1] = nullptr;
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       .             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   . .(r). . . . .   2
 * 1       .             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToEnd()
{
   // SETUP
   BoardEmpty board;

   Rook rook(7, 7, false /*white*/); // we will reset all this.
   rook.fWhite = true;
   rook.position.colRow = 0x21;
   board.board[2][1] = &rook;

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

   c2a2.source.colRow = c2b2.source.colRow = c2d2.source.colRow = 
   c2e2.source.colRow = c2f2.source.colRow = c2g2.source.colRow = 
   c2h2.source.colRow = c2c1.source.colRow = c2c3.source.colRow = 
   c2c4.source.colRow = c2c5.source.colRow = c2c6.source.colRow = 
   c2c7.source.colRow = c2c8.source.colRow = 0x21;

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


   // EXERCISE
   rook.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 14);

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

   // TEARDOWN
   board.board[2][1] = nullptr;  // rook
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       p             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   p .(r). . . . p   2
 * 1       p             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToBlock()
{
   // SETUP
   BoardEmpty board;

   Rook rook(7, 7, false /*white*/); // we will reset all this.
   rook.fWhite = true;
   rook.position.colRow = 0x21;
   board.board[2][1] = &rook;

   White w1(PAWN);
   board.board[2][7] = &w1;

   White w2(PAWN);
   board.board[7][1] = &w2;

   White w3(PAWN);
   board.board[2][0] = &w3;

   White w4(PAWN);
   board.board[0][1] = &w4;

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

   c2b2.capture = c2d2.capture = c2e2.capture = 
   c2f2.capture = c2g2.capture = c2c3.capture = 
   c2c4.capture = c2c5.capture = c2c6.capture = 
   c2c7.capture = SPACE;

   c2b2.source.colRow = c2d2.source.colRow = c2e2.source.colRow = 
   c2f2.source.colRow = c2g2.source.colRow = c2c3.source.colRow = 
   c2c4.source.colRow = c2c5.source.colRow = c2c6.source.colRow = 
   c2c7.source.colRow = 0x21;

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


   // EXERCISE
   rook.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 10);


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

   // TEARDOWN
   board.board[2][1] = nullptr;  // rook
   board.board[0][1] = nullptr;
   board.board[7][1] = nullptr;
   board.board[2][0] = nullptr;
   board.board[2][7] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       P             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   P .(r). . . . P   2
 * 1       P             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToCapture()
{
   // SETUP
   BoardEmpty board;

   Rook rook(7, 7, false /*white*/); // we will reset all this.
   rook.fWhite = true;
   rook.position.colRow = 0x21;
   board.board[2][1] = &rook;

   Black w1(PAWN);
   board.board[2][7] = &w1;

   Black w2(PAWN);
   board.board[7][1] = &w2;

   Black w3(PAWN);
   board.board[2][0] = &w3;

   Black w4(PAWN);
   board.board[0][1] = &w4;

   set <Move> moves;

   Move c2a2p;
   Move c2b2;
   Move c2d2;
   Move c2e2;
   Move c2f2;
   Move c2g2;
   Move c2h2p;

   Move c2c1p;
   Move c2c3;
   Move c2c4;
   Move c2c5;
   Move c2c6;
   Move c2c7;
   Move c2c8p;

   c2a2p.capture = c2h2p.capture = c2c1p.capture = c2c8p.capture = PAWN;

    c2b2.capture = c2d2.capture = c2e2.capture = 
    c2f2.capture = c2g2.capture = c2c3.capture =
    c2c4.capture = c2c5.capture = c2c6.capture =
    c2c7.capture = SPACE;

   c2a2p.source.colRow =  c2b2.source.colRow = c2d2.source.colRow =
    c2e2.source.colRow =  c2f2.source.colRow = c2g2.source.colRow =
   c2h2p.source.colRow = c2c1p.source.colRow = c2c3.source.colRow =
    c2c4.source.colRow =  c2c5.source.colRow = c2c6.source.colRow =
    c2c7.source.colRow = c2c8p.source.colRow = 0x21;

   c2a2p.dest.colRow = 0x01;
   c2b2.dest.colRow  = 0x11;
   c2d2.dest.colRow  = 0x31;
   c2e2.dest.colRow  = 0x41;
   c2f2.dest.colRow  = 0x51;
   c2g2.dest.colRow  = 0x61;
   c2h2p.dest.colRow = 0x71;
   c2c1p.dest.colRow = 0x20;
   c2c3.dest.colRow  = 0x22;
   c2c4.dest.colRow  = 0x23;
   c2c5.dest.colRow  = 0x24;
   c2c6.dest.colRow  = 0x25;
   c2c7.dest.colRow  = 0x26;
   c2c8p.dest.colRow = 0x27;


   // EXERCISE
   rook.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 14);

   assertUnit(moves.find(c2a2p) != moves.end());
   assertUnit(moves.find(c2b2)  != moves.end());
   assertUnit(moves.find(c2d2)  != moves.end());
   assertUnit(moves.find(c2e2)  != moves.end());
   assertUnit(moves.find(c2f2)  != moves.end());
   assertUnit(moves.find(c2g2)  != moves.end());
   assertUnit(moves.find(c2h2p) != moves.end());

   assertUnit(moves.find(c2c1p) != moves.end());
   assertUnit(moves.find(c2c3)  != moves.end());
   assertUnit(moves.find(c2c4)  != moves.end());
   assertUnit(moves.find(c2c5)  != moves.end());
   assertUnit(moves.find(c2c6)  != moves.end());
   assertUnit(moves.find(c2c7)  != moves.end());
   assertUnit(moves.find(c2c8p) != moves.end());

   // TEARDOWN
   board.board[2][1] = nullptr;  // rook
   board.board[0][1] = nullptr;
   board.board[7][1] = nullptr;
   board.board[2][0] = nullptr;
   board.board[2][7] = nullptr;
}


/*************************************
 * GET TYPE : rook
 * Input:
 * Output: ROOK
 **************************************/
void TestRook::getType()
{
   // SETUP  
   Rook rook(7, 7, false /*white*/); // we will reset all this.
   PieceType pt = SPACE;

   // EXERCISE
   pt = rook.getType();

   // VERIFY
   assertUnit(pt == ROOK);
}  // TEARDOWN
