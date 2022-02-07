#include <bits/stdc++.h>

using namespace std;

int N;
int num[12];
int obs[4];
vector<char> tmp;
int minR = 0x7f7f7f7f;
int maxR = 0;

// 연산자 끼워넣기
void back(int cnt) {
	if (cnt == N - 1) {
		int tmp2 = 0;

		for (int i = 0; i < N; i++) {
			if (i == 0) {
				tmp2 = num[i];
				continue;
			}
			int tmp3 = num[i];
			switch (tmp[i - 1]) {
			case '+' :
				tmp2 += tmp3;
				break;
			case '-' :
				tmp2 -= tmp3;
				break;
			case '*' :
				tmp2 *= tmp3;
				break;
			case '/' :
				tmp2 /= tmp3;
				break;
			}
		}
		minR = min(minR, tmp2);
		maxR = max(maxR, tmp2);
		
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (obs[i] <= 0) continue;
		switch (i) {
		case 0 :
			tmp.push_back('+');
			break;
		case 1 :
			tmp.push_back('-');
			break;
		case 2 :
			tmp.push_back('*');
			break;
		case 3 :
			tmp.push_back('/');
			break;
		}
		obs[i] -= 1;

		back(cnt + 1);

		tmp.pop_back();
		obs[i] += 1;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> num[i];
	for (int i = 0; i < 4; i++) cin >> obs[i];

	back(0);
	
	cout << maxR << "\n";
	cout << minR;
	return 0;
}