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

int check_board(board_t board)
{
	/* row */
	for (int i = 0; i < BOARD_SZ; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			if (board[i][0] == 'X')
				return 1;
			else if (board[i][0] == 'O')
				return -1;
		}
	}

	/* col */
	for (int i = 0; i < BOARD_SZ; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
			if (board[0][i] == 'X')
				return 1;
			else if (board[0][i] == 'O')
				return -1;
		}
	}
	return 0;
}

void print_res(int res)
{
	switch (res) {
		case 1:
			printf("X wins\n");
			break;
		case -1:
			printf("O wins\n");
			break;
		default:
			printf("draw\n");
	}
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
	} else if (!strcmp(argv[1], "debug")) {
		/* debug case */
		char *board_val[] = {"O", "_", "_", "X", "X", "X", "O", "_", "_"};
		init_board(&board, board_val);
		print_board(board);
		print_res(check_board(board));
		return 0;
	} else if (!strcmp(argv[1], "print")) {
		for (int r = 0; r < BOARD_SZ; r++) {
			for (int c = 0; c < BOARD_SZ; c++) {
				board[r][c] = '_';
			}
		}
		print_board(board);
		return 0;
	} else if (!strcmp(argv[1], "init")) {
		char *board_val[]  = {"X", "_", "O", "_", "X", "_", "_", "_", "O"};
		init_board(&board, board_val);
		if ((board[0][0] == 'X') && (board[0][0] == board[1][1]) &&
		    (board[0][1] == '_') && (board[0][1] == board[1][0]) &&
		    (board[0][1] == board[1][2]) && (board[0][1] == board[2][0]) &&
		    (board[0][1] == board[2][1]) && (board[0][2] == 'O') &&
		    (board[0][2] == board[2][2])) {
			printf("init success\n");
		} else {
			printf("init fail\n");
		}
	} else if (!strcmp(argv[1], "board")) {
		char *board_val[] = {"X", "_", "O", "_", "X", "_", "_", "_", "O"};
		init_board(&board, board_val);
		print_board(board);
	} else if (!strcmp(argv[1], "check")) {
		board[0][0] = board[0][1] = board[0][2] = 'X';
		board[1][0] = board[1][2] = board[2][0] = board[2][1] = '_';
		board[1][1] = board[2][2] = 'O';
		print_res(check_board(board));
	} else if (!strcmp(argv[1], "xhoriz")) {
		char *board_val[] = {"X", "X", "X", "_", "O", "_", "_", "_", "O"};
		init_board(&board, board_val);
		print_board(board);
		printf("X wins\n");
		return 0;
	} else if (!strcmp(argv[1], "overt")) {
		char *board_val[]  = { "X", "X", "O", "_", "_", "O", "_", "_", "O"};
		init_board(&board, board_val);
		print_board(board);
		print_res(check_board(board));
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
