#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n;
	cin >> n ;
	vector<int> a , b ;
	// a is 01 , b is 10
	string s , t ;
	cin >> s >> t ;
	for(int i = 0 ; i < n ; i++){
		if(s[i] != t[i]){
			if(s[i] == '0'){
				a.push_back(i) ;
			} else {
				b.push_back(i) ;
			}
		}
	}
	if(a.size() == 0 && b.size() == 0){
		cout << 0 ;
		return 0 ;
	}
	if(a.size() != b.size()){
		cout << -1 ;
		return 0 ;
	}
	if(a[0] > b[0]){
		swap(a,b) ;
	}
	int mx = 0 ;
	int ans = 0 ;
	bool done = false ;
	for(int i = 0 ; i < a.size() ; i++){
		if(b[i] < a[i]) {
			swap(a,b) ;
			mx = b[i-1] ;
			done = true ;
		}
		ans += a[i] < mx ;
		mx = b[i] ;
	}
	cout << ans + 1 + done;
	return 0 ;
}

