#include "Map.h"
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <utility>

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
    house_num_['a'] = {1, 79};
    house_num_['b'] = {1, 99};
    house_num_['c'] = {1, 29};
    house_num_['d'] = {1, 149};
    house_num_['e'] = {1, 19};
    house_num_['f'] = {1, 59};
    house_num_['g'] = {1, 29};
    house_num_['h'] = {1, 49};
    house_num_['i'] = {1, 19};
    house_num_['j'] = {1, 29};
    road_vertex_['a'] = {1, 2};
    road_vertex_['b'] = {1, 3};
    road_vertex_['c'] = {2, 3};
    road_vertex_['d'] = {3, 8};
    road_vertex_['e'] = {3, 4};
    road_vertex_['f'] = {4, 5};
    road_vertex_['g'] = {5, 8};
    road_vertex_['h'] = {6, 8};
    road_vertex_['i'] = {5, 6};
    road_vertex_['j'] = {6, 7};
    road_name_[1][2] = "Prince Ave.";
    road_name_[1][3] = "Baxter St.";
    road_name_[2][1] = "Prince Ave.";
    road_name_[2][3] = "Alps Rd.";
    road_name_[3][1] = "Baxter St.";
    road_name_[3][2] = "Alps Rd.";
    road_name_[3][4] = "Lumpkin St.";
    road_name_[3][8] = "Carlton St.";
    road_name_[4][3] = "Lumpkin St.";
    road_name_[4][5] = "Thomas St.";
    road_name_[5][4] = "Thomas St.";
    road_name_[5][6] = "Rogers Rd.";
    road_name_[5][8] = "Milledge Ave.";
    road_name_[6][5] = "Rogers Rd.";
    road_name_[6][7] = "North Ave.";
    road_name_[6][8] = "Brooks Dr.";
    road_name_[7][6] = "North Ave.";
    road_name_[8][3] = "Carlton St.";
    road_name_[8][5] = "Milledge Ave.";
    road_name_[8][6] = "Brooks Dr.";
    mp_[1][2] = 800;
    mp_[1][3] = 1000;
    mp_[2][1] = 800;
    mp_[2][3] = 300;
    mp_[3][1] = 1000;
    mp_[3][4] = 200;
    mp_[3][8] = 1500;
    mp_[4][3] = 200;
    mp_[4][5] = 600;
    mp_[5][4] = 600;
    mp_[5][6] = 200;
    mp_[5][8] = 300;
    mp_[6][5] = 200;
    mp_[6][7] = 300;
    mp_[6][8] = 500;
    mp_[7][6] = 300;
    mp_[8][3] = 1500;
    mp_[8][5] = 300;
    mp_[8][6] = 500;
}

std::string Map::GetRoadName(char &rd) {
    return road_name_[road_vertex_[rd].first][road_vertex_[rd].second];
}

bool Map::VerifyInput(char &rd, int &num) {
    if (house_num_.find(rd) == house_num_.end()) {
        return false;
    }

    if (num >= house_num_[rd].first && num <= house_num_[rd].second) {
        user_addr_road_ = rd;
        user_addr_house_num_ = num;
        return true;
    }
    else {
        return false;
    }
}

auto comp = [](std::pair<int,int> &p1, std::pair<int,int> &p2) {
    return p1.first > p2.first;
};

void Map::DFS(std::vector<int> &parent, std::vector<int> &vertex, int idx) {
    if (parent.at(idx) == -1) {
        vertex.push_back(idx);
        return;
    }
    else {
        DFS(parent, vertex, parent.at(idx));
        vertex.push_back(idx);
    }
}

void Map::Dijkstra(std::vector<std::string> &shortest_path, int &total_dist) {

    // Preprocess user's input
    int v1 {road_vertex_[user_addr_road_].first};
    int v2 {road_vertex_[user_addr_road_].second};

    int dist1 {mp_[v1][v2]/(house_num_[user_addr_road_].second + 1) * user_addr_house_num_};
    int dist2 {mp_[v1][v2] - dist1};

    mp_[0][v1] = dist1;
    mp_[0][v2] = dist2;

    road_name_[0][v1] = road_name_[v1][v2];
    road_name_[0][v2] = road_name_[v1][v2];

    // Dijkstra
    std::unordered_set<int> visited;
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, decltype(comp)> min_heap(comp);
    min_heap.push(std::make_pair(0,0));

    std::vector<int> dist (node_num_, INT_MAX);
    dist.at(0) = 0;
    std::vector<int> parent (node_num_, -1);

    while (visited.size() != node_num_ && min_heap.empty() != true) {
        int cur_node {min_heap.top().first};
        int cur_dist {min_heap.top().second};
        min_heap.pop();

        for (auto const &key : mp_[cur_node]) {
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
    std::vector<int> vertex;
    DFS(parent, vertex, node_num_ - 1);

    for (int i {0}; i < vertex.size() - 1; ++i) {
        shortest_path.push_back(road_name_[vertex.at(i)][vertex.at(i + 1)]);
    }

    total_dist = dist.at(8);
}

std::unordered_map<char, std::pair<int,int>> &Map::GetHouseNum() {
    return house_num_;
}

void Map::SetUserAddrRoad(char &road) {
    user_addr_road_ = road;
}

void Map::SetUserAddrHouseNum(int &num) {
    user_addr_house_num_ = num;
}