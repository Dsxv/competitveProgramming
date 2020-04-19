#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	string s ;
	cin >> s ;
	int n = s.size() ;
	int x = log2(n) + 1;
	int dp[n][n] = {} ;
	bool ispal[n][n] = {};
	vector<int> ans(n) ;

	for(int i = n - 1 ; i >= 0 ; i--){
		for(int j = i ; j < n ; j++){
			if(s[i] == s[j]){
				if(i+1 >= j-1) ispal[i][j] = 1 ;
				else {
					ispal[i][j] = ispal[i+1][j-1] ;
				}
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = i ; j < n ; j++){
			if(ispal[i][j])	{
				dp[i][j] = 1 ;
				ans[0]++ ;
			}
		}
	}
	for(int k = 2 ; k <= x; k++){
		for(int i = 0 ; i < n ; i++){
			for(int j = i+1 ; j < n ; j++){
				if(ispal[i][j] && dp[i][(i+j-1)/2] >= (k-1) ){
					if((1<<(k-1)) > (j-i+1)) continue ;
					dp[i][j] = k ;
					ans[k-1]++ ;
				}
			}
		}
	}
	for(auto i : ans) cout << i << " " ;
	return 0 ;
}

