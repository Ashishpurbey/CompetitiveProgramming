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
const int MAX = 3 * 1000 * 100 + 5;
//char a[11][10][6] = {
//	{".xxx." , "x...x" , "x...x" , "x...x" , "....." ,"x...x" , "x...x" , "x...x" ,".xxx." },
//
//
//};

int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);
	int n, m;
	string x;
	cin >> n >> m >> x;

	int c1 = 0, c2 = 0,ans=0;
	for (int i = 0; i < m; i++) {
		if (c1 == c2) {

			c1 += x[i] == '0';
			c2 += x[i] == '1';
			ans++;
			continue;
		}

		int l1 = n - c1;
		int l2 = n - c2;
		int rem = m - i;

		if ((l1 == rem&&l2>rem) || (l1>rem&&l2 == rem)) {
			c1 += x[i] == '0';
			c2 += x[i] == '1';

			continue;
		}
		if (l1 == 1 || l2 == 1) {
			c1 += x[i] == '0';
			c2 += x[i] == '1';
			continue;
		}
		c1 += x[i] == '0';
		c2 += x[i] == '1';

		ans++;
	}

	cout << ans << endl;


	pause();
	return 0;
}