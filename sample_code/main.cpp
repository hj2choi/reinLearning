#include "grid.h"


int main(void) {
  /* create the grid */
  Grid mygrid(5, 5);
  
  /* print the summary */
  mygrid.print();

  /* Policy Iteration */
  //mygrid.PolicyIteration();

  /* print the summary */
  //mygrid.print();

  /* Value Iteration*/
  //mygrid.ValueIteration();

  /* print the summary */
  //mygrid.print();
  return 0;
}
