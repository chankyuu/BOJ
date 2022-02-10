#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	map<string, int> s2i;
	int n = id_list.size();
	set<int> s[1002];
	vector<int> cnt(n);

	for (int i = 0; i < n; i++) s2i[id_list[i]] = i;

	for (auto& rep : report) {
		stringstream st(rep);
		string id1, id2;
		st >> id1 >> id2;
		s[s2i[id2]].insert(s2i[id1]);
	}

	for (int i = 0; i < n; i++) {
		if (s[i].size() < k) continue;
		for (auto x : s[i]) cnt[x]++;
	}

	return cnt;
}