#pragma once
#include <string>
#include <sstream>
#include "LinkedListInterface.h"

using namespace std;

template<class T>
class LinkedList: public LinkedListInterface <T>
{
private:
    struct Node {
    T data;
    Node* next;
    Node(const T& the_data, Node* next_val = NULL) :
        data(the_data) {next = next_val;}
    };
    
    Node* mylist;
    int num_items;

public:

	bool find(T value){
		Node *check = mylist;
		while(check != NULL){
			if(check->data == value){
				return true;
			}
			check = check->next;
		}
		return false;
	}
	

	LinkedList(void) {
	    mylist = NULL;
	    num_items = 0;
	};
	virtual ~LinkedList(void) {
		cout << "In destructor"<<endl;
		while(mylist != NULL) {
			Node *current = mylist;
			mylist = mylist->next;
			delete current;
		}
	};

	/*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
	virtual void insertHead(T value){
		cout << "In insertHead" << endl;
		if(mylist == NULL){
			cout << "mylist = NULL" << endl;
			mylist = new Node(value);
			cout << "new Node value set" << endl;
			mylist->next = NULL;
			cout << "next value set" << endl;
			num_items++;
		}
		else if(find(value) == true){
			cout << "Found duplicate in insertHead" << endl;
			return;
		}
		else{
			cout << "Inserting new head" << endl;
			Node *ptr = mylist;
			mylist = new Node(value);
			mylist->next = ptr;
			num_items++;
			
		}
	    
	    
	};

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	virtual void insertTail(T value){
		Node *tail = mylist;
		cout << "Entering insertTail" << endl;
		if (mylist == NULL){
			cout << "mylist = NULL" << endl;
			insertHead(value);
			return;
		}

		else if (find(value) == true){
			cout << "Found duplicate in insertTail" << endl;
			return;
		}
		cout << "creating tail node" << endl;
		while(tail->next != NULL){
			tail = tail->next;
		}
		if (tail->next == NULL){
			cout << "tail = NULL, setting new tail" << endl;
			Node *newTail = new Node(value);
			tail->next = newTail;
			newTail->next = NULL;
		}
		num_items++;
		
	    
	};

	/*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	virtual void insertAfter(T value, T insertionNode){
		cout << "Entering insertAfter" << endl;
		if(find(value) == true){
			cout << "Found duplicate in insertAfter" << endl;
			return;
		}
		if(find(insertionNode) == true){
			cout << "Insertion Node exists, finding Node now" << endl;
			Node *temp = mylist;
			while(temp != NULL){
				if(temp->data == insertionNode){
					Node *myInsert = new Node(value);
					myInsert->next = temp->next;
					temp->next = myInsert;
				}
				temp = temp->next;
			}
			num_items++;
		}
		
	    
	};

	/*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	virtual void remove(T value){
		cout << "Entering remove" << endl;
		if(find(value) == false){
			cout << "Value does not exist in list" << endl;
			return;
		}
		if (mylist->data == value){		
			Node *current = mylist;
			mylist = mylist->next;
			delete current;
			num_items--;
		}
		else{
			Node *ptr = mylist;
			while(ptr->next != NULL){
				if (ptr->next->data == value){
					Node *current = ptr->next;
					ptr->next = ptr->next->next;
					delete current;
					num_items--;
				}
				else{
					ptr = ptr->next;
				}
			}
		}
	};

	/*
	clear

	Remove all nodes from the list.
	*/
	virtual void clear(){
		cout << "Entering clear" << endl;
		while(mylist != NULL){
			Node *ptr = mylist->next;
			delete mylist;
			mylist = ptr;
			num_items--;
		}
	};
	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	virtual T at(int index){
		cout << "In T at"<<endl;
		if(index >= num_items || index < 0) {
			throw std::out_of_range("At Error");
		} else {
			cout << "Looking for T at " << index << endl;
			Node *ptr = mylist;
			int i = 0;
			while(ptr != NULL){
				if(i == index){
					cout << "Found T at " << index << endl;
					return ptr->data;
				}
				i++;
				ptr = ptr->next;
			}
		}
	    
	};

	/*
	size

	Returns the number of nodes in the list.
	*/
	virtual int size(){
		cout << "Entering size" << endl;
	    return num_items;
	};

	/*
	toString
	
	Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
	There should be no trailing space at the end of the string

	For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
	"1 2 3 4 5"
	*/
	virtual string toString(){
		cout << "Entering toString" << endl;
	    stringstream ss;
	    for(Node *ptr =mylist; ptr != NULL; ptr = ptr->next){
	    	if(ptr->next == NULL){
	    		ss << ptr->data;
	    	}
	    	else{
	    		ss << ptr->data << " ";	
	    	}
			
		}
		return (ss.str());
	};

};
