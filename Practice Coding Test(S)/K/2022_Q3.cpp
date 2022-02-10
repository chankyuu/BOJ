#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;


vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;
	int car[10000];
	int tmp[10000];

	fill(tmp, tmp + 10000, -1);

	for (int i = 0; i < records.size(); i++) {
		stringstream st(records[i]);
		string s_num, time, board;
		st >> time >> s_num >> board;

		int t = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
		int num = stoi(s_num);

		if (board == "IN")
			tmp[num] = t;
		else {
			car[num] += t - tmp[num];
			tmp[num] = -1;
		}
	}

	for (int i = 0; i < 10000; i++) {
		if (tmp[i] != -1) {
			car[i] += (23 * 60 + 59) - tmp[i];
		}
	}
	for (int i = 0; i < 10000; i++) {
		if (car[i] == 0) continue;
		if (car[i] <= fees[0]) {
			answer.push_back(fees[1]);
			continue;
		}
		int m = (car[i] - fees[0] + fees[2] - 1) / fees[2];

		answer.push_back(fees[1] + m * fees[3]);
	}
	return answer;
}