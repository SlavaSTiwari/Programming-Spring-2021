#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
#include<vector>

typedef std::vector<std::vector<int>> Vector_2d;
typedef std::vector<std::vector<bool>> Vector_2d_bool;

// Prototype functions:
void DFS(int x, int y, Vector_2d &world_map, Vector_2d_bool &visited);
int check_around(int x, int y, Vector_2d &world_map, Vector_2d_bool &visited);
int count_islands(Vector_2d world_map, Vector_2d_bool &visited);

int main() {

    int island_count;

    // DRAW THE MAP:

    Vector_2d w_map
    {//x~0,1,2,3,4   // y
        {0,0,0,0,1}, // 0
        {0,0,0,0,1}, // 1
        {1,1,0,0,0}  // 2
    };

    Vector_2d_bool visited(w_map.size(), std::vector<bool>(w_map[0].size(), 0));


    island_count = count_islands(w_map, visited);

    std::cout << "The number of islands are: " << island_count << std::endl;

    return 0;
}

void DFS(int x, int y, Vector_2d &world_map, Vector_2d_bool &visited) {

    // arrays to make check connected land tiles:
    int y_move[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int x_move[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // Making the current tile "visited":
    visited[y][x] = true;

    // Recursion for all the connected tiles using x_move, y_move;
    for(int c=0; c<8; c++) {
        if(check_around(x+x_move[c], y+y_move[c], world_map, visited)){
            DFS(x+x_move[c], y+y_move[c], world_map, visited);
        }
    }
}

int check_around(int x, int y, Vector_2d &world_map, Vector_2d_bool &visited) {

    // Check if the value is within the map boundaries AND if it is a land tile AND not been visited yet
    return (y >= 0) && (y < world_map.size()) && (x >= 0) && (x < world_map[0].size()) && (world_map[y][x] && !visited[y][x]);
}

int count_islands(Vector_2d world_map, Vector_2d_bool &visited) {

    int isle_count = 0;
    for(int j=0; j<world_map.size(); j++) {
        for(int i=0; i<world_map[j].size(); i++) {

            // if tile is land AND it is not visited before:
            if((world_map[j][i] == 1) && (!visited[j][i])) {
                DFS(i, j, world_map, visited);
                isle_count++;
            }
        }
    }

    return isle_count;

}
