#ifndef PROF_H
#define PROF_H

#include <stdio.h>
#include <time.h>
#include <unistd.h>

static const char *current_function;
static double time_spent;
static clock_t begin;
static clock_t end;

#define PROF_BEGIN(name)    time_spent = 0.0;\
                            begin = clock();\
                            current_function = #name;

#define PROF_END    end = clock();\
                    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;\
                    printf("%s execution took %f seconds\n", current_function, time_spent);
#endif
