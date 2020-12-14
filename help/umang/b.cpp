#include <bits/stdc++.h>
using namespace std ;

bool ok(int n){
	vector<int> v ;
	while(n){
		v.push_back(n % 10) ;
		n /= 10 ;
	}
	reverse(v.begin() , v.end()) ;
	for(int i = 0 ; i < v.size() - 1 ; i++){
		if(v[i] < v[i + 1]) return false ;
	}
	return true ;
}

int main(){
	int n ;
	cin >> n ;
	int ans = 0 ;
	for(int i = 1 ; i <= n ; i++){
		ans += ok(i) ;
	}
	cout << ans + 1 ;
	return 0 ;
}

