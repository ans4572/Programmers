#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int size = jobs.size();
    sort(jobs.begin(), jobs.end());  //����

    //ť�� �� �� �۾��� �ð��� �������� �ڵ����� �����ϵ��� �켱 ���� ť ��� 
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >> pq;

    int time = 0, answer = 0, compNum = 0;
    int index = 0;
    vector<bool> complete(size);

    //�Ϸ� ������ ������ ������ �ݺ�
    while (compNum < size) {
        for (int i = index; i < size; ++i) {
            if (!complete[i] && jobs[i][0] <= time) {
                pq.push(make_pair(jobs[i][1], i));
                complete[i] = true;
                index++;
            }
            //���� ���� �ð��� ���� time���� �� ū ���
            else if (!complete[i] && jobs[i][0] > time)
                break;
        }

        //pq�� ��������� �ð��� ���� ���� �ð����� ����
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