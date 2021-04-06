#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a;
	stack<string> tmp;
	int sum = 0;
	int count = 0;
	int result = 1;
	string idx;

	cin >> a;

	for (int i = 0; i < a.length(); i++) {
		idx = a.at(i);
		if (idx == "(" || idx == "[") tmp.push(idx);
		else { // 닫는 괄호가 들어올 때
			sum = 1;

			while (!tmp.empty() && tmp.top() != "(" && tmp.top() != "[") {   // 스택의 탑이 숫자일 때
				sum *= stoi(tmp.top());
				tmp.pop();
			}

			if (tmp.empty() || (tmp.top() != "(" && idx == ")") || (tmp.top() != "[" && idx == "]")) {
				result = 0;
				break;
			}

			if (idx == ")") sum *= 2;
			else sum *= 3;

			tmp.pop();

			while (!tmp.empty() && tmp.top() != "(" && tmp.top() != "[") {
				sum += stoi(tmp.top());
				tmp.pop();
			}

			tmp.push(to_string(sum));
		}
	}
	if (result == 0 || tmp.size() != 1 || tmp.top() == "(" || tmp.top() == "[") {
		cout << "0";
	}
	else
		cout << tmp.top();

	return 0;
}