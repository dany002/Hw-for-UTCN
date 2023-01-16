#include <stdlib.h>
#include <stdio.h>

int main() {
    char first_file[50], second_file[50];
    printf("What is the first file?");
    scanf("%s", first_file);
    printf("What is the second file?");
    scanf("%s", second_file);
    FILE* fileout = fopen(first_file, "wb");
    int x;
    for(int i = 0; i < 8; i++){
        printf("x = ");
        scanf("%d", &x);
        fprintf(fileout, "%d\n", x);
    }
    fclose(fileout);
    FILE* filein = fopen(first_file, "rb");
    int a[10];
    int n = 0;
    float s = 0;

    for(int i = 0; i < 8; i++){
        fscanf(filein, "%d", &x);
        if(x > 4) {
            a[n++] = x;
            s += x;
        }
    }
    fclose(filein);
    FILE* fileout_second_file = fopen(second_file, "w");
    fprintf(fileout_second_file, "Media aritmetica a numberelor ");
    for(int i = 0; i < n; i++)
        fprintf(fileout_second_file, "%d ", a[i]);
    fprintf(fileout_second_file, ", este %.2f", s / n);
    fclose(fileout_second_file);

    //Checked with valgrind -> No memory leaks
    return 0;
}

