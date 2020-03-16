#include "ListIterator.h"
#include <exception>


struct ListIteratorException : public std::exception{
    const char* foo() const throw(){
        return "Function called on invalid iterator";
    }

};


ListIterator::ListIterator(const IndexedList& list) : list(list){
    currentNode = list.head;
}

void ListIterator::first(){
    currentNode = list.head;
}

void ListIterator::next(){
    if(!valid()){
        throw ListIteratorException();
    }
    currentNode = currentNode->next;
}

bool ListIterator::valid() const{
    if(currentNode == NULL){
        return false;
    }
    return true;

}

TElem ListIterator::getCurrent() const{
    if(!valid()){
        throw ListIteratorException();
    }
    return currentNode->data;
}