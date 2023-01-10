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
    Date birth_date;
    char CNP[14];
    Date date_of_employment;
}Employee;



void PrintEmployees(Employee* employees, int number_of_employees){
    int i;
    for(i = 0; i < number_of_employees; ++i)
        printf("First name = %s\nLast name = %s\nBirth date = %d/%d/%d\nCNP = %s\nDate of employment = %d/%d/%d\n", employees[i].first_name, employees[i].last_name, employees[i].birth_date.day, employees[i].birth_date.month, employees[i].birth_date.year, employees[i].CNP, employees[i].date_of_employment.day, employees[i].date_of_employment.month, employees[i].date_of_employment.year);
}

int ReadEmployees(Employee* employees, int number_of_employees){
    int i;

    for(i = 0; i < number_of_employees; ++i){
        printf("Employee %d\n", i + 1);
        printf("First name = ");
        scanf("%s", (employees + i)->first_name);
        printf("Last name = ");
        scanf("%s", (employees + i)->last_name);
        printf("Day of birth = ");
        scanf("%d", &(employees + i)->birth_date.day);
        printf("Month of birth = ");
        scanf("%d", &(employees + i)->birth_date.month);
        printf("Year of birth = ");
        scanf("%d", &(employees + i)->birth_date.year);
        printf("CNP = ");
        scanf("%s", (employees + i)->CNP);
        printf("Day of employment = ");
        scanf("%d", &(employees + i)->date_of_employment.day);
        printf("Month of employment = ");
        scanf("%d", &(employees + i)->date_of_employment.month);
        printf("Year of employment = ");
        scanf("%d", &(employees + i)->date_of_employment.year);
    }
}

void sort_employees(Employee* employees, int number_of_employees){
    int i;
    int j;
    for(i = 0; i < number_of_employees - 1; ++i){
        for(j = i + 1; j < number_of_employees; ++j)
            if(employees[i].date_of_employment.year > employees[j].date_of_employment.year ||
            employees[i].date_of_employment.year == employees[j].date_of_employment.year &&
            employees[i].date_of_employment.month > employees[j].date_of_employment.month ||
            employees[i].date_of_employment.year == employees[j].date_of_employment.year &&
            employees[i].date_of_employment.month == employees[j].date_of_employment.month &&
            employees[i].date_of_employment.day > employees[j].date_of_employment.day){
                Employee help = employees[i];
                employees[i] = employees[j];
                employees[j] = help;
            }

    }
}

int main(int argc, char** argv) {
    printf("How many employees do you want?\n");
    int number_of_employees;
    scanf("%d", &number_of_employees);
    Employee* employees = (Employee*) malloc(number_of_employees * sizeof(Employee)); // Dynamic memory allocation
    ReadEmployees(employees, number_of_employees);
    sort_employees(employees, number_of_employees);
    PrintEmployees(employees, number_of_employees);
    free(employees);
    return 0;
    //Checked with Valgrind -> No memory leaks.
}

