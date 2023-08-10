#ifndef MAIN_H
#define MAIN_H

/* ============== Header Files ============*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

char **splitStringToArray(const char *str, const char *delim);

#endif
