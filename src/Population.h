#pragma once

#include "ngraph/ngraph.hpp"

enum class HealthState { UNINFECTED, INFECTED, DEAD, RECOVERED };

NGraph::Graph complete_graph(unsigned int nverts);

static const float INFECTION_PROB = 0.01f;

class Population
{
public:
    Population(unsigned int pop_size);
    unsigned int size()
    {
        return social_links.num_vertices();
    }

    unsigned int num_healthy();
    unsigned int num_infected();
    unsigned int num_recovered();
    void start_infection();
    void advance_infection();
       
private:
    unsigned int num_in_state(HealthState state);

private:
    NGraph::Graph social_links;
    std::vector<HealthState> status;
    std::vector<int> sick_days;
};

