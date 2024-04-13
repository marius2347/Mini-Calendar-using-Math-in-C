#include <stdio.h>
#include <stdbool.h>


// Creating the Leap Year function
bool is_leap_year(int year) {
    if (year % 4 != 0) { // the year is NOT divisible by 4
        return false;
    } else if (year % 100 != 0) {  // the year is NOT divisible by 100
        return true; 
    } else if (year % 400 != 0) { //  year if it is further NOT divisible by 400
        return false;
    } else { // we have ruled out all cases that do not meet conditions for a leap year
        return true;
    }

    // or return (year % 4 == 0 && (year % 100 || year % 400 == 0));
}

int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //  number of days in each of the twelve months in the Gregorian Calendar in the correct order

// Adding Days to a Given Date function
void add_days_to_date(int* mm, int* dd, int* yy, int days_left_to_add) {
    int days_left_in_month; 
    while (days_left_to_add > 0) {
        days_left_in_month = days_in_month[*mm] - *dd; // represent the number of days left in a month.
        if (*mm == 2 && is_leap_year(*yy)) { //  check if the current month is February because if the current year is a leap year
            days_left_in_month++;
        }
        if (days_left_to_add > days_left_in_month) { // if more days left than can be added in a month
            days_left_to_add -= days_left_in_month + 1; // jump to the first day of the next month 
            *dd = 1; // we are on the first day of the next month, but what is the next month?
            if (*mm == 12) { // if last month was December
                *mm = 1; // next month is January
                *yy = *yy + 1; // and we are in a new year so increase by 1
            }
            else *mm = *mm + 1; // if some other month, just increase by 1
        } else {
            *dd = *dd + days_left_to_add; // simply add the days
            days_left_to_add = 0; // no more days to add!
        }
    }
}
int main() {

    // User Input
    int year;
    printf("Input a year between 1800 and 10000: ");
    scanf("%d", &year);

    // Verify if the year is leap
    if(is_leap_year(year)) {
        printf("%d is Leap Year\n", year);
    } else{
        printf("%d is Not Leap Year\n", year);
    }
    int mm, dd, yy, days_left_to_add;
    printf("Please enter a date between the years 1800 and 10000 in the format mm dd yy and provide the number of days to add to this date: ");
    scanf("%d%d%d%d",  &mm, &dd, &yy, &days_left_to_add);
    add_days_to_date(&mm, &dd, &yy, days_left_to_add); 
    printf("The date is now: %d %d %d", mm, dd, yy); 
    return 0; 
}