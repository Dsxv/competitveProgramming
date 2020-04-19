#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m , k ;
	cin >> n >> m >> k ;
	for(int i = 0 ; i < k ; i++){
		pair<int,int> a ;
		cin >> a.first >> a.second ;
	}
	string ans = string(m-1,'L') + string(n-1,'U') ; 
	for(int i = 0 ; i < n ; i++){
		if(i%2 == 0) ans += string(m-1,'R') ;
		if(i%2){
			ans += "D" + string(m-1,'L') ;
			if(i < (n-1)) ans += "D" ;
		}
	}
	cout << ans.size() << endl ;
	cout << ans ;
	return 0 ;
}

