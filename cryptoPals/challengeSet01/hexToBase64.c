#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// echo "obase=2; 4794221" | bc

char b64Chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
				  "abcdefghijklmnopqrstuvwxyz"
                  "0123456789+/";

const size_t chunkLen = 3;
const size_t hexCharBits = 4;
const size_t b64CharBits = 6;
const char * const hexString =
	"49276d206b696c6c696e6720796f757220627261696e206c"
	"696b65206120706f69736f6e6f7573206d757368726f6f6d";

int main(int argc, char *argv[])
{
	size_t hexLen = strlen(hexString);
	size_t nHexBits = hexLen * 4;
	size_t padding = b64CharBits - (hexCharBits) % b64CharBits;
	if (padding == b64CharBits) padding = 0;
	size_t b64Len = (nHexBits + padding) / b64CharBits;

	size_t b64Idx = 0;
	char b64Out[b64Len];
	memset(b64Out, 0, b64Len);

	for (size_t i = 0; i < hexLen; i += chunkLen)
	{
		char subBuf[chunkLen];
		memcpy(subBuf, &hexString[i], chunkLen);
		long hNum = strtol(subBuf, NULL, 16);

		b64Out[b64Idx++] = b64Chars[((hNum>>6)&63)];
		b64Out[b64Idx++] = b64Chars[hNum&63];
	}

	for (size_t i = 0; i < b64Len; i++)
	{
		printf("%c", b64Out[i]);
	}
	puts("");
}