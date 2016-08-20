#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define	CMDBUFSIZ	32
#define	BUFSIZ_		32

#define	CMD_I	1
#define	CMD_D	2
#define	CMD_DF	3
#define	CMD_DL	4

typedef	struct list {
	struct	list	*next, *prev;
	long			key;
} list_t;

list_t	*top = NULL;

list_t	listStock[2000000];

#define	insertList(l1, l2)	{ \
	(l2)->next = l1; \
	(l2)->prev = (l1)->prev; \
	(l1)->prev->next = l2; \
	(l1)->prev = l2; \
}

#define	deleteList(l) { \
	(l)->next->prev = (l)->prev; \
	(l)->prev->next = (l)->next; \
}

#define	searchList(l, k) { \
	while ((l)->key != k) { \
		l = (l)->next; \
		assert(l != top); \
	} \
}

#define	linkTopList(l, k) { \
	top = l; \
	(l)->next = l; \
	(l)->prev = l; \
	(l)->key = k; \
}

#define	printList { \
	list_t	*_l = top; \
	printf("%ld", _l->key); \
	_l = _l->next; \
	while (_l != top) { \
		printf(" %ld", _l->key); \
		_l = _l->next; \
	} \
	printf("\n"); \
}

void
cmdProc(long n, long *cmdary)
{
	long	i, si = 0;
	list_t	*lp;
	i = 0;
	for (i = 0; i < n; i++) {
		printf("cmd=%ld, val=%ld\n", cmdary[i*2], cmdary[i*2+1]);
		if (cmdary[i*2] == CMD_I) {
			if (top == NULL) {
				linkTopList(&listStock[si], cmdary[i*2+1]);
			} else {
				listStock[si].key = cmdary[i*2+1];
				insertList(top, &listStock[si]);
			}
			si++;
		} else {
			assert(top != NULL);
			if (cmdary[i*2] == CMD_D) {
				lp = top;
				searchList(lp, cmdary[i*2+1]);
			} else if (cmdary[i*2] == CMD_DF) {
				lp = top;
			} else {	//CMD_DL
				lp = top->prev;
			}
			if (lp == lp->next) {
				top = NULL;
			} else {
				if (lp == top) top = lp->next;
				deleteList(lp);
			}
		}
	}
	if (top != NULL) printList;
}

int main()
{
	long	n;
	scanf("%ld", &n);
	long	*cmdary;
	if ((cmdary = (long*)malloc(sizeof(long)*n*2)) == NULL) return (1);
	char	cmd[BUFSIZ_];
	long	key;
	long	i;
	for (i = 0; i < n; i++) {
		scanf("%s%ld", cmd, &key);
		if (cmd[0] == 'i') {
			cmdary[i*2] = CMD_I;
			cmdary[i*2+1] = key;
		} else if (strlen(cmd) == strlen("delete")) {
			cmdary[i*2] = CMD_D;
			cmdary[i*2+1] = key;
		} else if (cmd[6] == 'F') {
			cmdary[i*2] = CMD_DF;
		} else {
			cmdary[i*2] = CMD_DL;
		}
	}
	cmdProc(n, cmdary);
	free(cmdary);
	return (0);
}
