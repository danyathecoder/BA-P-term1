//Заполнить элементы двумерного массива натуральными числами. Из каждой нечётной
//(нумерация начинается с 0) строки удалить минимальный элемент.
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
    {
        printf("Mermory error");
        exit(0);
    }
    // Ввод элементов массива
    for (i = 0; i < n; i++) // цикл по строкам
    {
        arr[i] = (int *)malloc(m * sizeof(int)); // Выделение памяти под хранение строк в i-том массиве
        for (j = 0; j < m; j++)                  // цикл по столбцам
        {
            printf("array[%d][%d] = ", i, j);
            while (!scanf("%d", &arr[i][j]) || arr[i][j] <= 0)
                printf("INPUT ERORR\n");
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
    for (i = 1; i < n; i + 2) //ходим по строкам
    {
        int min = arr[i][0];
        for (j = 1; j < m; j++) //ищем минимальный
        {
            if (min > arr[i][j])
                min = arr[i][j];
        }
        for (int j = 0; j < m; j++) //выбираем элемент массива
        {
            if (arr[i][j] == min) //сравнение
            {
                for (int k = j; k < m - 1; k++) //цикл перезаписи
                {
                    arr[i][k] = arr[i][k + 1];
                }
            }
        }
    }
    m--; //уменьшаем размер массива
    arr[i] = (int *)realloc(arr, m * sizeof(int));
    j--; //уменьшаем количество индексов в массиве (чтобы не выскакивать за размер)

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