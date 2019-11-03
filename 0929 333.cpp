#include <iostream>
#include <unordered_map>
#include <vector>
typedef long long ll;

using namespace std;
const int N = 2e6 + 5000;
const ll mod = 1e9 + 7;

ll quick_mul(ll x, ll y, ll mod)
{
	ll ans = 0;
	while (y != 0)
	{
		if (y & 1 == 1)ans += x, ans %= mod;
		x = x + x, x %= mod;
		y >>= 1;
	}
	return ans;
}

ll mul(ll x, ll y, ll mod)
{
	ll sum = 1;
	while (y != 0)
	{
		if (y & 1 == 1)sum = quick_mul(sum, x, mod), sum %= mod;
		x = quick_mul(x, x, mod), x %= mod;
		y = y >> 1;
	}
	return sum;
}

ll mulll(ll a, ll b, ll c)
{
	ll res = 1;
	while (b)
	{
		if (b & 1) res *= a, res %= c;
		a *= a, a %= c, b >>= 1;
	}
	return res;
}
ll phi(ll x)
{
	ll res = x;
	for (ll i = 2; i * i <= x; i++)
	{
		if (x % i == 0) res = res / i * (i - 1);
		while (x % i == 0) x /= i;
	}
	if (x > 1) res = res / x * (x - 1);
	return res;
}

ll n, k;
ll a[N];

unordered_map<int, int>m;
int main()
{
	ios::sync_with_stdio(false);
	ll t;
	ll x, y;
	while (cin >> x >> n)
	{
		vector <ll> v;
		for (ll i = 2; i * i <= x; i++)
		{
			if (x % i == 0)
			{
				v.push_back(i);
				while (x % i == 0) x /= i;
			}
		}
		ll ans = 1;
		if (x > 1) m[x] ++, v.push_back(x);
		for (auto tot : v)
		{
			ll d = tot;
			for (ll i = 1; tot <= n && tot > 0; i++, tot *= d)
			{
				if (n / tot < d)
				{
					ans *= (mul(tot, (n / tot), mod)) % mod, ans %= mod;
					break;
				}
				else  ans *= (mul(tot, (n / tot) - (n / (tot *  d)), mod)) % mod, ans %= mod;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
