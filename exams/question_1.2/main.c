/*#include <stdio.h>
#include <stdlib.h>

char** input(int n){
    char** arr= (char**)malloc(n * sizeof(char*));//allocation for n lines
    for(int i = 0; i < n; i++) {
        rewind(stdin);
        gets(arr[i]);
    }
    return arr;
}


int main(){

    char **txt;
    int n;
    printf("Enter the amount of lines: ");
    scanf("%d", &n);
    txt=input(n);
    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getSize() {
    int size;
    while(!(scanf("%d", &size)) || size <=0) {
        printf("error\n");
        rewind(stdin);
    }
    return size;
}

int isLetter(char c) {
    return (c <= 'z' && c >= 'a') ? 1 : 0;
}



void getMaxWord(char** text, int size) {
    int max_start = 0, max_end = 0, start, end, fl = 0, max_str = 0;
    for(int i = 0; i < size; i++) {
        for(int j = 0; text[i][j]; j++) {
            while(!isLetter(text[i][j]) && text[i][j] != '\0')
                j++;
            start = j;
            while(isLetter(text[i][j]))
                j++;
            end = j;
            if(end - start > max_end - max_start) {
                max_end = end;
                max_start = start;
                max_str = i;
            }
        }
    }

    for(int i = max_start; i <= max_end; i++)
        printf("%c", text[max_str][i]);
}


int main() {
    char** text, size, len, i;
    size = getSize();
    len = getSize();

    if(!(text = (char**)malloc(size * sizeof(char*)))) {
        printf("Error of allocation\n");
        return 0;
    }
    for(int i = 0; i < size; i++) {
        if(!(*(text + i) = (char*)malloc(len))) {
            printf("Error of allocation\n");
            for(i; i >= 0; i--)
                free(*(text + i));
            free(text);
        }
    }
    for(int i = 0; i < size; i++) {
        rewind(stdin);
        gets(text[i]);
    }

    getMaxWord(text, size);

    for(int i = 0; i < 0; i++) {
        free(text[i]);
    }
    free(text);
    return 0;
}

 