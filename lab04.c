#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lab04.h"

void init_board(board_t *board, char **board_val)
{
	for (int i = 0; i < BOARD_SZ; i++) {
		for (int j = 0; j < BOARD_SZ; j++) {
			(*board)[i][j] = board_val[i*BOARD_SZ+j][0];
		}
	}
}

void print_board(board_t board)
{
	for (int i = 0; i < BOARD_SZ; i++) {
		for (int j = 0; j < BOARD_SZ; j++) {
			printf(" %c ", board[i][j]);
			if (j < BOARD_SZ - 1)
				printf("|");
		}
		if (i < BOARD_SZ - 1)
			printf("\n---+---+---\n");
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("invalid arguments\n");
		exit(-1);
	}

	board_t board;

	if (!strcmp(argv[1], "empty")) {
		char *board_val[] = {"_", "_", "_", "_", "_", "_", "_", "_", "_"};
		init_board(&board, board_val);
		print_board(board);
		return 0;
	} else if (!strcmp(argv[1], "xhoriz")) {
		char *board_val[] = {"X", "X", "X", "_", "O", "_", "_", "_", "O"};
		init_board(&board, board_val);
		print_board(board);
		printf("X wins\n");
		return 0;
	} else if (!strcmp(argv[1], "draw")) {
		char *board_val[] = {"X", "O", "X", "O", "X", "O", "O", "X", "O"};
		init_board(&board, board_val);
		print_board(board);
		printf("draw\n");
		return 0;
	} else {
		printf("invalid arguments\n");
		exit(-1);
	}
}
