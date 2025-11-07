#include <iostream>
#include "book.h"
#include "exercise.h"

Book::Book(): first(nullptr), last(nullptr){};
void Book::addExercise(int chapter, int exercise){

    Exercise* previous = last;

    if(first == nullptr){
        first = new Exercise(chapter, exercise, previous, *this);
        last = first;
        return;
    }

   Exercise* newExercise= new Exercise(chapter, exercise, previous, *this);
   last->setNext(newExercise);
   last = newExercise;
   
 
}

Exercise* Book::getExercise(int chapter, int exercise){

    for(Exercise* ex = first; ex != nullptr; ex = ex->getNext()){
        if(ex->getChapter() == chapter && ex->getExercise() == exercise){
            return ex;
        }
    }
    std::cout<<"Exercise not found."<<std::endl;
    return nullptr;
}

void Book::printExercises(){

    if(first == nullptr){
        std::cout<<"No exercises to print."<<std::endl;
        return;
    }

    int currentChapter = first->getChapter();
    for(Exercise* ex = first; ex != nullptr; ex = ex->getNext()){

        if(ex->getChapter() != currentChapter){
            std::cout<<std::endl;
            currentChapter = ex->getChapter();
        }
        ex->print();
        std::cout<<" ";

    }
    std::cout<<std::endl;
}

void Book::unassignChapter(int chapter){

    for(Exercise* ex = first; ex != nullptr; ex = ex->getNext()){
        if(ex->getChapter() == chapter){
            ex->unassign();
        }
    }
}

Book::~Book(){
    Exercise* ex = first;

    while(ex != nullptr){

        Exercise* temp = ex;
        ex = ex->getNext();
        delete temp;
    }
}