#include "Population.h"

NGraph::Graph complete_graph(unsigned int nverts)
{
    NGraph::Graph k;

    k.set_undirected();

    for (unsigned int i = 0; i < nverts; ++i) {
        k.insert_vertex(i);
    }

    for (unsigned int i = 0; i < k.num_vertices(); ++i) {
        for (unsigned int j = i + 1; j < k.num_vertices(); ++j) {
            k.insert_edge(i, j);
        }
    }
    return k;
}

Population::Population(unsigned int pop_size) :
    social_links(complete_graph(pop_size)),
    status(pop_size),
    sick_days(pop_size)
{
    for (auto vert = social_links.begin(); vert != social_links.end(); ++vert) {
        status[social_links.node(vert)] = HealthState::UNINFECTED;
        sick_days[social_links.node(vert)] = 0;
    }
}

unsigned int Population::num_infected()
{
    unsigned int infected_count = 0;

    for (auto vert = social_links.begin(); vert != social_links.end(); ++vert) {
        if (status[social_links.node(vert)] == HealthState::INFECTED)
            ++infected_count;
    }
    return infected_count;
}

void Population::start_infection()
{
    status[0] = HealthState::INFECTED;
}

void Population::advance_infection()
{
    for (auto vert = social_links.begin(); vert != social_links.end(); ++vert) {
        
    }
}


