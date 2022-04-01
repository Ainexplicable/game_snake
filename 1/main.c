#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Common.h"

int main()
{
	srand((unsigned int)time(0));
	hello_world();
	char str[INPUT_LEN];
	char arg[ARG_NUM][ARG_LEN];
	for (;;) {
		printf("player> ");
		memset(str, 0, sizeof(str));
		memset(arg, 0, sizeof(arg));
		fgets(str, INPUT_LEN, stdin);
		if (parse(arg, str) == 0) {
			execute_args(arg);
		}
	}
}
