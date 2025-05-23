/***********************************************************************
 * Source File:
 *    TEST KNIGHT
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the knight
 ************************************************************************/

#include "testKnight.h"
#include "pieceKnight.h"     
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
  * 3             p   .   3
  * 2           P         2
  * 1              (n)    1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestKnight::getMoves_end()
{
   // SETUP
   BoardEmpty board;
   
   Knight knight(7, 7, false /*white*/); // we will reset all this.
//   knight.nMoves = 0;
   knight.fWhite = true;
   knight.position.colRow = 0x60;
   board.board[6][0] = &knight;
   
   Black black(PAWN);
   board.board[4][1] = &black;  //uppercase is black, lowercase is white
   
   White white(PAWN);
   board.board[5][2] = &white;
   
   set <Move> moves;
   
   Move g1e2p;
   g1e2p.source.colRow = 0x60;
   g1e2p.dest.colRow = 0x41;
   g1e2p.capture = PAWN;
   
   Move g1h3;
   g1h3.source.colRow = 0x60;
   g1h3.dest.colRow = 0x72;
   g1h3.capture = SPACE;

   // EXERCISE

   knight.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2);  // many possible moves
   assertUnit(moves.find(g1e2p) != moves.end());
   assertUnit(moves.find(g1h3) != moves.end());

   // TEARDOWN
   board.board[6][0] = nullptr; // white knight
   board.board[4][1] = nullptr; // black pawn
   board.board[5][2] = nullptr; // white pawn
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       p   p         7
 * 6     p       p       6
 * 5        (n)          5
 * 4     p       p       4
 * 3       p   p         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_blocked()
{
   // SETUP
   BoardEmpty board;

   Knight knight(7, 7, false /*white*/); // we will reset all this.
   //   knight.nMoves = 0;
   knight.fWhite = true;
   knight.position.colRow = 0x34;
   board.board[3][4] = &knight;

   White w1(PAWN);
   board.board[1][3] = &w1;  //uppercase is black, lowercase is white

   White w2(PAWN);
   board.board[1][5] = &w2;

   White w3(PAWN);
   board.board[2][2] = &w3;

   White w4(PAWN);
   board.board[2][6] = &w4;

   White w5(PAWN);
   board.board[4][2] = &w5;

   White w6(PAWN);
   board.board[4][6] = &w6;

   White w7(PAWN);
   board.board[5][3] = &w7;

   White w8(PAWN);
   board.board[5][5] = &w8;

   set <Move> moves;


   // EXERCISE

   knight.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 0);  

   // TEARDOWN
   board.board[4][3] = nullptr;  // knight
   board.board[1][3] = nullptr;
   board.board[1][5] = nullptr;
   board.board[2][2] = nullptr;
   board.board[2][6] = nullptr;
   board.board[4][2] = nullptr;
   board.board[4][6] = nullptr;
   board.board[5][3] = nullptr;
   board.board[5][5] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       P   P         7
 * 6     P       P       6
 * 5        (n)          5
 * 4     P       P       4
 * 3       P   P         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_capture()
{
   // SETUP
   BoardEmpty board;

   Knight knight(7, 7, false /*white*/); // we will reset all this.
   //   knight.nMoves = 0;
   knight.fWhite = false;
   knight.position.colRow = 0x34;
   board.board[3][4] = &knight;

   White w1(PAWN);
   board.board[1][3] = &w1;  //uppercase is black, lowercase is white

   White w2(PAWN);
   board.board[1][5] = &w2;

   White w3(PAWN);
   board.board[2][2] = &w3;

   White w4(PAWN);
   board.board[2][6] = &w4;

   White w5(PAWN);
   board.board[4][2] = &w5;

   White w6(PAWN);
   board.board[4][6] = &w6;

   White w7(PAWN);
   board.board[5][3] = &w7;

   White w8(PAWN);
   board.board[5][5] = &w8;

   set <Move> moves;

   Move d5b6p;
   d5b6p.source.colRow = 0x34;
   d5b6p.dest.colRow = 0x15;
   d5b6p.capture = PAWN;

   Move d5c7p;
   d5c7p.source.colRow = 0x34;
   d5c7p.dest.colRow = 0x22; 
   d5c7p.capture = PAWN;

   Move d5e7p; 
   d5e7p.source.colRow = 0x34;
   d5e7p.dest.colRow = 0x26; 
   d5e7p.capture = PAWN;

   Move d5f6p; 
   d5f6p.source.colRow = 0x34; 
   d5f6p.dest.colRow = 0x15;
   d5f6p.capture = PAWN;

   Move d5f4p; 
   d5f4p.source.colRow = 0x34; 
   d5f4p.dest.colRow = 0x46; 
   d5f4p.capture = PAWN;

   Move d5e3p; 
   d5e3p.source.colRow = 0x34; 
   d5e3p.dest.colRow = 0x42; 
   d5e3p.capture = PAWN;

   Move d5c3p; 
   d5c3p.source.colRow = 0x34; 
   d5c3p.dest.colRow = 0x22; 
   d5c3p.capture = PAWN;

   Move d5b4p; 
   d5b4p.source.colRow = 0x34; 
   d5b4p.dest.colRow = 0x42; 
   d5b4p.capture = PAWN;

   // EXERCISE

   knight.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 8);
   assertUnit(moves.find(d5b6p) != moves.end());
   assertUnit(moves.find(d5c7p) != moves.end());
   assertUnit(moves.find(d5e7p) != moves.end());
   assertUnit(moves.find(d5f6p) != moves.end());
   assertUnit(moves.find(d5f4p) != moves.end());
   assertUnit(moves.find(d5e3p) != moves.end());
   assertUnit(moves.find(d5c3p) != moves.end());
   assertUnit(moves.find(d5b4p) != moves.end());


   // TEARDOWN
   board.board[3][4] = nullptr;  // knight
   board.board[1][3] = nullptr;
   board.board[1][5] = nullptr;
   board.board[2][2] = nullptr;
   board.board[2][6] = nullptr;
   board.board[4][2] = nullptr;
   board.board[4][6] = nullptr;
   board.board[5][3] = nullptr;
   board.board[5][5] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7       .   .         7
 * 6     .       .       6
 * 5        (n)          5
 * 4     .       .       4
 * 3       .   .         3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKnight::getMoves_free()
{
   // SETUP
   BoardEmpty board;

   Knight knight(7, 7, false /*white*/); // we will reset all this.
   //   knight.nMoves = 0;
   knight.fWhite = false;
   knight.position.colRow = 0x34;
   board.board[3][4] = &knight;



   set <Move> moves;

   Move d5b6;
   d5b6.source.colRow = 0x34;
   d5b6.dest.colRow = 0x15;
   d5b6.capture = SPACE;

   Move d5c7;
   d5c7.source.colRow = 0x34;
   d5c7.dest.colRow = 0x22;
   d5c7.capture = SPACE;

   Move d5e7;
   d5e7.source.colRow = 0x34;
   d5e7.dest.colRow = 0x26;
   d5e7.capture = SPACE;

   Move d5f6;
   d5f6.source.colRow = 0x34;
   d5f6.dest.colRow = 0x15;
   d5f6.capture = SPACE;

   Move d5f4;
   d5f4.source.colRow = 0x34;
   d5f4.dest.colRow = 0x46;
   d5f4.capture = SPACE;

   Move d5e3;
   d5e3.source.colRow = 0x34;
   d5e3.dest.colRow = 0x42;
   d5e3.capture = SPACE;

   Move d5c3;
   d5c3.source.colRow = 0x34;
   d5c3.dest.colRow = 0x22;
   d5c3.capture = SPACE;

   Move d5b4;
   d5b4.source.colRow = 0x34;
   d5b4.dest.colRow = 0x42;
   d5b4.capture = SPACE;

   // EXERCISE

   knight.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 8);
   assertUnit(moves.find(d5b6) != moves.end());
   assertUnit(moves.find(d5c7) != moves.end());
   assertUnit(moves.find(d5e7) != moves.end());
   assertUnit(moves.find(d5f6) != moves.end());
   assertUnit(moves.find(d5f4) != moves.end());
   assertUnit(moves.find(d5e3) != moves.end());
   assertUnit(moves.find(d5c3) != moves.end());
   assertUnit(moves.find(d5b4) != moves.end());


   // TEARDOWN
   board.board[4][3] = nullptr;  // knight
}


/*************************************
 * GET TYPE : knight
 * Input:
 * Output: KNIGHT
 **************************************/
void TestKnight::getType()
{
   // SETUP  
   const Knight knight(7, 7, false /*white*/);
   PieceType pt = SPACE;

   // EXERCISE
   pt = knight.getType();

   // VERIFY
   assertUnit(pt == KNIGHT);
}  // TEARDOWN
