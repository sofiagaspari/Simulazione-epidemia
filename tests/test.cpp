#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <stdexcept>
#include <vector>

#include "../simulation/epidemic.hpp"
#include "doctest.h"

auto e = Epidemic(499, 1, 0, 0.05, 0.2, 1);

TEST_CASE("testing Epidemic") {
  CHECK(e.S_get(0) == 499);
  CHECK(e.I_get(0) == 1);
  CHECK(e.R_get(0) == 0);
}

TEST_CASE("testing Evolve") {
  e.Update(1);
  CHECK(e.S_get(1) == 499);
  CHECK(e.I_get(1) == 1);
  CHECK(e.R_get(1) == 0);
}
