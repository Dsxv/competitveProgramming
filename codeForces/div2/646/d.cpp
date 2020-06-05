#include <bits/stdc++.h>
using namespace std ;

#define int long long

int query(vector<int>* subs , int lo , int hi){
	vector<int> ans; 
	for(int i = lo ; i <= hi ; i++){
		for(auto j : subs[i]) ans.push_back(j) ;
	}
	cout <<"? "<< ans.size() << " " ;
	for(auto i : ans) cout << i << " " ;
	cout << endl ;
	int mx ;
	cin >> mx ;
	return mx ;
}

int query2(int n){
	cout << "? "<< n << " " ;
	for(int i = 1 ; i <= n ; i++) cout << i << " " ;
	cout << endl ;
	int x ; cin >> x ;
	return x ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k ;
		cin >> n >> k ;
		vector<int> subs[k] ;
		for(int i = 0 ; i < k ; i++){
			int x ;
			cin >> x ;
			subs[i].resize(x) ;
			for(int j = 0 ; j < x ; j++) cin >> subs[i][j] ;
		}
		int lo = 0 , hi = k - 1 ;
		int val = query2(n) ;
		while(lo < hi){
			int mid = (lo + hi) / 2 ;
			int x = query(subs,lo,mid) ;
			if(x == val){
				hi = mid ;
			} else {
				lo = mid + 1 ;
			}
		}
		assert(lo == hi) ;
		map<int,int> mp ;
		for(auto i : subs[lo]) mp[i]++ ;
		vector<int> rem ;
		for(int i = 1 ; i <= n ; i++) {
			if(mp.count(i)) continue ;
			rem.push_back(i) ;
		}
		cout <<"? "<< rem.size() << " " ;
		for(auto i : rem) cout << i << " " ;
		cout << endl ;
		int nx ; cin >> nx ; 
		vector<int> ans(k) ;
		for(int i = 0 ; i < k ; i++){
			if(i == lo) ans[i] = nx ;
			else ans[i] = val ;
		}
		cout << "! ";
		for(auto i : ans) cout << i << " " ;
		cout << endl ;
		string result ; 
		cin >> result ;
		assert(result == "Correct") ;
	}
	return 0 ;
}

