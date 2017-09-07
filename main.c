/*
 * main.c
 * sportsball
 *
 * Daniel Higley
 * CSC 362-001
 * Programming Assignment 2
 * Due 10/10/2016
 *
 * This program predicts the outcome of a given football game using both team's
 * rankings in various aspects of the game. This is done by reading a provided
 * disk file, one line at a time, and parsing the structured file's data into
 * variables assigned to both teams. These variables, along with the given
 * 'FACTOR' constants that are stored in the header file, are then used to compute
 * a 'preference' based on both teams strengths in the different aspects of the
 * game. These 'preferences', along with the 'WORTH' constants defined in the header
 * file, are then used to compare the home team to the visiting team to determine
 * the winning team and the resulting point spread. The winner of each game is
 * displayed via stdout along with the calculated point spread. A summary that
 * contains a count of all games predicted and the percentage of home team wins
 * is given after the entire file has been processed.
 *
 */
#include "sportsball.h" // include definitions, declarations, and prototypes from header file

int main(void) {
  // variables to be collected from the file
  char ht[15], vt[15];                              // team name strings
  int hto, htd, hts, hth, htc, vto, vtd, vts, vtr;  // team ranking ints
  int gc = 0, htw = 0, vtw = 0;                     // game count and team win count ints
  double p1, p2, p3, p4, p5, prediction;            // calculated preferences and prediction doubles

  // add the file name to a string variable and open the file read only
  char filename[] = "football2.txt";    // file name saved to a var
  FILE *fp = fopen(filename, "r");      // open input file
  if(!fp) {                             // test that the given file exist
    perror("File opening failed");
    return EXIT_FAILURE;                // Exit if it does not
  }
  // LINE COUNT IS NOT NEEDED IF A WHILE LOOP IS USED
  /* int i, line_count;                    // initialize i and line_count */
  /* line_count = lineCount(fp);           // get the number of lines in the file */

  // iterate through file one line at a time. one line == one game to predict
  /* for(i = 0; i < line_count; i++) { */ // REPLACE FOR LOOP WITH WHILE LOOP
  while (!feof(fp)) { // HOW DO I PREVENT THE LAST LINE FROM PRINTING TWICE?
    // get one line of data from the formatted file and save data to the defined variables
    getInput(fp, ht, &hto, &htd, &hts, &hth, &htc, vt, &vto, &vtd, &vts, &vtr);
    // compute "preference" values from data and 'FACTOR' constants
    compute(&p1, &p2, &p3, &p4, &p5, hto, htd, hts, hth, htc, vto, vtd, vts, vtr);
    // use 'preference' values and 'WORTH' constants to determine final point spread
    prediction = predict(p1, p2, p3, p4, p5);
    // output winner over loser along with predicted point spread
    output(ht, vt, prediction);
    // output number of games predicted and home team win percentage
    update(&gc, &htw, &vtw, prediction);
  }

  // displays the number of games predicted and the percentage of home team wins.
  summary(gc, htw, vtw);

  // close the file
  fclose(fp);
  return 0;
}

