#include <stdio.h>

char hexIn[] = "0x49276D";
// 4794221
// SSdt
// echo "obase=2; 4794221" | bc
// 00000000 01001001 00100111 01101101
// 00 000000 010010 010010 011101 101101
// >> 010010 = 18 = S
// 010010 = 18 = S
// 011101 = 29 = d
// 101101 = 45 = t

char b64Index[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
				  "abcdefghijklmnopqrstuvwxyz"
                  "0123456789+/";

int main(int argc, char *argv[])
{
	int x = 0x49276D;

	for (int i = 0; i < (sizeof(x)*8)-6; i+=6)
	{
		unsigned char byte = ((x>>i)&63);

		printf("%d\t%c\n", byte, b64Index[byte]);
	}
}
