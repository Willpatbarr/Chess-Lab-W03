/***********************************************************************
 * Source File:
 *    MOVE
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#include "move.h"
#include "pieceType.h"
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

/***************************************************
 * MOVE : DEFAULT CONSTRUCTOR
 ***************************************************/
Move::Move()
{
   dest = INVALID;
   source = INVALID;
}

Move::Move(string s)
{
   read(s);

}

void Move::read(string s)
{
   if (s.length() == 4 || s.length() == 5)
   {
      source = s.substr(0, 2);
      dest = s.substr(2, 2);
   }

   if (s.length() == 4)
   {
      moveType = MOVE;
   }
   else if (s.length() == 5)
   {
      char special = s[4];
      switch (special)
      {
      case 'E':
         moveType = ENPASSANT;
         break;
      case 'c':
         moveType = CASTLE_KING;
         break;
      case 'C':
         moveType = CASTLE_QUEEN;
         break;
      default:
         moveType = MOVE;
         capture = pieceTypeFromLetter(special);
         break;
      }
   }
}


string Move::getText() const
{
   string result;

   if (source.isValid())
   {
      char colChar = 'a' + source.getCol();
      char rowChar = '1' + source.getRow();
      result += colChar;
      result += rowChar;
   }
   else
   {
      result += "source not valid";
   }

   if (dest.isValid())
   {
      char colChar = 'a' + dest.getCol();
      char rowChar = '1' + dest.getRow();
      result += colChar;
      result += rowChar;
   }
   else
   {
      result += "dest not valid";
   }

   switch (moveType)
   {
   case ENPASSANT:
      result += 'E';
      break;
   case CASTLE_KING:
      result += 'c';
      break;
   case CASTLE_QUEEN:
      result += 'C';
      break;
   case MOVE:
      if (letterFromPieceType(capture) != ' ')
      {
         result += letterFromPieceType(capture);
      }
      break;

   default:
      break;
   }

   return result;
}


void Move::operator=(const string& s)
{
   read(s);
}



bool Move::operator<(const Move& rhs) const {
   if (dest.getRow() < rhs.dest.getRow())
   {

      return false;
   }
   else if (dest.getRow() == rhs.dest.getRow())
   {
      if (dest.getCol() != rhs.dest.getCol())
      {
         cout << 2 << endl;

         return dest.getCol() < rhs.dest.getCol();
      }
      else if (source.getRow() < rhs.source.getRow())
      {
         cout << 3 << endl;

         return true;
      }
      else if (source.getRow() == rhs.source.getRow() &&
      source.getCol() < rhs.source.getCol())
      {
         cout << 4 << endl;

         return true;
      }
   }
   return false;
}

bool Move::operator==(const Move& rhs) const
{
   return source == rhs.source && dest == rhs.dest;
}

char Move::letterFromPieceType(PieceType pt) const
{
   switch (pt)
   {
   case PAWN:   return 'p';
   case ROOK:   return 'r';
   case KNIGHT: return 'n';
   case BISHOP: return 'b';
   case QUEEN:  return 'q';
   case KING:   return 'k';
   case SPACE:  return ' ';
   default:     return ' ';
   }
}

PieceType Move::pieceTypeFromLetter(char letter) const
{
   switch (letter)
   {
   case 'p': return PAWN;
   case 'r': return ROOK;
   case 'n': return KNIGHT;
   case 'b': return BISHOP;
   case 'q': return QUEEN;
   case 'k': return KING;
   case ' ': return SPACE;
   default:  return SPACE;
   }
}





