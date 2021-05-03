#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[20001];

int solution(int n, vector<vector<int>> edge) {
    for (int i = 0; i < edge.size(); ++i) {
        vec[edge[i][0]].push_back(edge[i][1]);
        vec[edge[i][1]].push_back(edge[i][0]);
    }

    vector<pair<int,bool> > visit(n + 1);

    queue<int> q;
    q.push(1);
    visit[1].first = 0;
    visit[1].second = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < vec[now].size(); ++i) {
            int next = vec[now][i];
            if (!visit[next].second) {
                visit[next].first = visit[now].first + 1;
                visit[next].second = true;
                q.push(next);
            }
        }
    }

    int max = 0, answer = 0;
    for (int i = 1; i <= n; ++i) {
        if (max < visit[i].first) {
            max = visit[i].first;
            answer = 1;
        }
        else if (max == visit[i].first)
            answer++;
    }

    return answer;
}