#pragma once

#include "ngraph/ngraph.hpp"

enum class HealthState { UNINFECTED, INFECTED, DEAD, RECOVERED };

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

class Population
{
public:
    Population(unsigned int pop_size);
       
private:
    NGraph::Graph social_links;
    std::vector<HealthState> status;
    std::vector<int> sick_days;
};

