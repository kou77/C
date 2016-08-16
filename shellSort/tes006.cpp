#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdbool.h>
#include <vector>
#include <iostream>
using namespace std;

#define	MAX_ARY_SIZ	100

void
trace(int A[], int N)
{
	cout << A[0];
	for (int i = 1; i < N; i++) cout << " " << A[i];
	cout << endl;
}

int
InsertSort(int A[], int N, int G, int cnt)
{
	int	i, v, j;
	for (i = G; i < N; i++) {
		v = A[i];
		j = i - G;
		while (j >= 0 && A[j] > v) {
			A[j + G] = A[j];
			j = j - G;
			cnt++;
		}
		A[j + G] = v;
		trace(A, N);
	}
	return (cnt);
}

int
ShellSort(int A[], int N)
{
	vector<int>	G;
	for (int h = 1;;) {
		if (h > N) break;
		G.push_back(h);
		h = h * 3 + 1;
	}
	//cout << "G.sieze()=" << G.size() << endl;
	//cout << G.size() - 2 << endl;
	cout << G[G.size() - 1];
	for (int i = G.size() - 2; i >= 0; i--) cout << " " << G[i];
	cout << endl;
	int	cnt = 0;
	for (int i = G.size() - 1; i >= 0; i--) cnt = InsertSort(A, N, G[i], cnt);
	return (cnt);
}

int
main()
{
	int	N, A[MAX_ARY_SIZ], i;
	cin >> N;
	for (i = 0; i < N; i++) cin >> A[i];

	trace(A, N);
	int	cnt = ShellSort(A, N);
	cout << "cnt=" << cnt << endl;
	trace(A, N);
	return (0);
}

