#include <bits/stdc++.h>
using namespace std ;
#define int long long

bool check(int s , int mid , pair<int,int>* a, int n){
	vector<pair<int,int>> v ;
	int count = 0 ;
	for(int i = 0 ; i < n ; i++) {
		if(a[i].first >= mid) count++ , s -= a[i].first;
		if(a[i].second < mid) s -= a[i].first ;
		if(a[i].first < mid && a[i].second >= mid) v.push_back(a[i]) ;
	}
	int rem = (n+1)/2 - count ;
	// remaining elements >= mid
	if(rem < 0 ) rem = 0 ;
	if(v.size() < rem) return 0 ;
	for(int i = 0 ; i < v.size() ; i++){
		if(i < v.size() - rem) s -= v[i].first ;
		else s -= mid ; // the elements greater than mid (rem elements)
	}
	return s >= 0 ;
}

int solve(pair<int,int>* a , int s , int n){
	int lo = 0 , hi = s ;
	int ans = 0;
	while(lo <= hi){
		int mid = (lo+hi)/2 ;
		if(check(s,mid,a,n)){
			ans = max(ans,mid) ;
			lo = mid+1 ;
		}else{
			hi = mid-1;
		}		
	}
	return ans ;
}


int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , s ;
		cin >> n >> s ;
		pair<int,int> a[n] ;
		for(int i = 0 ; i < n ; i++) 
			cin >> a[i].first >> a[i].second ;
		sort(a,a+n);
		//cout << check(s,26,a,n) ;
		//cout << check(s,68,a,n) ;
		cout << solve(a,s,n) << '\n' ;
	}
	return 0 ;
}

