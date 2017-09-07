/*
 * computations.c
 * sportsball
 *
 * Daniel Higley
 * CSC 362-001
 * Programming Assignment 2
 * Due 10/10/2016
 *
 * provides functions for computing data and tracking results
 *
 */
#include "sportsball.h"

/* compute: calculates home team -vs- vising team 'preferences' using rankings imported from file and 'FACTOR' constants defined in the header */
void compute(double *p1, double *p2, double *p3, double *p4, double *p5, int hto, int htd, int hts, int hth, int htc, int vto, int vtd, int vts, int vtr) {
  // calculations defined in the spec file
  *p1 = hto * OFFENSIVE_FACTOR - vtd;
  *p2 = htd + 2 - vto * OFFENSIVE_FACTOR;
  *p3 = hts * SPECIAL_TEAMS_FACTOR - vts;
  *p4 = hth + htc * HOME_FIELD_ADVANTAGE - vts;
  *p5 = hto * htd * hth * OVERALL_FACTOR - vto * vtd * vtr;
}

/* predict: takes the predicted preferences from above, combines them with the 'WORTH' constants defined in the
 * header file, and returns a double that represents the number of points that the winning team will win by. */
double predict(int p1, int p2, int p3, int p4, int p5) {
  double sum;   // initialize the computed point spread

  // calculation defined in the spec file
  // a positive number represents a home team win, and a negative number represents a visiting team win
  sum = p1 * OFFENSIVE_WORTH + p2 * DEFENSIVE_WORTH + p3 * SPECIAL_WORTH + p4 * HOME_WORTH + p5 * OVERALL_WORTH;

  return sum;   // return the calculated result to the calling function
}

/* update: keeps count of how many games are predicted and how many wins are made by the home team vs the visiting team */
void update(int *gc, int *htw, int *vtw, double prediction) {
  *gc = *gc + 1;        // increment game count each time the function is called

  if (prediction < 0)
    *vtw = *vtw + 1;    // increment vtw if predicted score is less than zero
  else
    *htw = *htw + 1;    // increment htw if predicted score is greater than or equal to zero
}
