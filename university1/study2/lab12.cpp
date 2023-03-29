#include <iostream>
#include <vector>
#include <set>
#include <fstream>

using namespace std;

 main() {

	setlocale(LC_ALL, "rus");
	ifstream IN;
	IN.open("IN.txt");
	int N, L;
	IN >> N >> L;
	vector<vector<bool>> circuit(N);
	for (int i = 0; i < N; i++) {
		char t;
		circuit[i].resize(L);
		for (int j = 0; j < L; j++) {
			IN >> t;
			circuit[i][j] = (t == '1' ? 1 : 0);
		}
	}
	int K;
	IN >> K;
	vector<int>board(N);
	for (int i = 0; i < K; i++) {
		int c;
		IN >> c;
		for (int j = 0; j < c; j++) {
			int t;
			IN >> t;
			board[t - 1] = i;
		}
	}

	IN.close();

	int count = 0;
	for (int i = 0; i < L; i++) {
		set<int> temp;
		for (int j = 0; j < N; j++)
			if (circuit[j][i] == 1) temp.insert(board[j]);
		if (temp.size() > 1)count++;
	}
	cout << "Кол-во цепей в разрезе: " << count << endl;

	set<int>lock;
	bool f = 1;
	do {
		int min = 0, min_xy = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				int c1 = 0, c2 = 0;

				for (int k = 0; k < L; k++) {
					set<int> temp;
					for (int m = 0; m < N; m++)
						if (circuit[m][k] == 1) temp.insert(board[m]);
					if (temp.size() > 1)c1++;
				}

				swap(board[i], board[j]);
				for (int k = 0; k < L; k++) {
					set<int> temp;
					for (int m = 0; m < N; m++)
						if (circuit[m][k] == 1) temp.insert(board[m]);
					if (temp.size() > 1)c2++;
				}

				swap(board[i], board[j]);
				if ((lock.find(c1) == lock.end()) && (lock.find(c2) == lock.end()) && ((c2 - c1) < min)) {
					min = c2 - c1;
					min_xy = j + N * i;
				}
			}
		}
		if (min < 0) {
			swap(board[min_xy / N], board[min_xy % N]);
			lock.insert(min_xy / N);
			lock.insert(min_xy % N);
		}
		else f = 0;
	} while ((lock.size() < N) && f);

	for (int i = 0; i < K; i++) {
		cout << "Плата " << i + 1 << ": ";
		for (int j = 0; j < N; j++) {
			if (board[j] == i)cout << j + 1 << " ";
		}
		cout << "\n";
	}
	system("pause");
}
