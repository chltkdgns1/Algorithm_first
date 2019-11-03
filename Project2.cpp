#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	string origin;
	string arr;
	cin >> origin;
	
	arr = origin;
	arr.erase(arr.begin());
	
	vector<string> m_oTest;
	m_oTest.push_back(origin);
	for (int i = 0; i < origin.length() - 1; ++i)
	{
			m_oTest.push_back(arr);
			arr.erase(arr.begin());
	}

	sort(m_oTest.begin(), m_oTest.end());

	for (int i = 0; i < m_oTest.size(); ++i)
	{
		cout << m_oTest[i] << endl;
	}

	return 0;
}