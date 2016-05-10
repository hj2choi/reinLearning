#include"state.h"


const char *dir_names[] = {"North", "South", "West", "East"};

string NextState::print_str(void) const {
  ostringstream ss;
  ss << id.print_str();
  ss << " proba: " << proba << " reward: " << reward << endl;
  return ss.str();
}


string State::print_str(void) const {
  ostringstream ss;
  
  ss << "state: " << id_.print_str();
  ss << " policy: " << policy_ << " value_: " << value_ << endl;

  ss << "actions: " << endl;
  for (int i = 0;  i < actions_.size(); i++) {
    ss << "go " << dir_names[i] << endl;
    for (int j = 0; j < actions_[i].size(); j++) {
      ss << "next state: " << actions_[i][j].print_str();
    }
  }

  return ss.str();
}
