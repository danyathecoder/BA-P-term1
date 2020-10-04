//В каждом столбце выполнить циклический сдвиг на один элемент.
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
int main()
{
    int **arr; // указатель на указатель на строку элементов
    int i, j, n, m;
    printf("Enter the number of lines: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);
    arr = (int **)malloc(n * sizeof(int *)); // Выделение памяти под указатели на строки
    if (arr == NULL)                         //проверка выделенной памяти
        exit(0);
    // Ввод элементов массива
    for (i = 0; i < n; i++) // цикл по строкам
    {
        arr[i] = (int *)malloc(m * sizeof(int)); // Выделение памяти под хранение строк в i-том массиве
        for (j = 0; j < m; j++)                  // цикл по столбцам
        {
            printf("array[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    // Вывод элементов массива
    printf("Array unchanged\n");
    for (i = 0; i < n; i++) // цикл по строкам
    {
        for (j = 0; j < m; j++) // цикл по столбцам
        {
            printf("%5d ", arr[i][j]); // 5 знакомест под элемент массива
        }
        printf("\n");
    }
    int *tmp = *arr;
    for(int i=0; i<n-1;i++)
    {
        *(arr+i)=*(arr+i+1); 
    }
    *(arr+n-1)=tmp;
    // Вывод элементов массива
    printf("Array changed\n");
    for (i = 0; i < n; i++) // цикл по строкам
    {
        for (j = 0; j < m; j++) // цикл по столбцам
        {
            printf("%5d ", arr[i][j]); // 5 знакомест под элемент массива
        }
        printf("\n");
    }
    // Очистка памяти
    for (i = 0; i < n; i++) // цикл по строкам
        free(arr[i]);       // освобождение памяти под строку
    free(arr);
    return 0;
}