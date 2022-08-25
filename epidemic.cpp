#include "epidemic.hpp"
#include <iomanip>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cassert>

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
  assert(end.sus_>=0);
  assert(end.inf_>=0);
  assert(end.rim_>=0);
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

int main() {
  int n_s;
  int n_i;
  int n_r;
  int n_d;
  double beta_;
  double gamma_;
  std::cout << "Inserisci il numero di suscettibili:";
  std::cin >> n_s;
  std::cout << "Inserisci il numero di infetti:";
  std::cin >> n_i;
  std::cout << "Inserisci il numero di rimossi:";
  std::cin >> n_r;
  std::cout   << "Inserisci il parametro beta (valore compresso tra 0 e 1 compresi):";
  try{
    std::cin >> beta_;
    if(beta_<0 || beta_>1){
        throw std::runtime_error{"Non sei all'interno del dominio di beta"};
    }
  }
    catch (std::runtime_error const& e) {
       std::cerr << e.what() << '\n';
    }

  
  
  std::cout
      << "Inserisci il parametro gamma (valore compresso tra 0 e 1 compresi):";
  try{
    std::cin >> gamma_;
    if(gamma_<0 || gamma_>1){
        throw std::runtime_error{"Non sei all'interno del dominio di gamma"};
    }
  }
    catch (std::runtime_error const& e) {
       std::cerr << e.what() << '\n';
    }

  
  std::cout << "Inserisci il numero di giorni di evoluzione della epidemia:";
  std::cin >> n_d;
  Epidemic p(n_s, n_i, n_r, beta_, gamma_, n_d);
  p.Update(n_d);
  std::cout << std::setw(6) << "Giorno" << '\t' << std::setw(11)
            << "Suscettibili" << std::setw(11) << "Infetti" << '\t'
            << std::setw(11) << "Rimossi" << '\n';
  for (int i = 0; i <= n_d; ++i) {
    p.S_get(i);
    p.I_get(i);
    p.R_get(i);

    std::cout << std::setw(6) << i << '\t' << std::setw(11) << p.S_get(i)
              << std::setw(11) << p.I_get(i) << '\t' << std::setw(11)
              << p.R_get(i) << '\n';
  };
  std::cout << "\n\n";
}
