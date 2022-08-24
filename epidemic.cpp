#include "epidemic.hpp"
#include <iostream>
#include <iomanip>
#include <vector>

Epidemic::Epidemic(int s , int i , int r,double b, double y , int d ) 
:
    memory {State{s,i,r}},
    beta {b},
    gamma {y},
    tot {s + i + r},
    days {d}
    {}
    ;

State Epidemic::Evolve (State const& start) {
    State end;
    end.sus_=start.sus_-beta*start.sus_*start.inf_/tot;
    end.inf_=start.inf_+beta*start.sus_*start.inf_/tot-gamma*start.inf_;
    end.rim_=start.rim_+gamma*start.inf_;
return end;

};
void Epidemic::Update (int d){
for (int i = 0; i < d; ++i) {
    memory.push_back(Evolve(memory[i]));
  }
};

  int Epidemic::S_get (int i) const {
    return memory[i].sus_;};

    int Epidemic::I_get (int i) const  {
        return memory[i].inf_;
  };
int Epidemic::R_get (int i) const  { 
    return memory[i].rim_;
};

    int main () {
        int n_s;
        int n_i;
        int n_r;
        int n_d;
        double beta_;
        double gamma_;
         std::cin >> n_s >> n_i >> n_r >> beta_ >> gamma_ >> n_d;
         Epidemic p(n_s, n_i, n_r, beta_, gamma_ , n_d );
       p.Update(n_d);
        
        for (int i = 0; i <= n_d; ++i) {
        p.S_get(i);
        p.I_get(i);
        p.R_get(i);

    std::cout << std::setw(6) << i << '\t' << std::setw(11) << p.S_get(i) << std::setw(11) << p.I_get(i) << '\t'<< std::setw(11)<<p.R_get(i)<<'\n';};
       std::cout << "\n\n";
      
        


    }
 
