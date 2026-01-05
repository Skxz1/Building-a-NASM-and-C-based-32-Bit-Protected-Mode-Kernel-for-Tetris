#include "../cpu/idt.h"
#include "../cpu/isr.h"
#include "util.h"


#define TETRIMINO_AMOUNT 7
#define TETRIMINO_SIZE 16

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

#define TETRIMINO_ROWS 4
#define TETRIMINO_COLS 4

int xStart = 3;
int yindex = 0;
int count = 0;
int placed = 0;
int TetriminoType;
unsigned int seed = 1134212;
int loop = 0;
int timer = 0;

int random_number(unsigned int *seed) {
    *seed = *seed * 11035245 + 13424;
    return (*seed >> 16) % 7;
}


char board[BOARD_HEIGHT * BOARD_WIDTH];

void init_board() {
for (int i = 0; i < BOARD_HEIGHT*BOARD_WIDTH; i++){
    board[i] = '.';
}}


    
char tetrimino[TETRIMINO_AMOUNT][TETRIMINO_SIZE] = {
    {'.', '.', 'X', '.',
     '.', '.', 'X', '.',
     '.', '.', 'X', '.',
     '.', '.', 'X', '.'     }, // I tetromino


    {'.', '.', 'X', '.',
     '.', 'X', 'X', '.',
     '.', 'X', '.', '.',
     '.', '.', '.', '.'     }, // Z tetromino


    {'.', '.', '.', '.',
     '.', 'X', 'X', '.',
     '.', 'X', 'X', '.',
     '.', '.', '.', '.'       }, // O tetromino


    {'.', 'X', '.', '.',
     '.', 'X', 'X', '.',
     '.', '.', 'X', '.',
     '.', '.', '.', '.'       }, // S tetromino


    {'.', '.', 'X', '.',
     '.', 'X', 'X', '.',
     '.', '.', 'X', '.',
     '.', '.', '.', '.'       }, // T tetromino


    {'.', '.', '.', '.',
     '.', 'X', 'X', '.',
     '.', 'X', '.', '.',
     '.', 'X', '.', '.'       }, // J tetromino


    {'.', '.', '.', '.',
     '.', 'X', 'X', '.',
     '.', '.', 'X', '.',
     '.', '.', 'X', '.'       }  // L tetromino
};


void placeTetrimino(int tetriminoType, int xPos, int yPos) {
    // Get the 1D array representing the tetrimino
    char* tetriminoArray = tetrimino[tetriminoType];

    // Calculate the starting index in the board 1D array
    int boardIndex = (yPos * BOARD_WIDTH) + xPos;

    // Loop through each row and column of the tetrimino and update the board
    for (int row = 0; row < TETRIMINO_ROWS; row++) {
        for (int col = 0; col < TETRIMINO_COLS; col++) {
            // Calculate the index of the current cell in the tetrimino array
            int tetriminoIndex = (row * TETRIMINO_COLS) + col;

            // Calculate the index of the current cell in the board array
            int boardOffset = (row * BOARD_WIDTH) + col;

            // If the current cell in the tetrimino is not empty, update the board
            if (tetriminoArray[tetriminoIndex] == 'X') {
                board[boardIndex + boardOffset] = 'X';
            }
        }
    }
}
// An array to store the new rotated tetrimino shapes
char Newtetrimino[TETRIMINO_AMOUNT][TETRIMINO_SIZE];

// The number of times the current tetrimino has been rotated
int rotations = 0;

// The current and new X positions of the tetrimino
int oldX = 0;
int newX = 0;

// A function to rotate the current tetrimino shape
void Rotate(){
    
    // Loop through the rows and columns of the tetrimino shape
    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 4; x++){
            
            // Store the new rotated tetrimino shape in the Newtetrimino array
            Newtetrimino[TetriminoType][oldX] = tetrimino[TetriminoType][12 + y - (x * 4)];
            oldX++;
        }
    }
    
    // Reset the number of rotations and old X position of the tetrimino
    rotations = 0;
    oldX = 0;

    // Copy the new rotated tetrimino shape to the current tetrimino shape
    for(int i = 0; i < 16; i ++){
        tetrimino[TetriminoType][i] = Newtetrimino[TetriminoType][i];
    }
}

// A function to draw the current tetrimino on the game board
void draw_tetrimino() {
    int checkX = 0;
    int checkY = 0;

    // Loop through all the cells on the game board
    for(int i = 0; i < BOARD_HEIGHT * BOARD_WIDTH; i++){

        // Calculate the X and Y positions of the current cell
        checkX = i % 10;
        checkY = i / 10;

        // If the current cell is part of the tetrimino, draw it in the appropriate color
        if(board[i] == 'X'){
            if(TetriminoType == 0){
                Cyanblock(checkX + 11, checkY);
            }
            else if(TetriminoType == 1){
                Greenblock(checkX + 11, checkY);
            }
            else if(TetriminoType == 2){
                Yellowblock(checkX + 11, checkY);
            }
            else if(TetriminoType == 3){
                Redblock(checkX + 11, checkY);
            }
            else if(TetriminoType == 4){
                Pinkblock(checkX + 11, checkY);
            }
            else if(TetriminoType == 5){
                Blueblock(checkX + 11, checkY);
            }
            else if(TetriminoType == 6){
                Orangeblock(checkX + 11, checkY);
            }
        }
        // Otherwise, if the current cell is part of a completed line, draw it in the appropriate color
        else if(board[i] == '1'){
            Cyanblock(checkX + 11, checkY);
        }
        else if(board[i] == '2'){
            Greenblock(checkX + 11, checkY);
        }
        else if(board[i] == '3'){
            Yellowblock(checkX + 11, checkY);
        }
        else if(board[i] == '4'){
            Redblock(checkX + 11, checkY);
        }
        else if(board[i] == '5'){
            Pinkblock(checkX + 11, checkY);
        }

        else if(board[i] == '6'){
            Blueblock(checkX + 11, checkY);
        }
        else if(board[i] == '7'){
            Orangeblock(checkX + 11, checkY);
        }

        else if(board[i] == '.'){
            BlackBlock(checkX + 11, checkY);
        }
    }

}

void start_kernel() {
    clear_screen();
    isr_install();    
    asm volatile("sti");
    init_keyboard();
    

    for(int i = 0; i < 20; i++){
    Grayblock(21,i);
    }

    for(int i = 0; i < 20; i++){
    Grayblock(10,i);
    }

    init_board();
    

while (loop == 0){
TetriminoType = random_number(&seed);

while (placed == 0){
    
placeTetrimino(TetriminoType, xStart, yindex);

clear_line();

draw_tetrimino();

CheckIfTetriminoPlaced();
timer++;
if(timer % 800 == 0){
    shiftdown();

}

}

placed = 0;
GameEnd();

}

    }

void shiftleft(){
    // loop through the leftmost column of the board to count the number of blocks present in it
    for(int z = 0; z < BOARD_HEIGHT*BOARD_WIDTH; z = z + 10){
        if(board[z] == 'X'){
            count ++;
        }
    }
    // loop through each block of the current tetrimino to check if there is a block to the left of it on the board
    for(int i = 0; i < BOARD_HEIGHT*BOARD_WIDTH; i++){
        if(board[i] == 'X'){
            if(board[i-1] == '1' || board[i-1] == '2' || board[i-1] == '3' || board[i-1] == '4' || board[i-1] == '5' || board[i-1] == '6' || board[i-1] == '7'){
                count++;
            }
        }
    }
    // if there are no blocks in the leftmost column of the board and there are no blocks to the left of the current tetrimino on the board
    if(count == 0){
        // if the current tetrimino is not already at the left edge of the board
        if(board[0] != 'X'){
            // loop through each block on the board and move the current tetrimino one block to the left
            for (int i = 0; i < BOARD_HEIGHT*BOARD_WIDTH; i++){
                if(board[i] == 'X'){
                    board[i] = '.';
                    board[i-1] = 'X';
                }
            }
            // decrease the xStart variable by one to reflect the new position of the tetrimino
            xStart--;
        }
    }
    // reset the count variable to 0
    count = 0;
}



void shiftright(){
    // Loop through every 10th element in the board starting from index 9
    for(int z = 9; z < BOARD_HEIGHT*BOARD_WIDTH; z = z + 10){
        // If the element is 'X', increment the count
        if(board[z] == 'X'){
            count ++;
        }
    }
    // Loop through every element in the board
    for(int i = 0; i < BOARD_HEIGHT*BOARD_WIDTH; i++){
        // If the element is 'X'
        if(board[i] == 'X'){
            // Check the adjacent element to the right
            if(board[i+1] == '1' || board[i+1] == '2' || board[i+1] == '3' || board[i+1] == '4' || board[i+1] == '5' || board[i+1] == '6' || board[i+1] == '7'){
                // If the adjacent element to the right is a digit from 1 to 7, increment the count
                count++;
            }
        }
    }
    // If there are no 'X' elements that need to be shifted and the rightmost element is not already an 'X'
    if(count == 0){
        if(board[19] != 'X'){
            // Loop through every element in the board
            for (int i = 0; i < BOARD_HEIGHT*BOARD_WIDTH; i++){
                // Replace any 'X' elements with a '.'
                if(board[i] == 'X'){
                    board[i] = '.';
                }
            }
            // Increment the starting position of the 'X' elements
            xStart++;
        }
    }
    // Reset the count
    count = 0;
}


// Shift all elements down by one row
void shiftdown(){
    // Iterate over all elements on the board
    for (int i = 0; i < BOARD_HEIGHT*BOARD_WIDTH; i++){
        // If an element is 'X', replace it with '.'
        if(board[i] == 'X'){
            board[i] = '.';
        }
    }
    // Increase the index of the current row by one
    yindex ++;
}

// Shift all elements up by one row
void shiftup(){
    // Iterate over all elements on the board
    for (int i = 0; i < BOARD_HEIGHT*BOARD_WIDTH; i++){
        // If an element is 'X', replace it with '.'
        if(board[i] == 'X'){
            board[i] = '.';
        }
    }
    // Decrease the index of the current row by one
    yindex --;
}



void CheckIfTetriminoPlaced() {
    // Loop through the last row of the board
    for (int i = 190; i < 200; i++) {
        if (board[i] == 'X') {
            // Mark all blocks on the board with '1' to indicate they are fixed
            for (int j = 0; j < BOARD_WIDTH * BOARD_HEIGHT; j++) {
                if (board[j] == 'X') {
                    board[j] = TetriminoType + 49;
                }
            }

            // Set the 'placed' flag to indicate the current tetrimino is no longer being controlled
            placed = 1;

            // Set the starting position of the next tetrimino
            xStart = 3;
            yindex = 0;
        }
    }

    for(int i = 0; i < BOARD_HEIGHT * BOARD_WIDTH; i++){
        if(board[i] == 'X'){
            if(board[i + 10] == '1' || board[i + 10] == '2' || board[i + 10] == '3' || board[i + 10] == '4' || board[i + 10] == '5' || board[i + 10] == '6' || board[i + 10] == '7'){
            for(int j = 0; j < BOARD_HEIGHT * BOARD_WIDTH; j++){
                if(board[j] == 'X'){
                    board[j] = TetriminoType + 49;
                }
            }
            placed = 1;

            // Set the starting position of the next tetrimino
            xStart = 3;
            yindex = 0;
            }
        }
    }
}

void clear_line() {
    int lines_cleared = 0;
    for (int row = BOARD_HEIGHT - 1; row >= 0; row--) {
        int block_count = 0;
        for (int col = 0; col < BOARD_WIDTH; col++) {
            if (board[row * BOARD_WIDTH + col] == '1' || board[row * BOARD_WIDTH + col] == '2' || board[row * BOARD_WIDTH + col] == '3' || board[row * BOARD_WIDTH + col] == '4' || board[row * BOARD_WIDTH + col] == '5' || board[row * BOARD_WIDTH + col] == '6' || board[row * BOARD_WIDTH + col] == '7') {
                block_count++;
            }
        }
        if (block_count == BOARD_WIDTH) {
            // Shift all the rows above this row down by one
            for (int i = row; i > 0; i--) {
                for (int j = 0; j < BOARD_WIDTH; j++) {
                    board[i * BOARD_WIDTH + j] = board[(i - 1) * BOARD_WIDTH + j];
                }
            }
            // Clear the top row
            for (int j = 0; j < BOARD_WIDTH; j++) {
                board[j] = '.';
            }
            lines_cleared++;
            row++;
        }
    }

}
// This function calculates the number of empty spaces that the blocks can fall through
void fall() {
    int falldistance = 9999; // Initialize falldistance to a large value
    for (int i = 0; i < BOARD_HEIGHT * BOARD_WIDTH; i++) { // Iterate over all the blocks on the board
        if (board[i] == 'X') { // If a block is found
            int hasfallen = 0; // Initialize the flag to check whether the block has fallen
            int findfalldistance = 0; // Initialize the distance that the block can fall
            int z = i; // Save the index of the block
            while (hasfallen == 0 && z < BOARD_HEIGHT * BOARD_WIDTH - 10) { // Loop while the block hasn't fallen and there are still blocks below it
                if (board[z + 10] == '.' || board[z + 10] == 'X') { // Check if the space below the block is empty or has a block
                    findfalldistance++; // Increment the distance that the block can fall
                    z += 10; // Move to the space below the block
                } else {
                    hasfallen++; // Set the flag to indicate that the block has fallen
                }
            }
            if (falldistance > findfalldistance) { // Update the falldistance if the current block can fall farther than previous blocks
                falldistance = findfalldistance;
            }
        }
    }
    // Move the blocks down by the calculated distance
    for(int i = 0; i < falldistance; i++){
        for (int i = 0; i < BOARD_HEIGHT*BOARD_WIDTH; i++){ // Loop over all the blocks on the board
            if(board[i] == 'X'){ // If a block is found
                board[i] = '.'; // Remove the block from its current position
            }
        }
        yindex ++ ; // Move the blocks down one row
    }
}

// This function checks whether the game has ended
void GameEnd(){
    if(board[5] == 'X' || board[5] == '.'){ // Check if there is a block in the top row of the center column or if it's empty
        // The game hasn't ended yet
    }
    else{
        placed++; // Increment the number of blocks that have been placed
        loop++; // Increment the loop counter
    }
}
