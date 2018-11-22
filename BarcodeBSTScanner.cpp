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
    BinarySearchTree<UPC> bst;
    string upc, name;
    clock_t t;
    ifstream myfile;
    myfile.open("upc_corpus.1.txt");
    getline(myfile, name);
    
    // Create the UPC object for each product and add them
    // to the BST
    while (!myfile.eof()){
        //for (int i = 0; i < 10000; i++){
        getline(myfile, upc, ',');
        //cout << upc << endl;
        getline(myfile, name);
        //cout << name << endl;
        UPC temp (upc, name);
        bst.insert(temp);
        // cout << i << endl;
   }

   // Get User's input, create temp UPC object, search and time
   string userinput;
   getline(cin, userinput);
   UPC temp (userinput);
   t = clock();
   bst.search(temp);
   t = clock() - t;
   cout << "Time: " << t << " milliseconds" << endl;
}

