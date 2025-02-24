// Idea: Create a maze in STDOUT
// gcc {filename}.c -o {outputname}
// ./{filename}

#include <stdio.h>
#include <drako/drako.h>
#include <level3/level.h>

bool level3_main() {
    // Create a 2D array: [rows] [cols]
    char maze[MAZE_ROWS][MAZE_COLS] = {
            ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','v',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','x','#','#','#','#','#','#','#','#','#','#','#','#','.','#','#','#','#','#','#','#','#','#','#','d','x','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
            '#','#','.','#','.','.','.','.','.','.','.','.','.','.','.','.','#','#','#','#','#','#','#','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','#','#','#','#','7','#','#','.','.','.','.','.','#','.','#','#',
            '#','#','.','#','.','#','#','#','#','#','#','#','#','#','#','.','.','.','.','.','.','.','.','.','.','#','#','#','#','.','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','.','.','.','.','.','.','.','.','.','.','#','#','.','#','#','.','#','#',
            '#','#','.','.','.','#','#','#','.','.','.','.','.','.','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','#','#','#','#','#','.','#','#','#','#','#','#','#','#','#','#','.','#','#','.','#','#',
            '#','#','#','#','.','.','.','.','.','#','#','#','#','.','.','.','.','.','.','.','.','#','#','.','.','.','.','#','#','.','#','#','#','#','#','#','#','#','#','#','.','#','.','#','#','#','.','.','.','.','.','#','.','.','.','.','.','.','.','.','.','#','#','.','#','.','.','#','#',
            '#','.','.','#','#','#','#','#','.','.','.','#','#','.','#','#','#','#','#','#','#','#','#','.','#','#','#','#','#','.','.','#','#','3','#','#','.','.','.','.','.','#','.','.','.','#','#','.','#','#','.','#','#','#','#','#','#','#','#','#','.','#','#','.','#','.','#','#','#',
            '#','#','.','.','#','/','#','#','#','#','#','#','#','.','.','.','.','.','.','.','.','.','.','.','.','#','#','#','#','#','.','.','#','#','#','#','#','#','#','#','.','#','#','#','.','#','#','.','.','.','.','#','#',')','#','#','.','#','#','#','.','#','#','#','#','.','#','#','#',
            '#','#','#','.','.','.','.','.','.','.','.','.','.','.','#','#','#','#','#','#','#','#','#','#','#','#','i','n','t','#','#','.','.','.','.','.','.','.','.','.','.','#','#','#','.','#','#','.','#','#','#','#','.','.','.','.','.','#','!','#','.','.','.','.','.','.','#','6','#',
            '#','#','#','.','#','#','.','#','.','#','#','#','#','#','#','.','.','.','.','.','.','.','.','.','.','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','.','.','.','.','#','.','.','.','.','.','.','#','#','#','.','#','#','#','.','#','#','#','#','#','#','#','#',
            '#','.','.','.','#','.','.','#','.','.','.','.','.','.','#','.','#','#','#','#','#','#','#','#','.','#','#','.','.','.','#','.','.','.','.','.','.','.','.','.','.','.','.','#','#','#','#','.','#','#','#','#','#','#','-','#','.','.','.','#','#','#','#','.','.','.','.','.','#',
            '#','.','#','.','#','#','#','#','#','#','#','#','#','.','#','.','.','.','.','.','#','.','.','#','.','.','.','.','#','#','#','#','.','#','#','#','#','#','#','#','#','#','#','#','.','.','.','.','.','.','.','.','.','#','#','#','#','.','#','#','.','.','.','.','#','#','#','.','#',
            '#','.','#','.','.','.','.','.','.','#','#','4','#','#','#','#','.','#','#','#','#','#','.','#','#','#','#','.','.','.','#','.','.','.','#','.','.','.','.','.','.','#','.','.','.','#','#','#','#','.','#','.','#','#','.','.','.','.','#','.','.','#','#','#','#','.','#','.','#',
            '#','.','#','#','#','#','.','#','#','#','#','#','#','#','.','#','.','.','.','.','.','.','.','.','.','#','#','#','#','.','#','.','.','.','#','.','#','#','#','.','#','#','#','#','#','#','#','#','.','.','#','.','#','#','#','#','#','#','#','.','#','#','.','#','#','.','#','.','#',
            '#','.','#','.','#','#','.','#','#','.','.','.','.','.','.','#','#','#','#','#','#','#','#','#','.','.','.','.','#','.','#','#','#','#','#','.','#','#','.','.','.','.','.','.','.','.','.','#','#','#','.','.','.','.','.','.','.','#','#','.','#','.','.','.','.','.','#','.','#',
            '#','.','#','.','#','#','.','#','+','#','#','.','#','#','.','.','.','.','.','.','.','.','.','.','.','#','#','#','#','.','.','.','.','.','.','.','#','#','.','#','#','#','.','#','#','.','#','#','.','.','.','#','#','#','#','#','.','.','.','.','#','.','#','#','#','#','#','.','#',
            '#','.','#','.','#','#','.','#','#','#','#','.','#','#','#','#','#','.','#','#','#','#','#','#','.','#','#','#','#','#','#','#','#','#','#','#','#','.','.','#','%','#','.','#','#','.','#','#','#','#','#','#','#','.','#','#','#','#','#','#','#','.','#','#','.','.','.','.','#',
            '#','.','#','.','.','.','.','#','#','.','#','.','.','.','.','#','#','.','#','#','#','1','#','#','.','.','.','#','5','#','.','.','.','.','#','#','#','#','#','#','#','#','#','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','#','#','#','.','#','#',
            '#','.','#','#','#','#','.','#','#','.','#','#','#','#','.','#','#','.','#','#','#','#','#','#','#','#','.','#','#','#','#','.','#','#','#','#','.','.','.','#','#','.','#','#','#','#','#','#','#','.','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','.','#','#',
            '#','.','.','.','#','#','.','.','.','.','#','y','#','#','.','#','#','.','.','.','.','#','#','#','#','#','.','.','.','.','.','.','.','#','#','#','#','#','.','#','#','.','.','.','#','.','.','.','.','.','#','#','.','.','.','#','#','#','#','#','#','#','#','.','.','.','.','#','#',
            '#','#','#','.','.','#','.','#','#','#','#','#','#','.','.','.','#','#','#','#','.','#','#','#','#','#','.','#','#','#','#','#','#','#','#','#','#','.','.','#','#','#','.','#','#','#','#','.','#','#','#','#','.','9','.','#','.','.','.','.','.','.','.','.','#','#','.','.','#',
            '#','#','#','#','#','#','.','#','#','8','#','#','#','.','#','#','#','#','#','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','#','#','.','.','.','.','.','.','.','.','.','.','#','#','#','#','.','#','.','#','.','#','.','#','#','#','#','#','#','#','#','.','#',
            '#','#','.','.','.','.','.','.','.','.','.','#','#','#','#','#','.','.','.','.','.','#','#','#','#','#','#','#','#','#','#','#','#','#','.','#','#','#','#','#','#','#','.','#','#','#','#','.','#','#','#','#','.','#','#','#','.','#','.','#','#','#','#','*','#','#','#','.','#',
            '#','#','.','#','#','#','#','#','#','#','.','.','.','.','.','.','.','#','#','#','#','2','#','#','#','#','.','.','.','.','.','.','.','.','.','.','.','.','.','#','#','#','#','#','#','#','#','.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','.','.','.','.','#',
            '0','#','#','#','#','#','(','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','^','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'
    };

    char userAction;
    int userRow;
    int userCol;
    char backup;
    char *mazePtr = &maze[0][0];

    // Give Greeting
    level3();
    // scanf("%c", &userAction);
    userAction = getc(stdin);
    // Clear stdin
    clear();

    // Setup User position [row:2, col:33]
    userRow = 1;
    userCol = 32;
    backup = maze[userRow][userCol];

    // While loop
    while(1) {
        // Insert User position:
        printf("User Position: [%d][%d]\n", userRow-1, userCol);
        maze[userRow][userCol] = 'A';
        if ((userRow == 12) && (userCol == 32)) {
            break;
        }

        // New: if far away from the user, print X instead of walls.
        // Prints Maze
        for (int i = 0; i < MAZE_ROWS; i++) {
            for (int j = 0; j < MAZE_COLS; j++) {
                // if far away print X
                if (((i == 12) || (i == 13)) && ((j >= 31) && (j <= 33))) {
                    printf(".");
                }
                else if (((userRow - 5 > i) || (userRow + 5 < i)) || ((userCol - 5 > j) || (userCol + 5 < j))) {
                    printf("X");
                }
                else {
                    printf("%c", maze[i][j]);
                }
            }
            printf("\n");
        }
        printf("Input: ");
        // scanf("%c", &userAction);
        userAction = getc(stdin);
        if (userAction == 's') { // down
            mazePtr = &maze[userRow+1][userCol];
            if (userRow >= (MAZE_ROWS - 1)) {
                //printf("Reached bottom, cannot go further.\n");
            }
            else if (*mazePtr == '#') {
                //printf("Hit a wall, cannot go any further.\n");
            }
            else {
                maze[userRow][userCol] = backup;
                userRow += 1;
                backup = maze[userRow][userCol];
            }
        }
        else if (userAction == 'w') { // up
            mazePtr = &maze[userRow-1][userCol];
            if (userRow == 1) {
                //printf("Reached top, cannot go further.\n");
            }
            else if (*mazePtr == '#') {
                //printf("Hit a wall, cannot go any further.\n");
            }
            else {
                maze[userRow][userCol] = backup;
                userRow -= 1;
                backup = maze[userRow][userCol];
            }
        }
        else if (userAction == 'd') { // right
            mazePtr = &maze[userRow][userCol+1];
            if (userCol >= (MAZE_COLS - 1)) {
                //printf("Reached right, cannot go further.\n");
            }
            else if (*mazePtr == '#') {
                //printf("Hit a wall, cannot go any further.\n");
            }
            else {
                maze[userRow][userCol] = backup;
                userCol += 1;
                backup = maze[userRow][userCol];
            }
        }
        else if (userAction == 'a') { // left
            mazePtr = &maze[userRow][userCol-1];
            if (userCol == 0) {
                //printf("Reached left, cannot go further.\n");
            }
            else if (*mazePtr == '#') {
                //printf("Hit a wall, cannot go any further.\n");
            }
            else {
                maze[userRow][userCol] = backup;
                userCol -= 1;
                backup = maze[userRow][userCol];
            }
        }
        
        // Clear stdin
        clear();
    }
    // After breaking while loop
    printf("\n"
        "Reaching the center of this long, twisting labyrinth you are met\n"
        "by an unyielding darkness. You begin to cast an enhanced light\n"
        "spell...\n"
        "\n----- LEVEL 3: COMPLETE -----\n\n"
    );
    // increment level
    drako.currentLevel++;

    return 0;
}