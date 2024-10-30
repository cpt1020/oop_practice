#include "Map.h"
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <utility>
using namespace std;

// Overload << operator
std::ostream &operator<<(std::ostream &os, const Map &obj) {                  
    os << "        ○                                                 \n";
    os << "       / \\            Our Hospital                        \n";
    os << "  (a) /   \\ (b)            |                              \n";
    os << "     /     \\       (d)     V   (h)    (j)                 \n";
    os << "    ○-------○--------------●-------○------○               \n";
    os << "       (c)   \\              \\     /                       \n";
    os << "              \\ (e)      (g) \\   / (i)                    \n";
    os << "               \\              \\ /                         \n";
    os << "                ○--------------○                          \n";
    os << "                       (f)                                \n\n";
    os << "| Road Name        | Length of Road | House Number Range |\n";
    os << "| a: Prince Ave.   |  800 m         | 1-79               |\n";
    os << "| b: Baxter St.    | 1000 m         | 1-99               |\n";
    os << "| c: Alps Rd.      |  300 m         | 1-29               |\n";
    os << "| d: Carlton St.   | 1500 m         | 1-149              |\n";
    os << "| e: Lumpkin St.   |  200 m         | 1-19               |\n";
    os << "| f: Thomas St.    |  600 m         | 1-59               |\n";
    os << "| g: Milledge Ave. |  300 m         | 1-29               |\n";
    os << "| h: Brooks Dr.    |  500 m         | 1-49               |\n";
    os << "| i: Rogers Rd.    |  200 m         | 1-19               |\n";
    os << "| j: North Ave.    |  300 m         | 1-29               |\n";
    return os;
}

Map::Map() {
    house_num['a'] = {1, 79};
    house_num['b'] = {1, 99};
    house_num['c'] = {1, 29};
    house_num['d'] = {1, 149};
    house_num['e'] = {1, 19};
    house_num['f'] = {1, 59};
    house_num['g'] = {1, 29};
    house_num['h'] = {1, 49};
    house_num['i'] = {1, 19};
    house_num['j'] = {1, 29};
    rd_vertex['a'] = {1, 2};
    rd_vertex['b'] = {1, 3};
    rd_vertex['c'] = {2, 3};
    rd_vertex['d'] = {3, 8};
    rd_vertex['e'] = {3, 4};
    rd_vertex['f'] = {4, 5};
    rd_vertex['g'] = {5, 8};
    rd_vertex['h'] = {6, 8};
    rd_vertex['i'] = {5, 6};
    rd_vertex['j'] = {6, 7};
    road_name[1][2] = "Prince Ave.";
    road_name[1][3] = "Baxter St.";
    road_name[2][1] = "Prince Ave.";
    road_name[2][3] = "Alps Rd.";
    road_name[3][1] = "Baxter St.";
    road_name[3][2] = "Alps Rd.";
    road_name[3][4] = "Lumpkin St.";
    road_name[3][8] = "Carlton St.";
    road_name[4][3] = "Lumpkin St.";
    road_name[4][5] = "Thomas St.";
    road_name[5][4] = "Thomas St.";
    road_name[5][6] = "Rogers Rd.";
    road_name[5][8] = "Milledge Ave.";
    road_name[6][5] = "Rogers Rd.";
    road_name[6][7] = "North Ave.";
    road_name[6][8] = "Brooks Dr.";
    road_name[7][6] = "North Ave.";
    road_name[8][3] = "Carlton St.";
    road_name[8][5] = "Milledge Ave.";
    road_name[8][6] = "Brooks Dr.";
    mp[1][2] = 800;
    mp[1][3] = 1000;
    mp[2][1] = 800;
    mp[2][3] = 300;
    mp[3][1] = 1000;
    mp[3][4] = 200;
    mp[3][8] = 1500;
    mp[4][3] = 200;
    mp[4][5] = 600;
    mp[5][4] = 600;
    mp[5][6] = 200;
    mp[5][8] = 300;
    mp[6][5] = 200;
    mp[6][7] = 300;
    mp[6][8] = 500;
    mp[7][6] = 300;
    mp[8][3] = 1500;
    mp[8][5] = 300;
    mp[8][6] = 500;
}

string Map::get_rd_name(char &rd) {
    return road_name[rd_vertex[rd].first][rd_vertex[rd].second];
}

bool Map::verify_input(char &rd, int &num) {
    if (house_num.find(rd) == house_num.end()) {
        return false;
    }

    if (num >= house_num[rd].first && num <= house_num[rd].second) {
        addr_road = rd;
        addr_house_num = num;
        return true;
    }
    else {
        return false;
    }
}

auto comp = [](pair<int,int> &p1, pair<int,int> &p2) {
    return p1.first > p2.first;
};

void Map::dfs(vector<int> &parent, vector<int> &vertex, int idx) {
    if (parent.at(idx) == -1) {
        vertex.push_back(idx);
        return;
    }
    else {
        dfs(parent, vertex, parent.at(idx));
        vertex.push_back(idx);
    }
}

void Map::dijkstra() {

    // Preprocess user's input
    int v1 {rd_vertex[addr_road].first};
    int v2 {rd_vertex[addr_road].second};

    int dist1 {mp[v1][v2]/(house_num[addr_road].second + 1) * addr_house_num};
    int dist2 {mp[v1][v2] - dist1};

    mp[0][v1] = dist1;
    mp[0][v2] = dist2;

    road_name[0][v1] = road_name[v1][v2];
    road_name[0][v2] = road_name[v1][v2];

    // Dijkstra
    unordered_set<int> visited;
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> min_heap(comp);
    min_heap.push({0,0});

    vector<int> dist (node_num, INT_MAX);
    dist.at(0) = 0;
    vector<int> parent (node_num, -1);

    while (visited.size() != node_num && min_heap.empty() != true) {
        int cur_node {min_heap.top().first};
        int cur_dist {min_heap.top().second};
        min_heap.pop();

        for (auto const &key : mp[cur_node]) {
            if (visited.find(key.first) == visited.end()) {
                int adj {key.first};
                int adj_dist {key.second};

                if (cur_dist + adj_dist < dist.at(adj)) {
                    dist.at(adj) = (cur_dist + adj_dist);
                    parent.at(adj) = cur_node;
                    min_heap.push({adj, adj_dist + cur_dist});
                }
            }
        }

        visited.insert(cur_node);
    }

    // Process result
    vector<int> vertex;
    dfs(parent, vertex, node_num - 1);

    vector<string> roads;
    for (int i {0}; i < vertex.size() - 1; ++i) {
        roads.push_back(road_name[vertex.at(i)][vertex.at(i + 1)]);
    }

    cout << "\n" << *this;
    cout << "\nThe recommended route to our hospital is: ";

    for (int i {0}; i < roads.size(); ++i) {
        cout << roads.at(i) << ((i == roads.size() - 1) ? "\n" : " -> ");
    }

    cout << "Total distance: " << dist.at(8) << " meters" << endl;
}