/*
 * 
 * --------------------------------movie.cpp --------------------------------------------
 * CSS343 Assignment 4
 * Student Name: Eunsol Cho & Eunmi Lee
 * Student ID: 1920609, 2076383
 * Student e-mail: echo2@uw.edu, eunmi@uw.edu
 * Creation Date: 5/20/2021 
 * Date of Last Modification: 6/9/2021
 * -------------------------------------------------------------------------------------
 * The purpose of this class is to get and set movie information 
 * -------------------------------------------------------------------------------------
 * The assumption of this project is correct formatting, but codes may be invalid; e.g., in this data, the 'Z' code is an invalid entry so this line has to be discarded and users should be notified about this issue. 
 * -------------------------------------------------------------------------------------
 */

#include "movie.h"

// ------------------------------------constructor---------------------------------------------
// constructor
// -------------------------------------------------------------------------------------------
Movie::Movie() 
{
  stock = 0;
  title = "";
  director = "";
  year = 0;
}

// ------------------------------------destructor-----------------------------------------------
// destructor
// -------------------------------------------------------------------------------------------
Movie::~Movie() 
{

};

// ------------------------------------copy constructor---------------------------------------------
// copy constructor
// -------------------------------------------------------------------------------------------
Movie::Movie(const Movie *&rhs) 
{
  this->title = rhs->title;
  this->year = rhs->year;
  this->director = rhs->director;
  this->stock = rhs->stock;
}


// ------------------------------------getTitle-----------------------------------------------
// return movie title
// -------------------------------------------------------------------------------------------
const string & Movie::getTitle() const 
{
  return title;
}

// ------------------------------------setTitle-----------------------------------------------
// set movie title
// -------------------------------------------------------------------------------------------
void Movie::setTitle(string newTitle) 
{
  this->title = newTitle;
}

// ------------------------------------getYear------------------------------------------------
// return movie year
// -------------------------------------------------------------------------------------------
int Movie::getYear() const 
{
  return year;
}

// ------------------------------------setYear------------------------------------------------
// set movie year
// -------------------------------------------------------------------------------------------
void Movie::setYear(int newYear) 
{
  this->year = newYear;
}

// ------------------------------------getDirector--------------------------------------------
// return director's name
// -------------------------------------------------------------------------------------------
const string & Movie::getDirector() const 
{
  return director;
}

// ------------------------------------setStock--------------------------------------------
// getter for the type of the movie
//-------------------------------------------------------------------------------------------
void Movie::setStock(int newStock) 
{
  this->stock = newStock;
}

// ------------------------------------getStock--------------------------------------------
// getter for the type of the movie
//-------------------------------------------------------------------------------------------
int Movie::getStock() const 
{
  return stock;
}

// ------------------------------------setDirector--------------------------------------------
// setter for director's name 
// -------------------------------------------------------------------------------------------
void Movie::setDirector(const string &newDirector) 
{
  this->director = newDirector;
}


//------------------------------  Operator Overloading Movie--------------------------------
bool Movie::operator==(const Movie &rhs) const 
{
  if ( title == rhs.title && year == rhs.year && stock == rhs.stock && director == rhs.director ) 
  {
    return true;
  }
  return false;
}

bool Movie::operator!=(const Movie &rhs) const 
{
  if ( title != rhs.title || year != rhs.year || stock != rhs.stock || director != rhs.director) 
  {
    return true;
  }
  return false;
}

bool Movie::operator<(const Movie &rhs) const 
{
  if ( title < rhs.title && year < rhs.year && stock < rhs.stock && director < rhs.director ) 
  {
    return true;
  }
  return false;
}

bool Movie::operator>(const Movie &rhs) const 
{
  if (title > rhs.title && year > rhs.year && stock > rhs.stock && director > rhs.director ) 
  {
    return true;
  }
  return false;
}

ostream &operator<<(ostream &outStream, const Movie &rhs) 
{
  return outStream << rhs.getMovieType() << ", " <<rhs.getStock()   << ", " << rhs.getDirector() << ", " << rhs.getTitle()<< ", " << rhs.getYear() << endl;
}