#include <iostream>
using namespace std;
int main(void) {

	long long N, K, calK;
	long long totalnum = 0;
	long long numcount = 9;
	long long numlength = 1;
	long long tenten = 1;
	long long result;

	scanf("%lld %lld", &N, &K);
	calK = K;

	while (calK > numcount*numlength) {
		totalnum += numcount;
		calK -= numcount * numlength;
		numcount *= 10;
		numlength++;
	}

	totalnum += (calK - 1) / numlength + 1;

	if (totalnum > N)
		result = -1;
	else {
		long long temp = (calK - 1) % numlength + 1;

		for (int i = 0; i < numlength - 1; i++)
			tenten *= 10;

		for (int i = 0; i < temp; i++)
		{
			result = totalnum / tenten;
			totalnum %= tenten;
			tenten /= 10;
		}
	}

	printf("%d\n", result);


	return 0;
}


