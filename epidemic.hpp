#ifndef EPIDEMIC_HPP
#define EPIDEMIC_HPP

#include <vector>  //using vectors

struct State {  // struct declaration and definition
  int sus_;     // data member
  int inf_;
  int rim_;
};

class Epidemic {  // class declaration and definition
 private:
  std::vector<State> memory;  // private
  double beta;
  double gamma;
  int tot;  // people
  int days;

 public:
  Epidemic(int s, int i, int r, double b, double y,
           int d);  // constructor declaration

  State Evolve(State const &start);  // function declaration
  void Update(int d);                // function declaration

  int S_get(int i) const;  // function declaration

  int I_get(int i) const;  // function declaration

  int R_get(int i) const;  // function declaration
};
#endif
