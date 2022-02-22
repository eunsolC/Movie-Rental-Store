/*
 * 
 * --------------------------------hashTable.cpp --------------------------------------------
 * CSS343 Assignment 4
 * Student Name: Eunsol Cho & Eunmi Lee
 * Student ID: 1920609, 2076383
 * Student e-mail: echo2@uw.edu, eunmi@uw.edu
 * Creation Date: 5/20/2021 
 * Date of Last Modification: 6/9/2021
 * -------------------------------------------------------------------------------------
 * The purpose of this class to store customer data  
 * -------------------------------------------------------------------------------------
 * The assumption of this project is correct formatting, but codes may be invalid; e.g., in this data, the 'Z' code is an invalid entry so this line has to be discarded and users should be notified about this issue. 
 * -------------------------------------------------------------------------------------
 */
#include <cmath>
#include <queue>
#include <iostream>
#include "hashTable.h"
#include <fstream>
#include <sstream>
using namespace std;

const int BUCKET = 13;

// ------------------------------------constrctor--------------------------------------------
// constrctor
// -------------------------------------------------------------------------------------------
HashTable::HashTable() 
{
  numOfCustomer = 0;
  table = new Customer[101]; // set table size to 101 in case extra customers could be addded
  initialize();
}

// ------------------------------------destructor--------------------------------------------
// destructor
// -------------------------------------------------------------------------------------------
HashTable::~HashTable() 
{
  makeEmpty();
}

// ------------------------------------makeEmpty------------------------------------------------
// clear all values in table
// -------------------------------------------------------------------------------------------
void HashTable::makeEmpty() 
{
  delete[] table;
  BUCKET = 0;
  numOfCustomer = 0;
}

// ------------------------------------initialize------------------------------------------------
// initializes table array to stoe customers
// -------------------------------------------------------------------------------------------
void HashTable::initialize() 
{
  Customer customer(0, "", "");
  for (int i = 0; i < 101; i++)
  {
    table[i] = customer;
  }
}
//------------------------------------insert------------------------------------------------
// insert customer into table
// -------------------------------------------------------------------------------------------
bool HashTable::insert(const Customer &val) {


  int hashedID = val.getCustomerID() % 13;
  if (table[hashedID].getCustomerID() == 0)
  {
    table[hashedID] = val;
    return true;
  }
  else
  {
    while(table[hashedID].getCustomerID() != 0)
    {
      hashedID++;
    }
    table[hashedID] = val;
    return true;
  }
  
  return false;
  
}

// ------------------------------------get------------------------------------------------
// get value mapped to key
// -------------------------------------------------------------------------------------------
bool HashTable::get(const int &key, Customer *&val)
{
  int hc = key % 13;
  if (table[hc].getCustomerID() == key) 
  {
    val = &table[hc];
    return true;
  }
  else 
  {
    do
    {
      hc++;
    } while(table[hc].getCustomerID() != key && hc < 101);
    if (table[hc].getCustomerID() == key)
    {
      val = &table[hc];
      return true;
    }
      return false;
  }
  return false;   
}



// ------------------------------------display------------------------------------------------
// display all customers in table
// -------------------------------------------------------------------------------------------
void HashTable::display() const{
  cout << "=============== Displaying Customer Lists ===============" << endl;
  for (int i = 0; i < 101; i++)
  {
    if (table[i].getCustomerID() != 0 && table[i].getFirstName() != "" && table[i].getLastName() !="")
    {
      cout << table[i]; 
    }
  }
}
//------------------------------------setData------------------------------------------------
// read data from customer file
// -------------------------------------------------------------------------------------------
bool HashTable::setData(std::istream &inFile) 
{
  if (inFile.eof())
    return false;

  string line;
  int id;
  string first, last;

  if (getline(inFile, line))
  {
    istringstream ss(line);
    ss >> id;
    ss >> first;
    ss >> last;
    Customer c(id, first, last);

    if (insert(c))
    {
      return true;
    }
  }
  return false;
}

