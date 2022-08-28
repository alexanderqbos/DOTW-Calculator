#include <iostream>
#include <string>
#include "Weekday.h"
#include "Weekday.h"

int main()
{
    // Get the year from user input
    int year = promptForyear();
    // Get the month from user input
    int month = promptForMonth();
    // get the day in the month
    int day = promptForDayOfMonth();
    // get pass the return of calculateWeekday to getWeekdayName to save a variable
    std::cout << "Day of the week is " << getWeekdayName(calculateWeekday(month, day, year));
}