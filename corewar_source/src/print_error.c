#include "../includes/corewar.h"

void print_error_and_exit(char *errstr, int errno) {
    printf("%s\n", errstr);
    exit(errno);
}
