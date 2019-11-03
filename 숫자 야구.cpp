#include<iostream>

using namespace std;

#include<string>

#include<cstring>

int n, number, strike, ball;

bool arr[1000];

string tmp, one, two;

int strike_cnt, ball_cnt, ans;

int main()

{

	cin >> n;

	memset(arr, true, sizeof(arr));	//�ʱ�ȭ(��� ���� �����ϴٰ� true�� ����)

	for (int i = 123; i <= 999; i++)

	{

		tmp = to_string(i);

		if (tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2])

			arr[i] = false;//���� �ٸ� �����̱⿡ ���� ���ڰ� ������ false����

		if (tmp[0] - '0' == 0 || tmp[1] - '0' == 0 || tmp[2] - '0' == 0)

			arr[i] = false;

	}

	for (int i = 1; i <= n; i++)

	{

		cin >> number >> strike >> ball;

		for (int i = 123; i <= 999; i++)

		{

			strike_cnt = 0;

			ball_cnt = 0;

			if (arr[i])

			{

				one = to_string(number);

				two = to_string(i);

				for (int x = 0; x < 3; x++) {

					for (int y = 0; y < 3; y++) {

						if (x == y && one[x] == two[y])

							strike_cnt++;

						if (x != y && one[x] == two[y])

							ball_cnt++;

						//���� ���ڰ� ���ü��� �����ϱ� �̷��� �ص� ������� (if/ if)

					}

				}

				if (strike_cnt != strike || ball_cnt != ball)

					arr[i] = false;

			}

		}

	}

	for (int i = 123; i <= 999; i++)

	{

		if (arr[i])

			ans++;

	}

	cout << ans << endl;

	return 0;

}