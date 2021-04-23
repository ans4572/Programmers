#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> answer;

void DFS(int idx, string depart, vector<vector<string>>& tickets, vector<string> list, vector<bool>& use) {
	if (idx == tickets.size()) {
		if (answer.size() == 0) {
			answer = list;
		}
		else {
			for (int i = 0; i < answer.size(); ++i) {
				if (answer[i].compare(list[i]) == 0)
					continue;
				else if (answer[i].compare(list[i]) < 0) break;
				else{
					answer = list;
					break;
				}
			}
		}
	}
	else {
		for (int i = 0; i < tickets.size(); ++i) {
			if (!use[i] && depart == tickets[i][0]) {
				use[i] = true;
				list.push_back(tickets[i][1]);
				DFS(idx + 1, tickets[i][1], tickets, list, use);
				list.pop_back();
				use[i] = false;
			}
		}
	}

	return;
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<bool> use(tickets.size(), false);

	DFS(0, "ICN", tickets, { "ICN" }, use);

	return answer;
}

int main() {
	solution({ { "ICN", "SFO" },
			   { "ICN", "ATL" },
			   { "SFO", "ATL" },
			   {"ATL", "ICN"},
			   {"ATL", "SFO"} });
}
