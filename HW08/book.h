#ifndef BOOK_H
#define BOOK_H

#include "exercise.h"

class Book{

    private:
        Exercise* first;
        Exercise* last;

    public:
        Book();
        void addExercise(int chapter, int exercises);
        Exercise* getExercise(int chapter, int exercise);
        void printExercises();
        void unassignChapter(int chapter);
        virtual~Book();
};

#endif