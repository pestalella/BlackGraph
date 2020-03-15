#include "Population.h"

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

