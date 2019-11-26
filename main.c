#include <stdio.h>
#include <stdlib.h>

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

void aPrintf(int a[], int n)
{
    FILE *file;
    file = fopen("novekvo.dat", "w");

    for (int i=0; i<n; i++)
    {
        fprintf(file, "%d ", a[i]);
    }

    fclose(file);
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

    for (int i=0; i<n; i++)
    {
        a[i] = (rand() % (UPPER - LOWER + 1)) + LOWER;
    }
    printf("Eredeti tomb: \n");
    aPrint(a,n);

    aSort(a,n);
    printf("Rendezett tomb: \n");
    aPrint(a,n);
    aPrintf(a,n);



    return 0;
}
