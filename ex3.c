#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_string 200

typedef struct{
    int day;
    int month;
    int year;
}Date;

typedef struct{
    char first_name[max_string];
    char last_name[max_string];
    char occupation[max_string];
    Date birth_date;
    char department[max_string];
}Employee;



void PrintEmployees(Employee* employees, int number_of_employees){
    int i;
    for(i = 0; i < number_of_employees; ++i)
        printf("First name = %s\nLast name = %s\nOccupation = %s\nBirth date = %d/%d/%d\nDepartment = %s\n\n", employees[i].first_name, employees[i].last_name, employees[i].occupation, employees[i].birth_date.day, employees[i].birth_date.month, employees[i].birth_date.year, employees[i].department);
}

int ReadEmployees(Employee* employees, int number_of_employees){
    int i;

    for(i = 0; i < number_of_employees; ++i){
        printf("Employee %d\n", i + 1);
        printf("First name = ");
        scanf("%s", (employees + i)->first_name);
        printf("Last name = ");
        scanf("%s", (employees + i)->last_name);
        printf("Occupation = ");
        scanf("%s", (employees + i)->occupation);
        printf("Day of birth = ");
        scanf("%d", &(employees + i)->birth_date.day);
        printf("Month of birth = ");
        scanf("%d", &(employees + i)->birth_date.month);
        printf("Year of birth = ");
        scanf("%d", &(employees + i)->birth_date.year);
        printf("Department = ");
        scanf("%s", (employees + i)->department);


    }
}

void PrintEngineers(Employee* employees, int number_of_employees){
    int i;
    for(i = 0; i < number_of_employees; ++i){
        if(strcmp(employees[i].occupation, "Inginer") == 0 || strcmp(employees[i].occupation,"inginer") == 0)
            printf("First name = %s\nLast name = %s\nOccupation = %s\nBirth date = %d/%d/%d\nDepartment = %s\n", employees[i].first_name, employees[i].last_name, employees[i].occupation, employees[i].birth_date.day, employees[i].birth_date.month, employees[i].birth_date.year, employees[i].department);
    }
}

void print_menu(){
    printf("Type 1 if you want to display all the employees.\nType 2 if you want to display only the employees that are engineers.\nType 0 for exit.\n");
}




int main(int argc, char** argv) {
    printf("How many employees do you want?\n");
    int number_of_employees;
    scanf("%d", &number_of_employees);
    Employee* employees = (Employee*) malloc(number_of_employees * sizeof(Employee)); // Dynamic memory allocation
    ReadEmployees(employees, number_of_employees);
    while(1){
        int answer;
        print_menu();
        scanf("%d", &answer);
        switch(answer) {
            case 0:
                free(employees);
                return 0;
            case 1:
                PrintEmployees(employees, number_of_employees);
                break;
            case 2:
                PrintEngineers(employees, number_of_employees);
                break;
            default:
                printf("You have to choose between 0 or 1 or 2.");
        }
    }

    //Checked with Valgrind -> No memory leaks.
}

