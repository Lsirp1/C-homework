#include <iostream>
#include "exercise.h"

Exercise::Exercise(int chapter, int exercise, Exercise* prev, Book& book): chapter(chapter), exercise(exercise), next(nullptr), assigned(false), numRequirements(0), book(book){
    if (prev != nullptr) prev->next = this;

    requirements = new Exercise*[MAX_REQUIREMENTS];
    for (int i = 0; i < MAX_REQUIREMENTS; i++) requirements[i] = nullptr;
}

void Exercise::print() const {

    if(!this->assigned){
        std::cout<< "*.*";
        return;
    }

    std::cout << chapter << "." << exercise;
}

void Exercise::addRequirement(Exercise* requirement){

    if(numRequirements >= MAX_REQUIREMENTS){
        std::cout<<"Maximum number of requirements reached for this exercise."<<std::endl;
        return;
    }
    requirements[numRequirements++] = requirement;
}
void Exercise::assign(){


    assigned = true;

    for(int i = 0; i < numRequirements; i++){
        if(!requirements[i]->assigned){
            requirements[i]->assign();
        }
        
    }

}

void Exercise::unassign(){

    assigned = false;

    for(int i = 0; i < numRequirements; i++){
        if(requirements[i]->assigned){
            requirements[i]->unassign();
        }
        
    }

}

Exercise::~Exercise(){
    delete[] requirements;
}
