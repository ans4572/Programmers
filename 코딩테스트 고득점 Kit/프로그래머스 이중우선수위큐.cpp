#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    deque<int> dq;

    for (auto iter : operations) {
        if (iter[0] == 'I') {
            dq.push_back(stoi(iter.substr(2, iter.length())));
            sort(dq.begin(), dq.end());
        }
        else {
            if (dq.empty()) continue;
            if (iter[2] == '-')
                dq.pop_front();
            else
                dq.pop_back();
        }
    }

    vector<int> answer;

    if (dq.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    
    return answer;
}