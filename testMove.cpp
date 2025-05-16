/***********************************************************************
 * Header File:
 *    TEST MOVE
 * Author:
 *    <your name here>
 * Summary:
 *    test the Move class
 ************************************************************************/


#include "testMove.h"
#include "move.h"
#include <cassert>

 /*************************************
  * Constructor : default
  * Input:
  * Output: source=INVALID
  *         dest  =INVALID
  **************************************/
void TestMove::constructor_default()
{
   //setup
   //exercise
   Move moveTest;
   //verify
   assertUnit(0xff == moveTest.source.colRow);
   assertUnit(0xff == moveTest.dest.colRow);
   assertUnit(SPACE == moveTest.promote);
   assertUnit(SPACE == moveTest.capture);
   assertUnit(Move::MOVE == moveTest.moveType);
   assertUnit(true == moveTest.isWhite);
   //teardown
}

/*************************************
 * CONSTRUCTOR : standard string move
 * Input:  e5e6
 * Output: source=4,4
 *         dest  =4,5
 *         type  =MOVE
 **************************************/
void TestMove::constructString_simple()
{  // Setup
   // Exercise
   Move move("e5e6");
   // VERIFY
   assertUnit(0x44 == move.source.colRow);
   assertUnit(0x45 == move.dest.colRow);
   assertUnit(SPACE == move.promote);
   assertUnit(SPACE == move.capture);
   assertUnit(Move::MOVE == move.moveType);
   assertUnit(true == move.isWhite);
}  //Teardown

/*************************************
 * READ simple move
 * Input:  e5e6
 * Output: source=4,4
 *         dest  =4,5
 *         type  =MOVE
 **************************************/
void TestMove::read_simple()
{  // Setup
   Move move;
   move.source.colRow = 0xff;
   move.dest.colRow = 0xff;
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.moveType = Move::MOVE_ERROR;
   move.isWhite = false;
   move.text = "ERROR";
   // Exercise
   move.read(string("e5e6"));
   // VERIFY
   assertUnit(0x44 == move.source.colRow);
   assertUnit(0x45 == move.dest.colRow);
   assertUnit(SPACE == move.promote);
   assertUnit(SPACE == move.capture);
   assertUnit(Move::MOVE == move.moveType);
   assertUnit(false == move.isWhite);
}  //Teardown

/*************************************
 * READ capture move
 * Input:  e5d6r
 * Output: source=4,4
 *         dest  =3,5
 *         type  =MOVE
 *         capture=ROOK
 **************************************/
void TestMove::read_capture()
{  // Setup
   Move move;
   move.source.colRow = 0xff;
   move.dest.colRow = 0xff;
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.moveType = Move::MOVE_ERROR;
   move.isWhite = false;
   move.text= "ERROR";
   // Exercise
   move.read(string("e5e6r"));
   // VERIFY
   assertUnit(0x44 == move.source.colRow);
   assertUnit(0x45 == move.dest.colRow);
   assertUnit(SPACE == move.promote);
   assertUnit(ROOK == move.capture);
   assertUnit(Move::MOVE == move.moveType);
   assertUnit(false == move.isWhite);
}  //Teardown

/*************************************
 * READ enpassant move
 * Input:  e5f6E
 * Output: source=4,4
 *         dest  =5,5
 *         type  =ENPASSANT
 **************************************/
void TestMove::read_enpassant()
{
   //setup
   Move m;

   //exercise
   m.read("e5f6E");


   //verify
   assertUnit(m.source.getRow() == 4);
   assertUnit(m.source.getCol() == 4);
   assertUnit(m.dest.getCol() == 5);
   assertUnit(m.dest.getRow() == 5);
   assertUnit(m.moveType == Move::MoveType::ENPASSANT);
   //teardown
}

/*************************************
 * READ king side castle
 * Input:  e1g1c
 * Output: source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 **************************************/
void TestMove::read_castleKing()
{
   //setup
   Move m;

   //exercise
   m.read("e1g1c");

   //verify
   assertUnit(m.source.getRow() == 0);
   assertUnit(m.source.getCol() == 4);
   assertUnit(m.dest.getCol() == 6);
   assertUnit(m.dest.getRow() == 0);
   assertUnit(m.moveType == Move::MoveType::CASTLE_KING);
   //teardown
}

/*************************************
 * READ queen side castle
 * Input:  e1c1C
 * Output: source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 **************************************/
void TestMove::read_castleQueen()
{
   //setup
   Move m;

   m.read("e1c1C");
   //exercise

   //verify
   assertUnit(m.source.getRow() == 0);
   assertUnit(m.source.getCol() == 4);
   assertUnit(m.dest.getCol() == 2);
   assertUnit(m.dest.getRow() == 0);
   assertUnit(m.moveType == Move::MoveType::CASTLE_QUEEN);
   //teardown
}

/*************************************
 * ASSIGN simple move
 * Input:  e5e6
 * Output: source=4,4
 *         dest  =4,5
 *         type  =MOVE
 **************************************/
void TestMove::assign_simple()
{  //SETUP
   Move move;
   move.source.colRow = 0x44;
   move.dest.colRow = 0x45;
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.moveType = Move::MOVE_ERROR;
   move.isWhite = false;
   move.text = "ERROR";
   // EXERCISE
   move = string("e5e6");
   // VERIFY
   assertUnit(0x44 == move.source.colRow);
   assertUnit(0x45 == move.dest.colRow);
   assertUnit(SPACE == move.promote);
   assertUnit(SPACE == move.capture);
   assertUnit(Move::MOVE == move.moveType);
   assertUnit(false == move.isWhite);
} // teardown

/*************************************
 * ASSIGN capture move
 * Input:  e5d6r
 * Output: source=4,4
 *         dest  =3,5
 *         type  =MOVE
 *         capture=ROOK
 **************************************/
void TestMove::assign_capture()
{  //SETUP
   Move move;
   move.source.colRow = 0x44;
   move.dest.colRow = 0x35;
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.moveType = Move::MOVE_ERROR;
   move.isWhite = false;
   move.text = "ERROR";
   // EXERCISE
   move = string("e5d6r");
   // VERIFY
   assertUnit(0x44 == move.source.colRow);
   assertUnit(0x35 == move.dest.colRow);
   assertUnit(SPACE == move.promote);
   assertUnit(ROOK == move.capture);
   assertUnit(Move::MOVE == move.moveType);
   assertUnit(false == move.isWhite);
} // teardown

/*************************************
 * ASSIGN enpassant move
 * Input:  e5f6E
 * Output: source=4,4
 *         dest  =5,5
 *         type  =ENPASSANT
 **************************************/
void TestMove::assign_enpassant()
{  //SETUP
   Move move;
   move.source.colRow = 0x44;
   move.dest.colRow = 0x55;
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.moveType = Move::MOVE_ERROR;
   move.isWhite = false;
   move.text = "ERROR";
   // EXERCISE
   move = string("e5f6E");
   // VERIFY
   assertUnit(0x44 == move.source.colRow);
   assertUnit(0x55 == move.dest.colRow);
   assertUnit(SPACE == move.promote);
   assertUnit(SPACE == move.capture);
   assertUnit(Move::ENPASSANT == move.moveType);
   assertUnit(false == move.isWhite);
} // teardown

/*************************************
 * ASSIGN king side castle
 * Input:  e1g1c
 * Output: source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 **************************************/
void TestMove::assign_castleKing()
{  //SETUP
   Move move;
   move.source.colRow = 0x40;
   move.dest.colRow = 0x60;
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.moveType = Move::MOVE_ERROR;
   move.isWhite = false;
   move.text = "ERROR";
   // EXERCISE
   move = string("e1g1c");
   // VERIFY
   assertUnit(0x40 == move.source.colRow);
   assertUnit(0x60 == move.dest.colRow);
   assertUnit(SPACE == move.promote);
   assertUnit(SPACE == move.capture);
   assertUnit(Move::CASTLE_KING == move.moveType);
   assertUnit(false == move.isWhite);
} // teardown

/*************************************
 * ASSIGN queen side castle
 * Input:  e1c1C
 * Output: source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 **************************************/
void TestMove::assign_castleQueen()
{  //SETUP
   Move move;
   move.source.colRow = 0x40;
   move.dest.colRow = 0x20;
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.moveType = Move::MOVE_ERROR;
   move.isWhite = false;
   move.text = "ERROR";
   // EXERCISE
   move = string("e1c1C");
   // VERIFY
   assertUnit(0x40 == move.source.colRow);
   assertUnit(0x20 == move.dest.colRow);
   assertUnit(SPACE == move.promote);
   assertUnit(SPACE == move.capture);
   assertUnit(Move::CASTLE_QUEEN == move.moveType);
   assertUnit(false == move.isWhite);
} // teardown

/*************************************
 * GET TEXT simple move
 * Input : source=4,4
 *         dest  =4,5
 *         type  =MOVE
 * Output:  e5e6
 **************************************/
void TestMove::getText_simple()
{  //SETUP
   Move move;
   move.source.colRow = 0x44;
   move.dest.colRow = 0x45;
   move.promote = SPACE;
   move.capture = SPACE;
   move.moveType = Move::MOVE;
   move.isWhite = true;
   move.text = "";
   string s;
   // EXERCISE
   s = move.getText();
   // VERIFY
   assertUnit(s == string("e5e6"));
   assertUnit(0x44 == move.source.colRow);
   assertUnit(0x45 == move.dest.colRow);
   assertUnit(SPACE == move.promote);
   assertUnit(SPACE == move.capture);
   assertUnit(Move::MOVE == move.moveType);
   assertUnit(true == move.isWhite);
} // teardown

/*************************************
 * GET TEXT capture
 * Input : source=4,4
 *         dest  =4,5
 *         type  =MOVE
 *         capture=ROOK
 * Output:  e5e6r
 **************************************/
void TestMove::getText_capture()
{  //SETUP
   Move move;
   move.source.colRow = 0x44;
   move.dest.colRow = 0x45;
   move.promote = SPACE;
   move.capture = ROOK;
   move.moveType = Move::MOVE;
   move.isWhite = true;
   move.text = "";
   string s;
   // EXERCISE
   s = move.getText();
   // VERIFY
   assertUnit(s == string("e5e6r"));
   assertUnit(0x44 == move.source.colRow);
   assertUnit(0x45 == move.dest.colRow);
   assertUnit(SPACE == move.promote);
   assertUnit(ROOK == move.capture);
   assertUnit(Move::MOVE == move.moveType);
   assertUnit(true == move.isWhite);
} // teardown

/*************************************
 * GET TEXT en passant
 * Input : source=4,4
 *         dest  =5,5
 *         type  =ENPASSANT
 *         capture=PAWN
 * Output:  e5f6E
 **************************************/
void TestMove::getText_enpassant()
{  //SETUP
   Move move;
   move.source.colRow = 0x44;
   move.dest.colRow = 0x55;
   move.promote = SPACE;
   move.capture = SPACE;
   move.moveType = Move::ENPASSANT;
   move.isWhite = true;
   move.text = "";
   string s;
   // EXERCISE
   s = move.getText();
   // VERIFY
   assertUnit(s == string("e5f6E"));
   assertUnit(0x44 == move.source.colRow);
   assertUnit(0x55 == move.dest.colRow);
   assertUnit(SPACE == move.promote);
   assertUnit(SPACE == move.capture);
   assertUnit(Move::ENPASSANT == move.moveType);
   assertUnit(true == move.isWhite);
} // teardown

/*************************************
 * GET TEXT king side castle
 * Input : source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 * Output:  e1g1c
 **************************************/
void TestMove::getText_castleKing()
{  //SETUP
   Move move;
   move.source.colRow = 0x40;
   move.dest.colRow = 0x60;
   move.promote = SPACE;
   move.capture = SPACE;
   move.moveType = Move::CASTLE_KING;
   move.isWhite = true;
   move.text = "";
   string s;
   // EXERCISE
   s = move.getText();
   // VERIFY
   assertUnit(s == string("e1g1c"));
   assertUnit(0x40 == move.source.colRow);
   assertUnit(0x60 == move.dest.colRow);
   assertUnit(SPACE == move.promote);
   assertUnit(SPACE == move.capture);
   assertUnit(Move::CASTLE_KING == move.moveType);
   assertUnit(true == move.isWhite);
} // teardown

/*************************************
 * GET TEXT queen side castle
 * Input : source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 * Output:  e1c1C
 **************************************/
void TestMove::getText_castleQueen()
{  //SETUP
   Move move;
   move.source.colRow = 0x40;
   move.dest.colRow = 0x20;
   move.promote = SPACE;
   move.capture = SPACE;
   move.moveType = Move:: CASTLE_QUEEN;
   move.isWhite = true;
   move.text     = "";
   string s;
   // EXERCISE
   s = move.getText();
   // VERIFY
   assertUnit(s == string("e1c1C"));
   assertUnit(0x40 == move.source.colRow);
   assertUnit(0x20 == move.dest.colRow);
   assertUnit(SPACE == move.promote);
   assertUnit(SPACE == move.capture);
   assertUnit(Move::CASTLE_QUEEN == move.moveType);
   assertUnit(true == move.isWhite);
} // teardown

/*************************************
 * LETTER FROM PIECE TYPE space
 * Input :  SPACE
 * Output:  ' '
 **************************************/
void TestMove::letterFromPieceType_space()
{
   //SETUP
   Move move;
   move.source.colRow = 0x77;
   move.dest.colRow = 0x77;
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.moveType = Move::MOVE_ERROR;
   move.isWhite = false;
   move.text = "ERROR";
   // exercise
   char letter = move.letterFromPieceType(SPACE);
   // verify
   assertUnit(letter == ' ');
   assertUnit(0x77 == move.source.colRow);
   assertUnit(0x77 == move.source.colRow);
   assertUnit(KNIGHT == move.promote);
   assertUnit(BISHOP == move.capture);
   assertUnit(Move::MOVE_ERROR == move.moveType);
   assertUnit(false == move.isWhite);
} // teardown

/*************************************
 * LETTER FROM PIECE TYPE pawn
 * Input : PAWN
 * Output:  'p'
 **************************************/
void TestMove::letterFromPieceType_pawn()
{
   //SETUP
   Move move;
   move.source.colRow = 0x77;
   move.dest.colRow = 0x77;
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.moveType = Move::MOVE_ERROR;
   move.isWhite = false;
   move.text = "ERROR";
   // exercise
   char letter = move.letterFromPieceType(PAWN);
   // verify
   assertUnit(letter == 'p');
   assertUnit(0x77 == move.source.colRow);
   assertUnit(0x77 == move.source.colRow);
   assertUnit(KNIGHT == move.promote);
   assertUnit(BISHOP == move.capture);
   assertUnit(Move::MOVE_ERROR == move.moveType);
   assertUnit(false == move.isWhite);
} // teardown

/*************************************
 * LETTER FROM PIECE TYPE bishop
 * Input : BISHOP
 * Output:  'b'
 **************************************/
void TestMove::letterFromPieceType_bishop()
{
   //SETUP
   Move move;
   move.source.colRow = 0x77;
   move.dest.colRow = 0x77;
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.moveType = Move::MOVE_ERROR;
   move.isWhite = false;
   move.text = "ERROR";
   // exercise
   char letter = move.letterFromPieceType(BISHOP);
   // verify
   assertUnit(letter == 'b');
   assertUnit(0x77 == move.source.colRow);
   assertUnit(0x77 == move.source.colRow);
   assertUnit(KNIGHT == move.promote);
   assertUnit(BISHOP == move.capture);
   assertUnit(Move::MOVE_ERROR == move.moveType);
   assertUnit(false == move.isWhite);
} // teardown

/*************************************
 * LETTER FROM PIECE TYPE knight
 * Input : KNIGHT
 * Output:  'n'
 **************************************/
void TestMove::letterFromPieceType_knight()
{
   //SETUP
   Move move;
   move.source.colRow = 0x77;
   move.dest.colRow = 0x77;
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.moveType = Move::MOVE_ERROR;
   move.isWhite = false;
   move.text = "ERROR";
   // exercise
   char letter = move.letterFromPieceType(KNIGHT);
   // verify
   assertUnit(letter == 'n');
   assertUnit(0x77 == move.source.colRow);
   assertUnit(0x77 == move.source.colRow);
   assertUnit(KNIGHT == move.promote);
   assertUnit(BISHOP == move.capture);
   assertUnit(Move::MOVE_ERROR == move.moveType);
   assertUnit(false == move.isWhite);
} // teardown

/*************************************
 * LETTER FROM PIECE TYPE rook
 * Input : ROOK
 * Output:  'r'
 **************************************/
void TestMove::letterFromPieceType_rook()
{
   //SETUP
   Move move;
   move.source.colRow = 0x77;
   move.dest.colRow = 0x77;
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.moveType = Move::MOVE_ERROR;
   move.isWhite = false;
   move.text = "ERROR";
   // exercise
   char letter = move.letterFromPieceType(ROOK);
   // verify
   assertUnit(letter == 'r');
   assertUnit(0x77 == move.source.colRow);
   assertUnit(0x77 == move.source.colRow);
   assertUnit(KNIGHT == move.promote);
   assertUnit(BISHOP == move.capture);
   assertUnit(Move::MOVE_ERROR == move.moveType);
   assertUnit(false == move.isWhite);
} // teardown

/*************************************
 * LETTER FROM PIECE TYPE queen
 * Input : QUEEN
 * Output:  'q'
 **************************************/
void TestMove::letterFromPieceType_queen()
{
   //SETUP
   Move move;
   move.source.colRow = 0x77;
   move.dest.colRow = 0x77;
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.moveType = Move::MOVE_ERROR;
   move.isWhite = false;
   move.text = "ERROR";
   // exercise
   char letter = move.letterFromPieceType(QUEEN);
   // verify
   assertUnit(letter == 'q');
   assertUnit(0x77 == move.source.colRow);
   assertUnit(0x77 == move.source.colRow);
   assertUnit(KNIGHT == move.promote);
   assertUnit(BISHOP == move.capture);
   assertUnit(Move::MOVE_ERROR == move.moveType);
   assertUnit(false == move.isWhite);
} // teardown

/*************************************
 * LETTER FROM PIECE TYPE king
 * Input : KING
 * Output:  'k'
 **************************************/
void TestMove::letterFromPieceType_king()
{
   //SETUP
   Move move;
   move.source.colRow = 0x77;
   move.dest.colRow = 0x77;
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.moveType = Move:: MOVE_ERROR;
   move.isWhite = false;
   move.text = "ERROR";
   // exercise
   char letter = move.letterFromPieceType(KING);
   // verify
   assertUnit(letter  == 'k');
   assertUnit(0x77    == move.source.colRow);
   assertUnit(0x77    == move.source.colRow);
   assertUnit(KNIGHT  == move.promote);
   assertUnit(BISHOP  == move.capture);
   assertUnit(Move::MOVE_ERROR == move.moveType);
   assertUnit(false == move.isWhite);
} // teardown

/*************************************
 * PIECE TYPE FROM LETTER pawn
 * Input : 'p'
 * Output:  PAWN
 **************************************/
void TestMove::pieceTypeFromLetter_pawn()
{
   // setup
   Move move;
   move.source.colRow = 0x77;
   move.dest.colRow = 0x77;
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.moveType = Move::MOVE_ERROR;
   move.isWhite = false;
   move.text = "ERROR";
   // exercise
   PieceType pt = move.pieceTypeFromLetter('p');
   // verify
   assertUnit(pt == PAWN);
   assertUnit(0x77 == move.source.colRow);
   assertUnit(0x77 == move.dest.colRow);
   assertUnit(KNIGHT == move.promote);
   assertUnit(BISHOP == move.capture);
   assertUnit(Move::MOVE_ERROR == move.moveType);
   assertUnit(false == move.isWhite);
   // teardown
}

/*************************************
 * PIECE TYPE FROM LETTER bishop
 * Input : 'b'
 * Output:  BISHOP
 **************************************/
void TestMove::pieceTypeFromLetter_bishop()
{
   // setup
   Move move;
   move.source.colRow = 0x77;
   move.dest.colRow = 0x77;
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.moveType = Move::MOVE_ERROR;
   move.isWhite = false;
   move.text = "ERROR";
   // exercise
   PieceType pt = move.pieceTypeFromLetter('b');
   // verify
   assertUnit(pt == BISHOP);
   assertUnit(0x77 == move.source.colRow);
   assertUnit(0x77 == move.dest.colRow);
   assertUnit(KNIGHT == move.promote);
   assertUnit(BISHOP == move.capture);
   assertUnit(Move::MOVE_ERROR == move.moveType);
   assertUnit(false == move.isWhite);
   // teardown
}

/*************************************
 * PIECE TYPE FROM LETTER knight
 * Input : 'n'
 * Output:  KNIGHT
 **************************************/
void TestMove::pieceTypeFromLetter_knight()
{
   // setup
   Move move;
   move.source.colRow = 0x77;
   move.dest.colRow = 0x77;
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.moveType = Move::MOVE_ERROR;
   move.isWhite = false;
   move.text = "ERROR";
   // exercise
   PieceType pt = move.pieceTypeFromLetter('n');
   // verify
   assertUnit(pt == KNIGHT);
   assertUnit(0x77 == move.source.colRow);
   assertUnit(0x77 == move.dest.colRow);
   assertUnit(KNIGHT == move.promote);
   assertUnit(BISHOP == move.capture);
   assertUnit(Move::MOVE_ERROR == move.moveType);
   assertUnit(false == move.isWhite);
   // teardown
}

/*************************************
 * PIECE TYPE FROM LETTER rook
 * Input : 'r'
 * Output:  ROOK
 **************************************/
void TestMove::pieceTypeFromLetter_rook()
{
   // setup
   Move move;
   move.source.colRow = 0x77;
   move.dest.colRow = 0x77;
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.moveType = Move::MOVE_ERROR;
   move.isWhite = false;
   move.text = "ERROR";
   // exercise
   PieceType pt = move.pieceTypeFromLetter('r');
   // verify
   assertUnit(pt == ROOK);
   assertUnit(0x77 == move.source.colRow);
   assertUnit(0x77 == move.dest.colRow);
   assertUnit(KNIGHT == move.promote);
   assertUnit(BISHOP == move.capture);
   assertUnit(Move::MOVE_ERROR == move.moveType);
   assertUnit(false == move.isWhite);
   // teardown
}

/*************************************
 * PIECE TYPE FROM LETTER queen
 * Input : 'q'
 * Output:  QUEEN
 **************************************/
void TestMove::pieceTypeFromLetter_queen()
{
   // setup
   Move move;
   move.source.colRow = 0x77;
   move.dest.colRow = 0x77;
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.moveType = Move::MOVE_ERROR;
   move.isWhite = false;
   move.text = "ERROR";
   // exercise
   PieceType pt = move.pieceTypeFromLetter('q');
   // verify
   assertUnit(pt == QUEEN);
   assertUnit(0x77 == move.source.colRow);
   assertUnit(0x77 == move.dest.colRow);
   assertUnit(KNIGHT == move.promote);
   assertUnit(BISHOP == move.capture);
   assertUnit(Move::MOVE_ERROR == move.moveType);
   assertUnit(false == move.isWhite);
   // teardown
}

/*************************************
 * PIECE TYPE FROM LETTER king
 * Input : 'k'
 * Output:  KING
 **************************************/
void TestMove::pieceTypeFromLetter_king()
{
   // setup
   Move move;
   move.source.colRow = 0x77;
   move.dest.colRow = 0x77;
   move.promote = KNIGHT;
   move.capture = BISHOP;
   move.moveType = Move::MOVE_ERROR;
   move.isWhite = false;
   move.text = "ERROR";
   // exercise
   PieceType pt = move.pieceTypeFromLetter('k');
   // verify
   assertUnit(pt == KING);
   assertUnit(0x77 == move.source.colRow);
   assertUnit(0x77 == move.dest.colRow);
   assertUnit(KNIGHT == move.promote);
   assertUnit(BISHOP == move.capture);
   assertUnit(Move::MOVE_ERROR == move.moveType);
   assertUnit(false == move.isWhite);
   // teardown
}


/*************************************
 * EQUAL - NOT
 * Input : b2b4 == b2b5
 * Output: false
 **************************************/
void TestMove::equal_not()
{
   // setup
   Move move1("b2b4");
   Move move2("b2b5");

   // exercise
   bool result = (move1 == move2);

   // verify
   assertUnit(result == false);

   // teardown
}

/*************************************
 * EQUAL - EQUALS
 * Input : b2b4 == b2b4
 * Output: true
 **************************************/
void TestMove::equal_equals()
{
   // setup
   Move move1("b2b4");
   Move move2("b2b4");

   // exercise
   bool result = (move1 == move2);

   // verify
   assertUnit(result == true);

   // teardown
}

/*************************************
 * LESS THAN - LESS THAN
 * Input : b2b2 < b2b4
 * Output: false
 *    Note that the less-than operator is needed
 *    so std::set<T> can sort the elements. Thus,
 *    any T in a set must define less-than. In this
 *    case, I defined it according to the
 *     destination's Position's location.
 **************************************/
void TestMove::lessthan_lessthan()
{
   // setup
   Move move1("b2b2");
   Move move2("b2b4");
   //cout<< "lessthan " <<endl;
   // exercise
   bool result = (move1 < move2);

   // verify

   assertUnit(result == false);

   // teardown
}

/*************************************
 * LESS THAN - EQUALS
 * Input : b2b4 < b2b4
 * Output: false
 **************************************/
void TestMove::lessthan_equals()
{
   // setup
   Move move1("b2b4");
   Move move2("b2b4");

   // exercise
   bool result = (move1 < move2);

   // verify
   assertUnit(result == false);

   // teardown
}

/*************************************
 * LESS THAN - GREATAER THAN
 * Input : b2b4 < b2b2
 * Output: false
 **************************************/
void TestMove::lessthan_greaterthan()
{
   // setup
   Move move1("b2b4");
   Move move2("b2b2");

   // exercise
   bool result = (move1 < move2);

   // verify
   assertUnit(result == false);

   // teardown
}
