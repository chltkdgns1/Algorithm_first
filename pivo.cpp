#include <iostream>
using namespace std;


int fibonacci2(int number);
int main() {
	int exel_number;
	cin >> exel_number;
	int n;
	for (int i = 0; i < exel_number; i++) {
		cin >> n;
		if (0 <= n && n <= 40) {
			fibonacci2(n);
		}
	}
	//system("pause");
}

int fibonacci2(int number) {
	int a = 0;
	int b = 1;
	int c = 0;
	if (number == 0) {
		cout << b << " " << a << endl;
		return a;
	}
	if (number == 1) {
		cout << a << " " << b << endl;
		return b;
	}
	for (int i = 0; i < number - 1; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	cout << a << " " << b << endl;
	return c;
}

/*#include <iostream>
using namespace std;


int zero = 0;
int one = 0;
int fibonacci2(int number);
int fibonacci(int n);
int main() {
	int exel_number;

	cin >> exel_number;
	int n;
	for (int i = 0; i < exel_number; i++) {
		cin >> n;
		if (0 <= n && n <= 40) {
			cout<<fibonacci(n)<<endl;
			cout << fibonacci2(n) << endl;
			cout << zero << " " << one << endl;
			zero = 0;
			one = 0;
		}
	}
	system("pause");
}

int fibonacci(int n) {
	if (n == 0) {
		zero++;
		return 0;
	}
	else if (n == 1) {
		one++;
		return 1;
	}
	else {
		return fibonacci(n -1 ) + fibonacci(n - 2);
	}
}

int fibonacci2(int number) {
	int a = 0;
	int b = 1;
	int c = 0;
	if (number == 0) {
		cout << b << " " << a << endl;
		return a;
	}
	if (number == 1) {
		cout << a << " " << b << endl;
		return b;
	}
	for (int i = 0; i < number-1; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	cout << a << " " << b << endl;
	return c;
}*/

/*#include <iostream>
using namespace std;


int fibonacci2(int number);
int main() {
	int exel_number;
	cin >> exel_number;
	int n;
	for (int i = 0; i < exel_number; i++) {
		cin >> n;
		if (0 <= n && n <= 40) {
			fibonacci2(i);
		}
	}
	//system("pause");
}

int fibonacci2(int number) {
	int a = 0;
	int b = 1;
	int c;
	if (number == 0) {
		cout << b << " " << a << endl;
		return a;
	}
	if (number == 1) {
		cout << a << " " << b << endl;
		return b;
	}
	for (int i = 0; i < number - 1; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	cout << a << " " << b << endl;
	return c;
}*/