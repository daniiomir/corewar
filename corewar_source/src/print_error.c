#include "../includes/corewar.h"

void print_error_and_exit(char *errstr, int errno) {
    printf("%s\n", errstr);
    exit(errno);
}

void print_usage()
{
	printf("Usage: ./corewar [-v][-d <num> | -n <num> ] <champion1.cor> <...>\n");
	exit(1);
}
