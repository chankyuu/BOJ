// ��ȭ�� ���1
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int N;
//int stair[302];
//int D[302][3];
//int main(void) {
//	ios::sync_with_stdio(0);
//	cin.tie();
//	
//	cin >> N;
//	for (int i = 1; i <= N; i++) cin >> stair[i];
//
//	// D[i][j] = j���� ����� �����ؼ� ��Ұ�, i��° ����� ���� �� ���� �� �ִ� ������ �ִ�(��,  i��° ����� �ݵ�� ��ƾ���)
//	D[1][1] = stair[1];
//	D[1][2] = 0;
//	D[2][1] = stair[2];
//	D[2][2] = D[1][1] + stair[2];
//
//	for (int i = 3; i <= N; i++) {
//		D[i][1] = max(D[i - 2][1] + stair[i], D[i - 2][2] + stair[i]);
//		D[i][2] = D[i - 1][1] + stair[i];
//	}
//	cout << max(D[N][1], D[N][2]);
//	return 0;
//}

// ��ȭ�� ���2
#include <bits/stdc++.h>

using namespace std;

int N;
int stair[302];
int D[302];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie();

	int sum = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> stair[i];
		sum += stair[i];
	}
	// D[i] = i��° ��ܱ��� �ö��� �� ���� ���� ����� ���� �ּڰ�
	// ��, i��° ����� �ݵ�� ���� ���� ������� �����ؾ� ��
	D[1] = stair[1];
	D[2] = stair[2];
	D[3] = stair[3];
	for (int i = 4; i <= N; i++) {
		D[i] = min(D[i - 2] + stair[i], D[i - 3] + stair[i]);
	}

	cout << sum - min(D[N - 1], D[N - 2]);
	return 0;
}