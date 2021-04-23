#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int> > pq (scoville.begin(), scoville.end());
    
    int answer = 0;

    while (pq.top() < K) {
        if (pq.size() == 1)
            return answer = -1;
        int a = pq.top();
        pq.pop();
        pq.push(a + pq.top() * 2);
        pq.pop();

        answer++;
    }
    
    return answer;
}

int main() {
    solution({ 1, 2, 3, 9, 10, 12 }, 7);
}