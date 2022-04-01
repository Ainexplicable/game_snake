#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "Common.h"

#define INPUT_LEN 100
#define ARG_NUM 11
#define ARG_LEN 21

void hello_world();

int parse(char(*arg)[ARG_LEN], char* str);

void execute_args(char(*arg)[ARG_LEN]);

void man_set();

void didact();

void show_parameters(char keypress, int head, int dst);

void show_score(int score);

void display();

void do_sleep(double seconds);

void pause();
