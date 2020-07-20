#include <stdio.h>

/*
General notes
O will be denoted with char 'O'
X will be denoted with char 'X'
empty will be denoted with char '.'
*/


/*
Checks if the board is a win for either player, a draw, or there is still play
Inputs:

returns:
int:
 - 0 = player O wins
 - 1 = player X wins
 - 2 = There is still play
 - 3 = draw
*/
int board_status(char[9]);

/*
Loops until a valid new move is entered by the user
*/
int get_player_choice(char[9]);

/*
Player vs Random Computer Play Gamemode
*/
void player_vs_computer();

/*
2 player gamemode
*/
void player_vs_player();

/*
Show current board status
*/
void print_board(char[9]);

int main()
{
    srand(time(NULL)); // To use for random computer play

	printf("Select game mode (enter the integer denoting your choice):\n");
choosing_gamemodes:
	printf("1) Player vs Computer\n");
	printf("2) Player vs Player\n");

	int game_mode;
	scanf("%d", &game_mode);

	if (game_mode == 1) { // Player vs Computer gamemode
		player_vs_computer();
	}
	else if (game_mode == 2) { // Player vs Player gamemode
		player_vs_player();
	}
	else { // Undefined gamemode
		printf("%d is an undefined gamemode, please enter with 1 or 2 to choose one of the following:\n", game_mode);
		goto choosing_gamemodes;
	}

	return 0;
}


int board_status(char board[9]) {
    // Checking rows and columns
    for(int i = 0; i < 3; i++){
        int row_cond = board[3*i]==board[3*i+1]&&board[3*i+1]==board[3*i+2];
        int col_cond = board[i]==board[i+3]&&board[i+3]==board[i+6];
        if(row_cond && board[3*i] != '.'){
            return board[3*i]=='O' ? 0 : 1;
        }else if(col_cond && board[i] != '.'){
            return board[i]=='O' ? 0 : 1;
        }
    }

    // Checking diagonals
    int diagonal_cond  = board[0]==board[4]&&board[4]==board[8] || board[2]==board[4]&&board[4]==board[6];
    if(diagonal_cond && board[4] != '.'){
        return board[4]=='O' ? 0 : 1;
    }

    // Checking if there is an empty space to continue the game
    for(int i = 0; i < 9; i++){
        if(board[i]=='.'){
            return 2;
        }
    }


    return 3; // Draw
}


void print_board(char board[9]) {
	for (int i = 0; i < 3; i++) {
		printf(" %c | %c | %c \n", board[3*i], board[3*i+1], board[3*i+2]);
			if (i < 2) {
				printf("---|---|---\n");
			}
	}
}


int get_player_choice(char board[9]){
    int player_choice;

    while(1){
        // Get player choice
        scanf("%d",&player_choice);
        player_choice--; // For indexing 0 to 8

        // Assert choice is between 0 and 8 inclusive
        if(player_choice<0 || player_choice>8){
            printf("Please enter an integer between 1 and 9 (inclusive) \n");
            continue;
        }

        // Assert board location is clear
        if(board[player_choice]!='.'){
            printf("Please choose an empty spot\n");
            continue;
        }
        return player_choice;
    }
}


// Computer get move (random play)
int get_random_computer_move(char board[9]){
    int r,valid_choice;

    do{
        r = rand()%9;
        valid_choice = board[r]=='.' ? 1 : 0;
    }while(valid_choice==0);

    return r;
}

void player_vs_computer() {
    // Intialize an empty board
    char board[9];
    for(int i = 0; i < 9; i++){
            board[i] = '.';
    }

    char current_char = 'X';
    char player_char = 'X'; // Can be changed to allow user to play using O

    while(1){
        // Show current board
        print_board(board);

        // Get next player's move
        if(current_char==player_char){
            int player_choice = get_player_choice(board);

            board[player_choice] = current_char;
        }else{
            int computer_choice = get_random_computer_move(board);
            board[computer_choice] = current_char;
        }

        // Update game status
        int game_status = board_status(board);
        current_char = current_char=='X' ? 'O' : 'X';

        // Check if win or draw to end game
        switch(game_status){
            case 0:
                print_board(board);
                printf("O wins!");
                return;
                break;
            case 1:
                print_board(board);
                printf("X wins!");
                return;
                break;
            case 3:
                print_board(board);
                printf("Draw");
                return;
                break;
        }
    }
}

void player_vs_player() {
    // Initialize board
    char board[9];
    for(int i = 0; i < 9; i++){
            board[i] = '.';
    }

    char current_char = 'X';

    while(1){
        // Show current board
        print_board(board);

        // Get and execute next player's move
        int player_choice = get_player_choice(board);
        board[player_choice] = current_char;

        // Update game status
        int game_status = board_status(board);
        current_char = current_char=='X' ? 'O' : 'X';

        // Check if win or draw to end game
        switch(game_status){
            case 0:
                print_board(board);
                printf("O wins!");
                return;
                break;
            case 1:
                print_board(board);
                printf("X wins!");
                return;
                break;
            case 3:
                print_board(board);
                printf("Draw");
                return;
                break;
        }
    }
}
