#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;

#define	min(a, b) (a < b ? a : b)

class proc {
public:
	string	name;
	long	time;
};

typedef	vector<proc>	queue_t;

void 
enqueue(queue_t &q, proc &p)
{
	q.push_back(p);
}

proc
dequeue(queue_t &q)
{
	proc	p = q[0];
	q.erase(q.begin());
	return (p);
}

bool
is_empty(const queue_t &q)
{
	return (q.size() == 0);
}

void
dispatch(const long slice, queue_t &q)
{
	proc	p;
	long	quota, time = 0;
	while (is_empty(q) == false) {
		p = dequeue(q);
		quota = min(p.time, slice);
		time += quota;
		if (p.time == quota) {
			cout << p.name << " " << time << endl;
		} else {
			p.time -= quota;
			enqueue(q, p);
		}
	}
}

int
main()
{
	long			n, slice;
	cin >> n;
	cin >> slice;
	long			i;
	char			buf[1024];
	queue_t			q;
	proc			p;
	for (i = 0; i < n; i++) {
		cin >> buf;
		p.name = buf;
		cin >> p.time;
		enqueue(q, p);
	}
	dispatch(slice, q);
	return (0);
}

