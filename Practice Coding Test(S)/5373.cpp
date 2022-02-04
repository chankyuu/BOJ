#include <bits/stdc++.h>

using namespace std;

int T, N;
//(ÀÎµ¦½º) 0 : À­¸é, 1 : ¾Æ·§¸é, 2 : ¾Õ¸é, 3 : µÞ¸é, 4 : ¿ÞÂÊ¸é, 5 : ¿À¸¥ÂÊ ¸é
int cube[6][3][3] = { { {1, 1, 1 }, {1, 1, 1}, {1, 1, 1}},
								{{2, 2, 2}, {2, 2, 2}, {2, 2, 2 }},
								{{3, 3, 3}, { 3, 3, 3}, {3, 3, 3}},
								{{4, 4, 4}, {4, 4, 4}, {4, 4, 4}},
								{{5, 5, 5}, {5, 5, 5}, {5, 5, 5}},
								{{6, 6, 6}, {6, 6, 6}, {6, 6, 6} } };
// Å¥ºê µ¹¸®±â
void rollCube(char side, char slide) {
	int tmp[6][3][3];
	for (int i = 0; i < 6; i++) for (int j = 0; j < 3; j++) for (int k = 0; k < 3; k++) tmp[i][j][k] = cube[i][j][k];
	int idx = 0;

	if (side == 'U') {
		idx = 0;
		if (slide == '+') {
			for (int i = 0; i < 3; i++) cube[2][0][i] = tmp[5][0][i];
			for (int i = 0; i < 3; i++) cube[4][0][i] = tmp[2][0][i];
			for (int i = 0; i < 3; i++) cube[3][0][2 - i] = tmp[4][0][i];
			for (int i = 0; i < 3; i++) cube[5][0][i] = tmp[3][0][2 - i];
		}
		else {
			for (int i = 0; i < 3; i++) cube[5][0][i] = tmp[2][0][i];
			for (int i = 0; i < 3; i++) cube[2][0][i] = tmp[4][0][i];
			for (int i = 0; i < 3; i++) cube[4][0][i] = tmp[3][0][2 - i];
			for (int i = 0; i < 3; i++) cube[3][0][2 - i] = tmp[5][0][i];
		}
	}
	else if (side == 'D') {
		idx = 1;
		if (slide == '+') {
			for (int i = 0; i < 3; i++) cube[5][2][i] = tmp[2][2][i];
			for (int i = 0; i < 3; i++) cube[2][2][i] = tmp[4][2][i];
			for (int i = 0; i < 3; i++) cube[4][2][i] = tmp[3][2][2 - i];
			for (int i = 0; i < 3; i++) cube[3][2][2 - i] = tmp[5][2][i];
		}
		else {
			for (int i = 0; i < 3; i++) cube[2][2][i] = tmp[5][2][i];
			for (int i = 0; i < 3; i++) cube[4][2][i] = tmp[2][2][i];
			for (int i = 0; i < 3; i++) cube[3][2][2 - i] = tmp[4][2][i];
			for (int i = 0; i < 3; i++) cube[5][2][i] = tmp[3][2][2 - i];
		}
		if (slide == '+') slide = '-';
		else slide = '+';
	}
	else if (side == 'F') {
		idx = 2;
		if (slide == '+') {
			for (int i = 0; i < 3; i++) cube[5][i][0] = tmp[0][2][i];
			for (int i = 0; i < 3; i++) cube[1][2][2 - i] = tmp[5][i][0];
			for (int i = 0; i < 3; i++) cube[4][i][2] = tmp[1][2][i];
			for (int i = 0; i < 3; i++) cube[0][2][i] = tmp[4][2 - i][2];
		}
		else {
			for (int i = 0; i < 3; i++) cube[0][2][i] = tmp[5][i][0];
			for (int i = 0; i < 3; i++) cube[5][i][0] = tmp[1][2][2 - i];
			for (int i = 0; i < 3; i++) cube[1][2][i] = tmp[4][i][2];
			for (int i = 0; i < 3; i++) cube[4][2 - i][2] = tmp[0][2][i];
		}
	}
	else if (side == 'B') {
		idx = 3;
		if (slide == '+') {
			for (int i = 0; i < 3; i++) cube[0][0][i] = tmp[5][i][2];
			for (int i = 0; i < 3; i++) cube[5][i][2] = tmp[1][0][2 - i];
			for (int i = 0; i < 3; i++) cube[1][0][i] = tmp[4][i][0];
			for (int i = 0; i < 3; i++) cube[4][i][0] = tmp[0][0][2 - i];
		}
		else {
			for (int i = 0; i < 3; i++) cube[5][i][2] = tmp[0][0][i];
			for (int i = 0; i < 3; i++) cube[1][0][2 - i] = tmp[5][i][2];
			for (int i = 0; i < 3; i++) cube[4][i][0] = tmp[1][0][i];
			for (int i = 0; i < 3; i++) cube[0][0][2 - i] = tmp[4][i][0];
		}
		if (slide == '+') slide = '-';
		else slide = '+';
	}
	else if (side == 'L') {
		idx = 4;
		if (slide == '+') {
			for (int i = 0; i < 3; i++) cube[2][i][0] = tmp[0][i][0];
			for (int i = 0; i < 3; i++) cube[1][2 - i][0] = tmp[2][i][0];
			for (int i = 0; i < 3; i++) cube[3][i][0] = tmp[1][i][0];
			for (int i = 0; i < 3; i++) cube[0][i][0] = tmp[3][2 - i][0];
		}
		else {
			for (int i = 0; i < 3; i++) cube[0][i][0] = tmp[2][i][0];
			for (int i = 0; i < 3; i++) cube[2][i][0] = tmp[1][2 - i][0];
			for (int i = 0; i < 3; i++) cube[1][i][0] = tmp[3][i][0];
			for (int i = 0; i < 3; i++) cube[3][2 - i][0] = tmp[0][i][0];
		}
	}
	else {
		idx = 5;
		if (slide == '+') {
			for (int i = 0; i < 3; i++) cube[0][i][2] = tmp[2][i][2];
			for (int i = 0; i < 3; i++) cube[2][i][2] = tmp[1][2 - i][2];
			for (int i = 0; i < 3; i++) cube[1][i][2] = tmp[3][i][2];
			for (int i = 0; i < 3; i++) cube[3][2 - i][2] = tmp[0][i][2];
		}
		else {
			for (int i = 0; i < 3; i++) cube[2][i][2] = tmp[0][i][2];
			for (int i = 0; i < 3; i++) cube[1][2 - i][2] = tmp[2][i][2];
			for (int i = 0; i < 3; i++) cube[3][i][2] = tmp[1][i][2];
			for (int i = 0; i < 3; i++) cube[0][i][2] = tmp[3][2 - i][2];
		}
	}

	if (slide == '+') for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) cube[idx][i][j] = tmp[idx][2 - j][i];
	else 	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) cube[idx][i][j] = tmp[idx][j][2 - i];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--) {
		int c = 1;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					cube[i][j][k] = c;
				}
			}
			c++;
		}
		cin >> N;
		while (N--) {
			char side, slide;
			cin >> side >> slide;
			rollCube(side, slide);
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				switch (cube[0][i][j]) {
				case 1:
					cout << "w";
					break;
				case 2:
					cout << "y";
					break;
				case 3:
					cout << "r";
					break;
				case 4:
					cout << "o";
					break;
				case 5:
					cout << "g";
					break;
				case 6:
					cout << "b";
					break;
				}
			}
			cout << "\n";
		}
	}
	return 0;
}
