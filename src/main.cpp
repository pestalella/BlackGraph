#include "ngraph/ngraph.hpp"

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

int main()
{
    NGraph::Graph k = complete_graph(10);

    std::cout << "Node 0 neighbors: [";
    for (auto vert : k.out_neighbors(0)) {
        std::cout << vert << ", ";
    }
    std::cout << "]" << std::endl;
}