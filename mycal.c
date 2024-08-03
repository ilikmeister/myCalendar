// The program was written by Iliyas Akhmet on 4 August 2024; email: akhmet.i27@gmail.com

#include <stdio.h>
#include <stdlib.h>

#include "first_day_of_month.c"

#define MONTH 8
#define YEAR 2024

#define WEEKS_IN_MONTH 6
#define DAYS_IN_WEEK 7

int identify_month (int month, int year) {
	int days_in_month;

	switch (month) {
	case 1:	printf("January");
		days_in_month = 31;
		break;
	case 2: printf("February");
		if (year % 4 == 0) {
			if (year % 100 == 0) {
				if (year % 400 == 0) {
					days_in_month = 29;
				}
				else {
					days_in_month = 28;
				}
			}
			else {
				days_in_month = 29;
			}
		}
		else {
			days_in_month = 28;
		}
		break;
	case 3:	printf("March");
		days_in_month = 31;
		break;
	case 4: printf("April");
		days_in_month = 30;
		break;
	case 5:	printf("May");
		days_in_month = 31;
		break;
	case 6: printf("June");
		days_in_month = 30;
		break;
	case 7:	printf("July");
		days_in_month = 31;
		break;
	case 8: printf("August");
		days_in_month = 31;
		break;
	case 9:	printf("September");
		days_in_month = 30;
		break;
	case 10:printf("October");
		days_in_month = 31;
		break;
	case 11:printf("November");
		days_in_month = 30;
		break;
	case 12:printf("December");
		days_in_month = 31;
		break;
	}
	
	return days_in_month;
}

void print_cal (int month, int year) {
	int first_day = 4;
	first_day = first_day_of_month(month, year);
	
	printf("    ");
	int days_in_month = identify_month(month, year);
	int w, d;
	
	printf(" %d\n", year);
	printf("Su Mo Tu We Th Fr Sa\n");
	
	int day = 1 - first_day;
	
	for (w = 0; w < WEEKS_IN_MONTH; w++) {
		for (d = 0; d < DAYS_IN_WEEK; d++) {
			if (day < 1 || day > days_in_month) {
				printf("   ");
				day++;
			}
			else {
				printf("%2d ", day);
				day++;
			}
		}
		printf("\n");
	}
}

int main (int argc, char *argv[]) {
	int month, year;
	
	if (argc == 3) {
		month = atoi(argv[1]);
		year = atoi(argv[2]);
	}
	else if (argc == 1) {
		month = MONTH;
		year = YEAR;
	}
	else {
		printf("Error: arguments were not entered correctly\n");
		return 1;
	}
	
	print_cal(month, year);
	return 0;
}
