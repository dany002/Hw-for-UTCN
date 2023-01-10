#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_string 200
#define given_string_lowercase "aaa"
#define given_string_uppercase "AAA"

typedef struct{
    int year;
    int month;
    int day;
}Date;

typedef struct{
    char first_name[max_string];
    char last_name[max_string];
    char country[max_string];
    int group;
    Date birth_date;
}Student;

void PrintForeign(Student* students, int number_of_students){
    int i;
    for(i = 0; i < number_of_students; ++i){
        if(strcmp(students[i].country,"Romania"))
            printf("First name = %s\nLast name = %s\nCountry = %s\nGroup = %d\nYear = %d\nMonth = %d\nDay = %d\n", students[i].first_name, students[i].last_name, students[i].country, students[i].group, students[i].birth_date.year, students[i].birth_date.month, students[i].birth_date.day);
    }
}

int main(int argc, char** argv) {
    int number_of_students;
    Student* students = (Student *) malloc(30 * sizeof(Student)); // Dynamic memory allocation

    int i = 0;
    printf("Student %d\n",i+1);
    printf("First name = ");
    char name[max_string];
    scanf("%s", name);
    while(strcmp(name,given_string_uppercase) && strcmp(name, given_string_lowercase)){
        strcpy(students[i].first_name,name);
        printf("Last name = ");
        scanf("%s", students[i].last_name);
        printf("Country = ");
        scanf("%s", students[i].country);
        printf("Group = ");
        scanf("%d", &students[i].group);
        printf("Year of birth = ");
        scanf("%d", &students[i].birth_date.year);
        printf("Month of birth = ");
        scanf("%d", &students[i].birth_date.month);
        printf("Day of birth = ");
        scanf("%d", &students[i].birth_date.day);
        printf("Student %d\n", i + 2);
        printf("First name = ");
        scanf("%s", name);
        ++i;
    }
    number_of_students = i;
    PrintForeign(students, number_of_students);

    free(students);
    return 0;
    //Checked with Valgrind -> No memory leaks.
}

