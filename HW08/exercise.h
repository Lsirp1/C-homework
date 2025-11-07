#ifndef EXERCISE_H
#define EXERCISE_H

class Book;



class Exercise{

    private:
        int chapter;
        int exercise;
        Exercise* next;
        bool assigned;
        Exercise** requirements;
        static const int MAX_REQUIREMENTS = 16;
        int numRequirements;
        Book& book;

        public:
        Exercise(int chapter, int exercise, Exercise* previous, Book& book);
        void addRequirement(Exercise* requirement);
        void assign();
        void unassign();
        void print() const;
        int getChapter()const { return chapter; }
        int getExercise()const { return exercise; }
        void setNext(Exercise* n) {next = n; }
        Exercise* getNext() const {return next;}
        virtual ~Exercise();

    
        
};
#endif //EXERCISE_H