//отсортировать по убыванию методом вставок
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
//выбираем новый элемент и ставим его в нужное место
void insertion(int *array, int n) // array - указатель на массив, а n - число его элементов
{
    int tmp, j;
    for (int i = 1; i < n; i++)
    {
        j = i - 1;                       // запоминаем номер предыдущего элемента
        tmp = array[i];                  // запоминаем значение текущего элемента
        while (j >= 0 && tmp > array[j]) //цикл, в который мы входим, если два соседних не так стоят
        {
            array[j + 1] = array[j]; //присваиваем текущему значение предыдущего
            j--;                     //делаем индекс предыдущего меньше на 1
        }
        array[j + 1] = tmp; //перезаписываю предыдущий на текущий, согласно индексам
    }
    printf("\nSorted array (by insertion)\n");
    for (int i = 0; i < n; i++)
    {
        printf("[%d] %d; ", i, *(array + i));
    }
    printf("\n");
}
int main()
{
    int *arr;
    int n, tmp;
    printf("Enter size of array to sort ");
    scanf("%d", &n);                      // ввод размера массива
    arr = (int *)malloc(n * sizeof(int)); //инициализация массива
    if (arr == NULL)                      //проверка на выделение памяти
        exit;

    for (int i = 0; i < n; i++) //заполнение массива
    {
        printf("[%d] ", i);
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array\n"); //вывод введенного массива
    for (int i = 0; i < n; i++)
    {
        printf("[%d] %d; ", i, *(arr + i));
    }
    insertion(arr, n);
    free(arr);
    return 0;
}