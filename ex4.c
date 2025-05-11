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
Task 1
Number of sets with all paths
*/
#define ALL 1

/*
Task 2
The longest height of the pyramid
*/
#define MAX_HEIGHT 5

/*
Task 2
The longest length of the pyramid
*/
#define MAX_LENGTH 5

/*
0b0000
Task 3
Bitmask ( )
*/
#define BITS_00 0

/*
0b0001
Task 3
Bitmask [ ]
*/
#define BITS_01 1

/*
0b0010
Task 3
Bitmask { }
*/
#define BITS_10 2

/*
0b0011
Task 3
Bitmask < >
*/ 
#define BITS_11 3

/*
Task 3
TODO: NOTE
Used for overflow prevention
*/
#define MAX_TOTAL_CALLS 4096

/*
Task 3
TODO: NOTE
Used for overflow prevention
*/
#define MAX_NESTING_DEPTH 4096

/*
Task 3
TODO: NOTE
Used for overflow prevention
*/
#define BITS_PER_BITSTACK 64

/*
Task 3
TODO: NOTE
Used for overflow prevention
*/
#define BITS_PER_LEVEL 2

/*
Task 3
TODO: NOTE
Used for overflow prevention
*/
#define LEVELS_PER_BITSTACK (BITS_PER_BITSTACK / BITS_PER_LEVEL)

/*
Task 3
TODO: NOTE
Used for overflow prevention
*/
#define BITSTACK_COUNT (MAX_NESTING_DEPTH / LEVELS_PER_BITSTACK)

/*
Task 3
TODO: NOTE
Used for overflow prevention
*/
#define GET_BITSTACK(i) ( \
	(i)==0?bitstack0:(i)==1?bitstack1:(i)==2?bitstack2:(i)==3?bitstack3:(i)==4?bitstack4: \
	(i)==5?bitstack5:(i)==6?bitstack6:(i)==7?bitstack7:(i)==8?bitstack8:(i)==9?bitstack9: \
	(i)==10?bitstack10:(i)==11?bitstack11:(i)==12?bitstack12:(i)==13?bitstack13:(i)==14?bitstack14: \
	(i)==15?bitstack15:(i)==16?bitstack16:(i)==17?bitstack17:(i)==18?bitstack18:(i)==19?bitstack19: \
	(i)==20?bitstack20:(i)==21?bitstack21:(i)==22?bitstack22:(i)==23?bitstack23:(i)==24?bitstack24: \
	(i)==25?bitstack25:(i)==26?bitstack26:(i)==27?bitstack27:(i)==28?bitstack28:(i)==29?bitstack29: \
	(i)==30?bitstack30:(i)==31?bitstack31:(i)==32?bitstack32:(i)==33?bitstack33:(i)==34?bitstack34: \
	(i)==35?bitstack35:(i)==36?bitstack36:(i)==37?bitstack37:(i)==38?bitstack38:(i)==39?bitstack39: \
	(i)==40?bitstack40:(i)==41?bitstack41:(i)==42?bitstack42:(i)==43?bitstack43:(i)==44?bitstack44: \
	(i)==45?bitstack45:(i)==46?bitstack46:(i)==47?bitstack47:(i)==48?bitstack48:(i)==49?bitstack49: \
	(i)==50?bitstack50:(i)==51?bitstack51:(i)==52?bitstack52:(i)==53?bitstack53:(i)==54?bitstack54: \
	(i)==55?bitstack55:(i)==56?bitstack56:(i)==57?bitstack57:(i)==58?bitstack58:(i)==59?bitstack59: \
	(i)==60?bitstack60:(i)==61?bitstack61:(i)==62?bitstack62:(i)==63?bitstack63:(i)==64?bitstack64: \
	(i)==65?bitstack65:(i)==66?bitstack66:(i)==67?bitstack67:(i)==68?bitstack68:(i)==69?bitstack69: \
	(i)==70?bitstack70:(i)==71?bitstack71:(i)==72?bitstack72:(i)==73?bitstack73:(i)==74?bitstack74: \
	(i)==75?bitstack75:(i)==76?bitstack76:(i)==77?bitstack77:(i)==78?bitstack78:(i)==79?bitstack79: \
	(i)==80?bitstack80:(i)==81?bitstack81:(i)==82?bitstack82:(i)==83?bitstack83:(i)==84?bitstack84: \
	(i)==85?bitstack85:(i)==86?bitstack86:(i)==87?bitstack87:(i)==88?bitstack88:(i)==89?bitstack89: \
	(i)==90?bitstack90:(i)==91?bitstack91:(i)==92?bitstack92:(i)==93?bitstack93:(i)==94?bitstack94: \
	(i)==95?bitstack95:(i)==96?bitstack96:(i)==97?bitstack97:(i)==98?bitstack98:(i)==99?bitstack99: \
	(i)==100?bitstack100:(i)==101?bitstack101:(i)==102?bitstack102:(i)==103?bitstack103:(i)==104?bitstack104: \
	(i)==105?bitstack105:(i)==106?bitstack106:(i)==107?bitstack107:(i)==108?bitstack108:(i)==109?bitstack109: \
	(i)==110?bitstack110:(i)==111?bitstack111:(i)==112?bitstack112:(i)==113?bitstack113:(i)==114?bitstack114: \
	(i)==115?bitstack115:(i)==116?bitstack116:(i)==117?bitstack117:(i)==118?bitstack118:(i)==119?bitstack119: \
	(i)==120?bitstack120:(i)==121?bitstack121:(i)==122?bitstack122:(i)==123?bitstack123:(i)==124?bitstack124: \
	(i)==125?bitstack125:(i)==126?bitstack126:bitstack127)

/*
Task 3
TODO: NOTE
Used for overflow prevention
*/
#define SET_BITSTACK(i, val) do { \
	if ((i) == 0) bitstack0 = (val);  	 		   else if ((i) == 1)    bitstack1 = (val); \
	else if ((i) == 2)    bitstack2 = (val);  	 else if ((i) == 3)	  bitstack3 = (val); \
	else if ((i) == 4)    bitstack4 = (val);  	 else if ((i) == 5)   bitstack5 = (val); \
	else if ((i) == 6)    bitstack6 = (val);   	 else if ((i) == 7)   bitstack7 = (val); \
	else if ((i) == 8)    bitstack8 = (val); 	 else if ((i) == 9)   bitstack9 = (val); \
	else if ((i) == 10)   bitstack10 = (val);   else if ((i) == 11)  bitstack11 = (val); \
	else if ((i) == 12)   bitstack12 = (val);   else if ((i) == 13)  bitstack13 = (val); \
	else if ((i) == 14)   bitstack14 = (val);   else if ((i) == 15)  bitstack15 = (val); \
	else if ((i) == 16)   bitstack16 = (val);   else if ((i) == 17)  bitstack17 = (val); \
	else if ((i) == 18)   bitstack18 = (val);   else if ((i) == 19)  bitstack19 = (val); \
	else if ((i) == 20)  bitstack20 = (val);   else if ((i) == 21)  bitstack21 = (val); \
	else if ((i) == 22)  bitstack22 = (val);   else if ((i) == 23)  bitstack23 = (val); \
	else if ((i) == 24)  bitstack24 = (val);   else if ((i) == 25)  bitstack25 = (val); \
	else if ((i) == 26)  bitstack26 = (val);   else if ((i) == 27)  bitstack27 = (val); \
	else if ((i) == 28)  bitstack28 = (val);   else if ((i) == 29)  bitstack29 = (val); \
	else if ((i) == 30)  bitstack30 = (val);   else if ((i) == 31)  bitstack31 = (val); \
	else if ((i) == 32)  bitstack32 = (val);   else if ((i) == 33)  bitstack33 = (val); \
	else if ((i) == 34)  bitstack34 = (val);   else if ((i) == 35)  bitstack35 = (val); \
	else if ((i) == 36)  bitstack36 = (val);   else if ((i) == 37)  bitstack37 = (val); \
	else if ((i) == 38)  bitstack38 = (val);   else if ((i) == 39)  bitstack39 = (val); \
	else if ((i) == 40)  bitstack40 = (val);   else if ((i) == 41)  bitstack41 = (val); \
	else if ((i) == 42)  bitstack42 = (val);   else if ((i) == 43)  bitstack43 = (val); \
	else if ((i) == 44)  bitstack44 = (val);   else if ((i) == 45)  bitstack45 = (val); \
	else if ((i) == 46)  bitstack46 = (val);   else if ((i) == 47)  bitstack47 = (val); \
	else if ((i) == 48)  bitstack48 = (val);   else if ((i) == 49)  bitstack49 = (val); \
	else if ((i) == 50)  bitstack50 = (val);   else if ((i) == 51)  bitstack51 = (val); \
	else if ((i) == 52)  bitstack52 = (val);   else if ((i) == 53)  bitstack53 = (val); \
	else if ((i) == 54)  bitstack54 = (val);   else if ((i) == 55)  bitstack55 = (val); \
	else if ((i) == 56)  bitstack56 = (val);   else if ((i) == 57)  bitstack57 = (val); \
	else if ((i) == 58)  bitstack58 = (val);   else if ((i) == 59)  bitstack59 = (val); \
	else if ((i) == 60)  bitstack60 = (val);   else if ((i) == 61)  bitstack61 = (val); \
	else if ((i) == 62)  bitstack62 = (val);   else if ((i) == 63)  bitstack63 = (val); \
	else if ((i) == 64)  bitstack64 = (val);   else if ((i) == 65)  bitstack65 = (val); \
	else if ((i) == 66)  bitstack66 = (val);   else if ((i) == 67)  bitstack67 = (val); \
	else if ((i) == 68)  bitstack68 = (val);   else if ((i) == 69)  bitstack69 = (val); \
	else if ((i) == 70)  bitstack70 = (val);   else if ((i) == 71)   bitstack71 = (val); \
	else if ((i) == 72)  bitstack72 = (val);   else if ((i) == 73)   bitstack73 = (val); \
	else if ((i) == 74)  bitstack74 = (val);   else if ((i) == 75)   bitstack75 = (val); \
	else if ((i) == 76)  bitstack76 = (val);   else if ((i) == 77)   bitstack77 = (val); \
	else if ((i) == 78)  bitstack78 = (val);   else if ((i) == 79)   bitstack79 = (val); \
	else if ((i) == 80)  bitstack80 = (val);   else if ((i) == 81)   bitstack81 = (val); \
	else if ((i) == 82)  bitstack82 = (val);   else if ((i) == 83)   bitstack83 = (val); \
	else if ((i) == 84)  bitstack84 = (val);   else if ((i) == 85)   bitstack85 = (val); \
	else if ((i) == 86)  bitstack86 = (val);   else if ((i) == 87)   bitstack87 = (val); \
	else if ((i) == 88)  bitstack88 = (val);   else if ((i) == 89)   bitstack89 = (val); \
	else if ((i) == 90)  bitstack90 = (val);   else if ((i) == 91)    bitstack91 = (val); \
	else if ((i) == 92)  bitstack92 = (val);   else if ((i) == 93)    bitstack93 = (val); \
	else if ((i) == 94)  bitstack94 = (val);   else if ((i) == 95)    bitstack95 = (val); \
	else if ((i) == 96)  bitstack96 = (val);   else if ((i) == 97)    bitstack97 = (val); \
	else if ((i) == 98)  bitstack98 = (val);   else if ((i) == 99)    bitstack99 = (val); \
	else if ((i) == 100) bitstack100 = (val);  else if ((i) == 101)  bitstack101 = (val); \
	else if ((i) == 102) bitstack102 = (val);  else if ((i) == 103)  bitstack103 = (val); \
	else if ((i) == 104) bitstack104 = (val);  else if ((i) == 105)  bitstack105 = (val); \
	else if ((i) == 106) bitstack106 = (val);  else if ((i) == 107)  bitstack107 = (val); \
	else if ((i) == 108) bitstack108 = (val);  else if ((i) == 109)  bitstack109 = (val); \
	else if ((i) == 110) bitstack110 = (val);  	else if ((i) == 111)   bitstack111 = (val); \
	else if ((i) == 112) bitstack112 = (val);  	else if ((i) == 113)   bitstack113 = (val); \
	else if ((i) == 114) bitstack114 = (val);  	else if ((i) == 115)   bitstack115 = (val); \
	else if ((i) == 116) bitstack116 = (val);  	else if ((i) == 117)   bitstack117 = (val); \
	else if ((i) == 118) bitstack118 = (val);  	else if ((i) == 119)   bitstack119 = (val); \
	else if ((i) == 120) bitstack120 = (val);  else if ((i) == 121)   bitstack121 = (val); \
	else if ((i) == 122) bitstack122 = (val);  else if ((i) == 123)   bitstack123 = (val); \
	else if ((i) == 124) bitstack124 = (val);  else if ((i) == 125)   bitstack125 = (val); \
	else if ((i) == 126) bitstack126 = (val); \
	else bitstack127 = (val); \
} while (0)

/*
Task 3
TODO: NOTE
Used for overflow prevention
*/
static unsigned long long
	bitstack0  	 = 0LLU,  bitstack1   = 0LLU, bitstack2   = 0LLU, bitstack3   = 0LLU, bitstack4   = 0LLU,
	bitstack5    = 0LLU,  bitstack6   = 0LLU, bitstack7   = 0LLU, bitstack8   = 0LLU, bitstack9   = 0LLU,
	bitstack10   = 0LLU, bitstack11   = 0LLU, bitstack12  = 0LLU, bitstack13 = 0LLU, bitstack14  = 0LLU,
	bitstack15   = 0LLU, bitstack16   = 0LLU, bitstack17  = 0LLU, bitstack18 = 0LLU, bitstack19  = 0LLU,
	bitstack20   = 0LLU, bitstack21   = 0LLU, bitstack22 = 0LLU, bitstack23 = 0LLU, bitstack24 = 0LLU,
	bitstack25   = 0LLU, bitstack26   = 0LLU, bitstack27 = 0LLU, bitstack28 = 0LLU, bitstack29 = 0LLU,
	bitstack30   = 0LLU, bitstack31   = 0LLU, bitstack32 = 0LLU, bitstack33 = 0LLU, bitstack34 = 0LLU,
	bitstack35   = 0LLU, bitstack36   = 0LLU, bitstack37 = 0LLU, bitstack38 = 0LLU, bitstack39 = 0LLU,
	bitstack40   = 0LLU, bitstack41   = 0LLU, bitstack42 = 0LLU, bitstack43 = 0LLU, bitstack44 = 0LLU,
	bitstack45   = 0LLU, bitstack46   = 0LLU, bitstack47 = 0LLU, bitstack48 = 0LLU, bitstack49 = 0LLU,
	bitstack50   = 0LLU, bitstack51   = 0LLU, bitstack52 = 0LLU, bitstack53 = 0LLU, bitstack54 = 0LLU,
	bitstack55   = 0LLU, bitstack56   = 0LLU, bitstack57 = 0LLU, bitstack58 = 0LLU, bitstack59 = 0LLU,
	bitstack60   = 0LLU, bitstack61   = 0LLU, bitstack62 = 0LLU, bitstack63 = 0LLU, bitstack64 = 0LLU,
	bitstack65   = 0LLU, bitstack66   = 0LLU, bitstack67 = 0LLU, bitstack68 = 0LLU, bitstack69 = 0LLU,
	bitstack70   = 0LLU, bitstack71   = 0LLU, bitstack72 = 0LLU, bitstack73 = 0LLU, bitstack74 = 0LLU,
	bitstack75   = 0LLU, bitstack76   = 0LLU, bitstack77 = 0LLU, bitstack78 = 0LLU, bitstack79 = 0LLU,
	bitstack80   = 0LLU, bitstack81   = 0LLU, bitstack82 = 0LLU, bitstack83 = 0LLU, bitstack84 = 0LLU,
	bitstack85   = 0LLU, bitstack86   = 0LLU, bitstack87 = 0LLU, bitstack88 = 0LLU, bitstack89 = 0LLU,
	bitstack90   = 0LLU, bitstack91   = 0LLU, bitstack92 = 0LLU, bitstack93 = 0LLU, bitstack94 = 0LLU,
	bitstack95   = 0LLU, bitstack96   = 0LLU, bitstack97 = 0LLU, bitstack98  = 0LLU, bitstack99 = 0LLU,
	bitstack100 = 0LLU, bitstack101  = 0LLU, bitstack102 = 0LLU, bitstack103 = 0LLU, bitstack104 = 0LLU,
	bitstack105 = 0LLU, bitstack106  = 0LLU, bitstack107 = 0LLU, bitstack108 = 0LLU, bitstack109 = 0LLU,
	bitstack110 = 0LLU, bitstack111   = 0LLU, bitstack112 = 0LLU, bitstack113 = 0LLU, bitstack114 = 0LLU,
	bitstack115 = 0LLU, bitstack116   = 0LLU, bitstack117 = 0LLU, bitstack118 = 0LLU, bitstack119 = 0LLU,
	bitstack120 = 0LLU, bitstack121   = 0LLU, bitstack122 = 0LLU, bitstack123 = 0LLU, bitstack124 = 0LLU,
	bitstack125 = 0LLU, bitstack126   = 0LLU, bitstack127 = 0LLU;

/*
Task 3
TODO: NOTE
Used for overflow prevention
*/
static int recursion_count = 0;

/*
Task 4
Maximum legal grid dimension
*/
#define MAX 20

/*
Task 4
Indicates a row currently has no queen placed in any column
*/
#define NONE_PLACED -1

/*
Task 4
Minimum ASCII for zone ID
*/
#define ASCII_MIN 33


////////////////////////////////////////////
// MAIN MENU PROTOTYPES
////////////////////////////////////////////

/*
Menu Selection (global)
*/
int selectedTask = UNSELECTED;

/*
- Select menu option
- Validate / Reprompt
- Update global selectedTask
*/
void menuSelect();

/*
Navigate the menu according to selectedTask
*/
void menuNavigate();

/*
Print the menu
*/
void displayMenu();


/////////////////////////////////////
// TASK 1 PROTOTYPES
/////////////////////////////////////

/*
Task 1 Home
Restricted to traveling only left and/or down, how many paths could a robot take from some (x, y) to (0, 0)?
*/
void robotPaths();

/*
Task 1
Count total legal paths from (x, y) to (0, 0)
*/
void robotPathCount(
	unsigned long long i,
	unsigned long long paths[ALL],
	unsigned long long n,
	unsigned long long k
);


/////////////////////////////////////
// TASK 2 PROTOTYPES
/////////////////////////////////////

/*
Task 2 Home
What is the total weight load of each cheerleader in a pyramid formation?
*/
void humanPyramid();

/*
Task 2
Display the output of the computeWeightTotal recursive function
*/
void displayWeight(
	int row,
	int col,
	double selfWeight[MAX_HEIGHT][MAX_LENGTH]
);

/*
Task 2
Compute the total weight a cheerleader supports
*/
float computeWeightTotal(
	int row,
	int col,
	double selfWeight[MAX_HEIGHT][MAX_LENGTH]
);

/*
Task 2
Compute the overhead weight supported by a cheerleader
*/
float computeWeightOverhead(
	int row,
	int col,
	double selfWeight[MAX_HEIGHT][MAX_LENGTH]
);

 
/////////////////////////////////////
// TASK 3 PROTOTYPES
/////////////////////////////////////

/*
Task 3 Home
Has every opening parenthesis been properly closed?
Legal: ( ), [ ], { }, < >
*/
void parenthesisValidator();

/*
Task 3
TODO: NOTE
*/
void overflowProtection();

/*
Task 3
Check if all parentheses have been closed
*/
int closedAllParentheses(int depth);

/*
Task 3
Assign binary id to legal characters
Legal: ( ), [ ], { }, < >
*/
unsigned int encodeLegalCharacters(char c);


/////////////////////////////////////
// TASK 4 PROTOTYPES
/////////////////////////////////////

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
Task 4
Prepare the queen position tracker
*/
void initQueenTracker(
	int index,
	int dimension,
	int queenTracker[MAX]
);

/*
Task 4
Check if the puzzle has a solution
*/
int isPuzzleSolvable(
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
Compute the absolute difference between coodinates
*/
int computeDistanceBetweenCells(int a, int b);


//////////////////////////////////
// TASK 1 FUNCTIONS
//////////////////////////////////

void robotPaths() {
	int input = 0;
	long long x = 0LL, y = 0LL;

	printf("Please enter the coordinates of the robot (column, row):\n");

	while ((input = scanf(" %lld %lld", &x, &y)) != 2) {
		if (input == EOF) {
			selectedTask = EXIT_PROGRAM;
			return;
		}
		scanf("%*[^\n]");
		continue;
	}
	scanf("%*[^\n]");

	unsigned long long paths[ALL] = {0LLU};
	if (x < 0 || y < 0) {
		paths[0] = 0LLU;
	} else if (!(x && y)) {
		paths[0] = 1LLU;
	} else {
		unsigned long long k =0LLU;
		k = (
			x > y
				? (unsigned long long)y
			: (unsigned long long)x
		);
		robotPathCount(
			1LLU,
			paths,
			(unsigned long long)(x + y),
			k
		);
	}
	printf("The total number of paths the robot can take to reach home is: %llu\n", paths[0]);
}

void robotPathCount(
	unsigned long long i,
	unsigned long long paths[ALL],
	unsigned long long n,
	unsigned long long k
) {
	if (i <= k) {
		paths[0] = paths[0] * (n - k + i) / i;
		robotPathCount(
			i + 1,
			paths,
			n,
			k
		);
	}	
}


//////////////////////////////////
// TASK 2 FUNCTIONS
//////////////////////////////////

void humanPyramid() {
	double selfWeight[MAX_HEIGHT][MAX_LENGTH] = {0};

	printf("Please enter the weights of the cheerleaders:\n");

	for (int row = 0; row < MAX_HEIGHT; row++) {
		for (int col = 0; col <= row; col++) {

			double nextWeight = -1.00;
			int input = 0;

			if ((input = scanf(" %lf", &nextWeight)) != 1 || nextWeight < 0.00) {
				if (input == EOF) {
					selectedTask = EXIT_PROGRAM;
					return;
				}
				scanf("%*[^\n]");

				printf("Negative weights are not supported.\n");

				return;
			}

			selfWeight[row][col] = nextWeight;
		}
	}

	printf("The total weight on each cheerleader is:\n");

	for (int row = 0; row < MAX_HEIGHT; row++) {
		for (int col = 0; col <= row; col++) {
			displayWeight(row, col, selfWeight);
		}
		printf("\n");
	}
}

void displayWeight(
	int row,
	int col,
	double selfWeight[MAX_HEIGHT][MAX_LENGTH]
) {
	printf("%.2f ",
		computeWeightTotal(row, col, selfWeight)
	);
}

float computeWeightTotal(
	int row,
	int col,
	double selfWeight[MAX_HEIGHT][MAX_LENGTH]
) {
	return (
		row < 0 || col < 0 || col > row
			? 0.0f
		: (float)selfWeight[row][col] + computeWeightOverhead(row, col, selfWeight)
	);
}

float computeWeightOverhead(
	int row,
	int col,
	double selfWeight[MAX_HEIGHT][MAX_LENGTH]
) {
	if (row <= 0) {
		return 0.0f;
	}

	float weightUpLeft = (
		col <= 0
			? 0.0f
		: computeWeightTotal(row - 1, col - 1, selfWeight) / 2.0f
	);

	float weightUpRight = (
		col >= row
			? 0.0f
		: computeWeightTotal(row - 1, col, selfWeight) / 2.0f);

	return weightUpLeft + weightUpRight;
}


//////////////////////////////////
// TASK 3 FUNCTIONS
//////////////////////////////////

void parenthesisValidator() {
	int depth = 0, balance = EOF;

	// clear residual newline
	scanf("%*c");

	printf("Please enter a term for validation:\n");

	overflowProtection();

	balance = closedAllParentheses(depth);

	if (balance == EOF){
		selectedTask = EXIT_PROGRAM;
		return;
	}

	overflowProtection();

	printf("The parentheses are%sbalanced correctly.\n",
		balance
			? " "
			: " not "
	);
}

void overflowProtection() {
	bitstack0 = bitstack1 = bitstack2 = bitstack3 = bitstack4 = bitstack5 = bitstack6 = bitstack7
	= bitstack8 = bitstack9 = bitstack10 = bitstack11 = bitstack12 = bitstack13 = bitstack14 = bitstack15
	= bitstack16 = bitstack17 = bitstack18 = bitstack19 = bitstack20 = bitstack21 = bitstack22 = bitstack23
	= bitstack24 = bitstack25 = bitstack26 = bitstack27 = bitstack28 = bitstack29 = bitstack30 = bitstack31
	= bitstack32 = bitstack33 = bitstack34 = bitstack35 = bitstack36 = bitstack37 = bitstack38 = bitstack39
	= bitstack40 = bitstack41 = bitstack42 = bitstack43 = bitstack44 = bitstack45 = bitstack46 = bitstack47
	= bitstack48 = bitstack49 = bitstack50 = bitstack51 = bitstack52 = bitstack53 = bitstack54 = bitstack55
	= bitstack56 = bitstack57 = bitstack58 = bitstack59 = bitstack60 = bitstack61 = bitstack62 = bitstack63
	= bitstack64 = bitstack65 = bitstack66 = bitstack67 = bitstack68 = bitstack69 = bitstack70 = bitstack71
	= bitstack72 = bitstack73 = bitstack74 = bitstack75 = bitstack76 = bitstack77 = bitstack78 = bitstack79
	= bitstack80 = bitstack81 = bitstack82 = bitstack83 = bitstack84 = bitstack85 = bitstack86 = bitstack87
	= bitstack88 = bitstack89 = bitstack90 = bitstack91 = bitstack92 = bitstack93 = bitstack94 = bitstack95
	= bitstack96 = bitstack97 = bitstack98 = bitstack99 = bitstack100 = bitstack101 = bitstack102
	= bitstack103 = bitstack104 = bitstack105 = bitstack106 = bitstack107 = bitstack108 = bitstack109
	= bitstack110 = bitstack111 = bitstack112 = bitstack113 = bitstack114 = bitstack115 = bitstack116
	= bitstack117 = bitstack118 = bitstack119 = bitstack120 = bitstack121 = bitstack122 = bitstack123
	= bitstack124 = bitstack125 = bitstack126 = bitstack127
	= 0LLU;
	recursion_count = 0;
}

int closedAllParentheses(int depth) {
	if (
		++recursion_count > MAX_TOTAL_CALLS
		|| depth < 0 || depth > MAX_NESTING_DEPTH
	) {
		scanf("%*[^\n]");
		return 0;
	}

	int input = 0;
	char c = 0;

	if ((input = scanf("%c", &c)) != 1) {
		selectedTask = EXIT_PROGRAM;
		return EOF;
	}

	if (c == '\n') {
		return !depth;
	}

	unsigned int code = encodeLegalCharacters(c);

	if (code == (unsigned int)-1) {
		return closedAllParentheses(depth);
	}

	int index = depth / LEVELS_PER_BITSTACK;
	int shift = (depth % LEVELS_PER_BITSTACK) * BITS_PER_LEVEL;

	if (c == '(' || c == '[' || c == '{' || c == '<') {

		if (depth >= MAX_NESTING_DEPTH) {
			selectedTask = EXIT_PROGRAM;
			return 0;
		}

		unsigned long long bitstack = GET_BITSTACK(index);
		bitstack |= ((unsigned long long)code << shift);

		SET_BITSTACK(index, bitstack);

		return closedAllParentheses(depth + 1);
	}

	if (c == ')' || c == ']' || c == '}' || c == '>') {
		
		if (depth <= 0) {
			scanf("%*[^\n]");
			return 0;
		}

		index = (--depth) / LEVELS_PER_BITSTACK;
		shift = (depth % LEVELS_PER_BITSTACK) * BITS_PER_LEVEL;

		unsigned long long bitstack = GET_BITSTACK(index);
		unsigned int top = (bitstack >> shift) & 3LLU;

		if (top != code) {
			scanf("%*[^\n]");
			return 0;
		}

		bitstack &= ~(3LLU << shift);

		SET_BITSTACK(index, bitstack);
		
		return closedAllParentheses(depth);
	}

	selectedTask = EXIT_PROGRAM;
	return EOF;
}

unsigned int encodeLegalCharacters(char c) {
	switch(c) {
		case '(': case ')': return BITS_00;
		case '[': case ']': return BITS_01;
		case '{': case '}': return BITS_10;
		case '<': case '>': return BITS_11;
		default: return (unsigned int)-1;
	}
	return (unsigned int)-1;
}


//////////////////////////////////
// TASK 4 FUNCTIONS
//////////////////////////////////

void QueensBattle() {
	int input = 0, dimension = 0;

	printf("Please enter the board dimensions:\n");
	
	while (
		(input = scanf(" %d", &dimension)) != 1
		|| dimension <= 0 || dimension > MAX
	) {
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

	unsigned long long colMask = 0LLU, zoneMask = 0LLU;

	if (isPuzzleSolvable(
			dimension,
			queenTracker,
			&colMask,
			&zoneMask,
			zones
	)) {
		printf("Solution:\n");
		for (int row = 0; row < dimension; row++) {
			for (int col = 0; col < dimension; col++) {
				queenTracker[row] == col
					? printf("X ")
					: printf("* ");
			}
			printf("\n");
		}
	} else {
		printf("This puzzle cannot be solved.\n");
	}
	scanf("%*[^\n]");
}

void initQueenTracker(
	int index,
	int dimension,
	int queenTracker[MAX]
) {
	if (index >= 0 && index < dimension) {

		queenTracker[index] = NONE_PLACED;

		initQueenTracker(
			index + 1,
			dimension,
			queenTracker
		);
	}
}

int isPuzzleSolvable(
	int dimension, 
	int queenTracker[MAX],
	unsigned long long *colMask,
	unsigned long long *zoneMask, 
	char zones[MAX][MAX]
) {
	return (
		tryPlacingQueenInRow(
			0,
			dimension,
			queenTracker,
			colMask,
			zoneMask,
			zones
		) ? 1 : 0
	);
}

int tryPlacingQueenInRow(
	int currentRow,
	int dimension,
	int queenTracker[MAX],
	unsigned long long *colMask,
	unsigned long long *zoneMask,
	char zones[MAX][MAX]
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

int tryPlacingQueenInColumn(
	int col,
	int currentRow,
	int dimension,
	int queenTracker[MAX],
	unsigned long long *colMask,
	unsigned long long *zoneMask,
	char zones[MAX][MAX]
) {
	if (col != dimension) {

		unsigned long long colBit = 1LLU << col;
		int zid = zones[currentRow][col] - ASCII_MIN;
		unsigned long long zidBit = 1LLU << zid;

		if ((*colMask&colBit) || (*zoneMask & zidBit)) {
			return tryPlacingQueenInColumn(
				col + 1,
				currentRow,
				dimension,
				queenTracker,
				colMask,
				zoneMask,
				zones
			);
		}

		if (isCellAdjacentToExistingQueen(
				queenTracker,
				0,
				col,
				currentRow,
				dimension
		)) {
			return tryPlacingQueenInColumn(
				col + 1,
				currentRow,
				dimension,
				queenTracker,
				colMask,
				zoneMask,
				zones
			);
		}

		queenTracker[currentRow] = col;
		*colMask |= colBit;
		*zoneMask |= zidBit;

		if (tryPlacingQueenInRow(
			currentRow + 1,
			dimension,
			queenTracker,
			colMask,
			zoneMask,
			zones
		)) {
			return 1;
		}

		*colMask &= ~ colBit;
		*zoneMask &= ~ zidBit;
		queenTracker[currentRow] = NONE_PLACED;
		
		return (tryPlacingQueenInColumn(
			col + 1,
			currentRow,
			dimension,
			queenTracker,
			colMask,
			zoneMask,
			zones
		));
	}
	return 0;
}

int isCellAdjacentToExistingQueen(
	int queenTracker[MAX],
	int row,
	int col,
	int currentRow,
	int dimension
) {
	return (
		row < 0 || row == currentRow || row >= dimension
			? 0
		: queenTracker[row] >= 0
		&& computeDistanceBetweenCells(queenTracker[row], col) <= 1
		&& computeDistanceBetweenCells(row, currentRow) <= 1
			? 1
		: isCellAdjacentToExistingQueen(
			queenTracker,
			row + 1,
			col,
			currentRow,
			dimension
		)
	);
}

int computeDistanceBetweenCells(int a, int b) {
	return a > b ? a - b : b - a;
}


////////////////////////////////////////////
// MAIN, MENU, NAVIGATION
////////////////////////////////////////////

void displayMenu() {
	printf("Choose an option:\n"
		"1. Robot Paths\n"
		"2. The Human Pyramid\n"
		"3. Parenthesis Validation\n"
		"4. Queens Battle\n"
		"5. Exit\n"
	);
}

void menuNavigate() {
	switch (selectedTask) {
		case EXIT_PROGRAM: break;
		case ROBOT_PATHS: robotPaths(); break;
		case HUMAN_PYRAMID: humanPyramid(); break;
		case PARENTHESES_VALIDATOR: parenthesisValidator(); break;
		case QUEENS_BATTLE: QueensBattle(); break;
		default: printf("Please choose a task number from the list.\n");
	}
}

void menuSelect() {
	selectedTask = UNSELECTED;
	int input = UNSELECTED, temp = UNSELECTED;

	while (
		displayMenu(),
		(input = scanf(" %d",&temp)) != 1
		|| temp < 1 || temp > EXIT_PROGRAM
	) {
		if (input == EOF) {
			selectedTask = EXIT_PROGRAM;
			return;
		}

		scanf("%*[^\n]");
		printf("Please choose a task number from the list.\n");
	}
	selectedTask = temp;
}

int main() {
	while (selectedTask != EXIT_PROGRAM) {
		menuSelect();
		menuNavigate();
	}
	printf("Goodbye!\n");
	return 0;
}