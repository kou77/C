#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;

#define	MAX_ARY_SIZ	100

vector<string>
split(const string &s, const char *d)
{
	vector<string>	v;
	v.clear();
	string::size_type 	o1 = 0, o2;
	while ((o2 = s.find(d, o1)) != string::npos) {
		v.push_back(s.substr(o1, o2-o1));
		o1 = o2+strlen(d);
	}
	v.push_back(s.substr(o1));
	return (v);
}

void
push(vector<int> &s, int v)
{
	s.push_back(v);
}

int
pop(vector<int> &s)
{
	int	v = s.back();
	s.pop_back();
	return (v);
}

#define	eq_ope(o)	(strcmp(ite->c_str(), o) == 0)
#define	cal_ope(o)	{ \
	v1 = pop(stack); \
	v2 = pop(stack); \
	push(stack, v1 o v2); \
}
void
calculator(vector<string> formula)
{
	vector<int>	stack;
	int			v1, v2;
	for (vector<string>::iterator ite = formula.begin();
			ite < formula.end(); ite++) {
		if (eq_ope("+") == true) {
			cal_ope(+)
		} else if (eq_ope("-") == true) {
			cal_ope(-)
		} else if (eq_ope("*") == true) {
			cal_ope(*)
		} else {
			push(stack, atoi(ite->c_str()));
		}
	}
	printf("result=%d\n", stack[0]);
}

int
main()
{
	string	s;
	getline(cin, s);
	vector<string>	formula = split(s, " ");
	for (vector<string>::iterator ite = formula.begin();
			ite < formula.end(); ite++) {
		printf("ite->c_str()=[%s]\n", ite->c_str());
	}
	calculator(formula);
	return (0);
}

