#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
	deque<pair<int, int> > dq;

	for (int i = 0; i < priorities.size(); ++i)
		dq.push_back(make_pair(i, priorities[i]));

	int answer = 0;

	while (!dq.empty()) {
		int maxIndex = 0;
		int maxP = dq.front().second;
		for (int i = 1; i < dq.size(); ++i) {
			if (maxP < dq[i].second) {
				maxP = dq[i].second;
				maxIndex = i;
			}
		}

		for (int i = 0; i < maxIndex; ++i) {
			dq.push_back(dq.front());
			dq.pop_front();
		}

		answer++;
		if (dq.front().first == location) break;
		dq.pop_front();
	}

	return answer;
}

int main() {
	cout << solution({ 1,2,3,1 }, 2);
}