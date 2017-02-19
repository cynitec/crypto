#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// const char* hexIn = "49276D";
// 0x492 = 1170 = 0100 1001 0010
// = 010010 010010 = 18 18 = S S
// 0x76D = 1901 = 0111 0110 1101
// = 011101 101101 = 29 45 = d t

// 0x4 = 4 = 0000 0010 = PP0010 = 4 = E;
// 0x49 = 73 = 0100 1001 = PPPP01 001001 = 1 9 = B J

// echo "obase=2; 4794221" | bc

char b64Index[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
				  "abcdefghijklmnopqrstuvwxyz"
                  "0123456789+/";

const size_t chunkLen = 3;

int main(int argc, char *argv[])
{
	const char * const hexString = "49276D";
	size_t hexLen = strlen(hexString);
	size_t hexBits = hexLen * 4;
	size_t hexPadding = 6 - (hexBits) % 6;
	if (hexPadding == 6) hexPadding = 0;

	printf("hexLen: %lu, hexPadding: %lu\n", hexLen, hexPadding);

	size_t b64Len = (hexBits + hexPadding) / 6;

	printf("b64Len: %lu\n", b64Len);

	size_t b64Idx = 0;
	char b64Out[b64Len];	// TODO memset?

	for (int i = 0; i < hexLen; i += chunkLen)
	{
		char subBuf[chunkLen];
		memcpy(subBuf, &hexString[i], chunkLen);

		long hNum = strtol(subBuf, NULL, 16);

		unsigned char b64_1 = ((hNum>>6)&63);
		unsigned char b64_2 = (hNum&63);

		b64Out[b64Idx++] = b64Index[b64_1];
		b64Out[b64Idx++] = b64Index[b64_2];
	}

	for (int i = 0; i < b64Len; i++)
	{
		printf("%d\t%c\n", i, b64Out[i]);
	}
}
