/*
 * input-output.c
 * sportsball
 *
 * Daniel Higley
 * CSC 362-001
 * Programming Assignment 2
 * Due 10/10/2016
 *
 * provides functions for getting the data from the file and printing the
 * formatted results out for the user
 *
 */
#include "sportsball.h"

/* getInput: import each line of the file and assign data to variables */
void getInput(FILE *fp, char *ht, int *hto, int *htd, int *hts, int *hth, int *htc, char *vt, int *vto, int *vtd, int *vts, int *vtr) {

  fscanf(fp, "%s %d %d %d %d %d %s %d %d %d %d", ht, hto, htd, hts, hth, htc, vt, vto, vtd, vts, vtr);

}

/* lineCount: returns the number of lines in the given file */
int lineCount(FILE *file) {
  int ch, line_count = 0;

  do {                  // test each char in the file
    ch = fgetc(file);
    if(ch == '\n')      // advance the count if it is a new line character
      line_count++;
  } while (ch != EOF);

  rewind(file); // move position indicator back to the beginning of the file
  return line_count; // return the number of lines found
}

/* output: a formatted line showing the winning team over the losing team along with the predicted point spread */
void output(char *ht, char *vt, double prediction) {
  int score = (int)prediction; // convert predicted score into an int

  if (score > 0)      // predictions greater than zero, home team wins
    printf("Predicted %s over %s by %d\n", ht, vt, score);
  else if (score < 0) // predictions less than zero, visiting team wins
    printf("Predicted %s over %s by %d\n", vt, ht, abs(score));
  else                // no ties allowed, home team wins by 1
    printf("Predicted %s over %s by %d\n", ht, vt, score + 1);
}

/* summary: display the number of games predicted and calculated the home team win % */
void summary(int gc, int htw, int vtw) {
  double htwp = (htw * 100.0) / gc; // calculate the home team win %

  // print formatted results
  printf("\nOut of %d games predicted, %.2f%% favor the home team\n", gc, htwp);
}
