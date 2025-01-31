#include "A_star.h"

ll fast_pow(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}

ll fast_sqrt(ll n) {
    if (n == 0 || n == 1) return n;

    ll x = n, y = (x + 1) / 2;
    while (y < x) {
        x = y;
        y = (x + n / x) / 2;
    }
    return x;
}

struct Compare {
    bool operator()(const node* a, const node* b) {
        return a->f > b->f;
    }
};

AStar::AStar(const vector<vector<bool>>& graph_input, const vector<ll>& node_position_x_input, const vector<ll>& node_position_y_input)
    : graph(graph_input), node_position_x(node_position_x_input), node_position_y(node_position_y_input) {}

void AStar::find_location(int end, int start) {
    vector<node*> node_list;
    
    for (int i = 0; i < node_position_x.size(); i++) {
        node* new_node = new node();
        new_node->node_num = i;
        new_node->f = LLONG_MAX;
        new_node->g = LLONG_MAX;
        new_node->h = LLONG_MAX;
        new_node->parent = NULL;
        node_list.push_back(new_node);
    }

    node* select_node = node_list.at(start);
    select_node->f = 0;
    select_node->g = 0;
    select_node->h = 0;

    while (!(select_node->node_num == end)) {
        closed_list.push_back(select_node);
        priority_queue<node*, vector<node*>, Compare> min_heap;
        for (int i = 0; i < node_position_x.size(); i++) {
            auto a = find(closed_list.begin(), closed_list.end(), node_list.at(i));
            if (a == closed_list.end()) {
                if (graph.at(select_node->node_num).at(i) == true) {
                    node_list.at(i)->parent = select_node;
                    node_list.at(i)->g = select_node->g + fast_sqrt(fast_pow((node_position_x.at(select_node->node_num) * 100 - node_position_x.at(node_list.at(i)->node_num) * 100), 2)
                        + fast_pow((node_position_y.at(select_node->node_num) * 100 - node_position_y.at(node_list.at(i)->node_num) * 100), 2));
                    node_list.at(i)->h = fast_sqrt(fast_pow((node_position_x.at(end) * 100 - node_position_x.at(node_list.at(i)->node_num) * 100), 2)
                        + fast_pow((node_position_y.at(end) * 100 - node_position_y.at(node_list.at(i)->node_num) * 100), 2));
                    open_list.push_back(node_list.at(i));
                    node_list.at(i)->f = node_list.at(i)->g + node_list.at(i)->h;
                    min_heap.push(node_list.at(i));
                }
            }
        }
        if (open_list.empty()) {
            return;
        }
        select_node = min_heap.top();
    }

    start_node = select_node;
    return;
}

void AStar::print_route() {
    node* select_node = start_node;
    while (select_node != NULL) {
        cout << select_node->node_num << "->";
        select_node = select_node->parent;
    }
    cout << "µµÂø";
    return;
}