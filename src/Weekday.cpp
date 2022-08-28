#include <iostream>
#include <string>
#include "Weekday.h"
#include <limits>

// General get input method for catching ints and exception handling of non-integer values.
int getIntFromUser()
{
    int result;
    while(!(std::cin >> result))
    {
        std::cout << "invalid input. Enter an integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return result;
}

// THIS METHOD IS TECHNICALLY PRIVATE SINCE IT IS NOT DECLARED IN HEADER
// Helper method for the prompt functions to get valid input within ranges
bool inRange(int min, int max, int input)
{
    if(input < min || input > max)
    {
        std::cout << "out of range[" << min << "-" << max << "]. try again: ";
        return false;
    } else 
    {
        return true;
    }
}

// Prompt for year and specify the accepted format of year
int promptForyear()
{
    std::cout << "Enter year: (eg: 2012): ";
    int year = getIntFromUser();

    // Uses above helper method to get valid input that does not throw an exception
    while(!(inRange(0, 3000, year)))
    {
        year = getIntFromUser();
    }

    return year;
}

// Prompt for the month between 1 and 12
int promptForMonth()
{
    std::cout << "Enter month (1-12): ";
    int month = getIntFromUser();

    // Kind of saw the pattern around here and decided to make the helper method inRange
    while(!(inRange(1, 12, month)))
    {
        month = getIntFromUser();
    }
    return month;
}

// prompt for day of the month between 1 and 31
int promptForDayOfMonth()
{
    std::cout << "Enter day of month (1-31): ";
    int day = getIntFromUser();

    // Man making this helper method makes this look nice huh
    while(!(inRange(1, 31, day)))
    {
        day = getIntFromUser();
    }
    return day;
}

// Chucky formula for calculation weekday in month of a certain year by Christian Zeller
Weekday calculateWeekday(int month, int dayOfMonth, int year)
{
    // formula uses 3-14 for month so we need to add 12 if the int is below 4
    if(month < 3)
    {
        month += 12; // 1 -> 13 and 2 -> 14
        year--; // If it is the first or second month(falls in this if statement) decrament year by one.
    }

    int dayOfWeek = (dayOfMonth + (26*(month + 1))/10 + (year % 100) + (year % 100)/4 + (year/100)/4 + 5 * (year/100) ) % 7;

    // static cast for int to weekday since I declared the weekdays in the order of the result of the formula
    Weekday weekdayId(static_cast<Weekday>(dayOfWeek));

    return weekdayId;
}

// Simple quick switch for day of the week with enum weekday
std::string getWeekdayName(Weekday day)
{
    std::string result;

    // could also use 0-6 but the enum names makes it more clear.
    switch(day)
    {
        case SATURDAY: result = "Saturday"; break;
        case SUNDAY: result = "Sunday"; break;
        case MONDAY: result = "Monday"; break;
        case TUESDAY: result = "Tuesday"; break;
        case WEDNESDAY: result = "Wednesday"; break;
        case THURSDAY: result = "Thursday"; break;
        case FRIDAY: result = "Friday"; break;
    }

    return result;
}