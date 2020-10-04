#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void memcheck(int **arr){//memory allocation checking
    if(arr == NULL)
    {
        printf("Mermory error");
        exit(0);
    }
}

int** input(int **arr, int n) {//input array (REMEMBER! YOU MUST RETURN POINTER BACK TO FUNCTION OR GET TO FUNCTION ADRESS OF )
    arr = (int **) malloc(n * sizeof(int *));
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = (int *) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            arr[i][j] = rand() % 10;
    }
    memcheck(arr);

    return arr;
}

void output(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

void transpose(int **arr, int n) {//additional diagonal
    int i =0;
    while(i<n){
        int j=0;
        while(j<n-i-1){
            int tmp = arr[i][j];
            arr[i][j]=arr[n-1-j][n-1-i];
            arr[n-1-j][n-1-i]=tmp;
            j++;
        }
        i++;
    }
}

int main() {
    int **arr, n, m;
    printf("Enter the number of lines and columns:");
    scanf("%d", &n);

    arr = input(arr, n);
    printf("untransposed matrix\n");
    output(arr, n);

    transpose(arr, n);
    printf("transposed matrix\n");
    output(arr, n);

    return 0;
}
