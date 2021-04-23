#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

bool changePossible(string a, string b) {
    int count = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i])
            count++;
    }

    if (count >= 2) return false;
    else return true;
}

int solution(string begin, string target, vector<string> words) {
    if (find(words.begin(), words.end(), target) == words.end()) {
        return 0;
    }

    vector<bool> visit(words.size(), false);
    queue<pair<string,int> > queue;
    queue.push(make_pair(begin, 0));
    
    while (!queue.empty()) {
        pair<string, int> now = queue.front();

        queue.pop();

        for (int i = 0; i < words.size(); ++i) {
            if (!visit[i] && changePossible(now.first, words[i])) {
                if (words[i] == target) {
                    return now.second + 1;
                }
                queue.push(make_pair(words[i], now.second + 1));
                visit[i] = true;
            }
        }
    }

    return 0;
}

int main() {
    cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
}