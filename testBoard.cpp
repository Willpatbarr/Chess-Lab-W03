/***********************************************************************
 * Source File:
 *    TEST BOARD
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for board
 ************************************************************************/


#include "testBoard.h"
#include "position.h"
#include "piece.h"
#include "board.h"
#include <cassert>

#include <iostream>
using namespace std;



/********************************************************
 *    e5c6
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6       .             6       6       n             6
 * 5          (n)        5       5           .         5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_knightMove()
{  // SETUP
   Move e5c6;
   e5c6.source.colRow = 0x44;
   e5c6.dest.colRow = 0x25;
   e5c6.capture = SPACE;
   e5c6.promote = SPACE;
   e5c6.isWhite = true;
   e5c6.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, KNIGHT);
   board.board[2][5] = new PieceSpy(2, 5, false /*isWhite*/, SPACE);
   board.board[4][4]->nMoves = 17;
   PieceSpy::reset();

   // EXERCISE
   board.move(e5c6);

   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(KNIGHT == (board.board[2][5])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[2][5];
   delete board.board[4][4];
   board.board[2][5] = board.board[4][4] = nullptr;
}

 /********************************************************
 *    e5c6r
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7       R             7       7                     7
 * 6                     6       6       n             6
 * 5          (n)        5       5           .         5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
  ********************************************************/
void TestBoard::move_knightAttack()
{  // SETUP
   Move e5c6r;
   e5c6r.source.colRow = 0x44;
   e5c6r.dest.colRow = 0x25;
   e5c6r.capture = ROOK;
   e5c6r.promote = SPACE;
   e5c6r.isWhite = true;
   e5c6r.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, KNIGHT);
   board.board[2][5] = new PieceSpy(2, 5, false /*isWhite*/, ROOK);
   board.board[4][4]->nMoves = 17;
   PieceSpy::reset();

   // EXERCISE
   board.move(e5c6r);

   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(KNIGHT == (board.board[2][5])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[2][5];
   delete board.board[4][4];
   board.board[2][5] = board.board[4][4] = nullptr;
}




/********************************************************
 *   a2a3
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3   .                 3       3   p                 3
 * 2  (p)                2       2   .                 2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_pawnSimple()
{  // SETUP
   Move a2a3;
   a2a3.source.colRow = 0x01;
   a2a3.dest.colRow = 0x03;
   a2a3.capture = SPACE;
   a2a3.promote = SPACE;
   a2a3.isWhite = true;
   a2a3.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[0][1] = new PieceSpy(0, 1, true  /*isWhite*/, PAWN);
   board.board[0][3] = new PieceSpy(0, 3, false /*isWhite*/, SPACE);
   board.board[0][1]->nMoves = 17;
   PieceSpy::reset();

   // EXERCISE
   board.move(a2a3);

   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(SPACE == (board.board[0][1])->getType());
   assertUnit(PAWN == (board.board[0][3])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[0][1];
   delete board.board[0][3];
   board.board[0][1] = board.board[0][3] = nullptr;
}


/********************************************************
 *     a6b7r
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7     R               7       7    (p)              7
 * 6  (p)                6       6   .                 6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_pawnCapture()
{  // SETUP
   Move a6b7r;
   a6b7r.source.colRow = 0x05;
   a6b7r.dest.colRow = 0x16;
   a6b7r.capture = ROOK;
   a6b7r.promote = SPACE;
   a6b7r.isWhite = true;
   a6b7r.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[0][5] = new PieceSpy(0, 5, true  /*isWhite*/, PAWN);
   board.board[1][6] = new PieceSpy(1, 6, false /*isWhite*/, SPACE);
   board.board[0][5]->nMoves = 17;
   PieceSpy::reset();

   // EXERCISE
   board.move(a6b7r);

   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(SPACE == (board.board[0][5])->getType());
   assertUnit(PAWN == (board.board[1][6])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[0][5];
   delete board.board[1][6];
   board.board[0][5] = board.board[1][6] = nullptr;
}


/********************************************************
 *    e2e4
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4           .         4  -->  4          (p)        4
 * 3                     3       3                     3
 * 2          (p)        2       2           .         2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_pawnDouble()
{  // SETUP
   Move e2e4;
   e2e4.source.colRow = 0x41;
   e2e4.dest.colRow = 0x43;
   e2e4.capture = SPACE;
   e2e4.promote = SPACE;
   e2e4.isWhite = true;
   e2e4.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[4][1] = new PieceSpy(4, 1, true  /*isWhite*/, PAWN);
   board.board[4][3] = new PieceSpy(4, 3, false /*isWhite*/, SPACE);
   board.board[4][1]->nMoves = 17;
   PieceSpy::reset();

   // EXERCISE
   board.move(e2e4);

   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(SPACE == (board.board[4][1])->getType());
   assertUnit(PAWN == (board.board[4][3])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[4][1];
   delete board.board[4][3];
   board.board[4][1] = board.board[4][3] = nullptr;
}


/********************************************************
*     a5b6E
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6     .               6       6     p               6
 * 5  (p)P               5       5   . .               5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_pawnEnpassant()
{  // SETUP
   Move a5b6E;
   a5b6E.source.colRow = 0x04;
   a5b6E.dest.colRow = 0x16;
   a5b6E.capture = PAWN;
   a5b6E.promote = SPACE;
   a5b6E.isWhite = true;
   a5b6E.moveType = Move::ENPASSANT;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[0][4] = new PieceSpy(0, 4, true  /*isWhite*/, PAWN);
   board.board[1][4] = new PieceSpy(1, 4, false /*isWhite*/, PAWN);
   board.board[1][5] = new PieceSpy(1, 5, false /*isWhite*/, SPACE);
   board.board[0][4]->nMoves = 17;
   PieceSpy::reset();

   // EXERCISE
   board.move(a5b6E);

   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(SPACE == (board.board[0][4])->getType());
   assertUnit(SPACE == (board.board[1][4])->getType());
   assertUnit(PAWN == (board.board[1][5])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[0][4];
   delete board.board[1][5];
   delete board.board[1][4];

   board.board[0][4] = board.board[1][5] = board.board[1][4] = nullptr;
}


/********************************************************
 *    a7a8Q
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8   .                 8       8  (Q)                8
 * 7  (p)                7       7   .                 7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_pawnPromotion()
{  // SETUP
   Move a7a8Q;
   a7a8Q.source.colRow = 0x06;
   a7a8Q.dest.colRow = 0x07;
   a7a8Q.capture = SPACE;
   a7a8Q.promote = QUEEN;
   a7a8Q.isWhite = true;
   a7a8Q.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[0][6] = new PieceSpy(0, 6, true  /*isWhite*/, PAWN);
   board.board[0][7] = new PieceSpy(0, 7, false /*isWhite*/, SPACE);
   board.board[0][6]->nMoves = 17;
   PieceSpy::reset();

   // EXERCISE
   board.move(a7a8Q);

   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(SPACE == (board.board[0][6])->getType());
   assertUnit(QUEEN == (board.board[0][7])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[0][6];
   delete board.board[0][7];
   board.board[0][6] = board.board[0][7] = nullptr;
}


/********************************************************
 *    e5a5
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5   .      (r)        5       5  (r)      .         5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_rookSlide()
{  // SETUP
   Move e5a5;
   e5a5.source.colRow = 0x44;
   e5a5.dest.colRow = 0x04;
   e5a5.capture = SPACE;
   e5a5.promote = SPACE;
   e5a5.isWhite = true;
   e5a5.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, ROOK);
   board.board[0][4] = new PieceSpy(0, 4, false /*isWhite*/, SPACE);
   board.board[4][4]->nMoves = 17;
   PieceSpy::reset();

   // EXERCISE
   board.move(e5a5);

   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(ROOK == (board.board[0][4])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[4][4];
   delete board.board[0][4];
   board.board[4][4] = board.board[0][4] = nullptr;
}


/********************************************************
 *    e5a5b
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5   B      (r)        5       5  (r)      .         5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_rookAttack()
{  // SETUP
   Move e5a5b;
   e5a5b.source.colRow = 0x44;
   e5a5b.dest.colRow = 0x04;
   e5a5b.capture = BISHOP;
   e5a5b.promote = SPACE;
   e5a5b.isWhite = true;
   e5a5b.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, ROOK);
   board.board[0][4] = new PieceSpy(0, 4, false /*isWhite*/, BISHOP);
   board.board[4][4]->nMoves = 17;
   PieceSpy::reset();

   // EXERCISE
   board.move(e5a5b);

   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(ROOK == (board.board[0][4])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[4][4];
   delete board.board[0][4];
   board.board[4][4] = board.board[0][4] = nullptr;
}


/********************************************************
 *    e5g3
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5          (b)        5       5           .         5
 * 4                     4  -->  4                     4
 * 3               .     3       3               b     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_bishopSlide()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


/********************************************************
 *    e5g3q
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5          (b)        5       5           .         5
 * 4                     4  -->  4                     4
 * 3               Q     3       3               b     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_bishopAttack()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/********************************************************
 *    e5g3
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5          (q)        5       5                     5
 * 4                     4  -->  4           .         4
 * 3               .     3       3               q     3
 * 2                     2       2                     2
 * 1                     1       1                     1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_queenSlide()
{  // SETUP
   Move e5g3;
   e5g3.source.colRow = 0x44;
   e5g3.dest.colRow = 0x62;
   e5g3.capture = SPACE;
   e5g3.promote = SPACE;
   e5g3.isWhite = true;
   e5g3.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, QUEEN);
   board.board[6][2] = new PieceSpy(6, 2, false /*isWhite*/, SPACE);
   board.board[4][4]->nMoves = 17;
   PieceSpy::reset();

   // EXERCISE
   board.move(e5g3);

   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(QUEEN == (board.board[6][2])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[4][4];
   delete board.board[6][2];
   board.board[4][4] = board.board[6][2] = nullptr;
}


/********************************************************
*    e5a5b
* +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
* |                     |       |                     |
* 8                     8       8                     8
* 7                     7       7                     7
* 6                     6       6                     6
* 5   B      (q)        5       5  (q)      .         5
* 4                     4  -->  4                     4
* 3                     3       3                     3
* 2                     2       2                     2
* 1                     1       1                     1
* |                     |       |                     |
* +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
********************************************************/
void TestBoard::move_queenAttack()
{  // SETUP
   Move e5a5b;
   e5a5b.source.colRow = 0x44;
   e5a5b.dest.colRow = 0x04;
   e5a5b.capture = BISHOP;
   e5a5b.promote = SPACE;
   e5a5b.isWhite = true;
   e5a5b.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[4][4] = new PieceSpy(4, 4, true  /*isWhite*/, QUEEN);
   board.board[0][4] = new PieceSpy(0, 4, false /*isWhite*/, BISHOP);
   board.board[4][4]->nMoves = 17;
   PieceSpy::reset();

   // EXERCISE
   board.move(e5a5b);

   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(SPACE == (board.board[4][4])->getType());
   assertUnit(QUEEN == (board.board[0][4])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[4][4];
   delete board.board[0][4];
   board.board[4][4] = board.board[0][4] = nullptr;
}


/********************************************************
 *  e1f1
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1          (k).       1       1           . k       1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_kingMove()
{  // SETUP
   Move e1f1;
   e1f1.source.colRow = 0x40;
   e1f1.dest.colRow = 0x50;
   e1f1.capture = SPACE;
   e1f1.promote = SPACE;
   e1f1.isWhite = true;
   e1f1.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[4][0] = new PieceSpy(4, 0, true  /*isWhite*/, KING);
   board.board[5][0] = new PieceSpy(5, 0, false /*isWhite*/, SPACE);
   board.board[4][0]->nMoves = 17;
   PieceSpy::reset();

   // EXERCISE
   board.move(e1f1);

   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(SPACE == (board.board[4][0])->getType());
   assertUnit(KING == (board.board[5][0])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[4][0];
   delete board.board[5][0];
   board.board[4][0] = board.board[5][0] = nullptr;
}


/********************************************************
 *    e1f1r
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1          (k)R       1       1           . k       1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_kingAttack()
{  // SETUP
   Move e1f1r;
   e1f1r.source.colRow = 0x40;
   e1f1r.dest.colRow = 0x50;
   e1f1r.capture = ROOK;
   e1f1r.promote = SPACE;
   e1f1r.isWhite = true;
   e1f1r.moveType = Move::MOVE;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[4][0] = new PieceSpy(4, 0, true  /*isWhite*/, KING);
   board.board[5][0] = new PieceSpy(5, 0, false /*isWhite*/, ROOK);
   board.board[4][0]->nMoves = 17;
   PieceSpy::reset();

   // EXERCISE
   board.move(e1f1r);

   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(SPACE == (board.board[4][0])->getType());
   assertUnit(KING == (board.board[5][0])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[4][0];
   delete board.board[5][0];
   board.board[4][0] = board.board[5][0] = nullptr;
}

/********************************************************
 *    e1g1c
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1          (k). . r   1       1           . r k .   1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_kingShortCastle()
{  // SETUP
   Move e1g1c;
   e1g1c.source.colRow = 0x40;
   e1g1c.dest.colRow = 0x60;
   e1g1c.capture = SPACE;
   e1g1c.promote = SPACE;
   e1g1c.isWhite = true;
   e1g1c.moveType = Move::CASTLE_KING;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[4][0] = new PieceSpy(4, 0, true  /*isWhite*/, KING);
   board.board[5][0] = new PieceSpy(5, 0, false /*isWhite*/, SPACE);
   board.board[6][0] = new PieceSpy(6, 0, false /*isWhite*/, SPACE);
   board.board[7][0] = new PieceSpy(7, 0, false /*isWhite*/, ROOK);
   board.board[4][0]->nMoves = 17;
   PieceSpy::reset();

   // EXERCISE
   board.move(e1g1c);

   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(SPACE == (board.board[4][0])->getType());
   assertUnit(ROOK == (board.board[5][0])->getType());
   assertUnit(KING == (board.board[6][0])->getType());
   assertUnit(SPACE == (board.board[7][0])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[4][0];
   delete board.board[5][0];
   delete board.board[6][0];
   delete board.board[7][0];
   board.board[4][0] = board.board[5][0] = board.board[6][0] = board.board[7][0] = nullptr;
}



/********************************************************
 *    e1c1C
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 * |                     |       |                     |
 * 8                     8       8                     8
 * 7                     7       7                     7
 * 6                     6       6                     6
 * 5                     5       5                     5
 * 4                     4  -->  4                     4
 * 3                     3       3                     3
 * 2                     2       2                     2
 * 1   r . . .(k)        1       1   . . k r .         1
 * |                     |       |                     |
 * +---a-b-c-d-e-f-g-h---+       +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::move_kingLongCastle()
{  // SETUP
   Move e1c1C;
   e1c1C.source.colRow = 0x40;
   e1c1C.dest.colRow = 0x20;
   e1c1C.capture = SPACE;
   e1c1C.promote = SPACE;
   e1c1C.isWhite = true;
   e1c1C.moveType = Move::CASTLE_QUEEN;
   Board board(nullptr, true /*noreset*/);
   board.numMoves = 17;
   board.board[4][0] = new PieceSpy(4, 0, true  /*isWhite*/, KING);
   board.board[3][0] = new PieceSpy(3, 0, false /*isWhite*/, SPACE);
   board.board[2][0] = new PieceSpy(2, 0, false /*isWhite*/, SPACE);
   board.board[1][0] = new PieceSpy(1, 0, false /*isWhite*/, SPACE);
   board.board[0][0] = new PieceSpy(0, 0, false /*isWhite*/, ROOK);
   board.board[4][0]->nMoves = 17;
   PieceSpy::reset();

   // EXERCISE
   board.move(e1c1C);

   // VERIFY
   assertUnit(18 == board.numMoves);
   assertUnit(SPACE == (board.board[4][0])->getType());
   assertUnit(ROOK == (board.board[3][0])->getType());
   assertUnit(KING == (board.board[2][0])->getType());
   assertUnit(SPACE == (board.board[1][0])->getType());
   assertUnit(SPACE == (board.board[0][0])->getType());
   assertUnit(PieceSpy::numConstruct == 0);
   assertUnit(PieceSpy::numCopy == 0);
   assertUnit(PieceSpy::numDelete == 0);
   assertUnit(PieceSpy::numAssign == 0);
   assertUnit(PieceSpy::numMove == 0);

   // TEARDOWN
   delete board.board[4][0];
   delete board.board[3][0];
   delete board.board[2][0];
   delete board.board[1][0];
   delete board.board[0][0];
   board.board[4][0] = board.board[3][0] = board.board[2][0] = board.board[1][0] = board.board[0][0] = nullptr;
}




/********************************************************
 *        +---a-b-c-d-e-f-g-h---+
 *        |                     |
 *        8   R N B Q K B N R   8
 *        7   P P P P P P P P   7
 *        6                     6
 *        5                     5
 *   -->  4                     4
 *        3                     3
 *        2   p p p p p p p p   2
 *        1   r n b q k b n r   1
 *        |                     |
 *        +---a-b-c-d-e-f-g-h---+
 ********************************************************/
void TestBoard::construct_default()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/***********************************************
 * GET CURRENT MOVE : initially the board is empty
 * Setup:  board.numMoves=0
 * VERIFY: moveNumber=0
 ***********************************************/
void TestBoard::getCurrentMove_initial()
{  // SETUP
   Board board;
   createDummyBoard(board);
   board.numMoves = 0;
   int moveNumber = -1;
   // EXERCISE
   moveNumber = board.getCurrentMove();
   // VERIFY
   assertUnit(0 == board.numMoves);
   assertUnit(moveNumber == 0);
}  // TEARDOWN

/***********************************************
 * GET CURRENT MOVE : second move
 * Setup:  board.numMoves=1
 * VERIFY: moveNumber=1
 ***********************************************/
void TestBoard::getCurrentMove_second()
{  // SETUP
   Board board;
   createDummyBoard(board);
   board.numMoves = 1;
   int moveNumber = -1;
   // EXERCISE
   moveNumber = board.getCurrentMove();
   // VERIFY
   assertUnit(1 == board.numMoves);
   assertUnit(moveNumber == 1);
}  // TEARDOWN

/***********************************************
 * GET CURRENT MOVE : white turn in the middle of the game
 * Setup:  board.numMoves=4
 * VERIFY: moveNumber=4
 ***********************************************/
void TestBoard::getCurrentMove_middleWhite()
{  // SETUP
   Board board;
   createDummyBoard(board);
   board.numMoves = 4;
   int moveNumber = -1;
   // EXERCISE
   moveNumber = board.getCurrentMove();
   // VERIFY
   assertUnit(4 == board.numMoves);
   assertUnit(moveNumber == 4);
}  // TEARDOWN

/***********************************************
 * GET CURRENT MOVE : black turn in the middle of the game
 * Setup:  board.numMoves=5
 * VERIFY: moveNumber=5
 ***********************************************/
void TestBoard::getCurrentMove_middleBlack()
{  // SETUP
   Board board;
   createDummyBoard(board);
   board.numMoves = 5;
   int moveNumber = -1;
   // EXERCISE
   moveNumber = board.getCurrentMove();
   // VERIFY
   assertUnit(5 == board.numMoves);
   assertUnit(moveNumber == 5);
}  // TEARDOWN

/***********************************************
 * WHITE TURN : initially the board is empty
 * Setup:  board.numMoves=0
 * VERIFY: isWhiteTurn=true
 ***********************************************/
void TestBoard::whiteTurn_initial()
{  // SETUP
   Board board;
   board.numMoves = 0;
   createDummyBoard(board);
   bool isWhiteTurn;
   // EXERCISE
   isWhiteTurn = board.whiteTurn();
   // VERIFY
   assertUnit(0 == board.numMoves);
   assertUnit(isWhiteTurn == true);
}  // TEARDOWN

/***********************************************
 * WHITE TURN : second move
 * Setup:  board.numMoves=1
 * VERIFY: isWhiteTurn=false
 ***********************************************/
void TestBoard::whiteTurn_second()
{  // SETUP
   Board board;
   createDummyBoard(board);
   board.numMoves = 1;
   bool isWhiteTurn;
   // EXERCISE
   isWhiteTurn = board.whiteTurn();
   // VERIFY
   assertUnit(1 == board.numMoves);
   assertUnit(isWhiteTurn == false);
}  // TEARDOWN

/***********************************************
 * WHITE TURN : white turn in the middle of the game
 * Setup:  board.numMoves=4
 * VERIFY: isWhiteTurn=true
 ***********************************************/
void TestBoard::whiteTurn_middleWhite()
{  // SETUP
   Board board;
   createDummyBoard(board);
   board.numMoves = 4;
   bool isWhiteTurn;
   // EXERCISE
   isWhiteTurn = board.whiteTurn();
   // VERIFY
   assertUnit(4 == board.numMoves);
   assertUnit(isWhiteTurn == true);
}  // TEARDOWN

/***********************************************
 * WHITE TURN : black turn in the middle of the game
 * Setup:  board.numMoves=5
 * VERIFY: isWhiteTurn=false
 ***********************************************/
void TestBoard::whiteTurn_middleBlack()
{  // SETUP
   Board board;
   createDummyBoard(board);
   board.numMoves = 5;
   bool isWhiteTurn;
   // EXERCISE
   isWhiteTurn = board.whiteTurn();
   // VERIFY
   assertUnit(5 == board.numMoves);
   assertUnit(isWhiteTurn == false);
}  // TEARDOWN

class Position00 : public Position
{
public:
   int getRow() const { return 0; }
   int getCol() const { return 0; }
};

/***********************************************
 * FETCH : a1
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1  (x)                1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 ***********************************************/
void TestBoard::fetch_a1()
{  // setup
   Board board;
   PieceDummy piece;
   Piece* pSave = board.board[0][0];
   board.board[0][0] = &piece;
   Position00 pos;
   Piece* p = nullptr;
   // exercise
   p = &(board[pos]);
   // verify
   assertUnit(p == &piece);
   // teardown 
   board.board[0][0] = pSave;
}

void TestBoard::set_a1()
{  // setup
   Board board;
   PieceDummy piece;
   piece.fWhite = true;
   Piece* pSave = board.board[0][0];
   board.board[0][0] = &piece;
   Position00 pos;
   Piece* p = nullptr;
   // exercise
   board[pos].fWhite = false;
   // verify
   assertUnit(piece.fWhite == false);
   assertUnit(board.board[0][0]->fWhite == false);
   // teardown 
   board.board[0][0] = pSave;
}

class Position77 : public Position
{
public:
   int getRow() const { return 7; }
   int getCol() const { return 7; }
};

/***********************************************
 * FETCH : h8
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                (x)  8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 ***********************************************/
void TestBoard::fetch_h8()
{  // setup
   Board board;
   PieceDummy piece;
   Piece* pSave = board.board[7][7];
   board.board[7][7] = &piece;
   Position77 pos;
   Piece* p = nullptr;
   // exercise
   p = &(board[pos]);
   // verify
   assertUnit(p == &piece);
   // teardown 
   board.board[7][7] = pSave;
}

void TestBoard::set_h8()
{  // setup
   Board board;
   PieceDummy piece;
   piece.fWhite = true;
   Piece* pSave = board.board[7][7];
   board.board[7][7] = &piece;
   Position77 pos;
   Piece* p = nullptr;
   // exercise
   board[pos].fWhite = false;
   // verify
   assertUnit(piece.fWhite == false);
   assertUnit(board.board[7][7]->fWhite == false);
   // teardown 
   board.board[7][7] = pSave;
}

class Position07 : public Position
{
public:
   int getRow() const { return 7; }
   int getCol() const { return 0; }
};

/***********************************************
 * FETCH : a8
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8  (x)                8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 ***********************************************/
void TestBoard::fetch_a8()
{  // setup
   Board board;
   PieceDummy piece;
   Piece* pSave = board.board[0][7];
   board.board[0][7] = &piece;
   Position07 pos;
   Piece* p = nullptr;
   // exercise
   p = &(board[pos]);
   // verify
   assertUnit(p == &piece);
   // teardown 
   board.board[0][7] = pSave;
}

void TestBoard::set_a8()
{  // setup
   Board board;
   PieceDummy piece;
   piece.fWhite = true;
   Piece* pSave = board.board[0][7];
   board.board[0][7] = &piece;
   Position07 pos;
   Piece* p = nullptr;
   // exercise
   board[pos].fWhite = false;
   // verify
   assertUnit(piece.fWhite == false);
   assertUnit(board.board[0][7]->fWhite == false);
   // teardown 
   board.board[0][7] = pSave;
}


/***********************************************
 * CREATE DUMMY BOARD
 * Utility function - not a unit test
 * Just fill the board with the known pieces
 ***********************************************/
void TestBoard::createDummyBoard(Board& board)
{
   for (int r = 0; r < 8; r++)
      for (int c = 0; c < 8; c++)
      {
         board.board[c][r] = new PieceDummy;
      }
}



