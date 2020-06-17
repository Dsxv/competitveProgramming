#include <bits/stdc++.h>
using namespace std ;

const int N = 1e5 ;

#define int long long

struct Segtree{
	vector<vector<int>> t;
	int n ;

	Segtree(){
		n = N ; 
		t.resize(4*n) ;
	}

	Segtree(int n){
		this->n = n ;
		t.resize(4*n) ;
	}

	void build_util(int a[], int v, int tl, int tr) {
		if (tl == tr) {
			t[v] = vector<int>(1, a[tl]);
		} else {
			int tm = (tl + tr) / 2;
			build_util(a, v*2, tl, tm);
			build_util(a, v*2+1, tm+1, tr);
			merge(t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(),
				  back_inserter(t[v]));
		}
	}

	void build(int * a , int l){
		n = l ;
		build_util(a , 1 , 0 , n - 1) ;
	}

	int query_util(int v, int tl, int tr, int l, int r, int x) {
		if (l > r)
			return 0;
		if (l == tl && r == tr) {
			int lo = 0 , hi = t[v].size() - 1 ;
			int ans = -1 ;
			while(lo <= hi){
				int mid = (lo + hi) / 2 ;
				if(t[v][mid] <= x){
					ans = mid ;
					lo = mid + 1 ;
				} else {
					hi = mid - 1 ;
				}
			}
			return ans+1 ;
		}
		int tm = (tl + tr) / 2;
		return query_util(v*2, tl, tm, l, min(r, tm), x)
				   + query_util(v*2+1, tm+1, tr, max(l, tm+1), r, x);
	}

	int query(int l , int r , int x){
		return query_util(1,0,n-1,l,r,x) ;
	}
}  ;

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ;
	cin >> n ;
	pair<int,int> p[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> p[i].first ;
		cin >> p[i].second ;
	}
	sort(p , p+n) ;
	int b[n] ;
	for(int i = 0 ; i < n ; i++) b[i] = p[i].second ;
	Segtree seg(n) ;
	seg.build(b , n) ;
	int q ; cin >> q ;
	while(q--){
		int l1 , r1 , l2 , r2 ;
		cin >> l1 >> r1 >> l2 >> r2 ;
		int i = -1 ;
		int lo = 0 , hi = n - 1 ;
		while(lo <= hi){
			int mid = (lo + hi)  / 2; 
			if(p[mid].first >= l1){
				i = mid ;
				hi = mid - 1 ;
			} else {
				lo = mid + 1 ;
			}
		}
		lo = 0 , hi = n - 1 ;
		int j = -1 ;
		while(lo <= hi){
			int mid = (lo + hi) / 2 ;
			if(p[mid].first <= r1){
				j = mid ;
				lo = mid  + 1 ;
			} else {
				hi = mid - 1 ;
			}
		}
		if(i == -1 || j == -1) cout << 0 << '\n' ;
		cout << seg.query(i,j,r2) - seg.query(i,j,l2-1) << '\n' ;
	}
}


