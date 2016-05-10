#ifndef STATE_H
#define STATE_H

#include<cstdlib>
#include<vector>
#include<utility>
#include<string>
#include<iostream>
#include<sstream>
#include<algorithm>

#include"parameter.h"


using namespace std;



// row, col
class StateID {
 public:
  /* constructor */
  StateID(unsigned row, unsigned col): row(row), col(col) {}
  /* print string */
  inline string print_str(void) const 
  { ostringstream s; s << "(" << row << ", " << col << ")"; return s.str();}

  unsigned row;
  unsigned col;
};
inline bool operator==(const StateID& lhs, const StateID& rhs) 
{ return ((lhs.row==rhs.row) && (lhs.col==rhs.col)); }


/* a result of an action (state_id, probability, reward)*/
class NextState {
 public:
  NextState(StateID id, double proba, double reward):
      id(id), proba(proba), reward(reward) {}
  
  string print_str(void) const;

  StateID id;
  double proba;
  double reward;
};
/* an action is a set of results */
typedef vector<NextState> Action;


/* state */
class State {
 public:
  /* constructor */
  State(StateID id, vector<Action>& actions): 
      id_(id), actions_(actions), policy_(POLICY_DEFAULT), value_(VALUE_DEFAULT) {}
  
  string print_str(void) const;

  /* get action */
  /* default: action of the current policy */
  inline const Action& get_action(void) const {return actions_[policy_];}
  /* action of the policy dir */
  inline const Action& get_action(unsigned dir) const {return actions_[dir];}

  /* set policy and value */
  inline void set_policy(unsigned policy) {policy_ = policy;}
  inline void set_value(double value) {value_ = value;}

  /* get policy and value */
  inline unsigned policy(void) const  {return policy_;}
  inline double value(void) const  { return value_;}
  
 private:
  /* the state id */
  StateID id_;
  /* the action set (N S W E) */
  vector<Action> actions_;
  
  /* current policy and value */ 
  unsigned policy_;
  double value_;
};

#endif 
