#ifndef _MAP_H_
#define _MAP_H_
#include <iostream>
#include <unordered_map>
#include <utility>
#include <string>
using namespace std;

class Map {
    friend ostream &operator<<(ostream &os, const Map &obj);

private:
    const int node_num {9};
    unordered_map<char, pair<int,int>> house_num;
    unordered_map<int, unordered_map<int,string>> road_name;
    unordered_map<char, pair<int,int>> rd_vertex;
    unordered_map<int, unordered_map<int,int>> mp;
    char addr_road;
    int addr_house_num;

public:
    Map();

    void dfs(vector<int> &parent, vector<int> &vertex, int idx);
    void dijkstra();
    bool verify_input(char &rd, int &num);
    string get_rd_name(char &rd);

};

#endif