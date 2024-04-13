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
}
int main() {

    // User Input
    int year;
    printf("Input a year between 1800 and 10000: ");
    scanf("%d", &year);

    // Verify if the year is leap
    if(is_leap_year(year)) {
        printf("%d is Leap Year", year);
    } else{
        printf("%d is Not Leap Year", year);
    }
}