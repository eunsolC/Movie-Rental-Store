/*  
 * 
 * --------------------------------drama.cpp --------------------------------------------
 * CSS343 Assignment 4
 * Student Name: Eunsol Cho & Eunmi Lee
 * Student ID: 1920609, 2076383
 * Student e-mail: echo2@uw.edu, eunmi@uw.edu
 * Creation Date: 5/20/2021 
 * Date of Last Modification: 6/9/2021
 * -------------------------------------------------------------------------------------
 * The purpose of this class is generate drama type of movies 
 * -------------------------------------------------------------------------------------
 * The assumption of this project is correct formatting, but codes may be invalid; e.g., in this data, the 'Z' code is an invalid entry so this line has to be discarded and users should be notified about this issue. 
 * -------------------------------------------------------------------------------------
 */
 
#include "drama.h"

// ------------------------------------constructor------------------------------------------------
// constructor 
// -------------------------------------------------------------------------------------------
Drama::Drama(){}

// -------------------------------------destructor-----------------------------------------------
// destructor 
// -------------------------------------------------------------------------------------------
Drama::~Drama(){}

// ------------------------------------isEqual----------------------------------------------
// return whether two classic movies is equal to each other or not 
// -------------------------------------------------------------------------------------------
bool Drama::isEqual(const Drama &mov) const
{
  return mov.getDirector().compare(director) == 0 && mov.getTitle().compare(title) == 0;
}

// ------------------------------------isGreater----------------------------------------------
// return whether one classics object is greater than another or not 
// -------------------------------------------------------------------------------------------
bool Drama::isGreater(const Drama &mov) const
{
  if (director.compare(mov.getDirector()) != 0)
  {
    return director.compare(mov.getDirector()) > 0;
  }

  if (title.compare(mov.getTitle()) != 0)
  {
    return title.compare(mov.getTitle()) > 0;
  }
  return year > mov.getYear();
}

// ------------------------------------getMovieType-------------------------------------------
// getter for movie type 
// -------------------------------------------------------------------------------------------
MovieType Drama::getMovieType() const 
{
  return MovieType::DramaType;
}

// ------------------------------------print--------------------------------------------------
// print for movie information 
// -------------------------------------------------------------------------------------------
void Drama::print() const
{
  cout << "D, " << stock << ", " << director << ", " << title << ", " << year << endl;
}

// -------------------------------Operator Overloading----------------------------------------
// -------------------------------------------------------------------------------------------
bool Drama::operator==(const Drama &rhs) const 
{
  if ( getMovieType() != rhs.getMovieType() || title != rhs.title || year != rhs.year || stock != rhs.stock || director != rhs.director ) 
  {
    return false;
  }
  return true;
}

bool Drama::operator!=(const Drama &rhs) const 
{
  if ( getMovieType() != rhs.getMovieType()|| title != rhs.title || year != rhs.year || stock != rhs.stock || director != rhs.director ) 
  {
    return true;
  }
  return false;
}

bool Drama::operator<(const Drama &rhs) const 
{
  if ( getMovieType() != rhs.getMovieType()&& title < rhs.title && year < rhs.year && stock < rhs.stock && director < rhs.director ) 
  {
    return true;
  }
  return false;
}

bool Drama::operator>(const Drama &rhs) const 
{
  if ( getMovieType() != rhs.getMovieType() && title > rhs.title && year > rhs.year && stock > rhs.stock && director > rhs.director ) 
  {
    return true;
  }
  return false;
}