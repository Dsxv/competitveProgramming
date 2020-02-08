#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e3 + 10 ;
int dp[N][N][27] ;
int n ;
char ch = 'z' ;
int solve(string& s, int i = 0 , int j = n , char prev = ch){
	if(i == j) return 0;
	if(abs(i-j) == 1){
		if(s[i] == s[j] && s[i] != prev){
			return 2;
		} else {
			return 0 ;
		}
	} 
	int val = prev - 'a' ;
	if(dp[i][j][val] != -1) return dp[i][j][val] ;
	if(s[i] == s[j] && s[i] != prev){
		dp[i][j][val] = solve(s,i+1,j-1,s[i]) + 2 ;
	} else {
		dp[i][j][val] = max(solve(s,i+1,j,prev), solve(s,i,j-1,prev)) ;
	}
	return dp[i][j][val] ;
}
		

int32_t main(){
	string s ;
	cin >> s ;
	n = s.size() - 1;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			for(int k = 0 ; k < 27 ; k++){
				dp[i][j][k] = -1 ;
			}
		}
	}
	ch++ ;
	cout << solve(s) ;
	return 0 ;
}

