#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<bits/stdc++.h>
#include<chrono>
#include<unordered_map>
#include<random>
#include<complex> 
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#ifndef ONLINE_JUDGE
int __builtin_popcount(int mask) {
	int cnt = 0;
	for (int i = 0; i < 23; i++)
		if (mask & (1 << i)) ++cnt;
	return cnt;
}
#endif
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int dx[] = { 0,0,-1,1,-1,1,-1,1,0 };
int dy[] = { -1,1,0,0,-1,-1,1,1,0 };
int lx[] = { 2, 2, -1, 1, -2, -2, -1, 1 };
int ly[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
const ld eps = 1e-9;
const int N = 2e5 + 50, M = 1e5 + 10, mod = 998244353;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll t = gcd(a, b); return t ? (a / t * b) : 0; }
int ans[N];
int main() {
	fast_in_out();
	cout << fixed << setprecision(4);
	/*
	cub(n)=a+dx;
	n=(a+dx)^3
	n=a^3+3*x^2*y+3*x*y^2+y^3;
	n=a*a*a + 3 * x*x*y
	y=(n-a^3)/(3*x^2)
	*/
	double x;
	while (cin >> x && x) {
		ll a = 0;
		for (;;) {
			a++;
			if (a * a * a > x) { a--; break; }
		}
		double y = (x - a * a * a) / (3. * a * a);
		cout << a + y << endl;
	}
	return 0;
}