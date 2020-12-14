#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(vector<int>& v , int k){
	int n = v.size() ;
	set<vector<int>> mp ;
	for(int i = 0 ; i < n ; i++){
		vector<int> temp ;
		int cnt = 0 ;
		for(int j = i ; j < n ; j++){
			temp.push_back(v[j]) ;
			cnt += v[j] % 2 ;
			if(cnt > k) break ;
			mp.insert(temp) ;
		}
	}
	return mp.size() ;
}

int32_t main(){
	int n ;
	cin >> n ;
	vector<int> v(n) ;
	for(auto &i : v) cin >> i ;
	int k ; cin >> k ;
	cout << solve(v, k) ;
	return 0 ;
}

