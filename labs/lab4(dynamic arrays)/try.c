//Заполнить с клавиатуры два массива. Из первого удалить все числа, встречающиеся во втором.
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int main()
{
    int n, m;
    int *arr1, *arr2;
    printf("Enter size of first array: ");
    scanf("%d", &n); // ввод размера первого массива
    printf("Enter size of second array: ");
    scanf("%d", &m); // ввод размера второго массива

    arr1 = (int *)malloc(n * sizeof(int)); //выделение памяти
    arr2 = (int *)malloc(m * sizeof(int)); //выделение памяти

    if (arr1 == NULL || arr2 == NULL) //проверка выделенной памяти
    {
        printf("not enough memory");
        exit(0);
    }

    for (int i = 0; i < n; i++) //заполнение первого массива
    {
        printf("Enter %d value of first array: ", i);
        scanf("%d", &arr1[i]);
    }
    printf("\n");
    for (int j = 0; j < m; j++) //заполнение второго массива
    {
        printf("Enter %d value of second array: ", j);
        scanf("%d", &arr2[j]);
    }
    printf("\n");
    printf("First array (unchanged): \n");
    for (int i = 0; i < n; i++)
        printf("Value of element number %d = %d\n", i, *(arr1 + i)); //вывод значения из первого
    printf("Second array (unchanged): \n");
    for (int j = 0; j < m; j++)
        printf("Value of element number %d = %d\n", j, *(arr2 + j)); //вывод значения из второго

    for (int j = 0; j < m; j++) //выбираем элемент второго массива для сравнения
    {
        for (int i = 0; i < n; i++) //выбираем элемент первого массива
        {
            if (arr1[i] == arr2[j]) //сравнение
            {
                for (int k = i; k < n; k++) //цикл перезаписи
                {
                    arr1[i] = arr1[i + 1];
                }
                n--; //уменьшаем размер массива
                arr1 = (int *)realloc(arr1, n * sizeof(int));
                i--; //уменьшаем количество индексов в массиве (чтобы не выскакивать за размер)
            }
        }
    }
    printf("First array (changed): \n");
    for (int i = 0; i < n; i++)
        printf("Value of element number %d = %d\n", i, *(arr1 + i)); //вывод значения из первого
    free(arr1);
    free(arr2);
    return 0;
}
