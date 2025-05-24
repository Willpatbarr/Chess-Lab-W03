/***********************************************************************
 * Header File:
 *    POSITION
 * Author:
 *    <your name here>
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 ************************************************************************/

#pragma once

#include <string>
#include <cstdint>
using std::string;
using std::ostream;
using std::istream;

const int SIZE_SQUARE = 32;   // number of pixels in a square by default

/***********************************************
 * DELTA
 * Movement in a direction (dRow and dCol)
 **********************************************/
struct Delta
{
   int dRow;
   int dCol;
};

const Delta ADD_R = { 1,  0 };
const Delta ADD_C = { 0,  1 };
const Delta SUB_R = { -1,  0 };
const Delta SUB_C = { 0, -1 };


class PositionTest;

/***************************************************
 * POSITION
 * The location of a piece on the board
 ***************************************************/
class Position
{

   friend class PositionTest;
   friend class TestBoard;
   friend class TestKnight;
   friend class TestKing;
   friend class TestMove;
   friend class TestPawn;
   friend class TestRook;
   friend class TestQueen;

   friend class TestBishop;

public:

   // Position :    The Position class can work with other positions,
   //               Allowing for comparisions, copying, etc.
   Position(const Position& rhs): colRow(0)
   {
      set(rhs.colRow);
   }
   Position() : colRow(0xff) {set(0xff); }
   bool isInvalid() const 
   { 
      return (colRow & 0x88) ? true : false; 
   }
   bool isValid()   const 
   { 
      return !isInvalid(); 
   }
   void setValid() 
   {
      if (isInvalid())
         set(0x00);
   }
   void setInvalid() 
   {
      set(0xff);
   }
   bool operator <  (const Position& rhs) const { return colRow < rhs.colRow; }
   bool operator > (const Position& rhs) const { return colRow > rhs.colRow; }
   bool operator == (const Position& rhs) const 
   {
      if (isInvalid())
         return rhs.isInvalid();
      else
         return rhs.colRow == colRow;
   }
   bool operator != (const Position& rhs) const 
   { 
   if (isInvalid())
      return rhs.isValid();
   else
      return rhs.colRow != colRow; 
   }
   const Position& operator =  (const Position& rhs)
   {
      set(rhs.colRow);

      return *this;
   }

   const Position& operator =  (const char * rhs)
   {
   if (rhs == NULL)
      set(0xff);
   else if (rhs[0] < 'a' || rhs[0] > 'h' ||
            rhs[1] < '1' || rhs[1] > '8')
      set(0xff);
   else
      set(rhs[0] - 'a', rhs[1] - '1');
   return *this;

   }
   const Position& operator = (const string& rhs)
   {
      parseText(rhs.c_str());

      return *this;
   }

   // Location : The Position class can work with locations, which
   //            are 0...63 where we start in row 0, then row 1, etc.
   Position(int location) : colRow(0xff) 
   {
      setLocation(location);
   }
   int getLocation() const 
   { 
      return getRow() * 8 + getCol(); 
   }
   void setLocation(int location) 
   {
      if(0<= location && location < 64)
         set(location % 8, location /8);
      else
         set(0xff);
   }


   // Row/Col : The position class can work with row/column,
   //           which are 0..7 and 0...7
   Position(int c, int r) : colRow(0x99) 
   {
      set(c,r);
   }
   virtual int getCol() const
   {
      return (isValid() ? (int)((colRow & 0xf0) >> 4) : -1);
   }
   virtual int getRow() const
   {
      return (isValid() ? (int)(colRow & 0x0f) : -1);
   }
   void setRow(int r);
   void setCol(int c);
   void set(int c, int r);

   // Text:    The Position class can work with textual coordinates,
   //          such as "d4"

   Position(const char* s) : colRow(0x00)
   {
      *this = s;
   }



   // Pixels:    The Position class can work with screen coordinates,
   //            a.k.a. Pixels, these are X and Y coordinates. Note that
   //            we need to scale them according to the size of the board.
   int getX()   const
   {
      return (int)((double)getCol() * getSquareWidth() + getSquareWidth());
   }
   int getY()   const
   {
      return (int)((double)getRow() * getSquareHeight() + getSquareHeight());
   }


   void setXY(double x, double y)
   {

         set((int)(x / getSquareWidth()) - 1,
            8 - (int)(y / getSquareHeight()));
      
   }


   double getSquareWidth()  const { return squareWidth; }
   double getSquareHeight() const { return squareHeight; }

   void setSquareHeight(double h)
   {
      if (h >0.0)
         squareHeight = h;
   }

   void setSquareWidth(double w)
   {
      if (w > 0.0)
         squareWidth = w;
   }

   void setBoardWidthHeight(int widthBoard, int heightBoard)
   {
      if (widthBoard < 0 || heightBoard < 0)
         return;
      squareWidth = (double)widthBoard / 10.0; // 8 squares + 2 spaces
      squareHeight = (double)heightBoard / 10.0;
   }

   // Delta:    The Position class can work with deltas, which are
   //           offsets from a given location. This helps pieces move
   //           on the chess board.
   Position(const Position& rhs, const Delta& delta) : colRow(-1) 
   {
      set(rhs.getCol() + delta.dCol, rhs.getRow() + delta.dRow);
   }
   void adjustRow(int dRow) 
   { 
      set(getCol(), getRow() + dRow); 
   }
   void adjustCol(int dCol) 
   {
      set(getCol() + dCol, getRow()); 
   }
   const Position& operator += (const Delta& rhs)
   {
      adjustRow(rhs.dRow);
      adjustCol(rhs.dCol); 
      return *this;
   }
   Position operator + (const Delta& rhs) const
   {
      Position result = *this;
      result += rhs; return result;
   } // this could be wrong ngl

private:
   void set(uint8_t colRowNew);
   void parseText(const char* s);

   uint8_t colRow;
   static double squareWidth;
   static double squareHeight;
};


ostream& operator << (ostream& out, const Position& pos);
istream& operator >> (istream& in, Position& pos);

