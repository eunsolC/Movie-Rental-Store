/*
 * 
 * --------------------------------hashTable.h--------------------------------------------
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
#ifndef ASSIGNMENT_4_HASHTABLE_H
#define ASSIGNMENT_4_HASHTABLE_H
#include "customer.h"
class HashTable 
{
  public:
    HashTable();
    ~HashTable(); //destructor
    int hashFunction(int key); //hash function to get a index where value
    // is stored in a table. key is customer ID
    int quadHashFunction(int n); //quadratic hash function
    bool insert(const Customer&); //insert customer into table
    bool get(const int& key, Customer *&val); //get value mapped to key
    void display() const; //display all customers in table
    bool setData(std::istream& );
  private:
    Customer* table; //pointer array containing bucket
    int BUCKET;
    int numOfCustomer;
    void makeEmpty(); //clear all values in table
    void rehashing();
    void initialize();
};


#endif 
