#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string name) {
	int size = name.length();

	int answer = 0;
	int left = 0, right = 0, half_left = 0, half_right = 0;

	answer = name[0] < 78 ? name[0] - 'A' : 'Z' -name[0] + 1;

	for (int i = 1; i < size; ++i) {
		answer += name[i] < 78 ? name[i] - 'A' : 'Z' - name[i] + 1;

		if (name[i] != 'A') {
			right = i;
			if (i <= size / 2)
				half_right = i;
		}

		if (name[size - i] != 'A') {
			left = i;
			if (size - i > size / 2)
				half_left = i;
		}
	}

	answer += min(left, min(right, min(half_left * 2 + half_right, half_right * 2 + half_left)));

	cout << answer << endl;

	return answer;
}

int main() {
	solution("ABBAAAB");
}