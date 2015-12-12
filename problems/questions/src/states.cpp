#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;

/*
 * == payments at Square ==
 * A, C, R, V
 * start state - A
 * valid transitions - A->C, A->V, C->R
 *
 * part 1 -
 * [ A, C, R ] => true
 * [ A, V, R ] => false
 * [ C, R ] => false
 *
 * part 2 -
 * [ C, R, A ] => [ A, C, R ]
 * [ V, R, A ] => null
 */

bool isValidTransition(vector<vector<string>> edges, string current_state, string next_state) {
  for (auto transition : edges) {
    if (transition[0] == current_state && transition[1] == next_state) {
      return true;
    }
  }
  return false;
}

bool isValidTransition(string start_state, set<string> valid_states, vector<vector<string>> edges, vector<string> sequence) {

  if (sequence[0] != start_state) {
    return false;
  }

  unsigned int i = 0;
  string current_state = sequence[i];
  while (i < sequence.size() - 1) {
    string next_state = sequence[i+1];
    if (!isValidTransition(edges, current_state, next_state)) {
      return false;
    }

    current_state = next_state;
    i++;
  }

  return true;
}

vector<string> validNextStates(vector<vector<string>> edges, string current_state) {
  vector<string> next_states;
  for (auto edge : edges) {
    if (edge[0] == current_state) {
      next_states.push_back(edge[1]);
    }
  }
  return next_states;
}


bool isValidScrambledTransition(string start_state, set<string> valid_states, vector<vector<string>> edges, vector<string> scrambled) {
  vector<string>::iterator current_state_iter = find(scrambled.begin(), scrambled.end(), start_state);

  // if start state not in scrambled, return false.
  if (current_state_iter == scrambled.end()) {
    return false;
  }

  if (scrambled.size() == 1) {
    return true;
  }

  string current_state = *current_state_iter;
  scrambled.erase(current_state_iter);

  // find all the states in our scrambled list we can transition to
  vector<string> potential_next_states = validNextStates(edges, current_state);
  for (auto state : scrambled) {
    if (find(potential_next_states.begin(), potential_next_states.end(), state) != potential_next_states.end()) {
      if (isValidScrambledTransition(state, valid_states, edges, scrambled)) {
        return true;
      }
    }
  }

  return false;
}

int main() {

  string start_state = "A";
  set<string> valid_states = {"A", "C", "R", "V"};
  vector<vector<string>> edges = { {"A", "V"}, {"A", "C"}, {"C", "R"}, {"R", "V"}};

  vector<vector<string>> sequences = {
    {"A", "C", "R"},
    {"A", "V", "R"},
    {"C", "R"},
    {"A", "C", "T"}, // invalid state
    {"C", "C", "R"}, // invalid initial state
  };

  for (auto sequence : sequences) {
    // cout << isValidTransition(start_state, valid_states, edges, sequence) << endl;
  }

  vector<vector<string>> scrambled = {
    {"C", "R", "A"},
    {"V", "R", "A"},
    {"C", "R"},
  };

  for (auto sequence : scrambled) {
    cout << isValidScrambledTransition(start_state, valid_states, edges, sequence) << endl;
  }

  return 0;
}

