#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int size = jobs.size();
    sort(jobs.begin(), jobs.end());  //정렬

    //큐에 들어갈 때 작업의 시간을 기준으로 자동으로 정렬하도록 우선 순위 큐 사용 
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >> pq;

    int time = 0, answer = 0, compNum = 0;
    int index = 0;
    vector<bool> complete(size);

    //완료 개수를 만족할 때까지 반복
    while (compNum < size) {
        for (int i = index; i < size; ++i) {
            if (!complete[i] && jobs[i][0] <= time) {
                pq.push(make_pair(jobs[i][1], i));
                complete[i] = true;
                index++;
            }
            //다음 들어올 시간이 현재 time보다 더 큰 경우
            else if (!complete[i] && jobs[i][0] > time)
                break;
        }

        //pq가 비어있으면 시간을 다음 들어올 시간으로 변경
        if (pq.empty()) {
            time = jobs[index][0];
            continue;
        }
        
        answer += (time - jobs[pq.top().second][0] + pq.top().first);
        time += pq.top().first;
        pq.pop();
        compNum++;
    }
    
    return answer / size;
}

int main() {
    cout << solution({ {0,5} ,{2,10},{1000000000, 2} });
}