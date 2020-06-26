#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		string s ;
		cin >> s ;
		int ans = 0 , l = 0 , cnt = -1 , n = s.size();
		for(int i = 0 ; i <= 3*n ; i++){
			cnt++ ;
			while(l < n && cnt >= 0){
				if(s[l++] == '+') cnt++ ;
				else cnt-- ;
			}
			ans += l ;
			if(l == n && cnt >= 0) break ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

