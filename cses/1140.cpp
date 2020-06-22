#include <bits/stdc++.h>
using namespace std ;

#define int long long

pair<vector<int>,vector<int>> compress(vector<int>& a){
	int n = a.size() ;
	map<int,vector<int>> mp;
	for(int i = 0 ; i < n ; i++){
		mp[a[i]].push_back(i) ;
	}
	vector<int> ans(n) , mapped(n) ;
	int cnt = 0 ;
	for(auto i : mp){
		for(auto j : i.second){
			ans[j] = cnt ;
		}
		mapped[cnt] = i.first ;
		cnt++ ;
	}
	return {ans,mapped} ;
}
const int N = 5e5 + 10 ;
int dp[N] ;
vector<int> a , b , p;
int solve(vector<int>* v , int n , int i = 0){
	if(i >= 2*n){
		return 0 ;
	}
	if(~dp[i]) return dp[i] ;
	dp[i] = solve(v,n,i+1) ;
	for(auto j : v[i]){
		dp[i] = max(dp[i] , solve(v,n,b[j]+1) + p[j]) ;
	}
	return dp[i] ;
}

int32_t main(){
	memset(dp , -1 , sizeof(dp)) ;
	int n;
	cin >> n;
	a.clear() ; b.clear() ; p.clear() ;
	a.resize(n) ; b.resize(n) ; p.resize(n) ;
	vector<int> temp ;	
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] >> b[i] >> p[i] ;
		temp.push_back(a[i]) ; 
		temp.push_back(b[i]) ;
	}
	auto [x,y] = compress(temp) ;
	for(int i = 0 , j = 0 ; i < n ; i++ , j += 2){
		a[i] = x[j] ;
		b[i] = x[j+1] ;
	}
	vector<int> v[2*n] ;
	for(int i = 0 ; i < n ; i++){
		v[a[i]].push_back(i) ;
	}
	cout << solve(v,n) ;
	return 0 ;
}

