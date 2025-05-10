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
#define BITS_PER_WORD 64

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
#define LEVELS_PER_WORD (BITS_PER_WORD / BITS_PER_LEVEL)

/*
Task 3
TODO: NOTE
Used for overflow prevention
*/
#define WORD_COUNT (MAX_NESTING_DEPTH / LEVELS_PER_WORD)

/*
Task 3
TODO: NOTE
Used for overflow prevention
*/
#define GET_WORD(i) ( \
	(i)==0?word0:(i)==1?word1:(i)==2?word2:(i)==3?word3:(i)==4?word4: \
	(i)==5?word5:(i)==6?word6:(i)==7?word7:(i)==8?word8:(i)==9?word9: \
	(i)==10?word10:(i)==11?word11:(i)==12?word12:(i)==13?word13:(i)==14?word14: \
	(i)==15?word15:(i)==16?word16:(i)==17?word17:(i)==18?word18:(i)==19?word19: \
	(i)==20?word20:(i)==21?word21:(i)==22?word22:(i)==23?word23:(i)==24?word24: \
	(i)==25?word25:(i)==26?word26:(i)==27?word27:(i)==28?word28:(i)==29?word29: \
	(i)==30?word30:(i)==31?word31:(i)==32?word32:(i)==33?word33:(i)==34?word34: \
	(i)==35?word35:(i)==36?word36:(i)==37?word37:(i)==38?word38:(i)==39?word39: \
	(i)==40?word40:(i)==41?word41:(i)==42?word42:(i)==43?word43:(i)==44?word44: \
	(i)==45?word45:(i)==46?word46:(i)==47?word47:(i)==48?word48:(i)==49?word49: \
	(i)==50?word50:(i)==51?word51:(i)==52?word52:(i)==53?word53:(i)==54?word54: \
	(i)==55?word55:(i)==56?word56:(i)==57?word57:(i)==58?word58:(i)==59?word59: \
	(i)==60?word60:(i)==61?word61:(i)==62?word62:(i)==63?word63:(i)==64?word64: \
	(i)==65?word65:(i)==66?word66:(i)==67?word67:(i)==68?word68:(i)==69?word69: \
	(i)==70?word70:(i)==71?word71:(i)==72?word72:(i)==73?word73:(i)==74?word74: \
	(i)==75?word75:(i)==76?word76:(i)==77?word77:(i)==78?word78:(i)==79?word79: \
	(i)==80?word80:(i)==81?word81:(i)==82?word82:(i)==83?word83:(i)==84?word84: \
	(i)==85?word85:(i)==86?word86:(i)==87?word87:(i)==88?word88:(i)==89?word89: \
	(i)==90?word90:(i)==91?word91:(i)==92?word92:(i)==93?word93:(i)==94?word94: \
	(i)==95?word95:(i)==96?word96:(i)==97?word97:(i)==98?word98:(i)==99?word99: \
	(i)==100?word100:(i)==101?word101:(i)==102?word102:(i)==103?word103:(i)==104?word104: \
	(i)==105?word105:(i)==106?word106:(i)==107?word107:(i)==108?word108:(i)==109?word109: \
	(i)==110?word110:(i)==111?word111:(i)==112?word112:(i)==113?word113:(i)==114?word114: \
	(i)==115?word115:(i)==116?word116:(i)==117?word117:(i)==118?word118:(i)==119?word119: \
	(i)==120?word120:(i)==121?word121:(i)==122?word122:(i)==123?word123:(i)==124?word124: \
	(i)==125?word125:(i)==126?word126:word127)

/*
Task 3
TODO: NOTE
Used for overflow prevention
*/
#define SET_WORD(i, val) do { \
	if ((i)==0) word0=(val); else if ((i)==1) word1=(val); else if ((i)==2) word2=(val); \
	else if ((i)==3) word3=(val); else if ((i)==4) word4=(val); else if ((i)==5) word5=(val); \
	else if ((i)==6) word6=(val); else if ((i)==7) word7=(val); else if ((i)==8) word8=(val); \
	else if ((i)==9) word9=(val); else if ((i)==10) word10=(val); else if ((i)==11) word11=(val); \
	else if ((i)==12) word12=(val); else if ((i)==13) word13=(val); else if ((i)==14) word14=(val); \
	else if ((i)==15) word15=(val); else if ((i)==16) word16=(val); else if ((i)==17) word17=(val); \
	else if ((i)==18) word18=(val); else if ((i)==19) word19=(val); else if ((i)==20) word20=(val); \
	else if ((i)==21) word21=(val); else if ((i)==22) word22=(val); else if ((i)==23) word23=(val); \
	else if ((i)==24) word24=(val); else if ((i)==25) word25=(val); else if ((i)==26) word26=(val); \
	else if ((i)==27) word27=(val); else if ((i)==28) word28=(val); else if ((i)==29) word29=(val); \
	else if ((i)==30) word30=(val); else if ((i)==31) word31=(val); else if ((i)==32) word32=(val); \
	else if ((i)==33) word33=(val); else if ((i)==34) word34=(val); else if ((i)==35) word35=(val); \
	else if ((i)==36) word36=(val); else if ((i)==37) word37=(val); else if ((i)==38) word38=(val); \
	else if ((i)==39) word39=(val); else if ((i)==40) word40=(val); else if ((i)==41) word41=(val); \
	else if ((i)==42) word42=(val); else if ((i)==43) word43=(val); else if ((i)==44) word44=(val); \
	else if ((i)==45) word45=(val); else if ((i)==46) word46=(val); else if ((i)==47) word47=(val); \
	else if ((i)==48) word48=(val); else if ((i)==49) word49=(val); else if ((i)==50) word50=(val); \
	else if ((i)==51) word51=(val); else if ((i)==52) word52=(val); else if ((i)==53) word53=(val); \
	else if ((i)==54) word54=(val); else if ((i)==55) word55=(val); else if ((i)==56) word56=(val); \
	else if ((i)==57) word57=(val); else if ((i)==58) word58=(val); else if ((i)==59) word59=(val); \
	else if ((i)==60) word60=(val); else if ((i)==61) word61=(val); else if ((i)==62) word62=(val); \
	else if ((i)==63) word63=(val); else if ((i)==64) word64=(val); else if ((i)==65) word65=(val); \
	else if ((i)==66) word66=(val); else if ((i)==67) word67=(val); else if ((i)==68) word68=(val); \
	else if ((i)==69) word69=(val); else if ((i)==70) word70=(val); else if ((i)==71) word71=(val); \
	else if ((i)==72) word72=(val); else if ((i)==73) word73=(val); else if ((i)==74) word74=(val); \
	else if ((i)==75) word75=(val); else if ((i)==76) word76=(val); else if ((i)==77) word77=(val); \
	else if ((i)==78) word78=(val); else if ((i)==79) word79=(val); else if ((i)==80) word80=(val); \
	else if ((i)==81) word81=(val); else if ((i)==82) word82=(val); else if ((i)==83) word83=(val); \
	else if ((i)==84) word84=(val); else if ((i)==85) word85=(val); else if ((i)==86) word86=(val); \
	else if ((i)==87) word87=(val); else if ((i)==88) word88=(val); else if ((i)==89) word89=(val); \
	else if ((i)==90) word90=(val); else if ((i)==91) word91=(val); else if ((i)==92) word92=(val); \
	else if ((i)==93) word93=(val); else if ((i)==94) word94=(val); else if ((i)==95) word95=(val); \
	else if ((i)==96) word96=(val); else if ((i)==97) word97=(val); else if ((i)==98) word98=(val); \
	else if ((i)==99) word99=(val); else if ((i)==100) word100=(val); else if ((i)==101) word101=(val); \
	else if ((i)==102) word102=(val); else if ((i)==103) word103=(val); else if ((i)==104) word104=(val); \
	else if ((i)==105) word105=(val); else if ((i)==106) word106=(val); else if ((i)==107) word107=(val); \
	else if ((i)==108) word108=(val); else if ((i)==109) word109=(val); else if ((i)==110) word110=(val); \
	else if ((i)==111) word111=(val); else if ((i)==112) word112=(val); else if ((i)==113) word113=(val); \
	else if ((i)==114) word114=(val); else if ((i)==115) word115=(val); else if ((i)==116) word116=(val); \
	else if ((i)==117) word117=(val); else if ((i)==118) word118=(val); else if ((i)==119) word119=(val); \
	else if ((i)==120) word120=(val); else if ((i)==121) word121=(val); else if ((i)==122) word122=(val); \
	else if ((i)==123) word123=(val); else if ((i)==124) word124=(val); else if ((i)==125) word125=(val); \
	else if ((i)==126) word126=(val); else word127=(val); \
} while (0)


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
Task 3
TODO: NOTE
Used for overflow prevention
*/
static unsigned long long word0  = 0ULL;
static unsigned long long word1  = 0ULL;
static unsigned long long word2  = 0ULL;
static unsigned long long word3  = 0ULL;
static unsigned long long word4  = 0ULL;
static unsigned long long word5  = 0ULL;
static unsigned long long word6  = 0ULL;
static unsigned long long word7  = 0ULL;
static unsigned long long word8  = 0ULL;
static unsigned long long word9  = 0ULL;
static unsigned long long word10 = 0ULL;
static unsigned long long word11 = 0ULL;
static unsigned long long word12 = 0ULL;
static unsigned long long word13 = 0ULL;
static unsigned long long word14 = 0ULL;
static unsigned long long word15 = 0ULL;
static unsigned long long word16 = 0ULL;
static unsigned long long word17 = 0ULL;
static unsigned long long word18 = 0ULL;
static unsigned long long word19 = 0ULL;
static unsigned long long word20 = 0ULL;
static unsigned long long word21 = 0ULL;
static unsigned long long word22 = 0ULL;
static unsigned long long word23 = 0ULL;
static unsigned long long word24 = 0ULL;
static unsigned long long word25 = 0ULL;
static unsigned long long word26 = 0ULL;
static unsigned long long word27 = 0ULL;
static unsigned long long word28 = 0ULL;
static unsigned long long word29 = 0ULL;
static unsigned long long word30 = 0ULL;
static unsigned long long word31 = 0ULL;
static unsigned long long word32 = 0ULL;
static unsigned long long word33 = 0ULL;
static unsigned long long word34 = 0ULL;
static unsigned long long word35 = 0ULL;
static unsigned long long word36 = 0ULL;
static unsigned long long word37 = 0ULL;
static unsigned long long word38 = 0ULL;
static unsigned long long word39 = 0ULL;
static unsigned long long word40 = 0ULL;
static unsigned long long word41 = 0ULL;
static unsigned long long word42 = 0ULL;
static unsigned long long word43 = 0ULL;
static unsigned long long word44 = 0ULL;
static unsigned long long word45 = 0ULL;
static unsigned long long word46 = 0ULL;
static unsigned long long word47 = 0ULL;
static unsigned long long word48 = 0ULL;
static unsigned long long word49 = 0ULL;
static unsigned long long word50 = 0ULL;
static unsigned long long word51 = 0ULL;
static unsigned long long word52 = 0ULL;
static unsigned long long word53 = 0ULL;
static unsigned long long word54 = 0ULL;
static unsigned long long word55 = 0ULL;
static unsigned long long word56 = 0ULL;
static unsigned long long word57 = 0ULL;
static unsigned long long word58 = 0ULL;
static unsigned long long word59 = 0ULL;
static unsigned long long word60 = 0ULL;
static unsigned long long word61 = 0ULL;
static unsigned long long word62 = 0ULL;
static unsigned long long word63 = 0ULL;
static unsigned long long word64 = 0ULL;
static unsigned long long word65 = 0ULL;
static unsigned long long word66 = 0ULL;
static unsigned long long word67 = 0ULL;
static unsigned long long word68 = 0ULL;
static unsigned long long word69 = 0ULL;
static unsigned long long word70 = 0ULL;
static unsigned long long word71 = 0ULL;
static unsigned long long word72 = 0ULL;
static unsigned long long word73 = 0ULL;
static unsigned long long word74 = 0ULL;
static unsigned long long word75 = 0ULL;
static unsigned long long word76 = 0ULL;
static unsigned long long word77 = 0ULL;
static unsigned long long word78 = 0ULL;
static unsigned long long word79 = 0ULL;
static unsigned long long word80 = 0ULL;
static unsigned long long word81 = 0ULL;
static unsigned long long word82 = 0ULL;
static unsigned long long word83 = 0ULL;
static unsigned long long word84 = 0ULL;
static unsigned long long word85 = 0ULL;
static unsigned long long word86 = 0ULL;
static unsigned long long word87 = 0ULL;
static unsigned long long word88 = 0ULL;
static unsigned long long word89 = 0ULL;
static unsigned long long word90 = 0ULL;
static unsigned long long word91 = 0ULL;
static unsigned long long word92 = 0ULL;
static unsigned long long word93 = 0ULL;
static unsigned long long word94 = 0ULL;
static unsigned long long word95 = 0ULL;
static unsigned long long word96 = 0ULL;
static unsigned long long word97 = 0ULL;
static unsigned long long word98 = 0ULL;
static unsigned long long word99 = 0ULL;
static unsigned long long word100 = 0ULL;
static unsigned long long word101 = 0ULL;
static unsigned long long word102 = 0ULL;
static unsigned long long word103 = 0ULL;
static unsigned long long word104 = 0ULL;
static unsigned long long word105 = 0ULL;
static unsigned long long word106 = 0ULL;
static unsigned long long word107 = 0ULL;
static unsigned long long word108 = 0ULL;
static unsigned long long word109 = 0ULL;
static unsigned long long word110 = 0ULL;
static unsigned long long word111 = 0ULL;
static unsigned long long word112 = 0ULL;
static unsigned long long word113 = 0ULL;
static unsigned long long word114 = 0ULL;
static unsigned long long word115 = 0ULL;
static unsigned long long word116 = 0ULL;
static unsigned long long word117 = 0ULL;
static unsigned long long word118 = 0ULL;
static unsigned long long word119 = 0ULL;
static unsigned long long word120 = 0ULL;
static unsigned long long word121 = 0ULL;
static unsigned long long word122 = 0ULL;
static unsigned long long word123 = 0ULL;
static unsigned long long word124 = 0ULL;
static unsigned long long word125 = 0ULL;
static unsigned long long word126 = 0ULL;
static unsigned long long word127 = 0ULL;


/*
Menu Selection (global)
*/
int selectedTask;


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


// CRITICAL TODO: RECURSIVE
/*
Task 1
Count total legal paths from (x, y) to (0, 0)
*/
unsigned long long robotPathCount(unsigned long long n, unsigned long long k);


/*
Task 2
Display the output of the computeWeightTotal recursive function
*/
void displayWeight(int row, int col, double selfWeight[5][5]);


/*
Task 2
Compute the overhead weight supported by a cheerleader
*/
float computeWeightOverhead(int row, int col, double selfWeight[5][5]);


/*
Task 2
Compute the total weight a cheerleader supports
*/
float computeWeightTotal(int row, int col, double selfWeight[5][5]);


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
int closedAllParentheses(int depth);
// int closedAllParentheses(int depth, unsigned long long word);

/*
Task 3
TODO: NOTE
*/
void resetWords();

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
	// int currentRow,
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

	// CRITICAL TODO: MAGIC
	double selfWeight[5][5] = {0};
	
	printf("Please enter the weights of the cheerleaders:\n");
	
	// CRITICAL TODO: MAGIC
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= i; j++) {
			double nextWeight = -1.00;
			int input = 0;
			if ((input = scanf(" %lf", &nextWeight)) != 1 || nextWeight < 0.00) {
				if (input == EOF) {
					selectedTask = EXIT_PROGRAM;
					return;
				}
				scanf("%*[^\n]");
				// scanf("%*[^1234567890 \n]");
				printf("Negative weights are not supported.\n");
				return;
			}
			selfWeight[i][j] = nextWeight;
		}
	}
	printf("The total weight on each cheerleader is:\n");
	for (int row = 0; row < 5; row++) {
		for (int col = 0; col <= row; col++) {
			displayWeight(row, col, selfWeight);
			// printf("%.2f ", computeWeightTotal(row, col, selfWeight));
		}
		printf("\n");
	}
}


void parenthesisValidator() {
	resetWords();
	// unsigned long long word;

	int depth = 0, balance = EOF;

	// clear residual newline
	scanf("%*c");
	printf("Please enter a term for validation:\n");

	balance = closedAllParentheses(depth);
	// balance = closedAllParentheses(depth, word);

	balance == EOF
		? selectedTask = EXIT_PROGRAM
		: printf("The parentheses are%sbalanced correctly.\n", balance ? " " : " not ");
	
	resetWords();
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
	if (isPuzzleSolvable(dimension, queenTracker, &colMask, &zoneMask, zones)) {
	// if (isPuzzleSolvable(0, dimension, queenTracker, &colMask, &zoneMask, zones)) {
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
	
	// CRITICAL TODO: RECURSIVE
	for (unsigned long long i = 1; i <= k; i++) {
		r = r * (n - k + i) / i;
	}
	return r;
}


void displayWeight(int row, int col, double selfWeight[5][5]) {
	printf("%.2f ", computeWeightTotal(row, col, selfWeight));
}


float computeWeightOverhead(int row, int col, double selfWeight[5][5]) {
	if (row == 0) {
		return 0.0f;
	}

	float weightUpLeft = (col > 0) ? computeWeightTotal(row - 1, col - 1, selfWeight) / 2.0f : 0.0f;
	float weightUpRight = (col < row) ? computeWeightTotal(row - 1, col, selfWeight) / 2.0f : 0.0f;

	return weightUpLeft + weightUpRight;
}


float computeWeightTotal(int row, int col, double selfWeight[5][5]) {
	return (
		row < 0 || col < 0 || col > row
			? 0.0f
			: (float)selfWeight[row][col]
				+ computeWeightOverhead(row, col, selfWeight)
	);
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

int closedAllParentheses(int depth) {
    if (depth > MAX_NESTING_DEPTH) {
        scanf("%*[^\n]");
        return 0;
    }

    char c;
    if (scanf("%c", &c) != 1) return EOF;
    if (c == '\n') return depth == 0;

    unsigned int code = encodeLegalCharacters(c);
    if (code == (unsigned int)-1)
        return closedAllParentheses(depth);

    int index = depth / LEVELS_PER_WORD;
    int shift = (depth % LEVELS_PER_WORD) * BITS_PER_LEVEL;

    if (c == '(' || c == '[' || c == '{' || c == '<') {
        if (depth >= MAX_NESTING_DEPTH) {
            scanf("%*[^\n]");
            return 0;
        }
        unsigned long long word = GET_WORD(index);
        word |= ((unsigned long long)code << shift);
        SET_WORD(index, word);
        return closedAllParentheses(depth + 1);
    }

    if (c == ')' || c == ']' || c == '}' || c == '>') {
        if (depth <= 0) {
            scanf("%*[^\n]");
            return 0;
        }
        --depth;
        index = depth / LEVELS_PER_WORD;
        shift = (depth % LEVELS_PER_WORD) * BITS_PER_LEVEL;
        unsigned long long word = GET_WORD(index);
        unsigned int top = (word >> shift) & 3ULL;
        if (top != code) {
            scanf("%*[^\n]");
            return 0;
        }
        word &= ~(3ULL << shift);
        SET_WORD(index, word);
        return closedAllParentheses(depth);
    }

    return EOF;
}

// int closedAllParentheses(int depth, unsigned long long word) {
// 	int input = 0, open = 0, closed = 0;
// 	unsigned int code = (unsigned int)-1;
// 	char curr = 0;
// 	if ((input = scanf("%c", &curr)) != 1) {
// 		return EOF;
// 	}
// 	if (curr == '\n') {
// 		return !depth;
// 	}
// 	open = (curr == '(' || curr == '[' || curr == '{' || curr == '<') ? 1 : 0;
// 	closed = (curr == ')' || curr == ']' || curr == '}' || curr == '>') ? 1 : 0;
// 	if (!(open || closed)) {
// 		return closedAllParentheses(depth, word);
// 	}
// 	code = encodeLegalCharacters(curr);
// 	if (code == (unsigned int)-1) {
// 		// should never be reached
// 		return EOF;
// 	}
// 	if (open) {
// 		return closedAllParentheses(++depth, (word << 2) | code);
// 	}
// 	if (closed) {
// 		if (!depth || (word & 3U) != code) {
// 			scanf("%*[^\n]");
// 			return 0;
// 		}
// 		return closedAllParentheses(--depth, (word >> 2));
// 	}
// 	return EOF;
// }


void resetWords() {
    word0 = word1 = word2 = word3 = word4 = word5 = word6 = word7 =
    word8 = word9 = word10 = word11 = word12 = word13 = word14 = word15 =
    word16 = word17 = word18 = word19 = word20 = word21 = word22 = word23 =
    word24 = word25 = word26 = word27 = word28 = word29 = word30 = word31 =
    word32 = word33 = word34 = word35 = word36 = word37 = word38 = word39 =
    word40 = word41 = word42 = word43 = word44 = word45 = word46 = word47 =
    word48 = word49 = word50 = word51 = word52 = word53 = word54 = word55 =
    word56 = word57 = word58 = word59 = word60 = word61 = word62 = word63 =
    word64 = word65 = word66 = word67 = word68 = word69 = word70 = word71 =
    word72 = word73 = word74 = word75 = word76 = word77 = word78 = word79 =
    word80 = word81 = word82 = word83 = word84 = word85 = word86 = word87 =
    word88 = word89 = word90 = word91 = word92 = word93 = word94 = word95 =
    word96 = word97 = word98 = word99 = word100 = word101 = word102 = word103 =
    word104 = word105 = word106 = word107 = word108 = word109 = word110 = word111 =
    word112 = word113 = word114 = word115 = word116 = word117 = word118 = word119 =
    word120 = word121 = word122 = word123 = word124 = word125 = word126 = word127 = 0ULL;
}


void initQueenTracker(int index, int dimension, int queenTracker[MAX]) {
	if (index >= 0 && index < dimension) {
		queenTracker[index] = NONE_PLACED;
		initQueenTracker(index + 1, dimension, queenTracker);
	}
}

int isPuzzleSolvable(int dimension, int queenTracker[MAX],
// int isPuzzleSolvable(int currentRow, int dimension, int queenTracker[MAX],
	unsigned long long *colMask, unsigned long long *zoneMask, char zones[MAX][MAX]
) {
	return (
		tryPlacingQueenInRow(0, dimension, queenTracker, colMask, zoneMask, zones)
		// tryPlacingQueenInRow(0, dimension, queenTracker, colMask, zoneMask, zones)
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


// MENU FUNCTIONS

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
		case EXIT_PROGRAM:
			printf("Goodbye!\n");
			break;
		default:
			printf("Please choose a task number from the list.\n");
	}
}


int main() {
	while (selectedTask != EXIT_PROGRAM) {
		menuSelect();
		menuNavigate();
	}
	return 0;

	
// int main() {
	// while (selectedTask != EXIT_PROGRAM) {
	// 	menuSelect();
	// 	switch (selectedTask) {
	// 		case EXIT_PROGRAM: break;
	// 		case ROBOT_PATHS:
    //             robotPaths();
    //             break;
	// 		case HUMAN_PYRAMID:
    //             humanPyramid();
    //             break;
	// 		case PARENTHESES_VALIDATOR:
    //             parenthesisValidator();
    //             break;
    //         case QUEENS_BATTLE:
    //             QueensBattle();
    //             break;
	// 		default: printf("Please choose a task number from the list.\n");
	// 	}
	// }
	// printf("Goodbye!\n");
	// return 0;
}