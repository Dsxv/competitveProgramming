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
		int prez[n] = {} , sufz[n] = {} ;
		int preo[n] = {} , sufo[n] = {} ;
		for(int i = 0 ; i < n ; i++){
			if(i){
				prez[i] = prez[i-1] ;
				preo[i] = preo[i-1] ;
			}
			prez[i] += (s[i] - '0') == 0 ;
			preo[i] += s[i] - '0' ;
		}
		for(int i = n - 1 ; i >= 0 ; i--){
			if(i < n - 1){
				sufz[i] = sufz[i+1] ;
				sufo[i] = sufo[i+1] ;
			}
			sufz[i] += (s[i] - '0') == 0 ;
			sufo[i] += (s[i] - '0') ;
		}
		int minval = n ;
		for(int i = 0 ; i < n ; i++){
			minval = min(minval , n - (prez[i] + sufo[i])) ;
			minval = min(minval , n - (preo[i] + sufz[i])) ;
		}
		cout << minval << '\n' ;
	}
	return 0 ;
}

