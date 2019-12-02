#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int M = 105 , X = 1e3 + 5;

int dp[M][X] ;

int solve(vector<int>* v, int m , int x, int i = 1 , int j = 0){
	if(j > x) return INT_MIN ;
	if(i > m) return 0 ;
	if(v[i].size() == 0) return INT_MIN ;
	if(dp[i][j] != -1) return dp[i][j] ;
	int c = INT_MIN ;
	for(auto k : v[i]){
		int val = solve(v,m,x,i+1,j+k) ;
		if(val >= 0) c = max(c,k+val) ;
	}
	if(c >= 0) return dp[i][j] = c ;
	else return dp[i][j] = INT_MIN ;
}
int32_t main(){
	int n , m , x ;
	cin >> n >> m >> x ;
	vector<int> v[m+1] ;
	pair<int,int> a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i].first ;
	}
	for(int i = 0 ; i < n ; i++) {
		cin >> a[i].second ;
	}
	for(int i = 0 ; i <= m ; i++){
		for(int j = 0 ; j <= x ; j++) dp[i][j] = -1 ;
	}
	for(int i = 0 ; i < n ; i++){ 
		v[a[i].second].push_back(a[i].first) ;
	}
	//for(int i = 1 ; i <= m ; i++){
		//for(auto j : v[i]) cout << j <<" " ;
		//cout << endl ;
	//}
	int ans = solve(v,m,x) ;
	if(ans < 0) cout << -1 ;
	else cout << x-ans ;
	//cout << endl ;
	//for(int i = 1 ; i <= m ; i++){
		//for(int j = 0 ; j <= x ; j++) cout << dp[i][j] << " " ;
		//cout << endl ;
	//}

	return 0 ;
}

