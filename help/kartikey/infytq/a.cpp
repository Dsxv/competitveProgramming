#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool ok(int x) {
	int l = sqrt(x) ;
    for (int i = 0;  i <= l; i++) 
        if (x == i * (i + 1))  
        return true; 
    return false; 
} 

int32_t main(){
	string s ;
	cin >> s ;
	set<int> pronic; 
	for(int i = 0 ; i < s.size() ; i++){
		int val = 0 ;
		for(int j = i ; j < s.size() ; j++){
			val = val*10 + (s[j]-'0') ;
			if(ok(val) && val) {
				pronic.insert(val) ;
			}
		}
	}
	if(pronic.size()){
		int cnt = 0 ;
		for(auto i : pronic){
			cout << i ;
			if(cnt++ < (pronic.size()-1)) cout <<  ",";
		}
	} else {
		cout << -1 ;
	}
	return 0 ;
}

