#include <iostream>
#include <string>
using namespace std;int main(){string a;cin >> a;int n, c = 0;cin >> n;for (int i = 0; i < n; i++) {string b;cin >> b;b += b;if (b.find(a) != -1) c++;}cout << c;}