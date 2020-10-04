//Заполнить массив с клавиатуры. Удалить из массива все отрицательные значения.
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int main()
{
    int n;
    int *arr1;
    printf("Enter size of array: ");
    scanf("%d", &n); // ввод размера первого массива

    arr1 = (int *)malloc(n * sizeof(int)); //выделение памяти

    if (arr1 == NULL) //проверка выделенной памяти
    {
        printf("not enough memory");
        exit(0);
    }

    for (int i = 0; i < n; i++) //заполнение первого массива
    {
        printf("Enter %d value of array: ", i);
        scanf("%d", &arr1[i]);
    }
    printf("\n");
    printf("Array: \n");
    for (int i = 0; i < n; i++)
        printf("Value of element number %d = %d\n", i, *(arr1 + i)); //вывод значения из первого

    for (int i = 0; i < n; i++) //выбираем элемент первого массива
    {
        if (arr1[i] < 0) //сравнение
        {
            for (int k = i; k < n-1; k++) //цикл перезаписи
            {
                arr1[k] = arr1[k + 1];
            }
            n--; //уменьшаем размер массива
            arr1 = (int *)realloc(arr1, n * sizeof(int));
            i--; //уменьшаем количество индексов в массиве (чтобы не выскакивать за размер)
        }
    }

    printf("Array (changed): \n");
    for (int i = 0; i < n; i++)
        printf("Value of element number %d = %d\n", i, *(arr1 + i)); //вывод значения из первого
    free(arr1);
    return 0;
}
