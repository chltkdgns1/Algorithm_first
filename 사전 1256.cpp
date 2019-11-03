#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 100 + 1;
int N, M, K;
string word;
bool noWord;
int cache[MAX][MAX];
int possibleNumOfWord(int A, int Z)
{
	if (A == 0 || Z == 0)
		return 1;
	int &result = cache[A][Z];
	if (result != -1)
		return result;
	result = min(possibleNumOfWord(A - 1, Z) + possibleNumOfWord(A, Z - 1), 1000000000 + 1);
	return result;

}
void getWord(int A, int Z, int skip){
	if (A == 0)
	{
		for (int i = 0; i < Z; i++)
			word += 'z';
		return;
	}
	if (Z == 0)
	{
		for (int i = 0; i < A; i++)
			word += 'a';
		return;
	}
	int idx = possibleNumOfWord(A - 1, Z);
	if (skip < idx)
	{
		word += 'a';
		getWord(A - 1, Z, skip);
	}
	else  if (skip <= 1000000000)
	{
		word += 'z';
		getWord(A, Z - 1, skip - idx);
	}
}
int main(void){
	cin >> N >> M >> K;
	noWord = false;
	memset(cache, -1, sizeof(cache));
	if (K > possibleNumOfWord(N, M)) 
		noWord = true;
	else
		getWord(N, M, K - 1);
	if (noWord) 
		cout << -1 << endl;
	else
		cout << word << endl;
	return 0;
}