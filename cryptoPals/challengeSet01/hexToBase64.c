#include <stdio.h>

int main(int argc, char *argv[])
{
    int x = 13;     // 1101

    unsigned char byte = 0;

    byte = (x&1) + (x&2) + (x&4) + (x&8) + (x&16) + (x&32);

    printf("%u\n", byte);
}
