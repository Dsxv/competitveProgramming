#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		string s; 
		cin >> s; 
		char ch[10] = {} ;
		for(auto i : s) ch[i-'0']++ ;
		int n = s.size() ;
		int ans = n - *max_element(ch , ch + 10) ;
		for(int i = 0 ; i < 10 ; i ++){
			for(int j = 0 ; j < 10 ; j++){
				string tp = "" ;
				tp += (i + '0') ;
				tp += (j + '0') ;
				int cnt = 0 , l = 0 ;
				for(auto k : s){
					if(tp[l] == k){
						l = (l+1) % 2 ;
						if(l == 0) cnt += 2 ;
					}
				}
				ans = min(ans , n - cnt) ;
			}
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

