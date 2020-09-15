#include <bits/stdc++.h>
using namespace std ;

const int N = 4e3 + 10 ;
int dp[N][N] ;
int n ;

bool solve(vector<int>& a,  int i = 0 , int j = 0){
	int x = n/2 ;
	if(j > x) return 0 ;
	if(i == (int)a.size()){
		return j == x ;
	}
	if(~dp[i][j]) return dp[i][j] ;
	return dp[i][j] = (solve(a , i + 1 , j) | solve(a , i + 1 , j + a[i])) ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t; 
	cin >> t ;
	while(t--){
		cin >> n ;
		n  *= 2 ;
		for(int i = 0 ; i <= n ; i++){
			for(int j = 0 ; j <= n ; j++){
				dp[i][j] = -1 ;
			}
		}
		vector<pair<int,vector<int>>> v ;
		for(int i = 0 ; i < n ; i++){
			int x ; cin >> x ;
			vector<int> tp = {x} ;
			v.push_back({x , tp}) ;
		}
		bool ok = true ;
		vector<pair<int,vector<int>>> tp ;
		tp.push_back(v[0]) ;
		for(int i = 1 ; i < (int)v.size(); i++){
			if(tp.back().first > v[i].first){
				for(auto j : v[i].second){
					tp.back().second.push_back(j) ;
				}
			} else {
				tp.push_back(v[i]) ;
			}
		}
		vector<int> a ;
		for(auto i : tp){
			a.push_back((int)i.second.size()) ;
		}
		if(solve(a)) cout << "YES\n" ;
		else cout << "NO\n" ;
	}
	return 0 ;
}

