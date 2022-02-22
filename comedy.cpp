/*  
 * 
 * --------------------------------comedy.cpp --------------------------------------------
 * CSS343 Assignment 4
 * Student Name: Eunsol Cho & Eunmi Lee
 * Student ID: 1920609, 2076383
 * Student e-mail: echo2@uw.edu, eunmi@uw.edu
 * Creation Date: 5/20/2021 
 * Date of Last Modification: 6/9/2021
 * -------------------------------------------------------------------------------------
 * The purpose of this class is generate comedy type of movies 
 * -------------------------------------------------------------------------------------
 * The assumption of this project is correct formatting, but codes may be invalid; e.g., in this data, the 'Z' code is an invalid entry so this line has to be discarded and users should be notified about this issue. 
 * -------------------------------------------------------------------------------------
 */

#include "comedy.h"

// ------------------------------------constructor------------------------------------------------
// constructor 
// -----------------------------------------------------------------------------------------------
Comedy::Comedy() {}

// ------------------------------------copy constructor-------------------------------------------
// copy constructor 
// -----------------------------------------------------------------------------------------------
Comedy::Comedy(const Comedy &rhs) 
{
  this->stock = rhs.stock;
  this->director = rhs.director;
  this->title = rhs.title;
  this->year = rhs.year;
}

// ------------------------------------destructor------------------------------------------------
// destructor 
// ----------------------------------------------------------------------------------------------
Comedy::~Comedy() {}

// ------------------------------------print--------------------------------------------------
// print the movie information 
// -------------------------------------------------------------------------------------------
void Comedy::print() const
{
  cout << "F, " << stock << ", " << director << ", " << title << ", " << year << endl;
}

// ------------------------------------isEqual------------------------------------------------
// return whether two classic movies is equal to each other or not 
// -------------------------------------------------------------------------------------------
bool Comedy::isEqual(const Comedy &node) const
{
  return node.getTitle().compare(title) == 0 && node.getYear() == year;
}

// ------------------------------------isGreater----------------------------------------------
// return whether one classics object is greater than another or not 
// -------------------------------------------------------------------------------------------
bool Comedy::isGreater(const Comedy &node) const
{
  if (title.compare(node.getTitle()) != 0)
  {
    return title.compare(node.getTitle()) > 0;
  }
  return year > node.getYear();
}

// ------------------------------------getMovieType-------------------------------------------
// getter for movie type
// -------------------------------------------------------------------------------------------
MovieType Comedy::getMovieType() const
{
  return MovieType::ComedyType;
}

// -------------------------------Operator Overloading----------------------------------------
// -------------------------------------------------------------------------------------------

bool Comedy::operator==(const Comedy &rhs) const 
{
  if ( getMovieType() != rhs.getMovieType() || title != rhs.title || year != rhs.year || stock != rhs.stock || director != rhs.director ) 
  {
    return false;
  }
  return true;
}

bool Comedy::operator!=(const Comedy &rhs) const 
{
  if ( getMovieType() != rhs.getMovieType() || title != rhs.title || year != rhs.year || stock != rhs.stock || director != rhs.director ) 
  {
    return true;
  }
  return false;
}

bool Comedy::operator<(const Comedy &rhs) const 
{
  if ( getMovieType() < rhs.getMovieType() && title < rhs.title && year < rhs.year && stock < rhs.stock && director < rhs.director ) 
  {
    return true;
  }
  return false;
}

bool Comedy::operator>(const Comedy &rhs) const 
{
  if ( getMovieType() > rhs.getMovieType() && title > rhs.title && year > rhs.year && stock > rhs.stock && director > rhs.director ) 
  {
    return true;
  }
  return false;
}

// ------------------------------------setData-------------------------------------------
// read comedy movie file 
// -------------------------------------------------------------------------------------------
bool Comedy::setData(istream& inFile) 
{
  if (inFile.eof())
  {
    return false;
  }
  int movieYear;
  inFile >> movieYear;
  setYear(movieYear);
  
  return true;
}