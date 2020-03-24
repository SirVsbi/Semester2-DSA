#pragma once
//DO NOT INCLUDE LISTITERATOR

//DO NOT CHANGE THIS PART
typedef int TElem;

#define NULL_TELEM -11111

typedef struct Node{
    TElem data;
    struct Node* next;
    struct Node* prev;
} Node;

class ListIterator;

class IndexedList {
private:
    //the number of elements currently stored in the list 
    int length;

    //the data is represented using nodes, keeping track of the content and
    //the code before and after the current one 


    //the first node of the list 
    Node* head; 
	Node* tail;
	//DO NOT CHANGE THIS PART

    friend class ListIterator;    
public:
    // constructor
    IndexedList ();

    // returns the number of elements from the list
    int size() const;

    // checks if the list is empty
    bool isEmpty() const;

    // returns an element from a position
    //throws exception if the position is not valid
    TElem getElement(int pos) const;

    // modifies an element from a given position
	//returns the old value from the position
    //throws an exception if the position is not valid
    TElem setElement(int pos, TElem e);

    // adds an element to the end of the list
    void addToEnd(TElem e);

    // adds an element to a given position
    //throws an exception if the position is not valid
    void addToPosition(int pos, TElem e);

    // removes an element from a given position
	//returns the removed element
    //throws an exception if the position is not valid
    TElem remove(int pos);

    // searches for an element and returns the first position where the element appears or -1 if the element is not in the list
    int search(TElem e)  const;


    //removes every kth element from the list. If the list contains less than k elements, the list is not changes
    //returns the number of removed elements
    //throws an exception if k is negative or 0
    int removeFromKtoK(int k);

    // returns an iterator set to the first element of the list or invalid if the list is empty
    ListIterator iterator() const;

    //destructor
    ~IndexedList();

};
