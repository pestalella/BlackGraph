#include "Population.h"

#include <random>

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

float get_random()
{
    static std::default_random_engine e;
    static std::uniform_real_distribution<> dis(0, 1); // rage 0 - 1
    return static_cast<float>(dis(e));
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

unsigned int Population::num_in_state(HealthState state)
{
    unsigned int count = 0;

    for (auto vert = social_links.begin(); vert != social_links.end(); ++vert) {
        if (status[social_links.node(vert)] == state)
            ++count;
    }
    return count;

}

unsigned int Population::num_infected()
{
    return num_in_state(HealthState::INFECTED);
}

unsigned int Population::num_recovered()
{
    return num_in_state(HealthState::RECOVERED);
}

unsigned int Population::num_healthy()
{
    return num_in_state(HealthState::UNINFECTED);
}

void Population::start_infection()
{
    status[0] = HealthState::INFECTED;
}

void Population::advance_infection()
{
    for (auto vert = social_links.begin(); vert != social_links.end(); ++vert) {
        for (auto neighbor : social_links.out_neighbors(vert)) {
            if (status[neighbor] == HealthState::UNINFECTED) {
                if (get_random() < INFECTION_PROB) {
                    status[neighbor] = HealthState::INFECTED;
                }
            }
        }
    }
    
    for (auto vert = social_links.begin(); vert != social_links.end(); ++vert) {
        unsigned int vertIdx = social_links.node(vert);
        if (status[vertIdx] == HealthState::INFECTED) {
            ++sick_days[vertIdx];
        }
        if (sick_days[vertIdx] > 10) {
            status[vertIdx] = HealthState::RECOVERED;
        }
    }
}
