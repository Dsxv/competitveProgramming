#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		string s ;
		cin >> s ;
		int n = s.size() ;
		int cnt[n] = {} ;
		int ans = 0 ;
		for(int i = 0 ; i < n ; i++){
			int l = max(0LL,i-20) ;
			int val = 0 ;
			for(int j = i ; j >= l ; j--){
				val += (1LL<<(i-j))*(s[j]-'0') ;
				if((i-j+1) == val) ans++ ;
			}
			if(val > (i-l+1)){
				if(val <= (i-l+1+cnt[l])) ans++ ;
			}
			if(i){
				if(s[i-1] == '0') cnt[i] = cnt[i-1] + 1 ;
			}
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

