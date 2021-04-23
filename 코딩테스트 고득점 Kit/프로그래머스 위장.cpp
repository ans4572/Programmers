#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m;

    for (int i = 0; i < clothes.size(); ++i) {
        if (m.find(clothes[i][1]) == m.end()) 
            m.insert(make_pair(clothes[i][1], 1));
        else
            m[clothes[i][1]]++;
    }

    int answer = 1;

    for (auto i = m.begin(); i != m.end(); ++i) {
        answer *= (i->second + 1);
    }

    return answer - 1;
}