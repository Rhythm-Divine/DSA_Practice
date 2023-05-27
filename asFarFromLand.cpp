#include<bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1}; 
class Cell {
  public:
  int x, y, dist;
  Cell(int x, int y, int dist){
    
    y=this->y;
    dist=this->dist;
  }
};

bool operator<(const Cell &a, const Cell &b) {
  return a.dist < b.dist;
}

int maxDistance(vector<vector<int>> &grid) {
  int n = grid.size();
  int m = grid[0].size();
  int max_distance = -1;
  vector<pair<int, int>> lands;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 1) {
        lands.emplace_back(i, j);
      }
    }
  }
  if (lands.empty() || lands.size() == n * m) {
    return -1;
  }
  for (auto [x, y] : lands) {
    priority_queue<Cell> q;
    q.emplace(x, y, 0);
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    while (!q.empty()) {
      auto [x, y, dist] = q.top();
      q.pop();
      if (visited[x][y]) {
        continue;
      }
      visited[x][y] = true;
      max_distance = max(max_distance, dist);
      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
          q.emplace(nx, ny, dist + abs(x - nx) + abs(y - ny));
        }
      }
    }
  }
  return max_distance;
}

int main(){
    vector<vector<int>> grid={{1,0,1},{0,0,0},{1,0,1}};
    cout<<maxDistance(grid)<<endl;
}