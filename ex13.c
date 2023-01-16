#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <string.h>

typedef struct{
    char name[50];
    int quantity;
    float price;
}Cake;

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);
    Cake* cakes = (Cake*) malloc(n * sizeof(Cake));
    for(int i = 0; i < n; i++){
        printf("Cake id = %d\n", i);
        printf("Name = ");
        scanf("%s", cakes[i].name);
        printf("Quantity = ");
        scanf("%d", &cakes[i].quantity);
        printf("Price = ");
        scanf("%f", &cakes[i].price);
    }
    FILE* file_out = fopen("out.bin", "wb");
    for(int i = 0; i < n; i++)
        fprintf(file_out, "%s\n%d\n%f", cakes[i].name, cakes[i].quantity, cakes[i].price);

    fclose(file_out);
    FILE* file_in = fopen("out.bin", "rb");

    float min = FLT_MAX;
    Cake the_cheapest_cake;
    for(int i = 0; i < n; i++)
    {
        fscanf(file_in,"%s", cakes[i].name);
        fscanf(file_in, "%d", &cakes[i].quantity);
        fscanf(file_in, "%f", &cakes[i].price);
        if(cakes[i].price < min){
            min = cakes[i].price;
            strcpy(the_cheapest_cake.name, cakes[i].name);
            the_cheapest_cake.price = cakes[i].price;
            the_cheapest_cake.quantity = cakes[i].quantity;
        }
    }
    printf("%s\n%d\n%f", the_cheapest_cake.name, the_cheapest_cake.quantity, the_cheapest_cake.price);

    fclose(file_in);
    free(cakes);
    //Checked with Valgrind -> No memory leaks
    return 0;
}

