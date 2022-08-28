#ifndef WEEKDAY_H
#define WEEKDAY_H

enum Weekday {
    SATURDAY,
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
};

int getIntFromUser();

int promptForyear();

int promptForMonth();

int promptForDayOfMonth();

Weekday calculateWeekday(int month, int dayOfMonth, int year);

std::string getWeekdayName(Weekday day);

#endif