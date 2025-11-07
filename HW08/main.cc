#include <iostream>
#include <cmath>
#include "book.h"
#include "exercise.h"

int main() {
    Book textBook;

    
    textBook.addExercise(1,1);
    textBook.addExercise(1,2);
    textBook.addExercise(1,3);

    Exercise* c1e1 = textBook.getExercise(1,1);
    Exercise* c1e2 = textBook.getExercise(1,2);
    Exercise* c1e3 = textBook.getExercise(1,3);

   
    textBook.addExercise(2,1);
    textBook.addExercise(2,2);
    textBook.addExercise(2,3);

    Exercise* c2e1 = textBook.getExercise(2,1);
    Exercise* c2e2 = textBook.getExercise(2,2);
    Exercise* c2e3 = textBook.getExercise(2,3);

    
    c2e1->addRequirement(c1e1);
    c2e2->addRequirement(c1e2);
    c2e3->addRequirement(c1e1);
    c2e3->addRequirement(c1e3);

   
    textBook.addExercise(3,1);
    textBook.addExercise(3,2);
    textBook.addExercise(3,3);

    Exercise* c3e1 = textBook.getExercise(3,1);
    Exercise* c3e2 = textBook.getExercise(3,2);
    Exercise* c3e3 = textBook.getExercise(3,3);

   
    c3e1->addRequirement(c2e1);
    c3e1->addRequirement(c2e2);
    c3e1->addRequirement(c2e3);

    c3e2->addRequirement(c2e1);

    c3e3->addRequirement(c2e3);

    textBook.addExercise(4,1);
    textBook.addExercise(4,2);

    Exercise* c4e1 = textBook.getExercise(4,1);
    Exercise* c4e2 = textBook.getExercise(4,2);

    c4e1->addRequirement(c3e1);

    c4e2->addRequirement(c3e2);
    c4e2->addRequirement(c3e3);

 
    textBook.addExercise(5,1);
    Exercise* c5e1 = textBook.getExercise(5,1);
    c5e1->addRequirement(c4e1);
    c5e1->addRequirement(c4e2);

    std::cout<<"Choose the exercises you would like to assign or unassign:\n";

    while (true) {
        int chapter;
        int exercise;

        std::cout<<"Enter the chapter number (0 to exit): ";
        std::cin>>chapter;

        if (chapter == 0)
            break;

        std::cout<<"Enter exercise number (negative to unassign): ";
        std::cin>>exercise;

        Exercise* ex = textBook.getExercise(chapter, std::abs(exercise));
        if (!ex) {
            std::cout<<"Exercise not found."<<std::endl;
            continue;
        }

        if (exercise > 0) {
            textBook.unassignChapter(chapter);
            ex->assign();
        } else {
            ex->unassign();
        }

        textBook.printExercises();
        std::cout<<std::endl;
    }

    std::cout<<"Final exercise list:"<<std::endl;
    textBook.printExercises();

    return 0;
}
