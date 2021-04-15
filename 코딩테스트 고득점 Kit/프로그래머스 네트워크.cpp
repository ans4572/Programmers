#include <string>
#include <vector>
#include <iostream>

using namespace std;

int parent[201];

int Find(int x) {
    if (parent[x] == x)
        return x;
    else
        return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    parent[y] = x;
}

int solution(int n, vector<vector<int>> computers) {
    for (int i = 0; i < 201; ++i)
        parent[i] = i;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            if (computers[i][j] == 1)
                Union(i, j);
        }
    }

    int answer = n;
    for (int i = 0; i < n; ++i) {
        if (parent[i] != i)
            answer--;
    }

    for (int i = 0; i < n; ++i) {
        cout << parent[i] << " ";
    }
    cout << endl;

    return answer;
}

int main() {
    cout << solution(3, { {1, 1, 0} ,{1, 1, 0},{0, 0, 1} });
}