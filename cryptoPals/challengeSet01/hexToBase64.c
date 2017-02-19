#include <stdlib.h>
#include <string.h>
#include "hexToBase64.h"

char * hexToBase64(const char hexString[])
{
	const char const b64Chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                              "abcdefghijklmnopqrstuvwxyz"
                              "0123456789+/";
	const size_t chunkLen = 3;
	const size_t hexCharBits = 4;
	const size_t b64CharBits = 6;

	size_t hexLen = strlen(hexString);
	size_t nHexBits = hexLen * 4;
	size_t padding = b64CharBits - (hexCharBits) % b64CharBits;
	if (padding == b64CharBits) padding = 0;
	size_t b64Len = 1 + ((nHexBits + padding) / b64CharBits);

	size_t b64Idx = 0;
	char *b64Out = malloc(b64Len);

	if (!b64Out)
	{
		exit(EXIT_FAILURE);
	}

	memset(b64Out, 0, b64Len);

	for (size_t i = 0; i < hexLen; i += chunkLen)
	{
		char subBuf[chunkLen];
		memcpy(subBuf, &hexString[i], chunkLen);
		long hNum = strtol(subBuf, NULL, 16);

		b64Out[b64Idx++] = b64Chars[((hNum>>6)&63)];
		b64Out[b64Idx++] = b64Chars[hNum&63];
	}

	return b64Out;
}