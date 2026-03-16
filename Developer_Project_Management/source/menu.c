#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void clear(){
	#ifdef _WIN64
    system("cls");
    #else
    system("clear");
    #endif
}

void welcome(){
	printf("============================================================\n");
	printf("||                                                        ||\n");
	printf("||  WELCOME TO DEVELOPERS AND PROJECTS MANAGEMENT SYSTEM  ||\n");
	printf("||                                                        ||\n");
	printf("============================================================\n");
}

void menu_0(){
	printf("=====================================\n");
	printf("||   Chose your option:            ||\n");
	printf("||   (1) Developer Data Operation  ||\n");
	printf("||   (2) Project Data Operation    ||\n");
	printf("||   (3) Your profile              ||\n");
	printf("||   (4) Saving & Read file        ||\n");
	printf("||   (0) Log out                   ||\n");
	printf("=====================================\n");
}

void menu_0_1(){
	printf("=====================================\n");
	printf("||   Chose your option:            ||\n");
	printf("||   (1) Add new developer         ||\n");
	printf("||   (2) Search developer          ||\n");
	printf("||   (3) Sort developer            ||\n");
	printf("||   (4) Update developer          ||\n");
	printf("||   (5) Remove developer          ||\n");
	printf("||   (6) Show list of developer    ||\n");
	printf("||   (0) Back to previous page     ||\n");
	printf("=====================================\n");
}

void menu_0_1_2(){
	printf("=====================================\n");
	printf("||   Chose your option:            ||\n");
	printf("||   (1) Search by salary          ||\n");
	printf("||   (2) Search by name            ||\n");
	printf("||   (3) Search by birthyear       ||\n");
	printf("||   (0) Back to previous page     ||\n");
	printf("=====================================\n");
}

void menu_0_1_3(){
	printf("=====================================\n");
	printf("||   Chose your option:            ||\n");
	printf("||   (1) Sort by salary            ||\n");
	printf("||   (2) Sort by name              ||\n");
	printf("||   (3) Sort by birthyear         ||\n");
	printf("||   (0) Back to previous page     ||\n");
	printf("=====================================\n");
}

void menu_0_2(){
	printf("=====================================\n");
	printf("||   Chose your option:            ||\n");
	printf("||   (1) Adding project            ||\n");
	printf("||   (2) Experience's time         ||\n");
	printf("||   (3) Show project              ||\n");
	printf("||   (0) Back to previous page     ||\n");
	printf("=====================================\n");
}

void menu_0_3(){
	printf("=====================================\n");
	printf("||   Chose your option:            ||\n");
	printf("||   (1) Show your profile         ||\n");
	printf("||   (2) Change email              ||\n");
	printf("||   (3) Change passWord           ||\n");
	printf("||   (0) Back to previous page     ||\n"); 
	printf("=====================================\n");
}

void menu_0_4(){
	printf("=====================================\n");
	printf("||  Chose your option:             ||\n");
	printf("||  (1)  Save developer's file.txt ||\n");
	printf("||  (2)  Save project's file.txt   ||\n");
	printf("||  (3)  Read developer's file.txt ||\n");
	printf("||  (4)  Read project's file.txt   ||\n");
	printf("||  (0)  Back to previous page     ||\n"); 
	printf("=====================================\n");
}

void menuUpdate(){
	printf("=====================================\n");
	printf("||   Chose your option:            ||\n");
	printf("||   (1) Update name               ||\n");
	printf("||   (2) Update birthyear          ||\n");
	printf("||   (3) Update program language   ||\n");
	printf("||   (4) Update salary             ||\n");
	printf("||   (0) Quit                      ||\n");
	printf("=====================================\n");
}

void goodBye(){
	printf("====================================================\n");
	printf("||     THANK YOU FOR YOUR USING OUR SERVICES      ||\n");
	printf("||   Please contact us for further information    ||\n");
	printf("====================================================\n");
	printf("||%-27s||%-19s||\n", "Suppporter", "Contact number");
	printf("||------------------------------------------------||\n");
	printf("||%-27s||%-19s||\n", "Nguyen Xuan Truong", "0379693078");
	printf("||%-27s||%-19s||\n", "Vuong Tran Hieu Nghia", "0372607505");
	printf("||%-27s||%-19s||\n", "Nguyen Tien Minh", "0957898809");
	printf("||%-27s||%-19s||\n", "Nguyen Dinh Manh", "0908342768");
	printf("||------------------------------------------------||\n");
}