/***********************************************************************
 * Source File:
 *    POSITION
 * Author:
 *    <your name here>
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 ************************************************************************/

#include "position.h"
#include <iostream>

 /******************************************
  * PARSE TEXT
  * method to parse text into a colRow
  ******************************************/
void Position::parseText(const char* s)
{
   if (s == nullptr   // null pointer
      || s[0] < 'a'  // less than a
      || s[0] > 'h'  // greater than h
      || s[1] < '1'  // less than 1
      || s[1] > '8') // greater than 8
   {
      colRow = 0xff;  // invalid position hex code
   }
   else {
      int col = s[0] - 'a'; // subtracts the ASCII value of a to get the index
      int row = s[1] - '1'; // subtracts the ASCII value of 1 to get the index
      set((col << 4) | row);
   }
}
/******************************************
 * SETROW
 ******************************************/
void Position::setRow(int r) 
{
   if (r >= 0 && r < 8) 
      set((colRow & 0xf0) + (char)r);
   else
      set(0xff);
}

/******************************************
 * SETCOL
 ******************************************/
void Position::setCol(int c) 
{
   if (c >= 0 && c < 8)
      set((colRow & 0x0f) + ((char)c << 4));
   else
      set(0xff);
}


/******************************************
 * SET
 * uses two ints
 ******************************************/
void Position::set(int c, int r) 
{
   setRow(r);
   setCol(c);
   
}

/******************************************
 * SET
 * uses the unsigned int instead of two ints
 ******************************************/
void Position::set(uint8_t colRowNew) {
   if (colRowNew & 0x88) {
      colRow = 0xff;
   }
   else {
      colRow = colRowNew;
   }
}

/******************************************
 * POSITION INSERTION OPERATOR
 ******************************************/
ostream& operator << (ostream& out, const Position& rhs)
{
   if (rhs.isValid())
      out << (char)(rhs.getCol() + 'a')
          << (char)(rhs.getRow() + '1');

   else
      out << "error";
   return out;
}

/*************************************
 * POSITION EXTRACTION OPERATOR
 **************************************/
istream& operator >> (istream& in, Position& rhs)
{
   char text[3] = {};
   in >> text[0] >> text[1];
   if (in.fail())
   {
      in.clear();
      in.ignore();
      throw string("Error reading coordinates!");
   }
   else
   {
      rhs = text;
   }

   return in;
}


