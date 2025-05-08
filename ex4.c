/******************
Name: Samantha Newmark
ID:
Assignment: ex4
*******************/

#include <stdio.h>
#include <string.h>

/*
Menu Selection ID
Selection: None
*/
#define UNSELECTED 0

/*
Menu Selection ID
Selection: Task 1
*/
#define ROBOT_PATHS 1

/*
Menu Selection ID
Selection: Task 2
*/
#define HUMAN_PYRAMID 2

/*
Menu Selection ID
Selection: Task 3
*/
#define PARENTHESES_VALIDATOR 3

/*
Menu Selection ID
Selection: Task 4
*/
#define QUEENS_BATTLE 4

/*
Menu Selection ID
Goodbye!
*/
#define EXIT_PROGRAM 5

/*
0b0000
Task 3
Bitmask ( )
*/
#define BIN00 0

/*
0b0001
Task 3
Bitmask [ ]
*/
#define BIN01 1

/*
0b0010
Task 3
Bitmask { }
*/
#define BIN10 2

/*
0b0011
Task 3
Bitmask < >
*/ 
#define BIN11 3

/*
Task 4
Minimum ASCII for zone ID
*/
#define ASCII_MIN 33

/*
Task 4
Indicates a row currently has no queen placed in any column
*/
#define NONE_PLACED -1

/*
Task 4
Maximum legal grid dimension
*/
#define MAX 20

/*
Menu Selection (global)
*/
int selectedTask;

/*
Select task from the main menu
*/
void menuSelect();

/*
Print the main menu
*/
void displayMenu();

/*
Task 1 Home
Restricted to traveling only left and/or down, how many paths could a robot take from some (x, y) to (0, 0)?
*/
void robotPaths();

/*
Task 2 Home
What is the total weight load of each cheerleader in a pyramid formation?
*/
void humanPyramid();

/*
Task 3 Home
Has every opening parenthesis been properly closed?
Legal: ( ), [ ], { }, < >
*/
void parenthesisValidator();

/*
Task 4 Home
For a square grid of dimensions N x N and exactly N queens,
is there a legal configuration of queens such that none of these conditions is violated:
- exactly one queen in every row,
- exactly one queen in every column
- every cell adjacent to each queen is empty (row, col, diags)
*/ 
void QueensBattle();

/*
Task 1
Count legal paths from (x, y) to (0, 0)
*/
unsigned long long robotPathCount(unsigned long long n, unsigned long long k);

/*
Task 3
Assign binary id to legal characters
Legal: ( ), [ ], { }, < >
*/
unsigned int encodeLegalCharacters(char c);

/*
Task 3
Check if all parentheses have been closed
*/
int closedAllParentheses(int depth, unsigned long long word);

/*
Task 4
Prepare the queen position tracker
*/
void initQueenTracker(int index, int dimension, int queenTracker[MAX]);

/*
Task 4
Compute the absolute difference between coodinates
*/
int computeDistanceBetweenCells(int a, int b);

/*
Task 4
Check if the puzzle has a solution
*/
int isPuzzleSolvable(
	int currentRow,
	int dimension,
	int queenTracker[MAX],
	unsigned long long *colMask,
	unsigned long long *zoneMask,
	char zones[MAX][MAX]
);

/*
Task 4
Check if a cell is adjacent to any existing queens
*/
int isCellAdjacentToExistingQueen(
	int queenTracker[MAX],
	int row,
	int col,
	int currentRow,
	int dimension
);

/*
Task 4
Attempt each column in a row for legal queen placement
*/
int tryPlacingQueenInColumn(
	int col,
	int currentRow,
	int dimension,
	int queenTracker[MAX],
	unsigned long long *colMask,
	unsigned long long *zoneMask,
	char zones[MAX][MAX]
);

/*
Task 4
Attempt each row for legal queen placement
*/
int tryPlacingQueenInRow(
	int currentRow,
	int dimension,
	int queenTracker[MAX],
	unsigned long long *colMask,
	unsigned long long *zoneMask,
	char zones[MAX][MAX]
);


// MENU FUNCTIONS

void displayMenu() {
	printf("Choose an option:\n"
		"1. Robot Paths\n"
		"2. The Human Pyramid\n"
		"3. Parenthesis Validation\n"
		"4. Queens Battle\n"
		"5. Exit\n"
	);
}

void menuSelect() {
	selectedTask = UNSELECTED;
	int input = UNSELECTED, temp = UNSELECTED;
	while (
		displayMenu(),
		(input = scanf(" %d",&temp)) != 1 || temp < 1 || temp > EXIT_PROGRAM
	) {
		if (input == EOF) {
			selectedTask = EXIT_PROGRAM;
			return;
		}
		scanf("%*[^\n]");
		// scanf("%*[^12345 \t\n]");
		printf("Please choose a task number from the list.\n");
	}
	selectedTask = temp;
}


// TASK FUNCTIONS

void robotPaths() {
	int input = 0, x = 0, y = 0;

	printf("Please enter the coordinates of the robot (column, row):\n");

	while ((input = scanf(" %d %d", &x, &y)) != 2) {
		if (input == EOF) {
			selectedTask = EXIT_PROGRAM;
			return;
		}
		scanf("%*[^\n]");
		// scanf("%*[^1234567890 \t\n]");
		continue;
	}

	printf("The total number of paths the robot can take to reach home is: %llu\n",
				(x < 0 || y < 0) ? 0
					: ! (x && y) ? 1
						: robotPathCount((unsigned long long)(x + y), (unsigned long long)x)
	);
}

void humanPyramid() {
	double dataPyramid[5][5] = {0};

	printf("Please enter the weights of the cheerleaders:\n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= i; j++) {
			double nextWeight = -1.00;
			int input = 0;

			if ((input = scanf(" %lf", &nextWeight)) != 1 || nextWeight < 0) {
				if (input == EOF) {
					selectedTask = EXIT_PROGRAM;
					return;
				}
				scanf("%*[^\n]");
				// scanf("%*[^1234567890 \n]");
				printf("Negative weights are not supported.\n");
				return;
			}
			
			dataPyramid[i][j] = nextWeight;
		}
	}

	printf("The total weight on each cheerleader is:\n");

	// URGENT TODO: RECURSIVE

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= i; j++) {
			float weightLoad = dataPyramid[i][j];

			if (i > 0) {
				float weightUpLeft = (j > 0)
					? (float)dataPyramid[i - 1][j - 1] / 2.0
					: 0;
				
				float weightUpRight = (j < i)
					? (float)dataPyramid[i - 1][j] / 2.0
					: 0;
				
				weightLoad += weightUpLeft + weightUpRight;
			}
			dataPyramid[i][j] = weightLoad;
			printf("%.2f ", weightLoad);
		}
		printf("\n");
	}

}

void parenthesisValidator() {
	unsigned long long word = 0;
	int depth = 0, balance = EOF;
	
	// clear residual newline
	scanf("%*c"); 

	printf("Please enter a term for validation:\n");
	balance = closedAllParentheses(depth, word);
	balance == EOF
		? selectedTask = EXIT_PROGRAM
		: printf("The parentheses are%sbalanced correctly.\n", balance ? " " : " not ");
}

void QueensBattle() {
	int input = 0, dimension = 0;

	printf("Please enter the board dimensions:\n");
	while ((input = scanf(" %d", &dimension)) != 1 || dimension <= 0 || dimension > MAX) {
		if (input == EOF) {
			selectedTask = EXIT_PROGRAM;
			return;
		}
		scanf("%*[^ \t\n]");
		continue;
	}

	int filled = 0, row = 0, col = 0;
	char zones[MAX][MAX] = {{0}};
	char zoneChar = 0;

	printf("Please enter a %d*%d puzzle board:\n", dimension, dimension);
	while (filled < dimension*dimension) {
		if ((input = scanf("%c", &zoneChar)) != 1 || zoneChar == ' ' || zoneChar == '\n' || zoneChar == '\t') {
			if (input == EOF) {
				selectedTask = EXIT_PROGRAM;
				return;
			}
			continue;
		}
		zones[row][col++] = zoneChar;
		if (col == dimension) {
			col = 0;
			row++ ;
		}
		++filled;
	}

	/*
	- Track the locations of the queens
	- The index represents the row of a queen
	- The stored value at that index is its column
	*/
	int queenTracker[MAX] = {0};
	initQueenTracker(0, dimension, queenTracker);

	unsigned long long colMask = 0, zoneMask = 0;
	if (isPuzzleSolvable(0, dimension, queenTracker, &colMask, &zoneMask, zones)) {
		printf("Solution:\n");
		for (int i = 0; i < dimension; i++) {
			for (int j = 0; j < dimension; j++) {
				queenTracker[i] == j
					? printf("X ")
					: printf("* ");
			}
			printf("\n");
		}

	} else {
		printf("This puzzle cannot be solved.\n");
	}
	scanf("%*[^\n]");
	// scanf("%*[^1234567890 \t\n]");
}


// HELPER FUNCTIONS

unsigned long long robotPathCount(unsigned long long n, unsigned long long k) {
	if (k > n) {
		return 0;
	}
	if (k > n - k) {
		k = n - k;
	}
	unsigned long long r = 1;
	for (unsigned long long i = 1; i <= k; i++) {
		r = r * (n - k + i) / i;
	}
	return r;
}

unsigned int encodeLegalCharacters(char c) {
	switch(c) {
		case'(': case')': return BIN00;
		case'[': case']': return BIN01;
		case'{': case'}': return BIN10;
		case'<': case'>': return BIN11;
		default: return (unsigned int)-1;
	}
	return (unsigned int)-1;
}

int closedAllParentheses(int depth, unsigned long long word) {
	int input = 0, open = 0, closed = 0;
	unsigned int code = (unsigned int)-1;
	char curr = 0;

	if ((input = scanf("%c", &curr)) != 1) {
		return EOF;
	}
	if (curr == '\n') {
		return !depth;
	}

	open = (curr == '(' || curr == '[' || curr == '{' || curr == '<') ? 1 : 0;
	closed = (curr == ')' || curr == ']' || curr == '}' || curr == '>') ? 1 : 0;
	if (!(open || closed)) {
		return closedAllParentheses(depth, word);
	}

	code = encodeLegalCharacters(curr);
	if (code == (unsigned int)-1) {
		// should never be reached
		return EOF;
	}

	if (open) {
		return closedAllParentheses(++depth, (word << 2) | code);
	}
	if (closed) {
		if (!depth || (word & 3U) != code) {
			scanf("%*[^\n]");
			return 0;
		}
		return closedAllParentheses(--depth, (word >> 2));
	}
	return EOF;
}

void initQueenTracker(int index, int dimension, int queenTracker[MAX]) {
	if (index >= 0 && index < dimension) {
		queenTracker[index] = NONE_PLACED;
		initQueenTracker(index + 1, dimension, queenTracker);
	}
}

int isPuzzleSolvable(int currentRow, int dimension, int queenTracker[MAX],
	unsigned long long *colMask, unsigned long long *zoneMask, char zones[MAX][MAX]
) {
	return (
		tryPlacingQueenInRow(0, dimension, queenTracker, &colMask, &zoneMask, zones)
			? 1
			: 0
	);
}

int computeDistanceBetweenCells(int a, int b) {
	return (a > b) ? (a - b) : (b - a);
}

int isCellAdjacentToExistingQueen(int queenTracker[MAX], int row, int col, int currentRow, int dimension) {
	if (row < 0 || row == currentRow || row >= dimension) {
		return 0;
	}
	int c = queenTracker[row];
	return (
		(c >= 0 && computeDistanceBetweenCells(c, col) <= 1 && computeDistanceBetweenCells(row, currentRow) <= 1)
			? 1
			: isCellAdjacentToExistingQueen(queenTracker, row + 1, col, currentRow, dimension)
	);
}

int tryPlacingQueenInColumn(int col, int currentRow, int dimension, int queenTracker[MAX],
	unsigned long long *colMask, unsigned long long *zoneMask, char zones[MAX][MAX]
) {
    if (col == dimension) {
		return 0;
	}

	unsigned long long colBit = 1ULL << col;
    int zid = zones[currentRow][col] - ASCII_MIN;
	unsigned long long zidBit = 1ULL << zid;

    if ((*colMask&colBit) || (*zoneMask & zidBit)) {
        return tryPlacingQueenInColumn(col + 1, currentRow, dimension, queenTracker, colMask, zoneMask, zones);
    }
    if (isCellAdjacentToExistingQueen(queenTracker, 0, col, currentRow, dimension)) {
        return tryPlacingQueenInColumn(col + 1, currentRow, dimension, queenTracker, colMask, zoneMask, zones);
    }

    queenTracker[currentRow] = col;
    *colMask |= colBit;
    *zoneMask |= zidBit;

    if (tryPlacingQueenInRow(currentRow + 1, dimension, queenTracker, colMask, zoneMask, zones)) {
        return 1;
    }

    *colMask &= ~ colBit;
    *zoneMask &= ~ zidBit;
    queenTracker[currentRow] = NONE_PLACED;

    return tryPlacingQueenInColumn(col + 1, currentRow, dimension, queenTracker, colMask, zoneMask, zones);
}

int tryPlacingQueenInRow(int currentRow, int dimension, int queenTracker[MAX],
	unsigned long long *colMask, unsigned long long *zoneMask, char zones[MAX][MAX]
) {
	return (
		currentRow == dimension
			? 1
			: tryPlacingQueenInColumn(
				0,
				currentRow,
				dimension,
				queenTracker,
				colMask,
				zoneMask,
				zones
			)
	);
}


// NAVIGATE VIA MAIN

int main() {
	while (selectedTask != EXIT_PROGRAM) {
		menuSelect();
		switch (selectedTask) {
			case EXIT_PROGRAM: break;
			case ROBOT_PATHS:
                robotPaths();
                break;
			case HUMAN_PYRAMID:
                humanPyramid();
                break;
			case PARENTHESES_VALIDATOR:
                parenthesisValidator();
                break;
            case QUEENS_BATTLE:
                QueensBattle();
                break;
			default: printf("Please choose a task number from the list.\n");
		}
	}
	printf("Goodbye!\n");
	return 0;
}