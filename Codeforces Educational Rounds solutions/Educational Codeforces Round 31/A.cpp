#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<sstream>
#include<vector>
#include<string.h>
#include<queue>
#include<list>
#include<iterator>
#include<functional> 
#include<iomanip>
#include<bitset>
#include<stack>
#include <assert.h>
#include<complex>
#include<unordered_map>
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
const double PI = acos(-1.0);
#define point complex<double> // it can be long long not double
#define cp(a,b)   ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel cross product = area of parllelogram
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
void pause() {
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
int dx[] = { 0,0,-1,-1,-1,1,1,1 };
int dy[] = { -1,1,0,1,-1,-1,0,1 };
bool cmp1(pair<ld, ld>a, pair<ld, ld>b)
{
	return a.second < b.second;
}
bool cmp2(pair<ld, ld>a, pair<ld, ld>b)
{
	return a.second > b.second;
}
int main() {
	fast_in_out();
	cout << fixed << setprecision(6);
	//freopen("triple.in", "r", stdin);
	//freopen("","w",stdout);
	int n; cin >> n;
	int x; cin >> x;
	ll sum = 0;
	int i;
	for (i = 1; i <= n; i++)
	{
		int y; cin >> y;
		sum += (86400-y);
		if (sum >= x)
			break;
	}
	cout << i << endl;
	pause();
	return 0;
}