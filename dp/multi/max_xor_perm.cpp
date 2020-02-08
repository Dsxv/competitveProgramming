#include <bits/stdc++.h>
using namespace std ;

#define int long long
int x , y ,  z ;
const int N = 11 ;
int dp[N][N][N][N] ;

int solve(int ind = 0 ,int i = 0 , int j = 0 , int k = 0) {
	if(i > x || j > y || k > z) return INT_MIN ;
	if(ind == 10){
		if(i == x && j == y && k == z) return 0 ;
		return INT_MIN ;
	}
	if(dp[ind][i][j][k] != -1) return dp[ind][i][j][k] ;
	int ans = INT_MIN ; 
	for(int x = 0 ; x < 8 ; x++){
		int ca = (x>>2)&1 ;
		int cb = (x>>1)&1 ;
		int cc = x&1 ;
		int val = 0 ;
		if((ca + cb + cc)%2) val = (1<<(9-ind)) ;
		ans = max(ans,solve(ind+1,i+ca,j+cb,k+cc) + val) ;
	}
	return dp[ind][i][j][k] = ans ;
}


int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		string a , b , c ;
		cin >> a >> b >> c ;
		memset(dp,-1,sizeof(dp)) ;
		x = count(a.begin(),a.end(),'1') ;
		y = count(b.begin(),b.end(),'1') ;
		z = count(c.begin(),c.end(),'1') ;
		int ans =  solve() ;
		bitset<10> bb(ans) ;
		cout << bb << endl;
	}
	return 0 ;
}

