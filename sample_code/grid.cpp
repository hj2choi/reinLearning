#include"grid.h"

/* the possible directions for an action */
// N(-1, 0) S(1, 0) W(0, -1) E(0, 1)
const int direction_set[4][3][2] = {
  { 
    {-1, 0}, 
    {0, -1}, 
    {0, 1}
  },
  { 
    {1, 0}, 
    {0, -1}, 
    {0, 1}
  },
  { 
    {0, -1}, 
    {-1, 0}, 
    {1, 0}
  },
  { 
    {0, 1}, 
    {-1, 0},
    {1, 0} 
  }
};

/* probability for 3 possible directions */
const double proba_set[3] = {DIR1_PROBA, DIR2_PROBA, DIR2_PROBA};

/* direction names */
const char *dir_names_short[] = {"N", "S", "W", "E"};


void Grid::Intialize(void) {
  /*
   * add
   */
}

void Grid::PolicyIteration(void) {
  cout << endl << "Policy Iteration" << endl << endl;
  /* 
   * add
   */
  int cnt = 0;


  cout << "iter: " << cnt << endl;
  print_values();
  print_policy();
  cout << endl;
  while(/* add */) {
    /*
     * add
     */
    cnt++;
    cout << "iter: " << cnt << endl;
    print_values();
    print_policy();
    cout << endl;
  }
}


void Grid::ValueIteration(void) {
  cout << endl << "Value Iteration" << endl << endl;
  int cnt = 0;
  /*
   * add
   */
  cout << "iter: " << cnt << endl;
  print_values();
  cout << endl;
  while (/* add */) {
    /*
     * add
     */ 
    cnt++;
    cout << "iter: " << cnt << endl;
    cout << "delta: " << delta << endl;
    print_values();
    cout << endl;
    /*
     * add
     */
  }

  /* determine policy */
  
  /*
   * add
   */
  cout << "final policy: " << endl;
  print_policy();
  cout << endl;
}


void Grid::PolicyEvaluation(void) {
  /* 
   * add
   */
}

bool Grid::PolicyImprovement(void) {
  /*
   * add
   */
  return stable;
}


Grid::Grid(unsigned row, unsigned col):
    nrow_(row), 
    ncol_(col), 
    a_(A_POS),
    ap_(AP_POS),
    b_(B_POS),
    bp_(BP_POS),
    a_reward_(AREWARD),
    b_reward_(BREWARD),
    theta_(THETA_DEFALT),
    gamma_(GAMMA)
{

  // initialize states
  for (int i = 0; i < nrow_; i++) {
    StateRow state_row;
    states_.push_back(state_row);
    //states_row_t states_row;
    for (int j = 0; j < ncol_; j++) {
      StateID current_id(i, j);
      vector<Action> actions;
      // for each state, genreate result for 4 different actions (NSWE)
      for (int k = 0; k < 4; k++) 
        actions.push_back(generate_action(k, current_id));
      
      State current_state(current_id, actions);
      states_.back().push_back(current_state);
    }
  }
}


/* generate result for an action (different next states/rewards/probabilities)*/
Action Grid::generate_action(unsigned dir, StateID current_id) const {
  Action action;

  double reward;
  double proba;

  if (current_id == a_) 
    action.push_back(NextState(ap_, 1, a_reward_));
  else if (current_id == b_) 
    action.push_back(NextState(bp_, 1, b_reward_));
  else {
    // a non-deterministic action may generate different results
    for (int i = 0; i < 3; i++) {
      int newrow =  current_id.row + direction_set[dir][i][0];
      int newcol =  current_id.col + direction_set[dir][i][1];
      
      if(isingrid(newrow, newcol)) 
        reward = 0;
      else {
        newrow = current_id.row;
        newcol = current_id.col;
        reward = -1;		
      }
      proba = proba_set[i];
      action.push_back(NextState(StateID(newrow, newcol), proba, reward));
    }
  }
  return action;
}


bool Grid::isingrid(int row, int col) const {
  return  (row >= 0) && (row < nrow_) && (col >= 0) && (col < ncol_);
}


void Grid::print(void) const {
  cout << "Grid size: (" << nrow_ << ", " << ncol_ << ")" << endl;
  cout << "Point A: " << a_.print_str() << " -> AP: " <<  ap_.print_str();
  cout << " reward: " << a_reward_ << endl;
  cout << "Point B: " << b_.print_str() << " -> BP: " <<  bp_.print_str();
  cout << " reward: " << b_reward_ << endl;
  cout << "theta: " << theta_<< endl;
  print_values();
  print_policy();
  cout << endl;
}


void Grid::print_values(void) const {
  cout << "values";
  cout << endl;
  for (int i = 0; i < nrow_; i++) {
    for (int j = 0; j < nrow_; j++) {
      cout << states_[i][j].value() << " ";
    }
    cout << endl;
  }
}


void Grid::print_policy(void) const {
  cout << "actions";
  cout << endl;
  for (int i = 0; i < nrow_; i++) {
    for (int j = 0; j < nrow_; j++) {
      cout << dir_names_short[states_[i][j].policy()] << " ";
    }
    cout << endl;
  }
}



