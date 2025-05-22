/***********************************************************************
 * Source File:
 *    TEST KING
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the King
 ************************************************************************/

#include "testKing.h"
#include "pieceRook.h"
#include "pieceKing.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      


 /*************************************
  * +---a-b-c-d-e-f-g-h---+
  * |                     |
  * 8                     8
  * 7                     7
  * 6       p p p         6
  * 5       p(k)p         5
  * 4       p p p         4
  * 3                     3
  * 2                     2
  * 1                     1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestKing::getMoves_blocked()
{
   // SETUP
   BoardEmpty board;

   King king(7, 7, false /*white*/); // we will reset all this.
   king.fWhite = true;
   king.position.colRow = 0x34;
   board.board[3][6] = &king;

   White w1(PAWN);
   board.board[2][7] = &w1;  //uppercase is black, lowercase is white

   White w2(PAWN);
   board.board[3][7] = &w2;

   White w3(PAWN);
   board.board[4][7] = &w3;

   White w4(PAWN);
   board.board[4][6] = &w4;

   White w5(PAWN);
   board.board[4][5] = &w5;

   White w6(PAWN);
   board.board[3][5] = &w6;

   White w7(PAWN);
   board.board[2][5] = &w7;

   White w8(PAWN);
   board.board[2][6] = &w8;

   set <Move> moves;


   // EXERCISE

   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 0);

   // TEARDOWN
   board.board[3][6] = nullptr;  // knight
   board.board[2][7] = nullptr;
   board.board[3][7] = nullptr;
   board.board[4][7] = nullptr;
   board.board[4][6] = nullptr;
   board.board[4][5] = nullptr;
   board.board[3][5] = nullptr;
   board.board[2][5] = nullptr;
   board.board[2][6] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       P P P         6
 * 5       P(k)P         5
 * 4       P P P         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_capture()
{
   // SETUP
   BoardEmpty board;

   King king(7, 7, false /*white*/); // we will reset all this.
   king.fWhite = false;
   king.position.colRow = 0x34;
   board.board[3][4] = &king;

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

   Move d5c6p;
   d5c6p.source.colRow = 0x34;
   d5c6p.dest.colRow = 0x25;
   d5c6p.capture = PAWN;

   Move d5d6p;
   d5d6p.source.colRow = 0x34;
   d5d6p.dest.colRow = 0x35;
   d5d6p.capture = PAWN;

   Move d5e6p;
   d5e6p.source.colRow = 0x34;
   d5e6p.dest.colRow = 0x45;
   d5e6p.capture = PAWN;

   Move d5e5p;
   d5e5p.source.colRow = 0x34;
   d5e5p.dest.colRow = 0x44;
   d5e5p.capture = PAWN;

   Move d5e4p;
   d5e4p.source.colRow = 0x34;
   d5e4p.dest.colRow = 0x43;
   d5e4p.capture = PAWN;

   Move d5d4p;
   d5d4p.source.colRow = 0x34;
   d5d4p.dest.colRow = 0x33;
   d5d4p.capture = PAWN;

   Move d5c4p;
   d5c4p.source.colRow = 0x34;
   d5c4p.dest.colRow = 0x23;
   d5c4p.capture = PAWN;

   Move d5c5p;
   d5c5p.source.colRow = 0x34;
   d5c5p.dest.colRow = 0x24;
   d5c5p.capture = PAWN;

   // EXERCISE

   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 8);
   assertUnit(moves.find(d5c6p) != moves.end());
   assertUnit(moves.find(d5d6p) != moves.end());
   assertUnit(moves.find(d5e6p) != moves.end());
   assertUnit(moves.find(d5e5p) != moves.end());
   assertUnit(moves.find(d5e4p) != moves.end());
   assertUnit(moves.find(d5d4p) != moves.end());
   assertUnit(moves.find(d5c4p) != moves.end());
   assertUnit(moves.find(d5c5p) != moves.end());


   // TEARDOWN
   board.board[3][4] = nullptr;  // king
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
 * 8                     8
 * 7                     7
 * 6       . . .         6
 * 5       .(k).         5
 * 4       . . .         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_free()
{
   // SETUP
   BoardEmpty board;

   King king(7, 7, false /*white*/); // we will reset all this.
   king.fWhite = false;
   king.position.colRow = 0x34;
   board.board[3][4] = &king;

   set <Move> moves;

   Move d5c6;
   d5c6.source.colRow = 0x34;
   d5c6.dest.colRow = 0x25;
   d5c6.capture = SPACE;

   Move d5d6;
   d5d6.source.colRow = 0x34;
   d5d6.dest.colRow = 0x35;
   d5d6.capture = SPACE;

   Move d5e6;
   d5e6.source.colRow = 0x34;
   d5e6.dest.colRow = 0x45;
   d5e6.capture = SPACE;

   Move d5e5;
   d5e5.source.colRow = 0x34;
   d5e5.dest.colRow = 0x44;
   d5e5.capture = SPACE;

   Move d5e4;
   d5e4.source.colRow = 0x34;
   d5e4.dest.colRow = 0x43;
   d5e4.capture = SPACE;

   Move d5d4;
   d5d4.source.colRow = 0x34;
   d5d4.dest.colRow = 0x33;
   d5d4.capture = SPACE;

   Move d5c4;
   d5c4.source.colRow = 0x34;
   d5c4.dest.colRow = 0x23;
   d5c4.capture = SPACE;

   Move d5c5;
   d5c5.source.colRow = 0x34;
   d5c5.dest.colRow = 0x24;
   d5c5.capture = SPACE;

   // EXERCISE

   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 8);
   assertUnit(moves.find(d5c6) != moves.end());
   assertUnit(moves.find(d5d6) != moves.end());
   assertUnit(moves.find(d5e6) != moves.end());
   assertUnit(moves.find(d5e5) != moves.end());
   assertUnit(moves.find(d5e4) != moves.end());
   assertUnit(moves.find(d5d4) != moves.end());
   assertUnit(moves.find(d5c4) != moves.end());
   assertUnit(moves.find(d5c5) != moves.end());


   // TEARDOWN
   board.board[3][4] = nullptr;  // king
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
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2   . .               2
 * 1  (k).               1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_end()
{
   // SETUP
   BoardEmpty board;

   King king(7, 7, false /*white*/); // we will reset all this.
   king.fWhite = false;
   king.position.colRow = 0x00;
   board.board[0][0] = &king;

   White w1(PAWN);
   board.board[0][1] = &w1;  //uppercase is black, lowercase is white

   White w2(PAWN);
   board.board[1][1] = &w2;

   White w3(PAWN);
   board.board[0][1] = &w3;


   set <Move> moves;

   Move a1a2;
   Move a1b2;
   Move a1b1;

   a1a2.source.colRow = a1b2.source.colRow = a1b1.source.colRow = 0x00;
   a1a2.capture = a1b2.capture = a1b1.capture = SPACE;

   a1a2.dest.colRow = 0x01;
   a1b2.dest.colRow = 0x11;
   a1b1.dest.colRow = 0x10;


   // EXERCISE

   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 3);
   assertUnit(moves.find(a1a2) != moves.end());
   assertUnit(moves.find(a1b2) != moves.end());
   assertUnit(moves.find(a1b1) != moves.end());

   // TEARDOWN
   board.board[0][0] = nullptr;  // king
   board.board[0][1] = nullptr;
   board.board[1][1] = nullptr;
   board.board[0][1] = nullptr;
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r   . .(k). . r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastle()
{
   // SETUP
   BoardEmpty board;

   King king(7, 7, false /*white*/); // we will reset all this.
   king.nMoves =-1; 
   king.fWhite = true;
   king.nMoves = 0;
   king.position.colRow = 0x40;
   board.board[4][0] = &king;

   White w1(PAWN);
   board.board[3][1] = &w1;  //uppercase is black, lowercase is white

   White w2(PAWN);
   board.board[4][1] = &w2;

   White w3(PAWN);
   board.board[5][1] = &w3;

   White rookQueen(ROOK);
   board.board[0][0] = &rookQueen;
   rookQueen.nMoves = 0;

   White rookKing(ROOK);
   board.board[7][0] = &rookKing;
   rookKing.nMoves = 0;


   set <Move> moves;

   Move e1c1C;
   Move e1d1C;
   Move e1f1c;
   Move e1g1c;

   e1c1C.source.colRow = e1d1C.source.colRow = e1f1c.source.colRow = e1g1c.source.colRow = 0x40;
   e1c1C.capture = e1d1C.capture = e1f1c.capture = e1g1c.capture = SPACE;

   e1c1C.dest.colRow = 0x20;
   e1d1C.dest.colRow = 0x30;
   e1f1c.dest.colRow = 0x50;
   e1g1c.dest.colRow = 0x60;


   // EXERCISE

   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 4);
   assertUnit(moves.find(e1c1C) != moves.end());
   assertUnit(moves.find(e1d1C) != moves.end());
   assertUnit(moves.find(e1f1c) != moves.end());
   assertUnit(moves.find(e1g1c) != moves.end());


   // TEARDOWN
   board.board[4][0] = nullptr;  // king
   board.board[3][1] = nullptr;
   board.board[4][1] = nullptr;
   board.board[5][1] = nullptr;
   board.board[0][0] = nullptr; //rook queen side
   board.board[7][0] = nullptr; //rook king side
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8   R   . .(K). . R   8
 * 7         P P P       7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_blackCastle()
{
   // SETUP
   BoardEmpty board;

   King king(7, 7, false /*white*/); // we will reset all this.
   king.nMoves = -1;
   king.fWhite = true;
   king.nMoves = 0;
   king.position.colRow = 0x47;
   board.board[4][7] = &king;

   White w1(PAWN);
   board.board[3][6] = &w1;  //uppercase is black, lowercase is white

   White w2(PAWN);
   board.board[4][6] = &w2;

   White w3(PAWN);
   board.board[5][6] = &w3;

   White rookQueen(ROOK);
   board.board[0][7] = &rookQueen;
   rookQueen.nMoves = 0;

   White rookKing(ROOK);
   board.board[7][7] = &rookKing;
   rookKing.nMoves = 0;


   set <Move> moves;

   Move e8c8C;
   Move e8d8C;
   Move e8f8c;
   Move e8g8c;

   e8c8C.source.colRow = e8d8C.source.colRow = e8f8c.source.colRow = e8g8c.source.colRow = 0x47;
   e8c8C.capture = e8d8C.capture = e8f8c.capture = e8g8c.capture = SPACE;

   e8c8C.dest.colRow = 0x27;
   e8d8C.dest.colRow = 0x37;
   e8f8c.dest.colRow = 0x57;
   e8g8c.dest.colRow = 0x67;


   // EXERCISE

   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 4);
   assertUnit(moves.find(e8c8C) != moves.end());
   assertUnit(moves.find(e8d8C) != moves.end());
   assertUnit(moves.find(e8f8c) != moves.end());
   assertUnit(moves.find(e8g8c) != moves.end());


   // TEARDOWN
   board.board[4][7] = nullptr;  // king
   board.board[3][6] = nullptr;
   board.board[4][6] = nullptr;
   board.board[5][6] = nullptr;
   board.board[0][7] = nullptr; //rook queen side
   board.board[7][7] = nullptr; //rook king side
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r     .(k).   r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastleKingMoved()
{
   // SETUP
   BoardEmpty board;

   King king(7, 7, false /*white*/); // we will reset all this.
   king.nMoves = -1;
   king.fWhite = true;
   king.nMoves = 1;
   king.position.colRow = 0x40;
   board.board[4][0] = &king;

   White w1(PAWN);
   board.board[3][1] = &w1;  //uppercase is black, lowercase is white

   White w2(PAWN);
   board.board[4][1] = &w2;

   White w3(PAWN);
   board.board[5][1] = &w3;

   White rookQueen(ROOK);
   board.board[0][0] = &rookQueen;
   rookQueen.nMoves = 0;

   White rookKing(ROOK);
   board.board[7][0] = &rookKing;
   rookKing.nMoves = 0;


   set <Move> moves;

   Move e1d1;
   Move e1f1;

   e1d1.source.colRow = e1f1.source.colRow = 0x40;
   e1d1.capture = e1f1.capture = SPACE;

   e1d1.dest.colRow = 0x30;
   e1f1.dest.colRow = 0x50;


   // EXERCISE

   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2);
   assertUnit(moves.find(e1d1) != moves.end());
   assertUnit(moves.find(e1f1) != moves.end());


   // TEARDOWN
   board.board[4][0] = nullptr;  // king
   board.board[3][1] = nullptr;
   board.board[4][1] = nullptr;
   board.board[5][1] = nullptr;
   board.board[0][0] = nullptr; //rook queen side
   board.board[7][0] = nullptr; //rook king side
   }


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r     .(k).   r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastleRookMoved()
{
   // SETUP
   BoardEmpty board;

   King king(7, 7, false /*white*/); // we will reset all this.
   king.nMoves = -1;
   king.fWhite = true;
   king.nMoves = 0;
   king.position.colRow = 0x40;
   board.board[4][0] = &king;

   White w1(PAWN);
   board.board[3][1] = &w1;  //uppercase is black, lowercase is white

   White w2(PAWN);
   board.board[4][1] = &w2;

   White w3(PAWN);
   board.board[5][1] = &w3;

   White rookQueen(ROOK);
   board.board[0][0] = &rookQueen;
   rookQueen.nMoves = 1;

   White rookKing(ROOK);
   board.board[7][0] = &rookKing;
   rookKing.nMoves = 1;


   set <Move> moves;

   Move e1d1;
   Move e1f1;

   e1d1.source.colRow = e1f1.source.colRow = 0x40;
   e1d1.capture = e1f1.capture = SPACE;

   e1d1.dest.colRow = 0x30;
   e1f1.dest.colRow = 0x50;


   // EXERCISE

   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2);
   assertUnit(moves.find(e1d1) != moves.end());
   assertUnit(moves.find(e1f1) != moves.end());


   // TEARDOWN
   board.board[4][0] = nullptr;  // king
   board.board[3][1] = nullptr;
   board.board[4][1] = nullptr;
   board.board[5][1] = nullptr;
   board.board[0][0] = nullptr; //rook queen side
   board.board[7][0] = nullptr; //rook king side
}

/*************************************
 * GET TYPE : king
 * Input:
 * Output: KING
 **************************************/
void TestKing::getType()
{
   // SETUP  
   const King king(7, 7, false /*white*/);
   PieceType pt = SPACE;

   // EXERCISE
   pt = king.getType();

   // VERIFY
   assertUnit(pt == KING);
}  // TEARDOWN


