#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;



int N, M, K;



int main(void)

{

	ios_base::sync_with_stdio(0);

	cin.tie(0); //cin �ӵ� ���

	cin >> N >> M >> K;



	//�ִ� �κ� ���� ������ �ִ� �κ� ���� ������ �ϳ��� ���Ҹ� ����

	//N = M * K + 1�� ���: ���̰� M + 1�� ���� ������ ���̰� K + 1�� ���Ҽ����� ���� �� ����

	if (M + K - 1 <= N && N <= M * K)

	{

		vector<int> arr(N);

		for (int i = 0; i < N; i++)

			arr[i] = i + 1;



		//�ϳ��� �׷��� ���� �ε���

		int idx = 0;

		//M���� �׷����� ������

		for (int i = 1; i <= M; i++)

		{

			//�� �׷쿡 ����ִ� ���� K���� �۰ų� ���ƾ� �ϰ�

			//�־��� ������ ������Ű�� ���ؼ� �� �׷��� K���� ���� ���� �ִ�

			int temp = min(idx + K, N - M + i);

			//�� �׷��� �������ش�

			reverse(arr.begin() + idx, arr.begin() + temp);

			idx = temp;

		}



		for (int i = 0; i < N; i++)

			cout << arr[i] << " ";

		cout << "\n";

	}

	else

		cout << -1 << "\n";
	system("pause");
	return 0;

}