#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	string s ;
	cin >> s ;
	bool ok = true ;
	while(ok){
		int id = -1 ;
		for(int i = 0 ; i < (int)s.size() ; i++){
			if(i){
				if(s[i] == (s[i-1] + 1)) {
					if(id == -1 || s[i] > s[id]) id = i ;
				}
			}
			if(i < ((int)s.size() - 1)){
				if(s[i] == (s[i+1] + 1)) {
					if(id == -1 || s[i] > s[id]) id = i;
				}
			}
		}
		if(id == -1) ok = false ;
		else s.erase(id,1) ;
	}
	cout << n - (int)s.size() ;
	return 0 ;
}
