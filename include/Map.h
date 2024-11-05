#ifndef _MAP_H_
#define _MAP_H_
#include <iostream>
#include <unordered_map>
#include <utility>
#include <string>

class Map {
    friend std::ostream &operator<<(std::ostream &os, const Map &obj);

private:
    const int node_num_ {9};
    std::unordered_map<char, std::pair<int,int>> house_num_;
    std::unordered_map<int, std::unordered_map<int,std::string>> road_name_;
    std::unordered_map<char, std::pair<int,int>> road_vertex_;
    std::unordered_map<int, std::unordered_map<int,int>> mp_;
    char user_addr_road_;
    int user_addr_house_num_;

public:
    Map();

    void DFS(std::vector<int> &parent, std::vector<int> &vertex, int idx);
    void Dijkstra(std::vector<std::string> &shortest_path, int &total_dist);
    bool VerifyInput(char &rd, int &num);
    std::string GetRoadName(char &rd);
    std::unordered_map<char, std::pair<int,int>> &GetHouseNum();
    void SetUserAddrRoad(char &road);
    void SetUserAddrHouseNum(int &num);
    
};

#endif