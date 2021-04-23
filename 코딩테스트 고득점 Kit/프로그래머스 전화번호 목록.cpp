#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	sort(phone_book.begin(), phone_book.end());

	bool answer = true;

	for (int i = 1; i < phone_book.size(); ++i) {
		if (phone_book[i - 1] == phone_book[i].substr(0, phone_book[i - 1].length())) {
			answer = false;
			break;
		}
	}

	return answer;
}

int main() {

	solution({ "119", "97674223", "1195524421" });
}