/*
 * unsorted.cpp
 *
 *  Created on: Feb 15, 2021
 *      Author: amranzazai
 */
// This file contains the linked implementation of class
// UnsortedType.

#include "unsorted.h"
using namespace std;
struct NodeType  //struct containing user data and ptr to next node
{
    ItemType info;
    NodeType* next;
};

UnsortedType::UnsortedType()  // Class constructor
{
  length = 0;
  listData = NULL;
}

//FINISH THIS IMPLEMENTATION
void UnsortedType::MakeEmpty(){
  // Function: Returns the list to the empty state.
  // Post:  List is empty.
	NodeType* temporaryPtr; //Creating a temporary ptr

	while (listData != NULL) //while list is not empty
	{
		temporaryPtr = listData; //temporary ptr holds the data we want to delete
		listData = listData->next; //the next value in the list is held in the place that tempPtr freed up
		delete temporaryPtr; //entire list is traversed and delete is called on every element

	}

}
bool UnsortedType::IsFull() const{
	// Function:  Determines whether list is full.
	// Pre:  List has been initialized.
	// Post: Function value = (list is full)
	NodeType* location;
	try{
		location = new NodeType; //new operator throws bad_alloc exception when there's no more space to allocate
		delete location; //if there is enough room for a new node then the list is not full
		return false; //we return false for IsFull
	}
	catch(bad_alloc exception){
		return true;
	}
}

int UnsortedType::GetLength() const{
	// Function: Determines the number of elements in list.
	// Pre:  List has been initialized.
	// Post: Function value = number of elements in list
	return length; //returns length of list; length is incremented as we use PutItem
}

ItemType UnsortedType::GetItem(ItemType item, bool& found){
	// Function: Retrieves list element whose key matches item's key (if
	//           present).
	// Pre:  List has been initialized.
	//       Key member of item is initialized.
	// Post: If there is an element someItem whose key matches
	//       item's key, then found = true and someItem is returned;
	// 	 otherwise found = false and item is returned.
	//       List is unchanged.
	bool moreToSearch;
	NodeType* location;

	location = listData;
	found = false;
	moreToSearch = (location != NULL);

	while(moreToSearch && !found){
		switch (item.ComparedTo(location->info)){
		case LESS:
		case GREATER: location = location->next;
					  moreToSearch = (location != NULL);
					  break;
		case EQUAL: found = true;
					item = location->info;
					break;

		}
	}
	return item;
}

void UnsortedType::PutItem(ItemType item){
	// Function: Adds item to list.
	// Pre:  List has been initialized.
	//       List is not full.
	//       item is not in list.
	// Post: item is in list.

	NodeType* location; //Ptr to a node

	location = new NodeType; //Get a new node
	location -> info =  item; //Store the item inside of the node's info
	location -> next = listData; //Store the address of the first node into the new node's next

	listData = location; //Store the address of the new node into an external ptr

	length++; //increase the size of the list

}

void UnsortedType::DeleteItem(ItemType item){
	// Function: Deletes the element whose key matches item's key.
	// Pre:  List has been initialized.
	//       Key member of item is initialized.
	//       One and only one element in list has a key matching item's key.
	// Post: No element in list has a key matching item's key.
	NodeType* location = listData;
	NodeType* tempLocation;

	//finding the node to delete
	if (item.ComparedTo(listData->info) == EQUAL)
	{
		tempLocation = location; //saving a pointer to the node
		listData = listData-> next; //deleting the first node
	}
	else
	{

		while (item.ComparedTo(listData->info) != EQUAL){ // @suppress("Invalid arguments")
					location = location->next;
		}

		//deleting the node at location->next
		tempLocation = location->next;
		location->next = (location->next)->next;
	}
	delete tempLocation; //returning node
	length--; //length of list decremented
}


void UnsortedType::ResetList(){
	// Function: Initializes current position for an iteration through the list.
	// Pre:  List has been initialized.
	// Post: Current position is prior to list.
	currentPos = NULL; //using NULL to get to the value for item prior to first item of the list
}

ItemType UnsortedType::GetNextItem(){
	// Function: Gets the next element in list.
	// Pre:  List has been initialized and has not been changed since last call.
	//       Current position is defined.
	//       Element at current position is not last in list.
	//
	// Post: Current position is updated to next position.
	//       item is a copy of element at current position.
	if (currentPos == NULL)
		currentPos = listData;
	else
		currentPos = currentPos->next;

	return currentPos->info;
}
UnsortedType::~UnsortedType(){
	NodeType* temporaryPtr;
	while(listData!=NULL){
		temporaryPtr = listData;
		listData = listData->next;
		delete  temporaryPtr;
	}
}

