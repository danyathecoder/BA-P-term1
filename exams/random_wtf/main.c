// Два массива вещественных чисел (при вводе должны быть отсортированы по убыванию).
// В функции объединить их в третий массив упорядоченный по убыванию(без сортировки).

#include <stdio.h>
#include <stdlib.h>

void memcheck(float *arr) //memory checking
{
    if (arr==NULL) {
        printf("Memory allocation error");
        exit(42);
    }
}

void input(float *arr, int size){// filing the array
    for(int i=0; i<size; i++)
    {
        printf("arr[%d]: ",i);
        scanf("%f",&arr[i]);
    }
}
void output(float *arr, int size){// output array

    for (int i=0; i<size; i++){
        printf("arr[%d]: %f ",i, arr[i]);
    }

}
void hoare(float *arr, int r, int l) {//hoare's sort

    int i, j;
    int md = arr[(l+r)/2];//element for comparing
    i = l;//starts form left
    j = r;//starts from right
    do
    {
        while(arr[i]>md)i++;//searching of 'wrong element'(smaller on the left side than chosen)
        while(arr[j]<md)j--;//searching of 'wrong element'(bigger on the right side than chosen)
        if(i<=j)//we can swap something with chosen element
        {
            int tmp = arr[i];//swap
            arr[i]=arr[j];//swap
            arr[j]=tmp;//swap
            i++;// go to the right
            j--;//go to the left
        }

    }while(i<=j);//there can be only 2 sides

    if(i<r)//if i -- correct, sort right side
    {
        hoare(arr, i, r);
    }

    if(j>l)//if j -- correct, sort left side
    {
        hoare(arr, j, l);
    }
}

void merge(float *arr1, float *arr2, int n, int m){
    int k = m+n;
    int i = 0;
    int j = 0;
    int p = 0;
    float arr[k];
    while(p<k){
            if (arr1[i] >= arr2[j]&&i<n&&j<=m) {//fill in with the bigger element if everything is ok
                arr[p] = arr1[i];
                i++;
                p++;
                continue;
            }
            if (arr1[i] <= arr2[j]&&j<m&&i<=n) {//fill in with the bigger element if everything is ok
                arr[p] = arr2[j];
                j++;
                p++;
                continue;
            }
            if(j>=m){//fill in with arr1
                for(;p<k;p++){
                    arr[p] = arr1[i];
                    i++;
                }
                break;
            }
            if(i>=n){//fill in with arr2
                for(;p<k;p++){
                    arr[p] = arr2[j];
                    j++;
                }
                break;
            }
    }
    printf("Merged array:\n");
    output(arr, k);
}

int main() {
    int n , m;

    printf("Enter the size of the first array:\n");
    scanf("%d",&n);
    float *arr1 = (float*)malloc(n*sizeof(float));

    printf("\n");

    printf("Enter the size of the second array:\n");
    scanf("%d",&m);
    float *arr2 = (float*)malloc(m*sizeof(float));

    memcheck(arr1);
    memcheck(arr2);

    printf("Fill the first array\n");
    input(arr1, n);
    rewind(stdin);
    printf("Fill the second array\n");
    input(arr2, m);
    rewind(stdin);

    printf("The first unsorted array:\n");
    output(arr1, n);
    printf("\n");

    printf("The second unsorted array:\n");
    output(arr2, m);
    printf("\n");

    hoare(arr1, n-1, 0);
    hoare(arr2, m-1, 0);

    printf("The first sorted array:\n");
    output(arr1, n);
    printf("\n");

    printf("The second sorted array:\n");
    output(arr2, m);
    printf("\n");

    int k = m+n;
    float arr3[k];

    merge(arr1, arr2, n, m);

    free(arr1);
    free(arr2);
    return 0;
}
