#include <stdio.h>
#include <windows.h>

//Prototype,tipe data, dan variabel yang digunakan
char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char square2[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int play();
int close();
int win();
void board();
void invalidMenu();
void invalidMove();
void menu();
void loading();
void help();
void back();
int player = 1;
void acc();

void menu(){
	printf("\n\n\n\n\n\n\n");
	printf("\t\t  ||===========================================||\n");
    printf("\t\t  ||                  OXO GAME                 ||\n");
    printf("\t\t  ||                                           ||\n");
    printf("\t\t  ||             Play vs friend [1]            ||\n");
    printf("\t\t  ||             Help           [2]            ||\n");
    printf("\t\t  ||             Exit           [3]            ||\n");
    printf("\t\t  ||                                           ||\n");
    printf("\t\t  ||                                           ||\n");
    printf("\t\t  ||            Press the menu number          ||\n");
    printf("\t\t  ||===========================================||\n");
	switch(getch()){
        case '1':
        	system("cls");
        	loading();
			play();
            break;
        case '2':
        	system("cls");
        	loading();
        	help();
        	break;
        case '3':
			close();
            break;
        default:
        	invalidMenu();
			menu();
		}
}

void board(){												
	system("cls");
	printf("\n\n\t\t\t\t  OXO Game\n\n");
    printf("\t\t\tPlayer 1 (X)  -  Player 2 (O)\n\n\n");
    printf("\t\t\t          |     |     \n");
    printf("\t\t\t       %c  |  %c  |  %c \n", square[1], square[2], square[3]);
    printf("\t\t\t     _____|_____|_____\n");
    printf("\t\t\t          |     |     \n");
    printf("\t\t\t       %c  |  %c  |  %c \n", square[4], square[5], square[6]);
    printf("\t\t\t     _____|_____|_____\n");
    printf("\t\t\t          |     |     \n");
    printf("\t\t\t       %c  |  %c  |  %c \n", square[7], square[8], square[9]);
    printf("\t\t\t          |     |     \n\n");
}

int play(){
	int i, pil;
	char mark;

	do{
		board();
		player = (player%2) ? 1 : 2;						
		printf("\t\t\t       PLAYER %d TURN\n", player);
		printf("\t\t\t      ENTER A NUMBER!");
		printf("\n\t\t         (0 TO RETURN TO MAIN MENU)");
		mark = (player == 1) ? 'X':'O';
		switch(getch()){
			case '1':
				if (square[1] == '1'){
					square[1]=mark;	
				}
				else{
					invalidMove();
				}
				break;
			case '2':
				if (square[2] == '2'){
					square[2]=mark;	
				}
				else{
					invalidMove();
				}
				break;
			case '3':
				if (square[3] == '3'){
					square[3]=mark;	
				}
				else{
					invalidMove();
				}
				break;
			case '4':
				if (square[4] == '4'){
					square[4]=mark;	
				}
				else{
					invalidMove();
				}
				break;
			case '5':
				if (square[5] == '5'){
					square[5]=mark;	
				}
				else{
					invalidMove();
				}
				break;
			case '6':
				if (square[6] == '6'){
					square[6]=mark;	
				}
				else{
					invalidMove();
				}
				break;
			case '7':
				if (square[7] == '7'){
					square[7]=mark;	
				}
				else{
					invalidMove();
				}
				break;
			case '8':
				if (square[8] == '8'){
					square[8]=mark;	
				}
				else{
					invalidMove();
				}
				break;
			case '9':
				if (square[9] == '9'){
					square[9]=mark;	
				}
				else{
					invalidMove();
				}
				break;
			case '0':
				system("cls");
				loading();
				main();
				player = player-1;
				break;
			default:
				invalidMove();
				player--;		
		}
		
	i=checkWin();
	player++;
	} while(i == -1);

	board();
	if(i == 1){
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t===============\n");
		printf("\t\t\t\t|Player %d WIN|\n", --player);
		printf("\t\t\t\t===============\n");
		getch();
		system("cls");
		back();
	}
	else{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t=================\n");
		printf("\t\t\t\t|GAME ENDED DRAW|\n");
		printf("\t\t\t\t=================\n");
		getch();
		system("cls");
		back();
	}
	return 0;
	back();
}

void invalidMove(){
	system("cls");
	printf("\n\n\n\n\n");
	printf("       =================================================================\n");
	printf("       |                         Invalid move                          |\n");
	printf("       |                                                               |\n");
	printf("       |                                                               |\n");
	printf("       |      Please enter number of the box provided in the game      |\n");
	printf("       =================================================================\n");
	getch();
	system("cls");
	play();
}

void invalidMenu(){
	system("cls");
	printf("\n\n\n\n\n");
	printf("       =================================================================\n");
	printf("       |                         Invalid Input                         |\n");
	printf("       |                                                               |\n");
	printf("       |                                                               |\n");
	printf("       |          Please enter one of the numbers listed above         |\n");
	printf("       =================================================================\n");
	getch();
	system("cls");
}

void loading(){															
	int i;																							//variabel i untuk hitung titik
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\tNow Loading ");
	for (i=0;i<5;i++){
		printf(". ");
		Sleep(200);
	}
	system("cls");
}

int close(){		
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n");
    printf("                  --------------------------------------------\n");
    printf("                  ||               Are you sure?            ||\n");
    printf("                  ||----------------------------------------||\n");
    printf("                  ||             [1] Yes                    ||\n");
    printf("                  ||             [2] No                     ||\n");
    printf("                  ||----------------------------------------||\n");
	printf("                  --------------------------------------------\n");
	switch(getch()){
    	case '1':
			system("cls");
			loading();
			printf("\n\n\n\n\n\n\n\n\n\n");
			acc();
			exit(1);
	        break;
        case '2':
        	system("cls");
        	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
        	printf("                  ============================================\n");
			printf("                  |                                          |\n");
	        printf("                  |      You will return to the main menu    |\n");
	        printf("                  |                                          |\n");
	        printf("                  ============================================\n\n\n");
            system("PAUSE");
            system("cls");
            main();
            break;
        default:
        	system("cls");
			invalidMenu();
            system("cls");
            close();
	}
	return 0;
}

				/*********************************************
						Return 1  --> Game Selesai
						Return -1 --> Game masih berjalan
						Return O  --> Game berakhir (DRAW)
				 **********************************************/

int checkWin(){
    if (square[1] == square[2] && square[2] == square[3]){
    	return 1;
	}
    else if (square[4] == square[5] && square[5] == square[6]){
    	return 1;
	}
    else if (square[7] == square[8] && square[8] == square[9]){
    	return 1;
	}
    else if (square[1] == square[4] && square[4] == square[7]){
    	return 1;
	}
    else if (square[2] == square[5] && square[5] == square[8]){
    	return 1;
	}
    else if (square[3] == square[6] && square[6] == square[9]){
    	return 1;
	}
    else if (square[1] == square[5] && square[5] == square[9]){
    	return 1;
	}
    else if (square[3] == square[5] && square[5] == square[7]){
    	return 1;
	}
    else if (   square[1] != '1' && square[2] != '2' && square[3] != '3'
			  &&square[4] != '4' && square[5] != '5' && square[6] != '6'
			  &&square[7] != '7' && square[8] != '8' && square[9] != '9'){
		return 0;
	}
    else{
    	return  -1;
	}
}

void back(){
	int i;
	for(i=0;i<11;i++){
		square[i]=square2[i];
		square2[i]=square[i];
	}
	printf("\n\n\n\n");
	printf("\t\t\t============================\n");
	printf("\t\t\t|Do you want to play again?|\n");
	printf("\t\t\t|[0] No                    |\n");
	printf("\t\t\t|[1] Yes                   |\n");
	printf("\t\t\t============================\n");
	switch(getch()){
    	case '0':
    		printf("\n");
			acc();
	        exit(1);
	        break;
        case '1':
        	printf("\n");
        	printf("\t\t     ==================================\n");
			printf("\t\t     |          Press any key         |\n");
			printf("\t\t     |      To return to main menu    |\n");
			printf("\t\t     ==================================\n");
            getch();
            system("cls");
            main();
            break;
        default:
        	printf("\n");
        	printf("\t\t     ==================================\n");
			printf("\t\t     |          INVALID INPUT!        |\n");
			printf("\t\t     ==================================\n");
            getch();
            system("cls");
            close();
	}
}

void help(){
	system("cls");
	printf("\n\n\n\n\n");
	printf("===============================================================================\n");
	printf("|                               Game Information                              |\n");
	printf("|                                                                             |\n");
	printf("|                                                                             |\n");
	printf("|                                                                             |\n");
	printf("| This app is made to stimulate your skill in the classic game of Tic Tac Toe |\n");
	printf("| Press 1 in main menu to start the game. Press 2 to see the Game Information |\n");
	printf("| Press 3 if you want to quit from this game.                                 |\n");
	printf("| 2 players are required in order to play this game.                          |\n");
	printf("|                                                                             |\n");
	printf("| In game, enter 0 if you want to return to main menu.                        |\n");
	printf("|    Have Fun!!                                                               |\n");
	printf("|                                                                             |\n");
	printf("|                                            Press any key to go to main menu |\n");
	printf("===============================================================================\n");
	getch();
	system("cls");
    main();
}

void acc(){
			printf("\t\t     ===================================\n");
			printf("\t\t     |                                 |\n");
			printf("\t\t     |      Thank you for playing!     |\n");
			printf("\t\t     |                                 |\n");
			printf("\t\t     |                                 |\n");
	        printf("\t\t     |     This program designed by:   |\n");
	        printf("\t\t     |        @Geraldy Christanto      |\n");
	        printf("\t\t     |        @Achmad Faiz Siraj       |\n");
	        printf("\t\t     ===================================\n");

}
