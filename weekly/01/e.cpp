#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	string s;
	cin >> n >> s ;
	int c = 0 ;
	for(auto i : s) c += i == 'G' ;
	int ans = 0 , l = 0;
	for(int i = 0 ; i < n ; i++){
		if(s[i] == 'S'){
			if(i-l+1 > c){
				while(s[l++] != 'S') ;
			}
		}
		ans = max(ans,i-l+1) ;
	}
	cout << ans ;
	return 0 ;
}

