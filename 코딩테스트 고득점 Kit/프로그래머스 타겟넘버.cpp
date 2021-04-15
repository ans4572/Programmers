#include <string>
#include <vector>

using namespace std;

int ans = 0;

void DFS(vector<int> &numbers, int index, int sum, int &target) {
    if (index == numbers.size()) {
        if (sum == target)
            ans++;
    }
    else {
        DFS(numbers, index + 1, sum + numbers[index],target);
        DFS(numbers, index + 1, sum - numbers[index],target);
    }

    return;
}

int solution(vector<int> numbers, int target) {
    DFS(numbers, 0, 0, target);

    int answer = ans;

    return answer;
}