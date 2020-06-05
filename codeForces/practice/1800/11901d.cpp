#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	map<int,int> mp ;
	bool found = true ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
		mp[a[i]]++ ;
		found &= mp[a[i]] < 3 ;
	}
	int x = 0 ;
	for(auto i : mp) {
		x += i.second >= 2 ;
		if(i.second >= 2){
			found &= !mp.count(i.first-1) ;
		}
	}
	found &= x < 2 ;
	sort(a , a+n) ;
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		if(i > a[i]) {
			found = false ;
			break; 
		}else {
			ans += (a[i] - i) ;
		}
	}
	if(!found){
		cout << "cslnb" ;
	} else {
		cout << (ans&1?"sjfnb":"cslnb") ;
	}
	return 0 ;
}

