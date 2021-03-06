// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include"conio.h"

typedef struct _Player {
	char *name;
	int race;
	int age;
}Player;
void print(Player p) {
	printf("%s (%d-year) - (%d 000 race)\n", p.name, p.age, p.race);
}
int main() {
	Player players[5];
	players[0].name = "Audi RS 6";
	players[0].race = 80;
	players[0].age = 2014;
	players[1].name = "Subaru Impreza STI";
	players[1].race = 50;
	players[1].age = 2016;
	players[2].name = "Audi A5";
	players[2].race = 60;
	players[2].age = 2015;
	players[3].name = "BMW 530";
	players[3].race = 10;
	players[3].age = 2017;
	players[4].name = "Audi Q7";
	players[4].race = 100;
	players[4].age = 2012;
	Player worst = players[5];
	for (int i = 4; i>=0; i--) {
		if (players[i].race<worst.race) {
			worst = players[i];
		}
	}
	Player best = players[0];
	for (int i = 0; i<=4; i++) {
		if (players[i].race>best.race) {
			best = players[i];
		}
	}

	for (int i = 0; i<5; i++) {
		if (players[i].race == best.race) {
			printf("The biggest mileage:\n");
			print(players[i]);
		}
		if (players[i].race == worst.race) {
			printf("\nThe least mileage :\n");
			print(players[i]);
		}


	}
	_getch();
	return 0;
}