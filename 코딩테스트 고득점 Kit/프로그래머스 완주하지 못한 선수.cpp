#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> m;

    for (int i = 0; i < participant.size(); ++i) {
        if (m.count(participant[i]) == 0) {
            m.insert(make_pair(participant[i],1));
        }
        else
            m[participant[i]]++;
    }

    for (int i = 0; i < completion.size(); ++i) {
        m[completion[i]]--;
    }

    string answer;

    for (auto iter = m.begin(); iter != m.end(); ++iter) {
        if (iter->second > 0) {
            answer = iter->first;
            break;
        }
    }
    
    return answer;
}

int main() {

    solution({ "leo", "kiki", "eden" }, { "eden", "kiki" });
}