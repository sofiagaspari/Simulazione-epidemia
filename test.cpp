#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <stdexcept>
#include <vector>

#include "doctest.h"

struct State {
  int sus_;
  int inf_;
  int rim_;
};

class Epidemic {
 public:
  std::vector<State> memory;
  double beta;
  double gamma;
  int tot;
  int days;
  Epidemic(int s, int i, int r, double b, double y, int d);

  State Evolve(State const &start);
  void Update(int d);

  int S_get(int i) const;

  int I_get(int i) const;

  int R_get(int i) const;
};
Epidemic::Epidemic(int s, int i, int r, double b, double y, int d)
    : memory{State{s, i, r}}, beta{b}, gamma{y}, tot{s + i + r}, days{d} {};

State Epidemic::Evolve(State const &start) {
  State end;
  end.sus_ = start.sus_ - beta * start.sus_ * start.inf_ / tot;
  end.inf_ =
      start.inf_ + beta * start.sus_ * start.inf_ / tot - gamma * start.inf_;
  end.rim_ = start.rim_ + gamma * start.inf_;
  return end;
};
void Epidemic::Update(int d) {
  for (int i = 0; i < d; ++i) {
    memory.push_back(Evolve(memory[i]));
  }
};
int Epidemic::S_get(int i) const { return memory[i].sus_; };

int Epidemic::I_get(int i) const { return memory[i].inf_; };
int Epidemic::R_get(int i) const { return memory[i].rim_; };
auto e = Epidemic(499, 1, 0, 0.05, 0.2, 10);

TEST_CASE("testing Epidemic") {
  CHECK(e.memory[0].sus_ == 499);
  CHECK(e.memory[0].inf_ == 1);
  CHECK(e.memory[0].rim_ == 0);
}
TEST_CASE("testing Evolve") {
  e.Update(e.days);
  CHECK(e.memory[1].sus_ == 498);
  CHECK(e.memory[1].inf_ == 0);
  CHECK(e.memory[1].rim_ == 0);
}

TEST_CASE("testing S_get, I_get and R_get") {
  e.Update(e.days);

  CHECK(e.S_get(1) == 498);
  CHECK(e.I_get(1) == 0);
  CHECK(e.R_get(1) == 0);
}
