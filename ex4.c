/******************
Name: 
ID: 
Assignment: ex4
*******************/

#include <stdio.h>
#include <string.h>

// You can change the functions' names and prototypes as you wish, but keep the declarations at the top:
void task1RobotPaths();
void task2HumanPyramid();
void task3ParenthesisValidator();
void task4QueensBattle();

int main() {
    int task = -1;
    do {
        printf("Choose an option:\n"
               "1. Robot Paths\n"
               "2. The Human Pyramid\n"
               "3. Parenthesis Validation\n"
               "4. Queens Battle\n"
               "5. Exit\n");

        if (scanf("%d", &task)) { // To make sure the input is an integer
            switch (task) {
                case 1:
                    task1RobotPaths();
                    break;
                case 2:
                    task2HumanPyramid();
                    break;
                case 3:
                    task3ParenthesisValidator();
                    break;
                case 4:
                    task4QueensBattle();
                    break;
                case 5:
                    printf("Goodbye!\n");
                    break;
                default:
                    printf("Please choose a task number from the list.\n");
                    break;
            }
        } else {
            scanf("%*s"); // To discard the invalid input
            printf("Please choose a task number from the list.\n");
        }
    } while (task != 5);
}

void task1RobotPaths() {
    // Todo
}

void task2HumanPyramid() {
    // Todo
}

void task3ParenthesisValidator() {
    // Todo
}

void task4QueensBattle() {
    // Todo
}
