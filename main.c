#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define UPPER 50
#define LOWER 1

void aPrint(int a[], int n)
{
    for (int i=0; i<n; i++)
    {
        printf("%2d ", a[i]);
    }
    printf("\n");
}

void aPrintf(FILE *file, int a[], int n)
{


    for (int i=0; i<n; i++)
    {
        fprintf(file, "%d ", a[i]);
    }

    fclose(file);
}

void aPrintfRev(FILE *file_incr)
{
    FILE *file_decr;
    file_decr = fopen("csokkeno.dat", "w");
    char str[255];
    struct data {
        char str_tmp[4];
    };
    struct data data[10];
    int n=0;

    fgets(str, 255, file_incr);

    char delim[2] = " ";
    char *ptr;

    ptr = strtok(str, delim);
    while (ptr != NULL)
    {
        //printf("%s ", ptr);

        strcpy(data[n].str_tmp,ptr);
        n++;
        ptr = strtok(NULL, delim);
    }
    for (int i=n-1; i>0; i--)
    {
        printf("%s ", data[i].str_tmp);
        fprintf(file_decr, "%s ", data[i].str_tmp);
    }

    fclose(file_incr);
    fclose(file_decr);
}



void aSort(int *a, int n)
{
    int i;
    int min = a[0], max = a[0];
    for (i=0; i<n; i++)
    {
        if (a[i] < min) min = a[i];
        if (a[i] > max) max = a[i];
    }
    int range = max - min + 1;
    int holes[range];
    for (i = 0; i < range; i++)
        holes[i] = 0;

    for (i=0; i<n; i++)
        holes[a[i]-min]++;

    int index = 0;
    for (i=0; i < range; i++)
        while (holes[i]-- > 0)
        {
            a[index++] = i + min;
        }
}

int main()
{
    // 1. Készíts programot, ami 10 egész számot bekér billentyűzetről, növekvő sorba rendezi őket, majd bináris fájlba kiírja azokat ("növekvő.dat")!
    int a[10];
    int n = 10;

    FILE *file_incr;
    file_incr = fopen("novekvo.dat", "w");

    for (int i=0; i<n; i++)
    {
        a[i] = (rand() % (UPPER - LOWER + 1)) + LOWER;
    }
    printf("Eredeti tomb: \n");
    aPrint(a,n);

    aSort(a,n);
    printf("Rendezett tomb: \n");
    aPrint(a,n);
    aPrintf(file_incr, a, n); // novekvo.dat

    // 2. Az előző program adatait olvassuk vissza, majd csökkenő sorrendbe rendezve az adatokat, írjuk ki egy "csökkenő.dat" nevű fájlba!
    file_incr = fopen("novekvo.dat", "r");
    aPrintfRev(file_incr);


    return 0;
}
