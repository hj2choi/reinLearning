#ifndef GRID_H 
#define GRID_H

#include "state.h"
#include "parameter.h"
#include<float.h>
#include<cmath>

/* Row of states */
typedef vector<State> StateRow;

class Grid {
 public:
  /* constructor */
  Grid(unsigned row, unsigned col);

  /* Policy Iteration */ 
  void PolicyIteration(void);
  /* Value Iteration */ 
  void ValueIteration(void);
  /* Initialize values and policies */
  void Intialize(void);

  inline double get_state_value(StateID id) const 
  { return states_[id.row][id.col].value(); }

  /* print state information */
  inline void print_state(unsigned row, unsigned col) const 
  { cout << states_[row][col].print_str(); }

  /* print a summary of the whole grid */
  void print(void) const;
  /* print the current policy for the grid */
  void print_policy(void) const;
  /* print the current values for the grid */
  void print_values(void) const;


 private:
  /* Policy Evaluation */
  void PolicyEvaluation(void);
  /* Policy Improvement, return stable*/
  bool PolicyImprovement(void);

  /* generate next states information for state current_id */
  vector<NextState> generate_nextstate(StateID current_id) const;
  /* generate action for a action number for current_id */
  Action generate_action(unsigned action, StateID current_id) const;

   
  bool isingrid(int row, int col) const;


  
  unsigned nrow_, ncol_;
  /* point A A', B B' */
  StateID a_, ap_, b_, bp_;
  /* rewards for A B */
  int a_reward_, b_reward_;
  /* theta */
  double theta_;
  /* gamma */
  double gamma_;
  /* all states */
  /* a state of row i, column j can be accessed by state_[i][j] */
  vector<StateRow> states_;
};



#endif
