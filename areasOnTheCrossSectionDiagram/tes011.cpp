#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
using namespace std;

int
main()
{
	char			buf[20000+1];
	cin >> buf;
	/*printf("sizeof(buf)=%ld\n", sizeof(buf));
	printf("strlen(buf)=%ld\n", strlen(buf));*/
	int	sum = 0, total = 0;
	stack<int>		s;
	vector<pair<int, int> >	ans;
	int	p;
	for (int i = 0; i < strlen(buf); i++) {
		if (buf[i] == '\\') {
			s.push(i);
		} else if (buf[i] == '/' && s.size() > 0) {
			p = s.top();
			s.pop();
			sum = i-p;
			total += sum;
			/*if (ans.size() > 0)
				printf("ans.back().first=%d, p=%d\n", ans.back().first, p);*/
			while (ans.size() > 0 && ans.back().first > p) {
				sum += ans.back().second;
				ans.pop_back();
			}
			ans.push_back(make_pair(p, sum));
		}
	}
	cout << total << endl;
	cout << ans.size();
	for (vector<pair<int, int> >::iterator ite = ans.begin(); ite < ans.end();
			ite++) {
		cout << " " << ite->second;
	}
	cout << endl;
	return (0);
}

