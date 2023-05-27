#include<bits/stdc++.h>
using namespace std;


int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        //using dijkstra
        int n=maze.size();
        int m=maze[0].size();

        int er=entrance[0];
        int ec=entrance[1];
        set<pair<int,int>> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    s.insert({i,j});
                }
            }
            
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[entrance[er]][entrance[ec]]=0;

        q.push({0,{er,ec}});

        while(!q.empty()){
            auto pair=q.top();
            int d=pair.first;
            int row=pair.second.first;
            int col=pair.second.second;

            if(s.count({row,col})){
                return d;
            }
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(abs(i)!=abs(j)){
                        int cr=row+i;
                        int cc=col+j;
                        if(cr>=0 && cr<n && cc>=0 && cc<m && maze[cr][cc]=='.' ){
                            if(dist[cr][cc]>d+1){
                            q.push({d+1,{cr,cc}});
                            dist[cr][cc]=d+1;
                        }
                        }
                    }
                }
            }
        }
        return -1;
    }
int main() {
    // Test case 1
    vector<vector<char>> maze1 = {{'+','+','.','+'},{'+','.','.','+'},{'+','.','.','+'},{'+','+','+','+'}};
    vector<int> entrance1 = {1, 2};
    int expected1 = 1;
    int result1 = nearestExit(maze1, entrance1);
    cout << "Test Case 1: ";
    if (result1 == expected1) {
        cout << "PASSED";
    } else {
        cout << "FAILED";
    }
    // Test case 2
    vector<vector<char>> maze2 = {{'+','+','+'},{'.','.','+'},{'+','+','.'}};
    vector<int> entrance2 = {1, 0};
    int expected2 = 2;
    int result2 = nearestExit(maze2, entrance2);
    cout << "Test Case 2: ";
    if (result2 == expected2) {
        cout << "PASSED";
    } else {
        cout << "FAILED";
    }
    // Test case 3
    vector<vector<char>> maze3 = {{'.','.'}};
    vector<int> entrance3 = {0, 0};
    int expected3 = -1;
    int result3 = nearestExit(maze3, entrance3);
    cout << "Test Case 3: ";
    if (result3 == expected3) {
        cout <<"PASSED";
    } else {
        cout << "FAILED";
    }
    return 0;
} 


