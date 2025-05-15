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

void Move::read(const string& rhs)
{
   if (rhs.length() == 4 || rhs.length() == 5)
   {
      source = rhs.substr(0, 2);
      dest = rhs.substr(2, 2);
   }

   if (rhs.length() == 4)
   {
      moveType = MOVE;
   }
   else if (rhs.length() == 5)
   {
      char special = rhs[4];
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

