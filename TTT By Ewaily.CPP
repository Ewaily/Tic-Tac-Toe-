#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>

void T(int ,int);
void C(int ,int);
void A(); void I();
void O(); void E();

void grph();
void start();
void X(int ,int);
void OO(int ,int);

int turn; /* flag for the player's turn. 0 = player X, 1 = player O */
char board[9]; /* cells in the tic-tac-toe board */

/* get input from the user for what cell to play in */
int get_input() {
        /* get user input */
        printf("Position to play: ");
        int pos;
        scanf("%d", &pos);
        pos--;

        /* error check the input */


        if (pos < 0 || pos > 8) {
                printf("Invalid position (choose between 1 and 9)\n");
                return get_input();
        }

        /* make sure nobody has played in the cell before */
        if (board[pos] != '-') {
                printf("Somebody has already played there. Try again...\n");
                return get_input();
        }

        return pos;
}

/* display game board to the console */
void display_board() {
        int x;
        for ( x=0; x<9; x++) {
                /* new line after every 3 cells to form the grid output */
                if (x > 0 && x % 3 == 0) {
                        printf("\n-------------\n");
                }

                /* print either X or O depending whats in the cell. */
                /* print the cell number if the cell is empty */
                if (board[x] == '-') {
                        printf("| %d ", x+1);
                } else {
                        printf("| %c ", board[x]);
                }
                if ( x == 2 || x == 5 || x == 8)
                    printf("|");
        }

        printf("\n\n");
}

/* make a player move (place X or O in a cell) */
void make_move(int pos) {
	int i;

        board[pos] = turn ? 'O' : 'X';
        turn = !turn;
        clrscr();
        printf("\n\t\t\t\tCC213 - Programming Applications");
		printf("\n\t\t\t\t");

		for(i=1;i<=32;i++)
		{

			printf("*");
		}

        printf("\n");
        printf("Welcome to Tie-Tac-Toe By M.Ewaily\n");
        printf("Player X will go first.\n\n");
}

/* check if the game is over */
int game_over() {
        /* horizontal wins */
        if (board[0] != '-' && board[0] == board[1] && board[1] == board[2]) {
                printf("Player %c has won!\n", board[0]);
                return 1;
        }
        if (board[3] != '-' && board[3] == board[4] && board[4] == board[5]) {
                printf("Player %c has won!\n", board[3]);
                return 1;
        }
	if (board[6] != '-' && board[6] == board[7] && board[7] == board[8]) {
		printf("Player %c has won!\n", board[6]);
                return 1;
        }

        /* vertical wins */
        if (board[0] != '-' && board[0] == board[3] && board[3] == board[6]) {
                printf("Player %c has won!\n", board[0]);
                return 1;
        }
        if (board[1] != '-' && board[1] == board[4] && board[4] == board[7]) {
                printf("Player %c has won!\n", board[1]);
                return 1;
        }
        if (board[2] != '-' && board[2] == board[5] && board[5] == board[8]) {
                printf("Player %c has won!\n", board[2]);
                return 1;
        }

        /* diagonal wins */
        if (board[0] != '-' && board[0] == board[4] && board[4] == board[8]) {
                printf("Player %c has won!\n", board[0]);
                return 1;
        }
        if (board[2] != '-' && board[2] == board[4] && board[4] == board[6]) {
                printf("Player %c has won!\n", board[2]);
                return 1;
	}

	/* its a draw when all cells are filled */
	int i;
	for ( i=0; i<9; i++) {
		if (board[i] == '-') {
			return 0;
		}
	}
	printf("It's a draw!\n");
	return 1;
}


void main(){

    /*graph code */
	int i,ch,j;
	char a;
	start();
	grph();


		START: clrscr();
		printf("\n\t\t\t\tCC213 - Programming Applications");
		printf("\n\t\t\t\t");
		delay(2000);
		for(i=1;i<=32;i++)
		{
			delay(100);
			printf("*");
		}

	printf("\n");

    /*game code*/

    /* setup default game board */
       // int i;
       /* if (turn)
	    printf("true");
	else
	    printf("false");*/

	    for ( i=0; i<9; i++) {
		board[i] = '-';
	}

	printf("Welcome to Tie-Tac-Toe By M.Ewaily\n");
	printf("Player X will go first.\n\n");
	display_board();

	/* game loop until somebody wins or you both tie */
	while (!game_over()) {
		int position = get_input();
		make_move(position);
		display_board();
	}
	// to let the player 'X' starts again

	 turn = 0;

	printf("The game has ended.\n\n");


	getch();

       Re:	printf("Want to play again? (Y/N) :> ");
	scanf(" %c",&a);

	if (a =='y' || a == 'Y'){

		goto START;
	}

	else if(a !='y' && a!='Y'&& a != 'n' && a != 'N')  {
		printf("Invalid character!\n");
		goto Re;
	}
	else
	    printf("Okay bye!");
	getch();
	clrscr();
}



void start(){
	int gdrive=DETECT,gmode,i;
	initgraph(&gdrive,&gmode,"c:\\turboc3\\bgi");



    printf("\n\tCC213 - Programming Applications");
		printf("\n\t");
		delay(2000);
		for(i=1;i<=32;i++)
		{
			delay(100);
			printf("*");
		}

		printf("\n\t\t\t\t\t\t\t12th Project");
		printf("\n\t\t\t\t\t\t\t");
		delay(2000);
		for(i=1;i<=12;i++)
		{
			delay(100);
			printf("*");
		}



	// Drawing the 2 vert. lines

	  for(i = 0 ; i < 300 ; i ++){

	setcolor(8);
	circle(250,150+i,5);
	delay(10);
	  }

	  for(i = 0 ; i < 300 ; i ++){

	setcolor(8);
	circle(350,150+i,5);
	delay(10);
	  }



	  // Draw the 2 horiz. lines

	  for(i = 0 ; i < 300 ; i ++){

	setcolor(8);
	circle(150+i,250,5);
	delay(10);
	  }

	  for(i = 0 ; i < 300 ; i ++){

	setcolor(8);
	circle(150+i,350,5);
	delay(10);
	  }


	 // 1st X

	 X(310,270); delay(100);


    // 1st O

    OO(210,330);delay(100);


	  // 2n X

	  X(410,170); delay(100);

	  // 2n O

	  OO(310,230);delay(100);



	  // 3rd X

	  X(410,370); delay(100);

	  // 3rd O

	  OO(410,330);delay(100);



	  // 4th X

	  X(210,170); delay(100);

       setcolor(8);
	  line(150,150,450,450);

	  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tBy:M.Ewaily");
		printf("\n\t\t\t\t\t\t\t\t");
		delay(2000);
		for(i=1;i<=11;i++)
		{
			delay(100);
			printf("*");
		}

	  delay(1000);
	closegraph();
}


void grph(){
	int gdrive=DETECT,gmode;
	initgraph(&gdrive,&gmode,"c:\\turboc3\\bgi");
	delay(2000);


	T(80,100); delay(100);
	I(); delay(100);
	C(190,100);delay(100);
	T(330,100); delay(100);
	A();delay(100);
	C(485,100);delay(100);
	T(190,250);delay(100);
	O();delay(100);
	C(280,250);delay(100);
	E();delay(200);


    delay(2000);

	closegraph();
}




void I(){
	for(int i=0;i<20;i++){
		setcolor(2);
		circle(160+i,100,3);
		delay(10);
	}
	for(i=0;i<70;i++){
		circle(170,100+i,3);
		delay(10);
	}
	for(i=0;i<20;i++){
		setcolor(2);
		circle(160+i,170,3);
		delay(10);
	}
}

void C(int c1,int c2){
	for(int i=0;i<10;i++){
		setcolor(2);
		circle(c1+50,c2+10-i,3);
		delay(10);
	}
	for(i=0;i<50;i++){
		circle(c1+50-i,c2,3);
		delay(10);
	}
	for(i=0;i<70;i++){
		circle(c1,c2+i,3);
		delay(10);
	}
	for(i=0;i<45;i++){
		circle(c1+i,c2+70,3);
		delay(10);
	}
}

void O(){
	for(int i=0;i<70;i++){
		circle(330,320-i,3);
		delay(10);
	}
}

void T(int t1,int t2){
	for(int i=0;i<70;i++){
		setcolor(2);
		circle(t1+i,t2,3);
		delay(10);
	}
	for(i=0;i<70;i++){
		setcolor(2);
		circle(t1+35,t2+i,3);
		delay(10);
	}
}

void A(){
	for(int i=0;i<35;i++){
		circle(440-i,100+(i*2),3);
		delay(10);
	}
	for(i=0;i<35;i++){
		circle(440+i,100+(i*2),3);
		delay(10);
	}
	for(i=0;i<20;i++){
		circle(430+i,130,3);
		delay(10);
	}
}

void E(){
	for(int i=0;i<50;i++){
		circle(395-i,250,3);
		delay(10);
	}
	for(i=0;i<70;i++){
		circle(345,250+i,3);
		delay(10);
	}
	for(i=0;i<50;i++){
		circle(345+i,320,3);
		delay(10);
	}
	for(i=0;i<25;i++){
		circle(345+i,285,3);
		delay(10);
	}
}
void X(int X1,int X2){

    int i;

    for ( i = 0 ; i < 30 ; i ++ ){

        setcolor(1);
	circle(X1 - i , X2 + (i*2),3);
	delay(10);
    }

    for ( i = 0 ; i < 30 ; i ++ ){

	setcolor(1);
	circle(X1 - 30 + i , X2 + (i*2),3);
        delay(10);
    }
}
void OO(int O1,int O2){



    for (int i = 0 ; i < 50 ; i ++ ){

        setcolor(4);
        circle ( O1 , O2 - i , 3 );
        delay(10);
    }


	for(i=0;i<30;i++){
		circle(O1-i,O2-50,3);
		delay(10);
	}
	for(i=0;i<50;i++){
		circle(O1-30,O2-50+i,3);
		delay(10);
	}
	for(i=0;i<25;i++){
		circle(O1 - 30 +i,O2,3);
		delay(10);
	}
}
