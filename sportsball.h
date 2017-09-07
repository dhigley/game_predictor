/*
 * sportsball.h
 * sportsball
 *
 * Daniel Higley
 * CSC 362-001
 * Programming Assignment 2
 * Due 10/10/2016
 *
 * Header file to provide include statements, constants, and function prototypes
 *
 */

#ifndef sportsball_h // if not defined
#define sportsball_h // define...

// Library Include Statements
#include <stdio.h>  // for fprintf
#include <stdlib.h> // to get the absolute value of any negative numbers

// Constants defined by the project specs
#define OFFENSIVE_FACTOR 1.22
#define SPECIAL_TEAMS_FACTOR 1.13
#define HOME_FIELD_ADVANTAGE 1.1
#define OVERALL_FACTOR 1.2
#define OFFENSIVE_WORTH 0.27
#define DEFENSIVE_WORTH 0.31
#define SPECIAL_WORTH 0.18
#define HOME_WORTH 0.09
#define OVERALL_WORTH 0.15

// Function Prototypes
/* getInput uses fscanf to pull formatted data from a specified disk file */
void getInput(FILE *, char *, int *, int *, int *, int *, int *, char *, int *, int *, int *, int *);
/* lineCount is used in main to count the number of lines to be read from the given file */
int lineCount(FILE *);
/* compute uses a given formula to compute and store team specific preferences
 * based on team strengths given in the file and the 'FACTOR' constants given above */
void compute(double *, double *, double *, double *, double *, int, int, int, int, int, int, int, int, int);
/* predict uses the computed preferences from above, along with the 'WORTH'
 * constants given above to determine the final score of the given game */
double predict(int, int, int, int, int);
/* output uses printf to print the predicted game winners over losers and the
 * predicted point spread to stdout*/
void output(char *, char *, double);
/* update counts the number of the games predicted and the number of home
 * team wins versus the number of visiting team wins */
void update(int *, int *, int *, double);
/* prints the total games predicted and percentage of games won by the home team  */
void summary(int, int, int);

#endif
