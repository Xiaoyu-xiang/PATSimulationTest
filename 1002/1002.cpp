#include<iostream>
using namespace std;

struct Po{
	int exp;
	double coe;
	Po() {
		exp = 0;
		coe = 0;
	}
};

int main() {
	int K1 = 0, K2 = 0;
	cin >> K1;
	Po* p1 = new Po[K1];
	for (int i = 0; i < K1; i++)
		cin >> p1[i].exp >> p1[i].coe;
	cin >> K2;
	Po* p2 = new Po[K2];
	for (int i = 0; i < K2; i++)
		cin >> p2[i].exp >> p2[i].coe;
	Po* p3 = new Po[K1 + K2];
	int i = 0, j = 0, k = 0;
	while (i < K1 && j < K2) {
		if (p1[i].exp > p2[j].exp) {
			p3[k++] = p1[i++];
		}
		else if (p1[i].exp < p2[j].exp) {
			p3[k++] = p2[j++];
		}
		else {
			p3[k].exp = p1[i].exp;
			p3[k++].coe = p1[i++].coe + p2[j++].coe;
		}
	}
	if (i >= K1)
		while (j < K2) {
			p3[k++] = p2[j++];
		}
	else
		while (i < K1) {
			p3[k++] = p1[i++];
		}
	int sum = 0;
	for (int i = 0; i < k; i++)
		if (p3[i].coe != 0)
			sum++;
	cout << sum;
	for (int i = 0; i < k; i++)
		if (p3[i].coe != 0) {
			cout << " " << p3[i].exp << " ";
			printf("%.1f", p3[i].coe);
		}
	return 0;
}

/*
3 8 1.2 6 -4 0 1
3 7 3.3 6 4 0 2
result
*/