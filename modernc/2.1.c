#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * File operation
*/

FILE *open_file(char const *filename, char const *mode)
{
    FILE *file = fopen(filename, mode);
    if (!file)
    {
        perror("open file failed.");
        exit(EXIT_FAILURE);
    }

    return file;
}

#define BUFFER_SIZE 1000

void write_file(char const *filename, char *const line)
{
    FILE *file = open_file(filename, "a");

    fputs("feeling fine today\n", file);
    fclose(file);
}

typedef struct FileModel
{
    char *contents;
    size_t rows;
} FileModel;

FileModel read_file(char const *filename)
{
    FILE *file = file = open_file(filename, "r");

    fseek(file, 0, SEEK_END);

    long filesize;
    char *str = NULL;
    char txt[BUFFER_SIZE];
    filesize = ftell(file);
    str = (char *)malloc(filesize);
    str[0] = 0;

    rewind(file);
    size_t rows = 0;
    while ((fgets(txt, BUFFER_SIZE, file)) != NULL)
    {
        strcat(str, txt);
        ++rows;
    }
    fclose(file);

    FileModel fm =
        {
            .contents = str,
            .rows = rows,
        };
    return fm;
}

int main(void)
{
    char *const file_name = "modernc/assets/mylog.txt";
    write_file(file_name, "feeling fine today\n");
    FileModel fm = read_file(file_name);
    printf("file content :\n%s\nrows=%zu\n", fm.contents, fm.rows);

    return EXIT_SUCCESS;
}