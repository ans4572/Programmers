#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    stack<int> stack;
    vector<int> answer(prices.size());

    for (int i = 0; i < prices.size(); ++i) {
        while (!stack.empty() && prices[stack.top()] > prices[i]) {
            answer[stack.top()] = i - stack.top();
            stack.pop();
        }
        stack.push(i);
    }

    while (!stack.empty()) {
        answer[stack.top()] = prices.size() - stack.top() - 1;
        stack.pop();
    }

    for (int i = 0; i < answer.size(); ++i) {
        cout<<answer[i]<<" ";
    }

    return answer;
}

int main() {

    solution({5,4,3,2,1});
}