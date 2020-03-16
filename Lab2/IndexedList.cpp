#include <exception>

#include "IndexedList.h"
#include "ListIterator.h"

#include <iostream>

struct IndexedListException : public std::exception{
    const char* foo() const throw(){
        return "Function called on invalid index";
    }

};

IndexedList::IndexedList() {
	length = 0;
    head = NULL;
    tail = NULL;
    
}

int IndexedList::size() const {
    return length;
}


bool IndexedList::isEmpty() const {
    return length == 0;
}

TElem IndexedList::getElement(int pos) const {
    if(pos >= length || pos < 0){
        throw IndexedListException();
    }
    int position;
    Node* searchNode;    
    if(pos >= length / 2){
        position = length - 1;
        searchNode = tail;
        while(searchNode != NULL){
            if(position == pos){
                return searchNode->data;
            }
            position--;
            searchNode = searchNode->prev;
        }
    }
    else{
        position = 0;
        searchNode = head;
        while(searchNode != NULL){
            if(position == pos){
                return searchNode->data;
            }
            position++;
            searchNode = searchNode->next;
        }
    }
    return NULL_TELEM;
}

TElem IndexedList::setElement(int pos, TElem e) {
    if(pos >= length || pos < 0){
        throw IndexedListException();
    }
    int position = 0;
    int oldValue = NULL_TELEM;
    Node* searchNode;    
    if(pos >= length / 2){
        position = length - 1;
        searchNode = tail;
        while(searchNode != NULL){
            if(position == pos){
                oldValue = searchNode->data;
                searchNode->data = e;
                return oldValue;
            }
            position--;
            searchNode = searchNode->prev;
        }
    }
    else{
        position = 0;
        searchNode = head;
        while(searchNode != NULL){
            if(position == pos){
                oldValue = searchNode->data;
                searchNode->data = e;
                return oldValue;
            }
            position++;
            searchNode = searchNode->next;
        }
    }
    return oldValue;

}

void IndexedList::addToEnd(TElem e) {
    Node* newElem = new Node;
    newElem->data = e;
    if(head == NULL){
        head = newElem;
        newElem->prev = NULL;
        newElem->next = NULL;
        tail = newElem;
    }else{
        newElem->prev = tail;
        tail->next = newElem;
        newElem->next = NULL;
        tail = newElem;
    }
    length++;
}

void IndexedList::addToPosition(int pos, TElem e) {
    if(pos > length){
        throw IndexedListException();
    }
    //if there are no elements in the list
    if(pos == length){
        addToEnd(e);
        return;
    }
    Node* newElem = new Node;
    newElem->data = e;
    Node* current = head, *previous = NULL;
    while(pos--){
        previous = current;
        current = current -> next;
    }
    newElem->prev = previous;
    newElem->next = current;
    if(newElem->prev)
        newElem->prev->next = newElem;
    else
        head = newElem;
    
    if(newElem->next)
        newElem->next->prev = newElem;
    else
        tail = newElem;
    

    length++;

}



TElem IndexedList::remove(int pos) {
    if(pos >= length){
        throw IndexedListException();
    }
    length--;
    Node* temp;
    int oldValue;
	if(pos == 0){
        oldValue = head->data; 
        temp = head->next;
        delete head;
        head = temp;
        return oldValue;
    }
    else if(pos == length){
        oldValue = tail->data;
        temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        return oldValue;
    }
    temp = head->next;
    for(int i = 1; i < pos && temp != NULL; i++){
        temp = temp->next;
    }

    oldValue = temp->data;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    return oldValue;
}

int IndexedList::search(TElem e) const{
    Node* searchNode = head;
    int position = 0;
    while(searchNode != NULL){
        if(searchNode->data == e){
            return position;
        }
        searchNode = searchNode->next;
        position++;
    }
    return -1;
}

ListIterator IndexedList::iterator() const {
    return ListIterator(*this);        
}

IndexedList::~IndexedList() {
	Node* current = head;
    Node* next;
    while(current != NULL){
        next = current->next;
        delete current;
        current = next;
    }
}