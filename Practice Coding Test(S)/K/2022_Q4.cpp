#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//vector<int> lion(11);
//vector<int> appeach;
//vector<int> comp;
int result = 0;
// 화살 쏘기(백트래킹)
//void count(int n, int cnt) {
//	if (n == 10) {
//		lion[n] = cnt;
//		// 점수계산
//		int result = 0;
//		for (int i = 0; i < 11; i++) {
//			if (lion[i] > appeach[i]) result += (10 - i);
//			else if (appeach[i] != 0) result -= (10 - i);
//		}
//		if (result <= 0) return;
//
//		if (comp.size() == 0) {
//			comp = lion;
//			pre = result;
//			return;
//		}
//		if (result > pre) {
//			pre = result;
//			comp = lion;
//			return;
//		}
//		else if (result == pre) {
//			for (int i = 10; i >= 0; i--) {
//				if (comp[i] < lion[i]) {
//					comp = lion;
//					return;
//				}
//				else if (comp[i] > lion[i]) return;
//			}
//		}
//		return;
//	}
//
//	for (int i = 0; i <= cnt; i++) {
//		lion[n] = i;
//		count(n + 1, cnt - i);
//	}
//}
vector<int> solution(int n, vector<int> info) {
	vector<int> answer;

	// 백트래킹(count 함수 이용)
	//count(0, n); 

	// next_permutation 이용
	vector<int> lion(11, -1);
	vector<int> brute(n + 10);

	fill(brute.begin() + n, brute.end(), 1);

	do {
		vector<int> arrow;
		int pre = -1;
		for (int i = 0; i < n + 10; i++) {
			if (brute[i] == 1) {
				arrow.push_back(i - pre - 1);
				pre = i;
			}
		}
		arrow.push_back(n + 10 - pre - 1);
		int score = 0;
		for (int i = 0; i < 11; i++) {
			if (arrow[i] > info[i]) score += (10 - i);
			else if (info[i] != 0) score -= (10 - i);
		}
		if (score <= 0) continue;

		if (score > result) {
			lion = arrow;
			result = score;
		}
		else if (score == result) {
			for (int i = 10; i >= 0; i--) {
				if (lion[i] < arrow[i]) {
					lion = arrow;
					break;
				}
				else if (lion[i] > arrow[i]) break;
			}
		}
	} while (next_permutation(brute.begin(), brute.end()));

	if (result == 0) answer.push_back(-1);
	else answer = lion;
	return answer;
}
