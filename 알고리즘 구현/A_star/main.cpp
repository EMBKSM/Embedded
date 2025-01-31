#include "A_star.h"

int main() {
    vector<vector<bool>> graph = {
        {false, true,  true,  false, false},
        {true,  false, false, true,  false},
        {true,  false, false, false, true },
        {false, true,  false, false, true },
        {false, false, true,  true,  false}
    };

    vector<ll> node_x = { 0, 1, 1, 2, 2 };
    vector<ll> node_y = { 0, 0, 1, 1, 2 };

    AStar astar(graph, node_x, node_y);

    astar.find_location(4, 0);

    cout << "최단 경로: ";
    astar.print_route();

    return 0;
}