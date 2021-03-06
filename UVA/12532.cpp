#include<bits/stdc++.h>
#include<chrono>
#include<unordered_map>
#include<random>
#include<complex> 
using namespace std;
typedef complex<long double> point;
#define EPS 1e-9 
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a)) 
#define polar(r,t) ((r)*exp(point(0,(t)))) 
#define angle(v) (atan2((v).Y,(v).X)) 
#define length(v) ((long double)hypot((v).Y,(v).X)) 
#define lengthSqr(v) (dot(v,v)) 
#define dot(a,b) ((conj(a)*(b)).real()) 
#define cross(a,b) ((conj(a)*(b)).imag()) 
#define rotate(v,t) (polar(v,t)) 
#define rotateabout(v,t,a)  (rotate(vec(a,v),t)+(a)) 
#define reflect(p,m) ((conj((p)/(m)))*(m)) 
#define normalize(p) ((p)/length(p)) 
#define same(a,b) (lengthSqr(vec(a,b))<EPS) 
#define mid(a,b) (((a)+(b))/point(2,0)) 
#define perp(a) (point(-(a).Y,(a).X)) 
#define colliner pointOnLine 
enum STATE { IN, OUT, BOUNDRY };
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
#define PI acos(-1.)
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
const ld eps = 1e-3;
const int N = 1e5 + 10, M = 1e6 + 50, mod = 1e9+7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int n, q;
int tree[N << 2];
int ar[N];
string str;
void build(int ind, int s, int e) {
	if (s == e) {
		tree[ind] = ar[s];
		return;
	}
	int mid = s + e >> 1;
	int l = ind << 1, r = l | 1;
	build(l, s, mid);
	build(r, mid + 1, e);
	tree[ind] = tree[l] * tree[r];
}
void update(int ind, int s, int e, int x,int val) {
	if (x<s || x>e)return;
	if (s == e) {
		tree[ind] = val;
		return;
	}
	int mid = s + e >> 1;
	int l = ind << 1, r = l | 1;
	update(l, s, mid, x, val);
	update(r, mid + 1, e, x, val);
	tree[ind] = tree[l] * tree[r];
}
int solve(int ind, int s, int e, int x, int y) {
	if (x > e || y < s) return 1;
	if (s >= x && e <= y)return tree[ind];
	int mid = s + e >> 1;
	int l = ind << 1, r = l | 1;
	return solve(l, s, mid, x, y) * solve(r, mid + 1, e, x, y);
}
vector<int>get_input() {
	vector<int>ret;
	for (int i = 6; i < str.size(); i++) {
		int x = 0;
		while (i < str.size() && isdigit(str[i])) {
			x *= 10;
			x += str[i] - '0';
			i++;
		}
		ret.push_back(x);
	}
	return ret;
}
char change(int x) {
	if (x == 1)return '+';
	else if (x == -1)return '-';
	else return '0';
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(3);
	//srand(time(0));
	while (cin >> n >> q) {
		for (int i = 1; i <= n; i++) {
			int x; cin >> x;
			if (x > 0)ar[i] = 1;
			else if (x < 0)ar[i] = -1;
			else ar[i] = 0;
		}
		build(1, 1, n);
		while (q--) {
			char op;
			int x, y;
			cin >> op >> x >> y;
			if (op == 'P') {
				cout << change(solve(1, 1, n, x, y));
			}
			else {
				if (y > 0)y = 1;
				else if (y < 0)y = -1;
				update(1, 1, n, x, y);
			}
		}
		cout<<endl;
	}
	return 0;
}