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
   Move move;
   //verify
   assertUnit(move.source == INVALID);
   assertUnit(move.dest == INVALID);
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
{
   //setup
   //exercise
   Move move("e5e6");

   //verify
   assertUnit(move.source.getCol() == 4);
   assertUnit(move.source.getRow() == 4);
   assertUnit(move.dest.getCol() == 4);
   assertUnit(move.dest.getRow() == 5);
   assertUnit(move.moveType == Move::MoveType::MOVE);

   //teardown
}

/*************************************
 * READ simple move
 * Input:  e5e6
 * Output: source=4,4
 *         dest  =4,5
 *         type  =MOVE
 **************************************/
void TestMove::read_simple()
{

   //setup
   Move m;

   //exercise
   m.read("e5e6");


   //verify
   assertUnit(m.source.getRow() == 4);
   assertUnit(m.source.getCol() == 4);
   assertUnit(m.dest.getCol() == 4);
   assertUnit(m.dest.getRow() == 5);
   assertUnit(m.moveType == Move::MoveType::MOVE);
   //teardown

}

/*************************************
 * READ capture move
 * Input:  e5d6r
 * Output: source=4,4
 *         dest  =3,5
 *         type  =MOVE
 *         capture=ROOK
 **************************************/
void TestMove::read_capture()
{
   //setup
   Move m;
   //exercise

   m.read("e5d6r");


   //verify
   assertUnit(m.source.getRow() == 4);
   assertUnit(m.source.getCol() == 4);
   assertUnit(m.dest.getCol() == 3);
   assertUnit(m.dest.getRow() == 5);
   assertUnit(m.moveType == Move::MoveType::MOVE);
   assertUnit(m.capture == ROOK);
   //teardown
}

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
{
   // setup
   string moveText = "e5e6";

   // exercise
   Move move;
   move = moveText;

   // verify
   assertUnit(move.source.getCol() == 4);
   assertUnit(move.source.getRow() == 4);
   assertUnit(move.dest.getCol() == 4);
   assertUnit(move.dest.getRow() == 5);
   assertUnit(move.moveType == Move::MOVE);
   // teardown

}

/*************************************
 * ASSIGN capture move
 * Input:  e5d6r
 * Output: source=4,4
 *         dest  =3,5
 *         type  =MOVE
 *         capture=ROOK
 **************************************/
void TestMove::assign_capture()
{
   // setup
   string moveText = "e5d6r";

   // exercise
   Move move;
   move = moveText;

   // verify
   assertUnit(move.source.getCol() == 4);
   assertUnit(move.source.getRow() == 4);
   assertUnit(move.dest.getCol() == 3);
   assertUnit(move.dest.getRow() == 5);
   assertUnit(move.moveType == Move::MOVE);
   assertUnit(move.capture == ROOK);
   // teardown

}

/*************************************
 * ASSIGN enpassant move
 * Input:  e5f6E
 * Output: source=4,4
 *         dest  =5,5
 *         type  =ENPASSANT
 **************************************/
void TestMove::assign_enpassant()
{
   // setup
   string moveText = "e5f6E";

   // exercise
   Move move;
   move = moveText;

   // verify
   assertUnit(move.source.getCol() == 4);
   assertUnit(move.source.getRow() == 4);
   assertUnit(move.dest.getCol() == 5);
   assertUnit(move.dest.getRow() == 5);
   assertUnit(move.moveType == Move::ENPASSANT);

   // teardown
}

/*************************************
 * ASSIGN king side castle
 * Input:  e1g1c
 * Output: source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 **************************************/
void TestMove::assign_castleKing()
{
   // setup
   string moveText = "e1g1c";

   // exercise
   Move move;
   move = moveText;

   // verify
   assertUnit(move.source.getCol() == 4);
   assertUnit(move.source.getRow() == 0);
   assertUnit(move.dest.getCol() == 6);
   assertUnit(move.dest.getRow() == 0);
   assertUnit(move.moveType == Move::CASTLE_KING);

   // teardown
}

/*************************************
 * ASSIGN queen side castle
 * Input:  e1c1C
 * Output: source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 **************************************/
void TestMove::assign_castleQueen()
{
   // setup
   string moveText = "e1c1C";

   // exercise
   Move move;
   move = moveText;

   // verify
   assertUnit(move.source.getCol() == 4);
   assertUnit(move.source.getRow() == 0);
   assertUnit(move.dest.getCol() == 2);
   assertUnit(move.dest.getRow() == 0);
   assertUnit(move.moveType == Move::CASTLE_QUEEN);

   // teardown
}

/*************************************
 * GET TEXT simple move
 * Input : source=4,4
 *         dest  =4,5
 *         type  =MOVE
 * Output:  e5e6
 **************************************/
void TestMove::getText_simple()
{
   // setup
   Move move;
   move.source.set(4, 4);
   //move.source.colRow = 4,4;
   move.dest.set(4, 5);
   move.moveType = Move::MOVE;

   // exercise
   string result = move.getText();

   // verify
   assertUnit(result == "e5e6");
   // teardown
}

/*************************************
 * GET TEXT capture
 * Input : source=4,4
 *         dest  =4,5
 *         type  =MOVE
 *         capture=ROOK
 * Output:  e5e6r
 **************************************/
void TestMove::getText_capture()
{
   // setup
   Move move;
   move.source.set(4, 4);
   move.dest.set(4, 5);
   move.moveType = Move::MOVE;
   move.capture = ROOK;

   // exercise
   string result = move.getText();

   // verify
   assertUnit(result == "e5e6r");

   // teardown
}

/*************************************
 * GET TEXT en passant
 * Input : source=4,4
 *         dest  =5,5
 *         type  =ENPASSANT
 *         capture=PAWN
 * Output:  e5f6E
 **************************************/
void TestMove::getText_enpassant()
{
   // setup
   Move move;
   move.source.set(4, 4);
   move.dest.set(5, 5);
   move.moveType = Move::ENPASSANT;
   move.capture = PAWN;

   // exercise
   string result = move.getText();

   // verify
   assertUnit(result == "e5f6E");

   // teardown
}

/*************************************
 * GET TEXT king side castle
 * Input : source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 * Output:  e1g1c
 **************************************/
void TestMove::getText_castleKing()
{
   // setup
   Move move;
   move.source.set(4, 0);
   move.dest.set(6, 0);
   move.moveType = Move::CASTLE_KING;

   // exercise
   string result = move.getText();

   // verify
   assertUnit(result == "e1g1c");

   // teardown
}

/*************************************
 * GET TEXT queen side castle
 * Input : source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 * Output:  e1c1C
 **************************************/
void TestMove::getText_castleQueen()
{
   // setup
   Move move;
   move.source.set(4, 0);
   move.dest.set(2, 0);
   move.moveType = Move::CASTLE_QUEEN;

   // exercise
   string result = move.getText();

   // verify
   assertUnit(result == "e1c1C");

   // teardown
}

/*************************************
 * LETTER FROM PIECE TYPE space
 * Input :  SPACE
 * Output:  ' '
 **************************************/
void TestMove::letterFromPieceType_space()
{
   // setup
   Move move;

   // exercise
   char result = move.letterFromPieceType(SPACE);

   // verify
   assertUnit(result == ' ');

   // teardown
}

/*************************************
 * LETTER FROM PIECE TYPE pawn
 * Input : PAWN
 * Output:  'p'
 **************************************/
void TestMove::letterFromPieceType_pawn()
{
   // setup
   Move move;

   // exercise
   char result = move.letterFromPieceType(PAWN);

   // verify
   assertUnit(result == 'p');

   // teardown
}

/*************************************
 * LETTER FROM PIECE TYPE bishop
 * Input : BISHOP
 * Output:  'b'
 **************************************/
void TestMove::letterFromPieceType_bishop()
{
   // setup
   Move move;

   // exercise
   char result = move.letterFromPieceType(BISHOP);

   // verify
   assertUnit(result == 'b');

   // teardown
}

/*************************************
 * LETTER FROM PIECE TYPE knight
 * Input : KNIGHT
 * Output:  'n'
 **************************************/
void TestMove::letterFromPieceType_knight()
{
   // setup
   Move move;

   // exercise
   char result = move.letterFromPieceType(KNIGHT);

   // verify
   assertUnit(result == 'n');

   // teardown
}

/*************************************
 * LETTER FROM PIECE TYPE rook
 * Input : ROOK
 * Output:  'r'
 **************************************/
void TestMove::letterFromPieceType_rook()
{
   // setup
   Move move;

   // exercise
   char result = move.letterFromPieceType(ROOK);

   // verify
   assertUnit(result == 'r');

   // teardown
}

/*************************************
 * LETTER FROM PIECE TYPE queen
 * Input : QUEEN
 * Output:  'q'
 **************************************/
void TestMove::letterFromPieceType_queen()
{
   // setup
   Move move;

   // exercise
   char result = move.letterFromPieceType(QUEEN);

   // verify
   assertUnit(result == 'q');

   // teardown
}

/*************************************
 * LETTER FROM PIECE TYPE king
 * Input : KING
 * Output:  'k'
 **************************************/
void TestMove::letterFromPieceType_king()
{
   // setup
   Move move;


   // exercise
   char result = move.letterFromPieceType(KING);

   // verify
   assertUnit(result == 'k');

   // teardown
}

/*************************************
 * PIECE TYPE FROM LETTER pawn
 * Input : 'p'
 * Output:  PAWN
 **************************************/
void TestMove::pieceTypeFromLetter_pawn()
{
   // setup
   Move move;

   // exercise
   PieceType result = move.pieceTypeFromLetter('p');

   // verify
   assertUnit(result == PAWN);

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

   // exercise
   PieceType result = move.pieceTypeFromLetter('b');

   // verify
   assertUnit(result == BISHOP);

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

   // exercise
   PieceType result = move.pieceTypeFromLetter('n');

   // verify
   assertUnit(result == KNIGHT);

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

   // exercise
   PieceType result = move.pieceTypeFromLetter('r');

   // verify
   assertUnit(result == ROOK);

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

   // exercise
   PieceType result = move.pieceTypeFromLetter('q');

   // verify
   assertUnit(result == QUEEN);

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

   // exercise
   PieceType result = move.pieceTypeFromLetter('k');

   // verify
   assertUnit(result == KING);

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

   //cout << (move1 < move2) << " less ";
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
