#include <bits/stdc++.h>

using namespace std;

string tmp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tmp;
	int i = 0;
	while(i < tmp.size()){
		char cur = tmp[i];

		if (cur == '1') {
			if (i + 3 >= tmp.size() || !(tmp[i + 1] == '0' && tmp[i + 2] == '0')) {
				cout << "NOISE";
				return 0;
			}
			i++;
			while (tmp[i] == '0' && i < tmp.size()) i++;
			if (i >= tmp.size()) {
				cout << "NOISE";
				return 0;
			}
			i++
			while (i < tmp.size() && tmp[i] == '1') {
				if (i + 2 < tmp.size() && tmp[i + 1] == '0' && tmp[i + 2] == '0') break;
				i++;
			}
		}
		else {
			if (i + 1 >= tmp.size() || tmp[i + 1] != '1') {
				cout << "NOISE";
				return 0;
			}
			i += 2;
		}
	}
	cout << "SUBMARINE";
	return 0;
}
// Á¤±ÔÇ¥Çö½Ä »ç¿ë
//#include <iostream>
//#include <string>
//#include <regex>
//using namespace std;
//
//int main() {
//	string str;
//	cin >> str;
//	string ptn = "(100+1+|01)+";
//	if (regex_match(str, regex(ptn))) cout << "SUBMARINE";
//	else cout << "NOISE";
//	return 0;
//}
