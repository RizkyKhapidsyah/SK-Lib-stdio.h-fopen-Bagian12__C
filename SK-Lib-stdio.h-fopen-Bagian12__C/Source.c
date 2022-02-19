#pragma warning(disable:4996)

// crt_fopen.c
// compile with: /W3
// This program opens two files. It uses
// fclose to close the first file and
// _fcloseall to close all remaining files.

#include <stdio.h>
#include <conio.h>

/*
    Source by Microsoft
    Modified For Learn by RK
    I.D.E : VS2019
*/

FILE* stream, * stream2;

int main(void) {
    int numclosed;

    // Open for read (will fail if file "crt_fopen.c" does not exist)
    if ((stream = fopen("crt_fopen.c", "r")) == NULL) // C4996
    // Note: fopen is deprecated; consider using fopen_s instead
        printf("The file 'crt_fopen.c' was not opened\n");
    else
        printf("The file 'crt_fopen.c' was opened\n");

    // Open for write
    if ((stream2 = fopen("data2", "w+")) == NULL) // C4996
        printf("The file 'data2' was not opened\n");
    else
        printf("The file 'data2' was opened\n");

    // Close stream if it is not NULL
    if (stream) {
        if (fclose(stream)) {
            printf("The file 'crt_fopen.c' was not closed\n");
        }
    }

    // All other files are closed:
    numclosed = _fcloseall();
    printf("Number of files closed by _fcloseall: %u\n", numclosed);

    _getch();
    return 0;
}