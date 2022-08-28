#include "epidemic.hpp"
#include <cassert>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

Epidemic::Epidemic(int s, int i, int r, double b, double y,
                   int d)     // construct definition
    : memory{State{s, i, r}}, // initialization
      beta{b}, gamma{y}, tot{s + i + r}, days{d} {};

State Epidemic::Evolve(State const &start) { // function definition
  State end;
  end.sus_ = start.sus_ -
             beta * start.sus_ * start.inf_ / tot; // differential equation
  end.inf_ =
      start.inf_ + beta * start.sus_ * start.inf_ / tot - gamma * start.inf_;
  end.rim_ = start.rim_ + gamma * start.inf_;
  assert(end.sus_ >= 0);
  assert(end.inf_ >= 0);
  assert(end.rim_ >= 0);
  return end;
};
void Epidemic::Update(int d) { // function definition
  for (int i = 0; i < d; ++i) {
    memory.push_back(Evolve(memory[i]));
  }
};

int Epidemic::S_get(int i) const { // function definition
  return memory[i].sus_;
};

int Epidemic::I_get(int i) const { // function definition
  return memory[i].inf_;
};
int Epidemic::R_get(int i) const { // function definition
  return memory[i].rim_;
};
