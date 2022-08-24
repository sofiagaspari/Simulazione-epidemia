
#ifndef EPIDEMIC_HPP
#define EPIDEMIC_HPP

#include <vector>


struct State {
    int sus_ ;
    int inf_ ;
    int rim_ ;
    State (){
    sus_= 0.;
    inf_= 0.;
    rim_ = 0.;
        
    }
    }


class Epidemic {
    private:
    std::vector<State> Memory ;
    double beta ;
    double gamma ;
    int tot;
    int days;
    public:
    Epidemic (double b, double y ; int d );

    State Evolve ( State const& start);

    void Update (int d);

    int S_get ( int d) const;

    int I_get (int d) const;

    int R_get (int d) const;

}
#endif
