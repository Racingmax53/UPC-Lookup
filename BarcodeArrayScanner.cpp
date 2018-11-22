/*
        Maxwell Goulding-Miles
        Fatma Serce
        Assignment #4
        CS 300
*/
#include <iostream> 
#include <sstream>
#include <fstream>
#include <string>
#include <time.h>
#include "UPC.h"
#include "BinarySearchTree.h"

using namespace std;
int main(){
    UPC* array = new UPC[1200000];
    string upc;
    string name;
    clock_t t;
    ifstream myfile;
    myfile.open("upc_corpus.1.txt");
    getline(myfile, name);
    int index = 0;

    // Create UPC objects for each product and add them into the array
    while (!myfile.eof()){
        getline(myfile, upc, ',');
        //cout << upc << endl;
        getline(myfile, name);
        //cout << name << endl;
        UPC temp (upc, name);
        UPC* ptemp = &temp;
        array[index] = temp;
        index++;
        // cout << i << endl;
   }
   
   // Get User's input and iterate through the array until the
   // UPC code is found and time it
   string userinput;
   getline(cin, userinput);
   t = clock();
   for (int i = 0; i < 120000; i++){
       if (userinput == array[i].upc){
           break;
       }
   }
   t = clock() - t;
   cout << "Time: " << t << " milliseconds" << endl;

   delete[] array;
}