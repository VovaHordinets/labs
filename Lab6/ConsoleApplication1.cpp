// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include"conio.h"
#pragma warning(disable : 4996)
typedef struct {
	char name[50];
	int race;
	int year;
}Car;
void print(Car c) {
	printf("%s (%d-year) - (%d 000 race)\n", c.name, c.year, c.race);
}
Car CreateCarFromString(char* string) {
	int i = 0;
	Car c;
	char *t = string;
	while (*t != ';') {
		c.name[i] = *t;
		t++; i++;
	}c.name[i] = '\0';
	t++; i = 0;
	char race[5];
	while (*t!=';') {
		race[i] = *t;
		i++; t++;
	}race[i] = '\0';
	c.race = atoi(race);

	t++; i = 0;
	char year[5];
	while (*t!=';') {
		year[i] = *t;
		i++; t++;
	}year[i] = '\0';
	c.year = atoi(year);
	return c;
}
int main()
{
		FILE *f = fopen("D:\\Vova Hordinets\\1.txt","rt");
		if (f == NULL) {
			printf("Can`t open the file");
			return 0;
		}
		int n;
		fscanf(f, "%d", &n);
		fgetc(f);
		char string[100];
	
		Car *cars=(Car*)malloc(sizeof(Car)*n);
		for (int i = 0; i < n; i++) {
			fgets(string, 100, f);
			Car car = CreateCarFromString(string);
			cars[i] = car;
		}
		fclose(f);
		
		printf("From smallest race to biggest race:\n");
		for (int i = 0; i < n; i++) {
			int min = i;
			for (int j = i + 1; j < n; j++) {
				if (cars[j].race<cars[min].race) {
					min = j;
				}
			}
			Car swap = cars[i];
			cars[i] = cars[min];
			cars[min] = swap;
			print(cars[i]);
		}
		free(cars);
_getch();
return 0;
}

