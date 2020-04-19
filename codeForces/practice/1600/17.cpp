#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	string s ;
	cin >> s ;
	s = "a" + s + "a" ;
	int a[n+2] = {};
	int group = 0 , cnt = 0 ;
	for(int i = 1 ; i <= n ; i++){
		if(s[i] == '.' && s[i-1] == 'a'){
			group++ ;
		}
		if(s[i] == '.') cnt++ , a[i] = 1 ;
		else s[i] = 'a' ;
	}
	while(m--){
		int x ;
		char ch ;
		cin >> x >> ch ;
		if(ch != '.') ch = 'a' ;
		if(s[x] != ch){
			if(ch == '.'){
				cnt++ ;
				a[x] = 1;
				if(a[x-1] && a[x+1]) group-- ;
				if(!a[x-1] && !a[x+1]) group++;
			} else {
				cnt-- ;
				a[x] = 0 ;
				if(a[x-1] && a[x+1]) group++ ;
				if(!a[x-1] && !a[x+1]) group-- ;
			}
		}
		s[x] = ch ;
		cout << cnt - group << endl ;
	}
	return 0 ;
}

