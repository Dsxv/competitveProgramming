#include <bits/stdc++.h>
using namespace std ;

#define int long long


const int inf = 1e9 ;

int32_t main(){
	string s ; int k ;
	cin >> s >> k ;
	int n = s.size() ; 
    int dp[n] = {} ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) a[i] = s[i] - '0' ;
	int ans = n;
	for(int i = 0; i < n;){
		if(a[i] == 1){
			if(i + k <= n){
				ans -= k;
				i = i + k;
			}
			else{
				if(ans >= k) ans -= k;
				else  ans = -1;
				i = n;
			}
		}
		else
			i++;
	}
	cout << ans ;
return 0 ;
}

