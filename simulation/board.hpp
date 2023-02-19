#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

enum class Diag : char { s, i, r };
using line = std::vector<Diag>;

class Board {
 private:
  int dimension_;
  std::vector<line> grid;
  double beta_;
  double gamma_;
  int count_time = 0;
  int inf;
  int rim;
  int sus;
  int days;

 public:
  Board(int s, int i, int r, double b, double y, int days_);
  void evolve();
  int return_beta();
  int return_gamma();
  void draw();
};

#endif
