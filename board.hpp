#ifndef BOARD_HPP
#define BOARD_HPP
#include <vector>

enum class Diag : char { s, i, r };
typedef std::vector<Diag> line;

class Board {
private:
  int dimension_;
  std::vector<line> grid;
  double beta_;
  double gamma_;
  int count_time;
  int inf;
  int rim;
  int days;
  int num_i;
  int num_s;
  int num_r;

public:
  Board(int s, int i, int r, double b, double y, int days_);
  void evolve();
  int return_beta();
  int return_gamma();
  void draw();
};

#endif
