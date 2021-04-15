#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int size = progresses.size();
    vector<int> answer;
    vector<int> complete(size);

    for (int i = 0; i < size; ++i) {
        int remain = 100 - progresses[i];
        complete[i] = (remain % speeds[i]) > 0 ? (remain / speeds[i]) + 1 : (remain / speeds[i]);
        //cout << complete[i] << " ";
    }
    queue<int> queue;

    for (int i = 0; i < size; ++i) {
        if (!queue.empty() && complete[queue.front()] < complete[i]) {
            answer.push_back(queue.size());
            while (!queue.empty()) 
                queue.pop();
        }   
        queue.push(i);
    }

    answer.push_back(queue.size());

    for (int i = 0; i < answer.size(); ++i) {
        cout << answer[i] << " ";
    }

    return answer;
}

int main() {

    solution({ 95,95,95,95,95 }, { 4,5,4,5,4});
}