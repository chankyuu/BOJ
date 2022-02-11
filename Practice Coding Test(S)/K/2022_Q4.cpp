#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> lion(11);
vector<int> appeach;
vector<int> comp;
int pre = 0;
// 화살 쏘기
void count(int n, int cnt) {
	if (n == 10) {
		lion[n] = cnt;
		// 점수계산
		int result = 0;
		for (int i = 0; i < 11; i++) {
			if (lion[i] > appeach[i]) result += (10 - i);
			else if (appeach[i] != 0) result -= (10 - i);
		}
		if (result <= 0) return;

		if (comp.size() == 0) {
			comp = lion;
			pre = result;
			return;
		}
		if (result > pre) {
			pre = result;
			comp = lion;
			return;
		}
		else if (result == pre) {
			for (int i = 10; i >= 0; i--) {
				if (comp[i] < lion[i]) {
					comp = lion;
					return;
				}
				else if (comp[i] > lion[i]) return;
			}
		}
		return;
	}

	for (int i = 0; i <= cnt; i++) {
		lion[n] = i;
		count(n + 1, cnt - i);
	}
}
vector<int> solution(int n, vector<int> info) {
	vector<int> answer;

	appeach = info;
	count(0, n);

	if (comp.size() == 0) answer.push_back(-1);
	else answer = comp;
	return answer;
}
