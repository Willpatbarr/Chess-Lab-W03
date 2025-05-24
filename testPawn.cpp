/***********************************************************************
 * Source File:
 *    TEST PAWN
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the pawn
 ************************************************************************/

#include "testPawn.h"
#include "piecePawn.h"
#include "pieceRook.h"
#include "board.h"
#include "uiDraw.h"
#include <cassert>      

 /*************************************
  * GET MOVES TEST Simple
  * White pawn in the middle of the board move forward one space: b4 --> b5
  *
  * +---a-b-c-d-e-f-g-h---+
  * |                     |
  * 8                     8
  * 7                     7
  * 6                     6
  * 5     .               5
  * 4    (p)              4
  * 3                     3
  * 2                     2
  * 1                     1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestPawn::getMoves_simpleWhite()
{
   // SETUP
   BoardEmpty board;
   
   Pawn pawn(7, 7, false /*white*/); // we will reset all this.
   pawn.fWhite = true;
   pawn.position.colRow = 0x13;
   board.board[1][3] = &pawn;
   
   set <Move> moves;
   
   Move b5b6p;
   b5b6p.source.colRow = 0x13;
   b5b6p.dest.colRow = 0x14;
   b5b6p.capture = SPACE;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 1);  // many possible moves
   assertUnit(moves.find(b5b6p) != moves.end());
   
   // TEARDOWN
   board.board[1][4] = nullptr; // white pawn
}

/*************************************
 * GET MOVES TEST Simple
 * Black pawn in the middle of the board move forward one space: b4 --> b3
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4    (P)              4
 * 3     .               3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_simpleBlack()
{
   // SETUP
   BoardEmpty board;
   
   Pawn pawn(7, 7, false /*white*/); // we will reset all this.
   pawn.fWhite = false;
   pawn.position.colRow = 0x13;
   board.board[1][3] = &pawn;
   
   set <Move> moves;
   
   Move b4b3p;
   b4b3p.source.colRow = 0x13;
   b4b3p.dest.colRow = 0x12;
   b4b3p.capture = SPACE;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 1);  // many possible moves
   assertUnit(moves.find(b4b3p) != moves.end());
   
   // TEARDOWN
   board.board[1][3] = nullptr; // black pawn
}

/*************************************
 * GET MOVES TEST InitialAdvance
 * White pawn initial advance: b2 --> b4 as well as b2 --> b3
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 7                     8
 * 6                     7
 * 5                     6
 * 4                     5
 * 3     .               4
 * 2     .               3
 * 1    (p)              2
 * 0                     1
 * |                     |
 * +---0-1-2-3-4-5-6-7---+
 **************************************/
void TestPawn::getMoves_initialAdvanceWhite()
{
   // SETUP
   BoardEmpty board;
   
   Pawn pawn(7, 7, false /*white*/); // we will reset all this.
   pawn.fWhite = true;
   pawn.position.colRow = 0x11;
   board.board[1][1] = &pawn;
   
   set <Move> moves;
   
   Move b2b3p;
   b2b3p.source.colRow = 0x11;
   b2b3p.dest.colRow = 0x12;
   b2b3p.capture = SPACE;
   
   Move b2b4p;
   b2b4p.source.colRow = 0x11;
   b2b4p.dest.colRow = 0x13;
   b2b4p.capture = SPACE;
   
   // EXERCISE
   pawn.getMoves(moves, board);
   
   // VERIFY
   assertUnit(moves.size() == 2);  // many possible moves
   assertUnit(moves.find(b2b3p) != moves.end());
   assertUnit(moves.find(b2b4p) != moves.end());
   
   // TEARDOWN
   board.board[1][1] = nullptr; // white pawn
}

/*************************************
 * GET MOVES TEST InitialAdvance
 * Black pawn initial advance: c7 --> c6 as well as c7 --> c5
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 7                     8
 * 6      (P)            7
 * 5       .             6
 * 4       .             5
 * 3                     4
 * 2                     3
 * 1                     2
 * 0                     1
 * |                     |
 * +---0-1-2-3-4-5-6-7---+
 **************************************/
void TestPawn::getMoves_initialAdvanceBlack()
{
   // SETUP
   BoardEmpty board;
   
   Pawn pawn(7, 7, false /*white*/); // we will reset all this.
   pawn.fWhite = false; // pawn is black
   pawn.position.colRow = 0x26;
   board.board[2][6] = &pawn;
   
   set <Move> moves;
   
   Move c7c6p;
   c7c6p.source.colRow = 0x26;
   c7c6p.dest.colRow = 0x25;
   c7c6p.capture = SPACE;
   
   Move c7c5p;
   c7c5p.source.colRow = 0x26;
   c7c5p.dest.colRow = 0x24;
   c7c5p.capture = SPACE;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2);  // many possible moves
   assertUnit(moves.find(c7c6p) != moves.end());
   assertUnit(moves.find(c7c5p) != moves.end());
   
   // TEARDOWN
   board.board[2][6] = nullptr; // black pawn
}


/*************************************
 * GET MOVES TEST Capture
 * Double capture: move white pawn b6 and capture two: a7 and c7. b7 is blocked
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 7                     8
 * 6   P P P             7
 * 5    (p)              6
 * 4                     5
 * 3                     4
 * 2                     3
 * 1                     2
 * 0                     1
 * |                     |
 * +---0-1-2-3-4-5-6-7---+
 **************************************/
void TestPawn::getMoves_captureWhite()
{
   // SETUP
   BoardEmpty board;
   
   //subject piece
   Pawn pawn(7, 7, false /*white*/); // we will reset all this.
   pawn.fWhite = true;
   pawn.position.colRow = 0x15;
   board.board[1][5] = &pawn;
   
   //accompanying pieces
   Pawn bPawn1(7, 7, false /*white*/); // we will reset all this.
   bPawn1.fWhite = false;
   bPawn1.position.colRow = 0x06;
   board.board[0][6] = &bPawn1;
   
   Pawn bPawn2(7, 7, false /*white*/); // we will reset all this.
   bPawn2.fWhite = false;
   bPawn2.position.colRow = 0x16;
   board.board[1][6] = &bPawn2;
   
   Pawn bPawn3(7, 7, false /*white*/); // we will reset all this.
   bPawn3.fWhite = false;
   bPawn3.position.colRow = 0x26;
   board.board[2][6] = &bPawn3;
   
   set <Move> moves;
   
   Move b6a7p;
   b6a7p.source.colRow = 0x15;
   b6a7p.dest.colRow = 0x06;
   b6a7p.capture = PAWN;
   
   Move b6c7p;
   b6c7p.source.colRow = 0x15;
   b6c7p.dest.colRow = 0x26;
   b6c7p.capture = PAWN;
   
   // EXERCISE
   pawn.getMoves(moves, board);
   
   // VERIFY
   assertUnit(moves.size() == 2);  // many possible moves
   assertUnit(moves.find(b6a7p) != moves.end());
   assertUnit(moves.find(b6c7p) != moves.end());
   
   // TEARDOWN
   board.board[1][5] = nullptr; // white pawn
   board.board[0][6] = nullptr; // black pawn 1
   board.board[1][6] = nullptr; // black pawn 2
   board.board[2][6] = nullptr; // black pawn 3
}


/*************************************
 * GET MOVES TEST Capture
 * Double capture: move black pawn b6 and capture two: a5 and c5. b5 is blocked
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 7                     8
 * 6                     7
 * 5    (P)              6
 * 4   p p p             5
 * 3                     4
 * 2                     3
 * 1                     2
 * 0                     1
 * |                     |
 * +---0-1-2-3-4-5-6-7---+
 **************************************/
void TestPawn::getMoves_captureBlack()
{
   // SETUP
   BoardEmpty board;
   
   //subject piece
   Pawn pawn(7, 7, false /*white*/); // we will reset all this.
   pawn.fWhite = false;
   pawn.position.colRow = 0x15;
   board.board[1][5] = &pawn;
   
   //accompanying pieces
   Pawn wPawn1(7, 7, false /*white*/); // we will reset all this.
   wPawn1.fWhite = true;
   wPawn1.position.colRow = 0x06;
   board.board[0][4] = &wPawn1;
   
   Pawn wPawn2(7, 7, false /*white*/); // we will reset all this.
   wPawn2.fWhite = true;
   wPawn2.position.colRow = 0x16;
   board.board[1][4] = &wPawn2;
   
   Pawn wPawn3(7, 7, false /*white*/); // we will reset all this.
   wPawn3.fWhite = true;
   wPawn3.position.colRow = 0x26;
   board.board[2][4] = &wPawn3;
   
   set <Move> moves;
   
   Move b6a5p;
   b6a5p.source.colRow = 0x15;
   b6a5p.dest.colRow = 0x04;
   b6a5p.capture = PAWN;
   
   Move b6c5p;
   b6c5p.source.colRow = 0x15;
   b6c5p.dest.colRow = 0x24;
   b6c5p.capture = PAWN;
   
   // EXERCISE
   pawn.getMoves(moves, board);
   
   // VERIFY
   assertUnit(moves.size() == 2);  // many possible moves
   assertUnit(moves.find(b6a5p) != moves.end());
   assertUnit(moves.find(b6c5p) != moves.end());
   
   // TEARDOWN
   board.board[1][5] = nullptr; // black pawn
   board.board[0][4] = nullptr; // white pawn 1
   board.board[1][4] = nullptr; // white pawn 2
   board.board[2][4] = nullptr; // white pawn 3
}

/*************************************
 * GET MOVES TEST Enpassant
 * Enpassant: white b5 can capture a5 and c5. Note that b6 is blocked
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 7                     8
 * 6                     7
 * 5   . P .             6
 * 4   P(p)P             5
 * 3                     4
 * 2                     3
 * 1                     2
 * 0                     1
 * |                     |
 * +---0-1-2-3-4-5-6-7---+
 **************************************/
void TestPawn::getMoves_enpassantWhite()
{
   // SETUP
   BoardEmpty board;
   
      //subject piece
   Pawn pawn(7, 7, false /*white*/); // we will reset all this.
   pawn.fWhite = true;
   pawn.position.colRow = 0x14;
   board.board[1][4] = &pawn;
   
      //accompanying pieces
   Pawn bPawn1(7, 7, false /*white*/); // we will reset all this.
   bPawn1.fWhite = false;
   bPawn1.position.colRow = 0x04;
   board.board[0][4] = &bPawn1;
   
   Pawn bPawn2(7, 7, false /*white*/); // we will reset all this.
   bPawn2.fWhite = false;
   bPawn2.position.colRow = 0x15;
   board.board[1][5] = &bPawn2;
   
   Pawn bPawn3(7, 7, false /*white*/); // we will reset all this.
   bPawn3.fWhite = false;
   bPawn3.position.colRow = 0x24;
   board.board[2][4] = &bPawn3;
   
   set <Move> moves;
   
   Move b5a6p;
   b5a6p.source.colRow = 0x14;
   b5a6p.dest.colRow = 0x05;
   b5a6p.capture = PAWN;
   
   Move b5c6p;
   b5c6p.source.colRow = 0x14;
   b5c6p.dest.colRow = 0x25;
   b5c6p.capture = PAWN;
   
   // EXERCISE
   pawn.getMoves(moves, board);
   
   // VERIFY
   assertUnit(moves.size() == 2);  // many possible moves
   assertUnit(moves.find(b5a6p) != moves.end());
   assertUnit(moves.find(b5c6p) != moves.end());
   
   
   // TEARDOWN
   board.board[1][4] = nullptr; // white pawn
   board.board[0][4] = nullptr; // black pawn 1
   board.board[1][5] = nullptr; // black pawn 2
   board.board[2][4] = nullptr; // black pawn 3
}


/*************************************
 * GET MOVES TEST Enpassant
 * Enpassant black f4 can capture e4 and g4. Note that f3 is blocked
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 7                     8
 * 6                     7
 * 5                     6
 * 4                     5
 * 3           p(P)p     4
 * 2           . p .     3
 * 1                     2
 * 0                     1
 * |                     |
 * +---0-1-2-3-4-5-6-7---+
 **************************************/
void TestPawn::getMoves_enpassantBlack()
{
   // SETUP
   BoardEmpty board;
   
   //subject piece
   Pawn pawn(7, 7, false /*white*/); // we will reset all this.
   pawn.fWhite = false;
   pawn.position.colRow = 0x53;
   board.board[5][3] = &pawn;
   
   //accompanying pieces
   Pawn wPawn1(7, 7, false /*white*/); // we will reset all this.
   wPawn1.fWhite = true;
   wPawn1.position.colRow = 0x43;
   board.board[4][3] = &wPawn1;
   
   Pawn wPawn2(7, 7, false /*white*/); // we will reset all this.
   wPawn2.fWhite = true;
   wPawn2.position.colRow = 0x52;
   board.board[5][2] = &wPawn2;
   
   Pawn wPawn3(7, 7, false /*white*/); // we will reset all this.
   wPawn3.fWhite = true;
   wPawn3.position.colRow = 0x63;
   board.board[6][3] = &wPawn3;
   
   set <Move> moves;
   
   Move f5e4p;
   f5e4p.source.colRow = 0x15;
   f5e4p.dest.colRow = 0x04;
   f5e4p.capture = PAWN;
   
   Move f5g4p;
   f5g4p.source.colRow = 0x15;
   f5g4p.dest.colRow = 0x24;
   f5g4p.capture = PAWN;
   
   // EXERCISE
   pawn.getMoves(moves, board);
   
   // VERIFY
   assertUnit(moves.size() == 2);  // many possible moves
   assertUnit(moves.find(f5e4p) != moves.end());
   assertUnit(moves.find(f5g4p) != moves.end());
   
   // TEARDOWN
   board.board[5][3] = nullptr; // black pawn
   board.board[4][3] = nullptr; // white pawn 1
   board.board[5][2] = nullptr; // white pawn 2
   board.board[6][3] = nullptr; // white pawn 3
}

/*************************************
 * GET MOVES TEST Promotion
 * Promotion: white pawn b7 can capture two pawns: a8 and c8.
 *            It can also move into b8. All three are promoted to queen
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 7   P . P             8
 * 6    (p)              7
 * 5                     6
 * 4                     5
 * 3                     4
 * 2                     3
 * 1                     2
 * 0                     1
 * |                     |
 * +---0-1-2-3-4-5-6-7---+
 **************************************/
void TestPawn::getMoves_promotionWhite()
{
   // SETUP
   BoardEmpty board;
   
      //subject piece
   Pawn pawn(7, 7, false /*white*/); // we will reset all this.
   pawn.fWhite = true;
   pawn.position.colRow = 0x16;
   board.board[1][6] = &pawn;
   
      //accompanying pieces
   Pawn bPawn1(7, 7, false /*white*/); // we will reset all this.
   bPawn1.fWhite = false;
   bPawn1.position.colRow = 0x07;
   board.board[0][7] = &bPawn1;
   
   Pawn bPawn2(7, 7, false /*white*/); // we will reset all this.
   bPawn2.fWhite = false;
   bPawn2.position.colRow = 0x27;
   board.board[2][7] = &bPawn2;
   
   set <Move> moves;
   
   Move b7a8p;
   b7a8p.source.colRow = 0x16;
   b7a8p.dest.colRow = 0x07;
   b7a8p.capture = PAWN;
   
   Move b7b8p;
   b7b8p.source.colRow = 0x16;
   b7b8p.dest.colRow = 0x17;
   b7b8p.capture = SPACE;
   
   Move b7c8p;
   b7c8p.source.colRow = 0x16;
   b7c8p.dest.colRow = 0x27;
   b7c8p.capture = PAWN;
   
   // EXERCISE
   pawn.getMoves(moves, board);
   
   // VERIFY
   assertUnit(moves.size() == 3);  // many possible moves
   assertUnit(moves.find(b7a8p) != moves.end());
   assertUnit(moves.find(b7b8p) != moves.end());
   assertUnit(moves.find(b7c8p) != moves.end());
   
   // TEARDOWN
   board.board[1][6] = nullptr; // white queen
   board.board[0][7] = nullptr; // black pawn 1
   board.board[2][7] = nullptr; // black pawn 2
}


/*************************************
 * GET MOVES TEST Promotion
 * Promotion: black pawn e2 can capture two rooks: d1 and f1.
 *            It can also move into e1. All three are promoted to queen
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 7                     8
 * 6                     7
 * 5                     6
 * 4                     5
 * 3                     4
 * 2                     3
 * 1          (P)        2
 * 0         r . r       1
 * |                     |
 * +---0-1-2-3-4-5-6-7---+
 **************************************/
void TestPawn::getMoves_promotionBlack()
{
   // SETUP
   BoardEmpty board;
   
   //subject piece
   Pawn pawn(7, 7, false /*white*/); // we will reset all this.
   pawn.fWhite = false;
   pawn.position.colRow = 0x41;
   board.board[4][1] = &pawn;
   
   //accompanying pieces
   Rook wRook1(7, 7, false /*white*/); // we will reset all this.
   wRook1.fWhite = true;
   wRook1.position.colRow = 0x30;
   board.board[3][0] = &wRook1;
   
   Rook wRook2(7, 7, false /*white*/); // we will reset all this.
   wRook2.fWhite = true;
   wRook2.position.colRow = 0x50;
   board.board[5][0] = &wRook2;
   
   set <Move> moves;
   
   Move e2d1p;
   e2d1p.source.colRow = 0x41;
   e2d1p.dest.colRow = 0x30;
   e2d1p.capture = ROOK;
   
   Move e2e1p;
   e2e1p.source.colRow = 0x41;
   e2e1p.dest.colRow = 0x40;
   e2e1p.capture = SPACE;
   
   Move e2f1p;
   e2f1p.source.colRow = 0x41;
   e2f1p.dest.colRow = 0x50;
   e2f1p.capture = ROOK;
   
   // EXERCISE
   pawn.getMoves(moves, board);
   
   // VERIFY
   assertUnit(moves.size() == 3);  // many possible moves
   assertUnit(moves.find(e2d1p) != moves.end());
   assertUnit(moves.find(e2e1p) != moves.end());
   assertUnit(moves.find(e2f1p) != moves.end());
   
   // TEARDOWN
   board.board[4][1] = nullptr; // black pawn
   board.board[3][0] = nullptr; // white rook 1
   board.board[5][0] = nullptr; // white rook 2
}


/*************************************
 * GET TYPE : pawn
 * Input:
 * Output: PAWN
 **************************************/
void TestPawn::getType()
{
   // SETUP
   Pawn pawn(7, 7, false /*white*/); // we will reset all this.
   
   PieceType pType;
   
   // EXERCISE
   pType = pawn.getType();
   
   // VERIFY
   assertUnit(pType == PAWN);
}

