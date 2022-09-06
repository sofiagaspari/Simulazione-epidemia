#ifndef BOARD_HPP
#define BOARD_HPP
#include <vector>
#include <random>


enum class Diag : char { s, i, r };
typedef std::vector<Diag> line;
inline std::random_device dev;
inline std::mt19937 generator(dev());
inline std::uniform_real_distribution<double> distr(0.0, 1.0);
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
