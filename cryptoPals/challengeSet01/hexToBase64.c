#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// assumes little endian
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;

    for (int i = size-1; i >= 0; i--)
    {
        for (int j = 7; j >= 0; j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

int main(int argc, char *argv[])
{
    int i = 23;
    uint ui = UINT_MAX;
    int iMin = INT_MIN;
    float f = 23.45f;
    printBits(sizeof(i), &i);
    printBits(sizeof(ui), &ui);
    printBits(sizeof(f), &f);
    printBits(sizeof(iMin), &iMin);
    return 0;
}
