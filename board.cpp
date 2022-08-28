#include <SFML/Graphics.hpp>
#include <array>
#include <cmath>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>
#include <stdexcept>
#include <thread>

enum class Diag : char { s, i, r };
typedef std::vector<Diag> line;
std::random_device dev;
std::mt19937 generator(dev());
std::uniform_real_distribution<double> distr(0.0, 1.0);

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
  double inf_prob;

public:
  Board(int s, int i, int r, double b, double y, int days_);
  void evolve();
  int return_beta(double prob);
  int return_gamma();
  void draw();
};
Board::Board(int s, int i, int r, double b, double y, int days_)
    : dimension_{static_cast<int>(sqrt(s + i + r)) + 2},
      grid(dimension_, std::vector<Diag>(dimension_)) {
  beta_ = b;
  gamma_ = y;
  inf = i;
  rim = r;
  days = days_;
  count_time=0;
  num_i = i;
  num_s = dimension_ * dimension_;
  num_r = 0;
  inf_prob = 0.;
  for (int i = 0; i < inf; i++) {
    int ran1 = distr(generator) * dimension_;
    int ran2 = distr(generator) * dimension_;
    grid[ran1][ran2] = Diag::i;
    for (int i = 0; i < rim; i++) {
      int ran3 = distr(generator) * dimension_;
      int ran4 = distr(generator) * dimension_;
      grid[ran3][ran4] = Diag::r;
    }
  }
}

int Board::return_beta(double prob) {
  double num1 = prob;
  
  if (distr(generator) < num1) {
    return 1;
  } else {
    return 2;
  }
}

int Board::return_gamma() {
  double num2 = gamma_;
  if (distr(generator) < num2) {
    return 1;
  } else {
    return 2;
  }
}
void Board::evolve() {
  count_time+=1;
  num_i = 0;
  num_s = 0;
  num_r = 0;
  int count_i;
  count_i = 0;
  for (int l = 1; l < dimension_ - 1; ++l) {
    for (int c = 1; c < dimension_ - 1; ++c) {
      inf_prob = 0;
      switch (grid[l][c]) {
      case Diag::s:
        for (int i = -1; i <= 1; i++) {
          for (int j = -1; j <= 1; j++) {
            if (grid[l - i][c - j] == Diag::i) {
              count_i += 1;
            }
          }
        }
        if (count_i >= 1) {
          inf_prob = beta_;
          if (return_beta(inf_prob) == 1) {
            grid[l][c] = Diag::i;
            num_i += 1;
          } else {
            grid[l][c] = Diag::s;
            num_s += 1;
          }
        } else {
          grid[l][c] = Diag::s;
          num_s += 1;
        }
        break;
      case Diag::i:
        if (return_gamma() == 1) {
          grid[l][c] = Diag::r;
          num_r += 1;
        } else {
          grid[l][c] = Diag::i;
          num_i += 1;
        }
        break;
      case Diag::r:
        grid[l][c] = Diag::r;
        num_r += 1;
        break;
      }
    }
  }
};

;

void Board::draw() {
  float bit_size = 1.;
  if (dimension_ < 350) {
    bit_size = 2.;
  }
  int win_size = static_cast<int>(bit_size * dimension_);
  sf::RenderWindow window(sf::VideoMode(win_size * 2, win_size), "epidemia");
  sf::RectangleShape sus_bit(sf::Vector2f(bit_size, bit_size));
  sf::RectangleShape inf_bit(sf::Vector2f(bit_size, bit_size));
  sf::RectangleShape rec_bit(sf::Vector2f(bit_size, bit_size));

  sus_bit.setFillColor(sf::Color::Green);
  inf_bit.setFillColor(sf::Color::Red);
  rec_bit.setFillColor(sf::Color::Blue);

  while (window.isOpen()) {

    sf::Event event;
    while (window.pollEvent(event)) {

      if (event.type == sf::Event::Closed){
        window.close();
      
    }
    

    window.clear();
   
      evolve();
      for (int l = 1; l < dimension_ - 1; ++l) {
        for (int c = 1; c < dimension_ - 1; ++c) {
          switch (grid[l][c]) {
          case Diag::s:
            sus_bit.setPosition(bit_size * c, bit_size * l);
            window.draw(sus_bit);
            break;
          case Diag::i:
            inf_bit.setPosition(bit_size * c, bit_size * l);
            window.draw(inf_bit);
            break;
          case Diag::r:
           rec_bit.setPosition(bit_size * c, bit_size * l);
            window.draw(rec_bit);
            break;
          }
        }
      };
      sf::RectangleShape black_quad(sf::Vector2f(win_size, win_size));
      black_quad.setPosition(1.5 * win_size, 0.25 * win_size);
      black_quad.setFillColor(sf::Color::Black);
      std::string numi = std::to_string(num_i);
      std::string nums = std::to_string(num_s);
      std::string numr = std::to_string(num_r);
      sf::Text text_s;
      sf::Text text_i;
      sf::Text text_r;
      sf::Font font;
      font.loadFromFile("chintzy.ttf");
      text_s.setFont(font);
      text_i.setFont(font);
      text_r.setFont(font);
      text_s.setString(nums);
      text_i.setString(numi);
      text_r.setString(numr);
      text_s.setCharacterSize(20);
      text_i.setCharacterSize(20);
      text_r.setCharacterSize(20);
      text_s.setFillColor(sf::Color::Green);
      text_i.setFillColor(sf::Color::Red);
      text_r.setFillColor(sf::Color::Blue);
      text_s.setPosition(win_size * 1.5, 0.75 * win_size);
      text_i.setPosition(win_size * 1.5, 0.5 * win_size);
      text_r.setPosition(win_size * 1.5, 0.25 * win_size);
      window.draw(black_quad);
      window.draw(text_s);
      window.draw(text_i);
      window.draw(text_r);
      window.display();
        if(count_time==days){
            window.clear();
              sf::Text text_end;
              text_end.setFont(font);
              text_end.setFillColor(sf::Color::White);
              text_end.setString("SIMULATION ENDED:");
              text_end.setPosition(0.4*win_size,0.45*win_size);
              text_end.setCharacterSize(20);
              window.draw(text_end);
            window.draw(text_s);
            window.draw(text_i);
            window.draw(text_r);
            window.display();
            std::this_thread::sleep_for(std::chrono::seconds(15));
            window.close();
           
            
              }
        
              
    }
  }
}
