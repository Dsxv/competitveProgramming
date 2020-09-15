#include <bits/stdc++.h>
using namespace std ;

const int N = 2e3 + 1 , M = 3e3 + 2;
int dp[M][N] ;

int solve(vector<pair<int,int>>& v , int i = 0 , int j = 0){
	if(i == v.size()){
		return 0 ;
	}
	if(~dp[i][j]) return dp[i][j] ;
	int ans = solve(v , i + 1 , j) ;
	if(v[i].first > j || (v[i].second <= j)){
		ans = max(ans , 1 + solve(v , i + 1 , max(v[i].second , j))) ;
	}
	return dp[i][j] = ans ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		memset(dp , -1 , sizeof(dp)) ;
		int n ; 
		cin >> n ;
		vector<pair<int,int>> v ;
		v.resize(n) ;
		for(int i = 0 ; i < n ; i++){
			cin >> v[i].first >> v[i].second ;
		}
		sort(v.begin() , v.end()) ;
		cout << solve(v) << '\n' ;
	}
	return 0 ;
}

