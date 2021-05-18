// Copyright (c) 2021 Liam Csiffary All rights reserved.
//
// Created by: Liam Csiffary
// Date: May 18, 2021
// This program determines whether a year is a leap year or not
#include <iostream>

// make variables
int year;


//////////////////// the informant functions //////////

// if the year is a leap year this gets called
int isLeapYear() {
    std::cout << year << " is indeed a leap year!";
}

// if the year is not a leap year this gets called
int isNotLeapYear() {
    std::cout << year << " is not a leap year";
}

// if the year is a leap year this gets called
int isLeapYearNeg() {
    std::cout << abs(year) << "BCE is indeed a leap year!";
}

// if the year is not a leap year this gets called
int isNotLeapYearNeg() {
    std::cout << abs(year) << "BCE is not a leap year";
}

////////// The processing /////////

int main() {
    // malke the string version of the var
    std::string yearString;

    std::cout << "What is the year you wish to know about: ";
    std::cin >> yearString;

    try {
        year = std::stoi(yearString);

/////////// IF THE YEAR IS NEGATIVE ///////////////

        if (year < 0) {
            // if before leap years
            if (year < -45) {
                // make number positive so that it makes sense
                year = abs(year);
                std::cout << year << "BCE is before leap years were invented";

            // if it is a valid year
            } else {
                // if divisible by 4
                if (year % 4 == 0) {
                    // if year is also divisible by 100
                    if (year % 100 ==0) {
                        // if divisible by all
                        if (year % 400 == 0) {
                            isLeapYearNeg();
                        // divisible by only 4 and 100
                        } else {
                            isNotLeapYearNeg();
                        }

                    // is only divisible by 4
                    } else {
                        isLeapYearNeg();
                    }

                // not divisible by any
                } else {
                    isNotLeapYearNeg();
                }
            }

////////////// IF YEAR IS POSITIVE ///////////
        } else {
            // if divisible by 4
            if (year % 4 == 0) {
                // if year is also divisible by 100
                if (year % 100 ==0) {
                    // if divisible by all
                    if (year % 400 == 0) {
                       isLeapYear();

                    // divisible by only 4 and 100
                    } else {
                        isNotLeapYear();
                    }

                // is only divisible by 4
                } else {
                    isLeapYear();
                }

            // not divisible by any
            } else {
                isNotLeapYear();
            }
        }
    } catch (std::invalid_argument) {
        std::cout << "This is not a valid year";
    }
}
