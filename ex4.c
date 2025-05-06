/******************
Name: Samantha Newmark
ID: 
Assignment: ex4
*******************/

#include<stdio.h>
#include<string.h>

/*
no menu option selected
*/
#define UNSELECTED 0

/*
menu selection id
task 1
*/
#define ROBOT_PATHS 1

/*
menu selection id
task 2
*/
#define HUMAN_PYRAMID 2

/*
menu selection id
task 3
*/
#define PARENTHESES 3

/*
menu selection id
task 4
*/
#define QUEENS 4

/*
menu selection
exit program
*/
#define DONE 5

/*
0b0000
task 3
mask ( )
*/
#define BIN00 0

/*
0b0001
task 3
mask [ ]
*/
#define BIN01 1

/*
0b0010
task 3
mask { }
*/
#define BIN10 2

/*
0b0011
task 3
mask < >
*/ 
#define BIN11 3


/*
task 4
minimum legal character ASCII for zone id
*/
#define ASCII_MIN 33


/*
select task from menu options
*/
void menuSelect();

/*
print menu options
*/
void displayMenu();

/*
menu selection
global
*/
int selectedTask;


/*
Restricted to traveling only left and/or down, how many paths could a robot take from some (x, y) to (0, 0)?
*/
void task1RobotPaths();


/*
What is the total weight load of each cheerleader in a pyramid formation?
*/
void task2HumanPyramid();


/*
Has every opening parenthesis been properly closed?
Legal: ( ), [ ], { }, < >
*/
void task3ParenthesisValidator();


/*
For a square grid of dimensions N x N and exactly N queens,
is there a legal configuration of queens such that none of these conditions is violated:
- exactly one queen in every row,
- exactly one queen in every column
- every cell adjacent to each queen is empty (row, col, diags)
*/ 
void task4QueensBattle();


/*
task 1
count legal paths from (x, y) to (0,0)
*/
unsigned long long robotPathCount(unsigned long long n, unsigned long long k);


/*
task 3
assign binary id to parenthesis
*/
unsigned int bitmaskParenthesis(char c);


/*
task 3
check if all parentheses are closed
*/
int closedAllParentheses(int depth, unsigned long long word);
// int closedAllParentheses(int input, char curr, int *depth, unsigned int *word);

/*
task 4
distance between coodinates
*/
int absoluteDifference(int a, int b);


// MENU FUNCTIONS

void displayMenu(){
	printf("Choose an option:\n"
	"1. Robot Paths\n"
	"2. The Human Pyramid\n"
	"3. Parenthesis Validation\n"
	"4. Queens Battle\n"
	"5. Exit\n");
}

void menuSelect(){
	selectedTask=UNSELECTED;
	int input=UNSELECTED, temp=UNSELECTED;
	while(displayMenu(), (input=scanf(" %d",&temp)) !=1 ||temp<1 ||temp>DONE){
		if(input==EOF){
			selectedTask=DONE;
			return;
		}
		scanf("%*[^\n]");
		// scanf("%*[^12345 \t\n]");
		printf("Please choose a task number from the list.\n");
	}
	selectedTask=temp;
}


// TASK FUNCTIONS

void task1RobotPaths(){
	int input=0, x=0, y=0;
	printf("Please enter the coordinates of the robot (column, row):\n");
	while((input=scanf(" %d %d", &x, &y)) !=2){
		if(input==EOF){
			selectedTask=DONE;
			return;
		}
		scanf("%*[^\n]");
		// scanf("%*[^1234567890 \t\n]");
		continue;
	}
	printf("The total number of paths the robot can take to reach home is: %llu\n",
		(x<0 ||y<0)?0:(!x && !y)?1:robotPathCount((unsigned long long)(x+y), (unsigned long long)x)
	);
}

void task2HumanPyramid(){
	double dataPyramid[5][5]={0};
	printf("Please enter the weights of the cheerleaders:\n");
	for(int i=0; i<5; i++){
		for(int j=0; j<=i; j++){
			double nextWeight= -1.00;
			int input=0;
			if((input=scanf(" %lf", &nextWeight)) !=1 ||nextWeight<0){
				if(input==EOF){
					selectedTask=DONE;
					return;
				}
				scanf("%*[^\n]");
				// scanf("%*[^1234567890 \n]");
				printf("Negative weights are not supported.\n");
				return;
			}
			dataPyramid[i][j]=nextWeight;
		}
	}
	printf("The total weight on each cheerleader is:\n");
	for(int i=0; i<5; i++){
		for(int j=0; j<=i; j++){
			float weightLoad=dataPyramid[i][j];
			if(i>0){
				float weightUpLeft=(j>0)?(float)dataPyramid[i-1][j-1]/2.0:0;
				float weightUpRight=(j<i)?(float)dataPyramid[i-1][j]/2.0:0;
				weightLoad+=weightUpLeft+weightUpRight;
			}
			dataPyramid[i][j]=weightLoad;
			printf("%.2f ", weightLoad);
		}
		printf("\n");
	}
	return;
}

void task3ParenthesisValidator(){
	int depth=0, balance=0;
	unsigned long long word=0;
	scanf("%*c");
	printf("Please enter a term for validation:\n");
	balance=closedAllParentheses(depth, word);
	balance==EOF ? selectedTask=DONE
	: printf("The parentheses are%sbalanced correctly.\n", balance?" ":" not ");
}

void task4QueensBattle(){
	int input=0, dimension=0;
	printf("Please enter the board dimensions:\n");
	while((input=scanf(" %d", &dimension)) !=1 ||dimension<=0 ||dimension>20){
		if(input==EOF){
			selectedTask=DONE;
			return;
		}
		scanf("%*[^ \t\n]");
		continue;
	}
	int filled=0, row=0, col=0;
	char zoneChar='\0';
	char zones[20][20]={{0}};
	printf("Please enter a %d*%d puzzle board:\n", dimension, dimension);
	while(filled<dimension*dimension){
		if((input=scanf("%c", &zoneChar)) !=1 ||zoneChar==' ' ||zoneChar=='\n' ||zoneChar=='\t'
		){
			if(input==EOF){
				selectedTask=DONE;
				return;
			}
			continue;
		}
		zones[row][col++]=zoneChar;
		if(col==dimension){
			col=0;
			row++;
		}
		++filled;
	}
	int board[20];
	for(int i=0; i<dimension; i++){
		board[i]= -1;
	}
	int currentRow=0, solved=0;
	unsigned long long colMask=0, zoneMask=0;
	
	// CRITICAL TODO: RECURSIVE
	while(1){
	
		board[currentRow]++;
		while(board[currentRow]<dimension){
			int col=board[currentRow];
			int zid=zones[currentRow][col]-ASCII_MIN;
			int valid= !(colMask &(1ULL<<col)) && !(zoneMask &(1ULL<<zid));
			for(int r=0; valid&&r<currentRow; r++){
				int c=board[r];
				if(c>=0 &&absoluteDifference(c, col)<=1 &&absoluteDifference(r, currentRow)<=1){
					valid=0;
				}
			}
			if(valid){
				break;
			}
			board[currentRow]++;
		}
		if(board[currentRow]==dimension){
			board[currentRow]= -1;
			currentRow--;
			if(currentRow<0){
				break;
			}
			colMask&=~(1ULL<<board[currentRow]);
			zoneMask&=~(1ULL<<(zones[currentRow][board[currentRow]]-ASCII_MIN));
			continue;
		}
		if(currentRow==dimension-1){
			solved=1;
			break;
		}
		colMask|=1ULL<<board[currentRow];
		zoneMask|=1ULL<<(zones[currentRow][board[currentRow]]-ASCII_MIN);
		currentRow++;
		board[currentRow]= -1;
	
	}

	if(solved){
		printf("Solution:\n");
		for(int i=0; i<dimension; i++){
			for(int j=0; j<dimension; j++){
				if(board[i]==j){
					printf("X ");
				}
				else{
					printf("* ");
				}
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

unsigned long long robotPathCount(unsigned long long n, unsigned long long k){
	if(k>n){
		return 0;
	}
	if(k>n-k){
		k=n-k;
	}
	unsigned long long r=1;
	for(unsigned long long i=1; i<=k; i++)
		r=r*(n-k+i)/i;
	return r;
}

unsigned int bitmaskParenthesis(char c){
	switch(c){
		case'(':case')':return BIN00;
		case'[':case']':return BIN01;
		case'{':case'}':return BIN10;
		case'<':case'>':return BIN11;
	}
	return (unsigned int)-1;
}

int closedAllParentheses(int depth, unsigned long long word){
	int input=0, open=0, closed=0;
	unsigned int code=(unsigned int)-1;
	char curr=0;
	if ((input=scanf("%c", &curr)) != 1) {
		return EOF;
	}
	if (curr=='\n'){
		return !depth;
	}
	open=(curr=='(' ||curr=='[' ||curr=='{' ||curr=='<')?1:0;
	closed=(curr==')' ||curr==']' ||curr=='}' ||curr=='>')?1:0;
	if(!(open ||closed)){
		return closedAllParentheses(depth, word);
	}
	code=bitmaskParenthesis(curr);
	if(code==(unsigned int)-1){
		// should never be reached
		return EOF;
	}
	if(open){
		return closedAllParentheses(++depth, (word << 2) | code);
	}
	if(closed){
		if(!depth ||(word&3U)!=code){
			scanf("%*[^\n]");
			return 0;
		}
		return closedAllParentheses(--depth, (word >> 2));
	}
	return EOF;
}

int absoluteDifference(int a, int b){
	return a>b?a-b:b-a;
}


// NAVIGATE VIA MAIN

int main(){
	while(selectedTask !=DONE){
		menuSelect();
		switch (selectedTask){

			case DONE:
				break;
			
			case ROBOT_PATHS:
				task1RobotPaths();
				break;
			
			case HUMAN_PYRAMID:
				task2HumanPyramid();
				break;
			
			case PARENTHESES:
				task3ParenthesisValidator();
				break;
			
			case QUEENS:
				task4QueensBattle();
				break;
			
			default:
				printf("Please choose a task number from the list.\n");
		}
	}
	printf("Goodbye!\n");
	return 0;
}