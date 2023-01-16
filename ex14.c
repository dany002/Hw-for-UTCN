#include <stdlib.h>
#include <stdio.h>

int main() {
    FILE* file_out = fopen("date_out.bin", "wb");
    int n;
    printf("n = ");
    scanf("%d", &n);
    int x;
    for(int i = 0; i < n; i++){
        printf("x = ");
        scanf("%d", &x);
        fprintf(file_out, "%d\n", x);
    }
    fclose(file_out);

    FILE* file_in = fopen("date_out.bin", "rb");
    printf("Se considera ca se numara de la 0.\n");
    for(int i = 0; i < n; i++){
        fscanf(file_in,"%d", &x);
        if(i % 2){
            printf("Numarul %d se afla pe pozitia %d si este", x, i);
            if(x % 2)
                printf(" impar\n");
            else
                printf(" par\n");
        }

    }

    fclose(file_in);
    
    //Checked with Valgrind -> No memory leaks.
    return 0;
}

