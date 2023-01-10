#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define max_string 200

typedef struct{
    char first_name[max_string];
    char last_name[max_string];
    float average;
}Student;

void PrintMaxAverage(Student* students, int number_of_students){
    int i;
    float maxim = FLT_MIN;
    for(i = 0; i < number_of_students; ++i)
        if(students[i].average > maxim)
            maxim = students[i].average;
    for(i = 0; i < number_of_students; ++i)
        if(students[i].average == maxim)
            printf("First name = %s\nLast name = %s\nAverage = %f\n", students[i].first_name, students[i].last_name, students[i].average);

}

int main(int argc, char** argv) {
    int number_of_students;
    printf("Number of students = ");
    scanf("%d", &number_of_students);
    Student* students = (Student *) malloc(number_of_students * sizeof(Student)); // Dynamic memory allocation

    for(int i = 0; i < number_of_students; ++i){
        printf("First name = ");
        scanf("%s", students[i].first_name);
        printf("Last name = ");
        scanf("%s", students[i].last_name);
        printf("Average = ");
        scanf("%f", &students[i].average);
    }

    PrintMaxAverage(students, number_of_students);

    free(students);
    return 0;
    //Checked with Valgrind -> No memory leaks.
}

