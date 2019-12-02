#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e3 + 5 ;

int dp[N][N] ;

int solve(string& a  , string& b , int i = 0 , int j = 0){
	if(i == a.size() || j == b.size()){
		return 0 ;
	}
	if(dp[i][j] != -1) return dp[i][j] ;
	if(a[i] == b[j]) return dp[i][j] = 1 + solve(a,b,i+1,j+1) ;
	else{
		return dp[i][j] = max( solve(a,b,i+1,j) , solve(a,b,i,j+1)) ;
	}
}

string getans(string& a , string b , int i = 0 , int j = 0){
	if(i == a.size() || j == b.size()) return "" ;
	if(a[i] == b[j]) return a[i] + getans(a,b,i+1,j+1) ;
	if(dp[i+1][j] > dp[i][j+1]){
		return getans(a,b,i+1,j) ;
	}else{
		return getans(a,b,i,j+1) ;
	}
}

int32_t main(){
	string a , b ;
	cin >> a >> b ;
	for(int i = 0 ; i <= a.size() ; i++){
		for(int j = 0 ; j <= b.size() ; j++) dp[i][j] = -1 ;
	}
    solve(a,b) ;
	cout <<  getans(a,b) ;
	return 0 ;
}

