#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hexToBase64.h"

int main(int argc, char *argv[])
{
	// if (argc < 2)
	// {
	// 	puts("Usage:");
	// 	printf("\t%s <hexString>\n", argv[0]);
	// 	exit(EXIT_FAILURE);
	// }

	char * b64Out = hexToBase64("49276d206b696c6c696e6720796f7572206"
                                "27261696e206c696b65206120706f69736f"
                                "6e6f7573206d757368726f6f6d");

	// char * b64Out = hexToBase64(argv[1]);

	for (size_t i = 0; i < strlen(b64Out); i++)
	{
		printf("%c", b64Out[i]);
	}
	free(b64Out);
	puts("");
}