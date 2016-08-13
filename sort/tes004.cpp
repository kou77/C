#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
using namespace std;

#define    MAX_ARY_SIZ    100
#define    STR_LEN    4

int
BubbleSort(char A[][STR_LEN], int N)
{
    int i, j, c = 0;
    bool    f = true;
    for (i = 0; f == true && i < N - 1; i++) {
        f = false;
        for (j = N - 1; j > i; j--) {
            if (strcmp(&A[j - 1][1], &A[j][1]) > 0) {
                swap(A[j - 1], A[j]);
                c++;
                f = true;
            }
        }
    }
    return (c);
}

int
SelectionSort(char A[][STR_LEN], int N)
{
    int    sw =0;
    for (int i = 0, min; i < N - 1; i++) {
        min = i;
        for (int j = i; j < N; j++) {
            if (strcmp(&A[j][1], &A[min][1]) < 0) {
                min = j;
            }
        }
        if (i != min) {
            swap(A[i], A[min]);
            sw++;
        }
    }
    return (sw);
}

bool
IsStable(char A[][STR_LEN], char O[][STR_LEN], int N)
{
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            if (strcmp(&A[j][1], &A[i][1]) != 0) continue;
            for (int k = 0; k < N; k++) {
                if (strcmp(O[k], A[i]) == 0) {
                    break;
                } else if (strcmp(O[k], A[j]) == 0) {
                    return (false);
                }
            }
        }
    }
    return (true);
}

void
print(char A[][STR_LEN], int N)
{
    cout << A[0];
    for (int i = 1; i < N; i++) cout << " " << A[i];
    cout << endl;
}

void
printCheckStable(char A[][STR_LEN], char O[][STR_LEN], int N)
{
    if (IsStable(A, O, N) == true)
        cout << "stable" << endl;
    else
        cout << "not stable" << endl;
}

int main()
{
    int    N, i;
    char    O[MAX_ARY_SIZ][STR_LEN], A[MAX_ARY_SIZ][STR_LEN];
    cin >> N;
    for (i = 0; i < N; i++) cin >> O[i];
    for (i = 0; i < N; i++) strcpy(A[i], O[i]);
    (void)BubbleSort(A, N);
    print(A, N);
    printCheckStable(A, O, N);
    for (i = 0; i < N; i++) strcpy(A[i], O[i]);
    (void)SelectionSort(A, N);
    print(A, N);
    printCheckStable(A, O, N);
    return (0);
}
