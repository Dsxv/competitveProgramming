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
		int cnt = 0 , mc = 0 ;
		for(int i = 0 ; i < n ; i++){
			if(s[i] == 'L') cnt++ ;
			else cnt = 0 ;
			mc = max(cnt, mc) ;
		}
		cout << mc + 1 << endl ;
	}
	return 0 ;
}

