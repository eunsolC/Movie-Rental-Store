/*
 * 
 * --------------------------------movie.h --------------------------------------------
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

#ifndef ASSIGNMENT_4_MOVIE_H
#define ASSIGNMENT_4_MOVIE_H
#include <iostream>

using namespace std;

enum MovieType
{
  ComedyType,
  DramaType,
  ClassicType
};

class Movie {

  friend ostream &operator<<(ostream &outStream, const Movie &rhs);

public:

  Movie(); // constructor
  virtual ~Movie(); // destructor
  Movie(const Movie *&); // copy constructor

  virtual int  getStock() const; // getter for stock
  virtual void setStock(int); // setter for stock

  virtual const string & getTitle() const; // getter for title
  virtual void setTitle(string); //setter for title

  virtual const string & getDirector() const; // getter for director
  virtual void setDirector(const string&); //setter for director


  virtual int getYear() const; //getter the year when the movie was made
  virtual void setYear(int); //setter the year when the movie was made

  virtual MovieType getMovieType() const = 0;

  // check operator for two movies
  virtual bool operator==(const Movie &rhs) const;

  virtual bool operator!=(const Movie &rhs) const;

  virtual bool operator<(const Movie &rhs) const;

  virtual bool operator>(const Movie &rhs) const;

protected:
  string title; //title of the movie 
  string director; //name of the director
  int year; //the year the movie was made
  int stock; //number of stock
  
};


#endif 