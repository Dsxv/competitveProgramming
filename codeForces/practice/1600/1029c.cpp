#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	pair<int,int> suf[n] ;
	pair<int,int> p[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> p[i].first >> p[i].second ;
	}
	suf[n-1] = p[n-1] ;
	for(int i = n - 2 ; i >= 0 ; i--){
		suf[i].first = max(p[i].first , suf[i+1].first) ;
		suf[i].second = min(p[i].second , suf[i+1].second) ;
	}
	pair<int,int> a = p[0] ;
	int mx = max(0LL , suf[1].second - suf[1].first) ;
	for(int i = 1 ; i < n - 1 ; i++){
		pair<int,int> temp = {max(suf[i+1].first , a.first) , min(suf[i+1].second , a.second)} ;
		mx = max(mx , temp.second - temp.first) ;
		a.first = max(p[i].first , a.first) ;
		a.second = min(p[i].second , a.second) ;
	}
	mx = max(mx , a.second - a.first) ;
	cout << mx ;
	return 0 ;
}

