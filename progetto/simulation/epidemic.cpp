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
}
  
