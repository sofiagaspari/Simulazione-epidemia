#include "board.cpp"
#include "epidemic.cpp"

int main() {
  int n_s;
  int n_i;
  int n_r;
  int n_d;
  double beta_;
  double gamma_;
  std::cout << "Per popolazioni maggiori di 100000, la simulazione grafica "
               "potrebbe risultare lenta."
            << '\n'
            << "Inserisci il numero di suscettibili:";
  try {
    std::cin >> n_s;
    if (n_s < 0) {
      throw std::runtime_error{
          "Il numero di suscettibili deve essere non negativo"};
    }
  } catch (std::runtime_error const &e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << "Inserisci il numero di infetti:";
  try {
    std::cin >> n_i;
    if (n_i < 0) {
      throw std::runtime_error{"Il numero di infetti deve essere non negativo"};
    }
  } catch (std::runtime_error const &e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << "Inserisci il numero di rimossi:";
  try {
    std::cin >> n_r;
    if (n_r < 0) {
      throw std::runtime_error{"Il numero di rimossi deve essere non negativo"};
    }
  } catch (std::runtime_error const &e) {
    std::cerr << e.what() << '\n';
  }
  std::cout
      << "Inserisci il parametro beta (valore compreso tra 0 e 1 inclusi):";
  try {
    std::cin >> beta_;
    if (beta_ < 0 || beta_ > 1) {
      throw std::runtime_error{"Non sei all'interno del dominio di beta"};
    }
  } catch (std::runtime_error const &e) {
    std::cerr << e.what() << '\n';
  }

  std::cout
      << "Inserisci il parametro gamma (valore compreso tra 0 e 1 inclusi):";
  try {
    std::cin >> gamma_;
    if (gamma_ < 0 || gamma_ > 1) {
      throw std::runtime_error{"Non sei all'interno del dominio di gamma"};
    }
  } catch (std::runtime_error const &e) {
    std::cerr << e.what() << '\n';
  }

  std::cout << "Inserisci il numero di giorni di evoluzione della epidemia:";
  try {
    std::cin >> n_d;
    if (n_d < 0) {
      throw std::runtime_error{"Il numero di giorni deve essere non negativo"};
    }
  } catch (std::runtime_error const &e) {
    std::cerr << e.what() << '\n';
  }

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
  std::cout << "Nella finestra grafica che si apre i suscettibili sono verdi, "
               "gli infetti rossi e i rimossi blu."
            << '\n';
  Board b(n_s, n_i, n_r, beta_, gamma_, n_d);
  b.draw(); 
}
