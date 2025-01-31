#ifndef A_STAR_H_
#define A_STAR_H_
#define ll long long

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef struct Node {
    int node_num;
    ll f;
    ll g;
    ll h;
    struct Node* parent;
} node;

class AStar {
private:
    node* start_node;
    vector<vector<bool>> graph;
    vector<ll> node_position_x;
    vector<ll> node_position_y;
    vector<node*> open_list;
    vector<node*> closed_list;
public:
    AStar(const vector<vector<bool>>& graph_input, const vector<ll>& node_position_x_input, const vector<ll>& node_position_y_input);
    void find_location(int end, int start);//자식은 부모만 가리키고 부모는 자식을 못가리키기에 거꾸로 두어서 자식에서 부모로 가는 경로가 똑바로 되게함
    void print_route();
};

ll fast_pow(ll base, ll exp);
ll fast_sqrt(ll n);

#endif