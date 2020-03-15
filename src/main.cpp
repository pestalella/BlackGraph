#include "Population.h"

int main()
{
    const unsigned int numVerts = 10;

    Population pop(numVerts);

    pop.start_infection();
    for (int i = 0; i < 100; ++i) {
        std::cout << "Day " << i << " total population:" << pop.size() << " healthy:" << pop.num_healthy() << 
            " infected:" << pop.num_infected() << " recovered:" << pop.num_recovered() << std::endl;
        pop.advance_infection();
    }
}

