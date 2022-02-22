/*  
 * 
 * --------------------------------classic.cpp --------------------------------------------
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
#include "classic.h"

// ------------------------------------constructor------------------------------------------------
// constructor 
// -------------------------------------------------------------------------------------------
Classic::Classic(){}

// ------------------------------------destructor------------------------------------------------
// destructor 
// -------------------------------------------------------------------------------------------
Classic::~Classic(){}

// ------------------------------------copy constructor------------------------------------------------
// copy constructor 
// -------------------------------------------------------------------------------------------
Classic::Classic(const Classic &rhs) 
{
this->stock = rhs.stock;
this->director = rhs.director;
this->title = rhs.title;
this->majorActor= rhs.majorActor;
this->releaseMonth = rhs.releaseMonth;
}

// ------------------------------------getMajorActor------------------------------------------
// getter for major actor name
// -------------------------------------------------------------------------------------------
const string & Classic::getMajorActor() const{
    return majorActor;
}

// ------------------------------------setMajorActor------------------------------------------
// setter for major actor name
// -------------------------------------------------------------------------------------------
void Classic::setMajorActor(const string & name)
{
    majorActor = name;
}

// ------------------------------------getMonth-----------------------------------------------
// getter for return release months
// -------------------------------------------------------------------------------------------
int Classic::getReleaseMonth() const {
    return releaseMonth;
}
// ------------------------------------setMonth-----------------------------------------------
// setter for release month
// -------------------------------------------------------------------------------------------
void Classic::setReleaseMonth(int month)
{
    this->releaseMonth = month;
}

// ------------------------------------isEqual------------------------------------------------
// return whether two classic movies is equal to each other or not 
// -------------------------------------------------------------------------------------------
bool Classic::isEqual(const Classic &mov) const
{
    return mov.getYear() == year && mov.getMajorActor().compare(majorActor) == 0 &&         mov.getReleaseMonth() == releaseMonth;
}

// ------------------------------------isGreater----------------------------------------------
// return whether one classics object is greater than another or not 
// -------------------------------------------------------------------------------------------
bool Classic::isGreater(const Classic &mov) const
{
    if (year != mov.getYear())
        return year > mov.getYear();

    if (releaseMonth != mov.getReleaseMonth())
        return releaseMonth > mov.getReleaseMonth();

    return majorActor.compare(mov.getMajorActor()) > 0;
}

//------------------------------------print--------------------------------------------------
// print the movie information 
// -------------------------------------------------------------------------------------------
void Classic::print() const
{
    cout << "C, " << stock << ", " << director << ", " << title <<
    ", " << majorActor << " " << releaseMonth << " " << year << endl;
}

// ------------------------------------getMovieType-------------------------------------------
// getter for return movie type 
// -------------------------------------------------------------------------------------------
MovieType Classic::getMovieType() const
{
    return ClassicType;
}


// -------------------------------Operator Overloading----------------------------------------
// -------------------------------------------------------------------------------------------
bool Classic::operator==(const Classic &mov) const 
{
    return mov.getYear() == year &&
           mov.getMajorActor().compare(majorActor) == 0 &&
           mov.getReleaseMonth() == releaseMonth;
}

bool Classic::operator!=(const Classic &rhs) const 
{
    if ( getMovieType() != rhs.getMovieType() || title != rhs.title || year != rhs.year || stock != rhs.stock || director != rhs.director ) {
        return true;
    }
    return false;
}

bool Classic::operator<(const Classic &rhs) const 
{
    if ( getMovieType() != rhs.getMovieType() && title < rhs.title && year < rhs.year && stock < rhs.stock && director < rhs.director ) 
    {
        return true;
    }
    return false;
}

bool Classic::operator>(const Classic &mov) const 
{
    if (year != mov.getYear())
        return year > mov.getYear();

    if (releaseMonth != mov.getReleaseMonth())
        return releaseMonth > mov.getReleaseMonth();

    return majorActor.compare(mov.getMajorActor()) > 0;
}

