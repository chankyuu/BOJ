#include <bits/stdc++.h>
using namespace std;

void func(int n, int cnt) {
	if (n == 0) 	return;

	if (n == cnt) cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << "\n";

	for (int i = 0; i < 4 * (cnt - n); i++) cout << "_";
	cout << "\"����Լ��� ������?\"" << "\n";
	for (int i = 0; i < 4 * (cnt - n); i++) cout << "_";
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << "\n";
	for (int i = 0; i < 4 * (cnt - n); i++) cout << "_";
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << "\n";
	for (int i = 0; i < 4 * (cnt - n); i++) cout << "_";
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << "\n";

	if (n == 1) {
		for (int i = 0; i < 4 * cnt; i++) cout << "_";
		cout << "\"����Լ��� ������?\"" << "\n";
		for (int i = 0; i < 4 * cnt; i++) cout << "_";
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << "\n";
		for (int i = 0; i < 4 * cnt; i++) cout << "_";
		cout << "��� �亯�Ͽ���." << "\n";
	}
	func(n - 1, cnt);
	for (int i = 0; i < 4 * (cnt - n); i++) cout << "_";
	cout << "��� �亯�Ͽ���." << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	func(n, n);

	return 0;
}
