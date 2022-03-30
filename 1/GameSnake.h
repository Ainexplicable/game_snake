#pragma once

#define HEIGHT 20
#define WIDTH 20

#define SNAKE_EMPTY 0
#define SNAKE_HEAD 1
#define SNAKE_BODY 2
#define SNAKE_DST 3

extern int matrix[HEIGHT][WIDTH];
extern char sep_line[WIDTH * 2 + 3];
extern int highest_score;
extern char keypress;

int game_snake(struct LinkedList* snake);
int generate_dst();
int* value_in_matrix(int pos);
