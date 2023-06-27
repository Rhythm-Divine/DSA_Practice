#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Robot {
    int position;
    int health;
    int index;
};

vector<int> survivingRobots(vector<int>& positions, vector<int>& healths, string& directions) {
    int n = positions.size();
    vector<Robot> robots(n);

    // Create a list of robots with position, health, and index
    for (int i = 0; i < n; i++) {
        robots[i].position = positions[i];
        robots[i].health = healths[i];
        robots[i].index = i;
    }

    // Sort the robots based on their positions
    sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
        return a.position < b.position;
    });

    stack<Robot> stk;
    for (const Robot& robot : robots) {
        int position = robot.position;
        int health = robot.health;
        int index = robot.index;

        while (!stk.empty()) {
            Robot prevRobot = stk.top();
            int prevPosition = prevRobot.position;
            int prevHealth = prevRobot.health;
            int prevIndex = prevRobot.index;

            if (prevPosition == position) {
                if (prevHealth <= health) {
                    stk.pop();
                    if (prevHealth < health) {
                        health--;
                    }
                } else {
                    break;
                }
            } else {
                break;
            }
        }

        stk.push({position, health, index});
    }

    vector<int> finalHealths;
    while (!stk.empty()) {
        finalHealths.push_back(stk.top().health);
        stk.pop();
    }

    // Reverse the order to match the original indices
    reverse(finalHealths.begin(), finalHealths.end());

    return finalHealths;
}

int main() {
    vector<int> positions = {3,5,2,6};
    vector<int> healths = {10,10,15,12};
    string directions = "RLRL";

    vector<int> finalHealths = survivingRobots(positions, healths, directions);

    for (int health : finalHealths) {
        cout << health << " ";
    }
    cout << endl;

    return 0;
}