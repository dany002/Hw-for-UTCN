#include <stdio.h>
#include <stdlib.h>
#define max_string 200

typedef struct{
    int id;
    char name[max_string];
    float wage;
}Employee;

void PrintStructurePassedByValue(Employee employee){
    printf("Id = %d\nName = %s\nWage = %f\n\n", employee.id, employee.name, employee.wage);
}

void PrintStructurePassedByAddress(Employee* employee){
    printf("Id = %d\nName = %s\nWage = %f\n\n", employee->id, employee->name, employee->wage);
}

void ReadDataForStructure(Employee* employee){
    printf("Id = ");
    scanf("%d", &employee->id);
    printf("Name = ");
    scanf("%s", employee->name);
    printf("Wage = ");
    scanf("%f", &employee->wage);
    getchar();
}

void print_menu(){
    printf("Type 1 if you want to display the structure passed by value.\nType 2 if you want to display the structure by address.\n");
}


int main(int argc, char** argv) {
    Employee* employee = (Employee*) malloc(sizeof(Employee)); // Dynamic memory allocation
    ReadDataForStructure(employee);
    print_menu();
    int answer;
    scanf("%d", &answer);
    switch (answer) {
        case 1:
            PrintStructurePassedByValue(*employee);
            break;
        case 2:
            PrintStructurePassedByAddress(employee);
            break;
        default:
            free(employee);
            printf("You had to choose between 1 and 2.");
            exit(1);
    }
    free(employee);

    //Checked with Valgrind -> No memory leaks.
    return 0;
}

