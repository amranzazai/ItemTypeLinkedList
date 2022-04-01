/*
 * main.cpp
 *
 *  Created on: Feb 15, 2021
 *      Author: amranzazai
 */
// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include <sstream> //in order to convert substring to an int

#include "unsorted.h"

using namespace std;
void PrintList(ofstream& outFile, UnsortedType& list);

int main()
{

  ifstream inFile;       // file containing operations
  ofstream outFile;      // file containing output
  string inFileName;     // input file external name
  string outFileName;    // output file external name
  string outputLabel;
  string command; // operation to be executed

  ItemType item;
  UnsortedType list;
  bool found;
  int numCommands;
  string commandNo;
  string line;
  string number;
  int number2;


  // Prompt for file names, read file names, and prepare files
  cout << "Enter name of input command file; press return." << endl;
  cin  >> inFileName;
  inFile.open(inFileName.c_str());

  cout << "Enter name of output file; press return." << endl;
  cin  >> outFileName;
  outFile.open(outFileName.c_str());

  cout << "Enter name of test run; press return." << endl;
  cin  >> outputLabel;
  outFile << outputLabel << endl;

  numCommands=0;

  if (!inFile)
    {
      cout << "file not found" << endl;
  	exit(2);
    }

    inFile >> command; //read command until whitespace

    numCommands = 0;
    while (command != "Quit")
    {

   //FINISH MENU HERE
    	outFile.open(outFileName.c_str());
		if(command == "GetLength"){ //finding a match for the command

			  outFile<<"Length is: "<<list.GetLength()<<endl;
		  }
		  else if (command == "PrintList"){
			  PrintList(outFile, list);
		  }
		  else if (command == "IsFull"){
			  if(list.IsFull())
				  outFile<<"List Full";
			  else
				  outFile<<"List is empty";
		  }
		  else if (command == "MakeEmpty"){
			  list.MakeEmpty();
		  }
		  else if (command == "PutItem"){
			  	  	  inFile >> number; //if command is PutItem read the int that comes after the command
			  	  	  number2 = stoi(number); //convert the string read using inFile to an int
					  item.Initialize(number2); //Initialize item with the integer value
					  list.PutItem(item); //Place item in the list
					  outFile<<number2<<" is in list"; //write to file
		  }
		  else if (command == "GetItem"){
			  inFile >> number;
			  number2 = stoi(number);
			  list.GetItem(item, found);
			  outFile<<number2<<" found in list";
		  }
		  else if (command == "DeleteItem"){
			      inFile >> number;
			      number2 = stoi(number);
				  list.DeleteItem(item);
				  outFile<<number2<<" was deleted";
		  }
		  else if (command == "Quit"){
			  break;
		  }
		  else{
			 cout<< command << " is not a command.\n";
		  }


      cout <<  " Command number " << numCommands << " completed." << endl;
      numCommands++;
      inFile >> command;
    };

    cout << "Testing completed."  << endl;
    inFile.close();
    outFile.close();
    return 0;
  }




void PrintList(ofstream& dataFile, UnsortedType& list)
	// Pre:  list has been initialized.
	//       dataFile is open for writing.
	// Post: Each component in list has been written to dataFile.
	//       dataFile is still open.
{
	 //FINISH PRINTLIST
	int length;
	ItemType item;
	list.ResetList();
	length= list.GetLength();

	for(int counter = 1; counter <= length; counter++)
		{
			item = list.GetNextItem();
			item.Print(dataFile);
		}
}


