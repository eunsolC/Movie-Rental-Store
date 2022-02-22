/*  
 * 
 * --------------------------------classic.h --------------------------------------------
 * CSS343 Assignment 4
 * Student Name: Eunsol Cho & Eunmi Lee
 * Student ID: 1920609, 2076383
 * Student e-mail: echo2@uw.edu, eunmi@uw.edu
 * Creation Date: 5/20/2021 
 * Date of Last Modification: 6/9/2021
 * -------------------------------------------------------------------------------------
 * The purpose of this class is generate classic type of movies 
 * -------------------------------------------------------------------------------------
 * The assumption of this project is correct formatting, but codes may be invalid; e.g., in this data, the 'Z' code is an invalid entry so this line has to be discarded and users should be notified about this issue. 
 * -------------------------------------------------------------------------------------
 */
#ifndef ASSIGNMENT_4_CLASSIC_H
#define ASSIGNMENT_4_CLASSIC_H
#include "movie.h"

class Classic : public Movie 
{
public:
  Classic(); // constructor
  virtual ~Classic(); // destructor
  Classic(const Classic &rhs); // copy constructor
  int getReleaseMonth() const; // getter for releasemonth 
  void setReleaseMonth(int year); // setter for releasemonth 
  virtual const string & getMajorActor() const; // getter for actor
  virtual void setMajorActor(const string & name); // setter for actor 
  virtual bool isEqual(const Classic &mov) const; // compare two movies if they are equal
  virtual bool isGreater(const Classic &mov) const; // compare two movies if greater 
  virtual MovieType getMovieType() const; // getter for return movie type 
  void print() const; // display purpose 

  // -------------Operator Overloading--------------------------
  bool operator==(const Classic &rhs)const;
  bool operator!=(const Classic &rhs)const;
  bool operator<(const Classic &rhs) const;
  bool operator>(const Classic &rhs) const;

private:
  string majorActor; // name of actor 
  int releaseMonth; // releaseMonth 
};

#endif