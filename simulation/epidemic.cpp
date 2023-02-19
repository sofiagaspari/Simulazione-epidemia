#include "epidemic.hpp"

#include <cassert>
#include <cmath>

Epidemic::Epidemic(int s, int i, int r, double b, double y, int d)
    : memory{State{s, i, r}}, beta{b}, gamma{y}, tot{s + i + r}, days{d} {}

State Epidemic::Evolve(State const &start) {
  State end;
  double susd = start.sus_ - beta * start.sus_ * start.inf_ / tot;
  end.sus_ = std::round(susd);
  double infd =
      start.inf_ + beta * start.sus_ * start.inf_ / tot - gamma * start.inf_;
  end.inf_ = std::round(infd);
  end.rim_ = tot - end.sus_ - end.inf_;
  assert(end.sus_ >= 0);
  assert(end.inf_ >= 0);
  assert(end.rim_ >= 0);
  return end;
}
void Epidemic::Update() {
  for (int i = 0; i < days; ++i) {
    memory.push_back(Evolve(memory[i]));
  }
}

int Epidemic::S_get(int i) const { return memory[i].sus_; }
int Epidemic::I_get(int i) const { return memory[i].inf_; }
int Epidemic::R_get(int i) const { return memory[i].rim_; }
