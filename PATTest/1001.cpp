#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
	long num[3] = {0,0,0};
	long a = 0, b = 0, sum = 0, abssum = 0;
	cin >> a >> b;
	sum = a + b;
	abssum = abs(sum);
	num[2] = abssum % 1000;
	abssum /= 1000;
	num[1] = abssum % 1000;
	abssum /= 1000;
	num[0] = abssum % 1000;

	if (sum < 0)cout << "-";
	if (!num[0] && !num[1] && !num[2])
		cout << 0;
	else {
		bool flag = false;
		int firstnot0=0;
		for (int i = 0; i < 3; i++) {
			if (num[i] == 0 && !flag)
				firstnot0 = i+1;
			else {
				flag = true;
				if (i != firstnot0)
					cout << setw(3) << setfill('0') << num[i];
				else
					cout << num[i];
				if (i != 2)
					cout << ",";
			}
		}
	}
	return 0;
}