#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const int MAX_NUM = 32001;

vector<int> dy;
vector<int> vec;

void DFS(int N, int now) {
	if (dy[now] >= 8)
		return;

	for (int i = 0; i < vec.size(); ++i) {
		if (dy[now] + dy[vec[i]] > 8)
			continue;

		if (now + vec[i] < MAX_NUM && dy[now + vec[i]] > dy[now] + dy[vec[i]]) {
			dy[now + vec[i]] = dy[now] + dy[vec[i]];
			vec.push_back(now + vec[i]);

			if(dy[now + vec[i]] < 8)
				DFS(N, now + vec[i]);
		}
		if (now - vec[i] >= 0 && dy[now - vec[i]] > dy[now] + dy[vec[i]]) {
			dy[now - vec[i]] = dy[now] + dy[vec[i]];
			vec.push_back(now - vec[i]);

			if (dy[now - vec[i]] < 8)
				DFS(N, now - vec[i]);
		}
		if (vec[i] - now >= 0 && dy[vec[i] - now] > dy[now] + dy[vec[i]]) {
			dy[vec[i] - now] = dy[now] + dy[vec[i]];
			vec.push_back(vec[i] - now);

			if (dy[vec[i] - now] < 8)
				DFS(N, vec[i] - now);
		}
		if (now * vec[i] < MAX_NUM && dy[now * vec[i]] > dy[now] + dy[vec[i]]) {
			dy[now * vec[i]] = dy[now] + dy[vec[i]];
			vec.push_back(now * vec[i]);

			if (dy[now * vec[i]] < 8)
				DFS(N, now * vec[i]);
		}
		if (vec[i] > 0 && dy[now / vec[i]] > dy[now] + dy[vec[i]]) {
			dy[now / vec[i]] = dy[now] + dy[vec[i]];
			vec.push_back(now / vec[i]);

			if (dy[now / vec[i]] < 8)
				DFS(N, now / vec[i]);
		}
		if (now > 0 && dy[vec[i] / now] > dy[now] + dy[vec[i]]) {
			dy[vec[i] / now] = dy[now] + dy[vec[i]];
			vec.push_back(vec[i] / now);

			if (dy[vec[i] / now] < 8)
				DFS(N, vec[i] / now);
		}
	}
}

int solution(int N, int number) {
	dy.resize(MAX_NUM, 100);

	int temp = 0;
	for (int i = 0; i < 4; ++i) {
		temp += N * pow(10, i);
		dy[temp] = i + 1;
		vec.push_back(temp);
	}
	if (N <= 2) {
		dy[temp + N * pow(10, 4)] = 5;
		vec.push_back(temp + N * pow(10, 4));
	}

	DFS(N, N);
	
	if (dy[number] > 8)
		return -1;
	else
		return dy[number];
}

int main() {
	cout << solution(3, 2) << endl;
}