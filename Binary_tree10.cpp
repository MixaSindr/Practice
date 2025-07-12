#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;


vector<string> getNeighbors(string s) {
    vector<string> res;
    for (int i = 0; i < 4; i++) {
        string next1 = s;
        if (next1[i] == '9') next1[i] = '0';
        else next1[i] += 1;
        res.push_back(next1);

        string next2 = s;
        if (next2[i] == '0') next2[i] = '9';
        else next2[i] -= 1;
        res.push_back(next2);
    }
    return res;
}


int openLock(vector<string>& deadends, string target) {
    unordered_set<string> deadSet(deadends.begin(), deadends.end());
    string start = "0000";
    if (deadSet.find(start) != deadSet.end()) {
        return -1;
    }

    queue<pair<string, int>> q;
    unordered_set<string> visited;
    visited.insert(start);
    q.push({ start, 0 });

    while (!q.empty()) {
        string current = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (current == target) {
            return steps;
        }

        vector<string> neighbors = getNeighbors(current);
        for (string neighbor : neighbors) {
            if (visited.find(neighbor) == visited.end() &&
                deadSet.find(neighbor) == deadSet.end()) {
                visited.insert(neighbor);
                q.push({ neighbor, steps + 1 });
            }
        }
    }
    return -1;
}

int main() {
    string target;
    int k;
    cin >> target; // Целевая комбинация
    cin >> k;      // Количество тупиков

    vector<string> deadends(k);
    for (int i = 0; i < k; i++) {
        cin >> deadends[i];
    }

    cout << openLock(deadends, target) << endl;
    return 0;
}