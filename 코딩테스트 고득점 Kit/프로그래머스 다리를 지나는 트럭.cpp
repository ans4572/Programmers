#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	queue<pair<int, int> > q;  //first: index, second: exist time

	int weightSum = truck_weights[0];
	q.push(make_pair(0, 0));
	int answer = 1;
	int index = 1;

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; ++i) {
			pair<int, int> temp = q.front();
			q.pop();
			if ((temp.second + 1) == bridge_length)
				weightSum -= truck_weights[temp.first];
			else
				q.push(make_pair(temp.first, temp.second + 1));
		}

		if (index < truck_weights.size() && (weightSum + truck_weights[index] <= weight)) {
			q.push(make_pair(index, 0));
			weightSum += truck_weights[index];
			index++;
		}

		answer++;
	}

	return answer;
}

int main() {
	cout << solution(2, 10, { 7, 4, 5, 6 });
}
