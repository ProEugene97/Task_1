/*
    Создать структуру для хранения информации о музыкальной композиции: ее авторе, исполнителе, названии и длительности.
 Составить с ее использованием программу вывода информации обо всех песнях, исполненных своим автором.
*/


#include <stdio.h>
#include <string.h>

#define SIZE 64

typedef struct {
    char title[SIZE];
    char author[SIZE];
    char singer[SIZE];
    int duration;
} Single;

int author_is_singer(const Single* single) {
    if (single != NULL) {
        if (!strncmp(single->author, single->singer, SIZE) && strncmp(single->title, "\n", 1)) {
            return 1;
        } else
            return 0;
    } else
        return 0;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Error: add file");
        return 0;
    }
    FILE *file;
    if ((file = fopen(argv[1], "r")) == NULL)
    {
        printf("Error: can't open file");
        return 0;
    }
    int n = 0;
    fscanf(file, "%i", &n);
    for (int i = 0; i < n; ++i) {
        char c[2];
        fgets(c, 2, file);
        Single single;
        fgets(single.title, SIZE, file);
        fgets(single.author, SIZE,file);
        fgets(single.singer, SIZE, file);
        fscanf(file, "%i", &single.duration);
        if (author_is_singer(&single)) {
            printf("title: %s", single.title);
            printf("author: %s", single.author);
            printf("singer: %s", single.singer);
            printf("duration: %i\n", single.duration);
        }
    }
    fclose(file);
    return  0;
}
