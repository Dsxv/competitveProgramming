#include <bits/stdc++.h>
using namespace std ;

#define int long long

int check(int x , pair<int,int>* p , int n){
	for(int i = 0 ; i < n ; i++){
		if(p[i].second == 1 && x < 1900) return -1 ; // rating low
		if(p[i].second == 2 && x > 1899) return 1 ; // rating high
		x += p[i].first ;
	}
	return 0 ;
}

int32_t main(){
	int n;
	cin >> n ;
	pair<int,int> p[n] ;
	bool found = false ;
	int val = 0 ;
	for(int i = 0 ; i < n ; i++){
		cin >> p[i].first >> p[i].second ;
		if(p[i].second == 2) found = true ;
		val += p[i].first ;
	}
	if(!found){
		cout << "Infinity" ;
		return 0 ;
	}
	int lo = -2e7 - 10 , hi = 2e7 + 10 ;
	int ans = -1 ;
	found = false ;
	while(lo <= hi){
		int mid = (lo + hi)/ 2 ;
		int x = check(mid,p,n) ;
		if(x == 0){
			found = true ;
			ans = mid ;
			lo = mid + 1 ;
		} else if(x == 1) { // rating higher than supposed to be
			hi = mid - 1;
		} else { // rating lower than supposed to be
			lo = mid + 1 ;
		}
	}
	if(!found) cout << "Impossible" ;
	else cout << ans + val;
	return 0 ;
}

