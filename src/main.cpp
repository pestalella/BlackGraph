#include "Population.h"

int main()
{
    const unsigned int numVerts = 10;

    Population pop(numVerts);

    pop.start_infection();
    for (int i = 0; i < 100; ++i) {
        std::cout << "Day " << i << " total population:" << pop.size() << " infected:" << pop.num_infected() << std::endl;
        pop.advance_infection();
    }
}

