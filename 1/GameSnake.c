#include "GameSnake.h"

int matrix[HEIGHT][WIDTH];
char sep_line[WIDTH * 2 + 3];
int highest_score = 0;

/**
 * return
 * 0 - quit
 * 1 - failed
 * 2 - matrix is full
 */
int game_snake(struct LinkedList* snake) {
	memset(matrix, 0, sizeof(matrix));
	memset(sep_line, '-', sizeof(sep_line));
	sep_line[strlen(sep_line) - 1] = 0;

	int start = WIDTH * (HEIGHT / 2) - WIDTH / 2;
	enqueue(snake, start);
	*value_in_matrix(start) = SNAKE_HEAD;

	int dst = generate_dst();
	*value_in_matrix(dst) = SNAKE_DST;
	char keypress = 0;

	for (;;) {
		clear_screen();
		show_parameters(keypress, rear(snake), dst);
		display();
		show_score(snake->size - 1);
		printf("(press h for help or q to quit)\n");

		int next = rear(snake);
		keypress = (char)getch();
		switch (keypress) {
		case 'w':
			if (next - WIDTH >= 0)
				next -= WIDTH;
			else
				return 1;
			break;
		case 's':
			if (next + WIDTH < HEIGHT * WIDTH)
				next += WIDTH;
			else
				return 1;
			break;
		case 'a':
			if (next % WIDTH > 0)
				next--;
			else
				return 1;
			break;
		case 'd':
			if (next % WIDTH < WIDTH - 1)
				next++;
			else
				return 1;
			break;
		case 'h':
			didact();
			continue;
		case 'q':
			return 0;
		default:
			printf("Invalid input.\n");
			continue;
		}

		// a position has a specific value in the matrix
		// representing the type of this cell in the previous step

		// mark the previous head as body
		*value_in_matrix(rear(snake)) = SNAKE_BODY;

		// insert the new head
		enqueue(snake, next);

		if (snake->size == WIDTH * HEIGHT) {
			return 2;
		}

		int* head = value_in_matrix(rear(snake));

		if (*head == SNAKE_DST) {
			// destination is found
			dst = generate_dst();
			*value_in_matrix(dst) = SNAKE_DST;
		}
		else {
			// remove the tail and mark as empty
			*value_in_matrix(dequeue(snake)) = SNAKE_EMPTY;
		}

		// if the current head has already been
		// occupied by its body, game fails.
		if (*head == SNAKE_BODY) {
			return 1;
		}

		*head = SNAKE_HEAD;
	}
}

int generate_dst() {
	for (;;) {
		int dst = rand() % (HEIGHT * WIDTH);
		if (*value_in_matrix(dst) == SNAKE_EMPTY) {
			return dst;
		}
	}
}

int* value_in_matrix(int pos) {
	return &matrix[pos / WIDTH][pos % WIDTH];
}
