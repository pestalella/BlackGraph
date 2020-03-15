#pragma once

#include "ngraph/ngraph.hpp"

enum class HealthState { UNINFECTED, INFECTED, DEAD, RECOVERED };

NGraph::Graph complete_graph(unsigned int nverts);

class Population
{
public:
    Population(unsigned int pop_size);
    unsigned int size()
    {
        return social_links.num_vertices();
    }

    unsigned int num_infected();
    void start_infection();
    void advance_infection();
       
private:
    NGraph::Graph social_links;
    std::vector<HealthState> status;
    std::vector<int> sick_days;
};

