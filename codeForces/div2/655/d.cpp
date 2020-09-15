#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(vector<int>& a , int k){
	int mx = 0 ;
	for(int i = 0 ; i < k ; i++){
		mx += a[i] ;
	}
	int cur = mx ;
	for(int i = k ; i < a.size() ; i++){
		cur -= a[i-k] ;
		cur += a[i] ;
		if(mx < cur) mx = cur ;
	}
	return mx ;
}

int32_t main(){
	int n;
	cin >> n;
	int tp[2*n] ;
	vector<int> a , b ;
	for(int i = 0 ; i < n ; i++){
		cin >> tp[i] ;
		tp[i+n] = tp[i] ;
	}
	for(int i = 0 ; i < 2*n ; i++){
		if(i&1){
			b.push_back(tp[i]) ;
		} else {
			a.push_back(tp[i]) ;
		}
	}
	cout << max(solve(a,n+1 >> 1) , solve(b , n+1 >> 1)) ;
	return 0 ;
}

