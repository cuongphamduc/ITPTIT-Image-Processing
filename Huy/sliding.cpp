#include <iostream>
#include <deque>
#define maxN 10005

using namespace std;

deque <int> q;
int a[maxN], i, j, k, m, n;

void push(int x) {
	while (!q.empty() && q.front() > x) q.pop_front();
	q.push_front(x);
}

main () {
	cin >> n >> k;
	for (i = 0; i < n; i++) cin >> a[i];
	for (i = 0; i < k; i++) push(a[i]);
	cout << q.back() << ' ';
	for (i = k; i < n; i++) {
		if (q.back() == a[i-k]) q.pop_back();
		push(a[i]);
		cout << q.back() << ' ';
	}
}
