#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e5 + 10 ;

int dp[N][2] ;
int n ;
int INF = 1e18;
string s[N][2] ;

bool ok(string& a , string& b){
	if(a == b) return true ;
	for(int i = 0 ; i < a.size() && i < b.size() ; i++){
		if(a[i] > b[i]){
			return false ;
		} else if(a[i] < b[i]){
			return true ;
		}
	}
	return ((int)a.size() < (int)b.size()) ;
}
int solve(int* a , int i = 1 , int j = 0){
	if(i == (n+1)){
		return 0 ;
	}
	if(~dp[i][j]) return dp[i][j] ;
	int t1 = INF , t2 = INF ;
	if(ok(s[i-1][j] , s[i][0])){
		t1 = min(t1 , solve(a,i+1,0)) ;
	}
	if(ok(s[i-1][j] , s[i][1])){
		t2 = min(t2 , solve(a,i+1,1) + a[i]) ;
	}
	return dp[i][j] = min(t1 , t2) ;
}

int32_t main(){
	memset(dp,-1,sizeof(dp)) ;
	cin >> n ;
	int a[n+1] ;
	for(int i = 1 ; i <= n;  i++) cin >> a[i] ;
	s[0][0] = "a" ;
	s[0][1] = "a" ;
	for(int i = 1 ; i <= n ; i++){
		cin >> s[i][0] ;
		s[i][1] = s[i][0] ;
		reverse(s[i][1].begin(),s[i][1].end()) ;
	}
	int val = solve(a) ;
	if(val == INF){
		cout << -1 ;
	} else {
		cout << val ;
	}
	return 0 ;
}

