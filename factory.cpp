 /*
 * 
 * --------------------------------factory.cpp --------------------------------------------
 * CSS343 Assignment 4
 * Student Name: Eunsol Cho & Eunmi Lee
 * Student ID: 1920609, 2076383
 * Student e-mail: echo2@uw.edu, eunmi@uw.edu
 * Creation Date: 5/20/2021 
 * Date of Last Modification: 6/9/2021
 * -------------------------------------------------------------------------------------
 * The purpose of this class is generate read file, change stock, and display. 
 * -------------------------------------------------------------------------------------
 * The assumption of this project is correct formatting, but codes may be invalid; e.g., in this data, the 'Z' code is an invalid entry so this line has to be discarded and users should be notified about this issue. 
 * -------------------------------------------------------------------------------------
 */

#include "factory.h"
#include <fstream>
#include <sstream>

using namespace std;

// ----------------------------------constructor---------------------------------------
// constructor
// --------------------------------------------------------------------------------------
Factory::Factory() {}

// ----------------------------------destructor---------------------------------------
// destructor
// --------------------------------------------------------------------------------------
Factory::~Factory() {}


// ------------------------------------readCustomer------------------------------------------------
// read customer's file
// -------------------------------------------------------------------------------------------
bool Factory::readCustomer(string file) 
{
  ifstream inFile(file);
  if (!inFile.is_open())
  {
    cout << "File fail to open" << endl; // print error message 
    return false;
  }
  while (!inFile.eof())
  {
    if (!customer.setData(inFile))
    {
      return false;
    }  
  }
  return true;
}

// ------------------------------------readTransaction------------------------------------------------
// read transaction file
// -------------------------------------------------------------------------------------------
bool Factory::readTransaction(string file) 
{
  ifstream inFile(file);

  if (!inFile.is_open())
  {
    cout << "File fail to open" << endl; // print error message 
    return false;
  }
  string line;
  while (!inFile.eof())
  {
    processTransaction(inFile);
  }
  return true;
}

// ------------------------------------readMovie------------------------------------------------
// read movie file
// -------------------------------------------------------------------------------------------
bool Factory::readMovie(string file) 
{
  ifstream inFile(file);

  if (!inFile.is_open())
  {
    cout << "File fail to open" << endl; // print error message 
    return false;
  }
  movieInv.readMovieFile(file);
  return true;
}

// ------------------------------------processTransaction------------------------------------------------
// process transactions
// -------------------------------------------------------------------------------------------
bool Factory::processTransaction(istream& inFile) 
{
  int id;
  char type, movie, movieType;
  string title, tmp;
    
  inFile >> type;
  if (inFile.fail())
  {
    return false;
  }
  if (type != 'H' &&  type != 'B' &&type != 'R' && type != 'I')
  {
    getline(inFile, title);
    cout << "INVALID ACTION CODE" << type << endl; // print error message 
    return false;
  }

  if (type == 'I')
  {
    //print out all transactin history
    displayMList();
    transactionHistory.push_back("I");
    return true;
  }
  inFile.ignore();
  inFile >> id;
  Customer* ct;
  if (!customer.get(id, ct))
  {
    cout << "INCORRECT CUSTOMER ID " << id << endl; // print error message 
     return false;
  }
  if (type == 'H')
  {
    cout << *ct;
    transactionHistory.push_back("H " + to_string(ct->getCustomerID()));
    return true;
  }
  inFile.ignore();
  inFile >> movie;
  inFile.ignore();
  inFile >> movieType;

  Transaction* tr;
  Borrow br;
  Return rt;

  switch (type)
  {
    case 'B':

      if (!changeStock(-1, movieType, inFile, title))
      {
        tr->setData(title, ct);
        return false;
      }
      tr = &br;
      break;

    case 'R':
      if (!changeStock(1, movieType, inFile, title))
      {
        tr->setData(title, ct);
        return false;
      }
      tr = &rt;
      break;

    default:
      cout << "INVALID ACTION CODE" << endl; // print error message 
      return false;
    }
    tr->setMovieType(movie);
    tr->setTransactionType(type);
    tr->setData(title, ct); //change to inFile later
    transactionHistory.push_back(type + (to_string(ct->getCustomerID())) + " " + movieType);

    return true;
}

// ------------------------------------changeStock------------------------------------------------
// change the number of stock 
// -------------------------------------------------------------------------------------------
bool Factory::changeStock(int numOfStock, char type,  istream& inFile, string& mTitle) 
{
  Comedy cm;
  Comedy *cmFound;
  Drama dm;
  Drama *dmFound;
  Classic cs;
  Classic* csFound;
  string title, director, actF, actL, tmp, actor;
  int year, month;
  switch (type)
  {
    case 'F':
      inFile.ignore();
      getline(inFile >> ws, title, ',');
      inFile.ignore();
      inFile >> year;
      cm.setTitle(title);
      cm.setYear(year);
      mTitle = title + " " + to_string(year);
      if (movieInv.getComedyTree().retrieve(cm, cmFound))
      {
        if ((cmFound->getStock() + numOfStock) >= 0)
        {
          cmFound->setStock(cmFound->getStock() + numOfStock);
          return true;
        }
        else
        {
          cout << "Out of Stock :  " << mTitle << endl;
          mTitle += "  OUT OF STOCK TRANSACTION FAILED ";
          return false;
        }
      }        
      break;
    case 'D':
      inFile.ignore();
      getline(inFile >> ws, director, ',');
      inFile.ignore();
      getline(inFile >> ws, title, ',');
      dm.setTitle(title);
      dm.setDirector(director);
      mTitle = title + " " + director;

      if (movieInv.getDramaTree().retrieve(dm, dmFound))
      {
        if ((dmFound->getStock() + numOfStock) >= 0)
        {
          dmFound->setStock(dmFound->getStock() + numOfStock);
          return true;
        }
        else 
        {
          cout << "Out of Stock :  " << mTitle << endl;
          mTitle += "  OUT OF STOCK TRANSACTION FAILED";
          return false;
        }
      }
      break;
    case 'C':
      inFile >> month;
      inFile >> year;
      inFile >> actF;
      inFile >> actL;
      cs.setYear(year);
      cs.setReleaseMonth(month);
      actor = actF + " " +  actL;
      cs.setMajorActor(actor);
      mTitle = to_string(month) + " " + to_string(year) + " " + actor;

      if (movieInv.getClassicTree().retrieve(cs, csFound))
      {
        if ((csFound->getStock() + numOfStock) >= 0)
        {
          csFound->setStock(csFound->getStock() + numOfStock);
          return true;
        }
        else 
        {
          cout << "Out of Stock :  " << mTitle << endl;
          mTitle += "  OUT OF STOCK TRANSACTION FAILED";
          return false;
        }
      }
      break;
    default:
      mTitle = "TRANSACTION FAILED (MOVIE NOT FOUND)";
      getline(inFile, title);
      cout << "INVALID VIDEO CODE" << title << endl;
      return false;
  }
  mTitle = "TRANSACTION FAILED (MOVIE NOT FOUND)";
  return false;
}

//------------------------------------displayCustomer------------------------------------------
// displays customer list
// -------------------------------------------------------------------------------------------
void Factory::displayCList() const {
    cout << endl;
    customer.display();
}

// ------------------------------------displayTransition------------------------------------------
// displays transaction history
// -------------------------------------------------------------------------------------------
void Factory::displayTHistory() const {
    cout << endl;
    cout << "=============== Transaction History ===============" << endl;
    for (string s : transactionHistory)
    {
        cout << s << endl;
    }
}

//------------------------------------displayMovies----------------------------------------------
// display movie list
// -------------------------------------------------------------------------------------------
void Factory::displayMList() const {
    cout << endl;
    cout << "=============== Displaying Movie List ===============" << endl;
    movieInv.printAllMovies();
}