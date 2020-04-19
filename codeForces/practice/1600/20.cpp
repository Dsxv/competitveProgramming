#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool is_subseq(string a , string b){
	for(int i = 0 , j = 0 ; j < b.size() && i < a.size() ; i++){
		if(a[i] == b[j]){
			j++ ;
		}
		if(j == b.size()) return true ;
	}
	return false ;
}

bool check(int x ,int* a , string&s , string& t){
	int temp[s.size()] = {} ;
	for(int i = 0 ; i < x ; i++){
		temp[a[i]-1] = 1 ;
	}
	string ns = "" ;
	for(int i = 0 ; i < s.size() ; i++){
		if(!temp[i]) ns += s[i] ;
	}
	return is_subseq(ns,t) ;
}

int32_t main(){
	string s ;
	string target ;
	cin >> s >> target ;
	int n = s.size() ; 
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	int lo = 0 , hi = n - 1 ;
	int ans = -1 ;
	while(lo <= hi){
		int mid = (lo + hi) / 2 ;
		if(check(mid,a,s,target)) {
			lo = mid + 1 ;
			ans = mid ;
		} else {
			hi = mid - 1 ;
		}
	}
	cout << ans ;
	return 0 ;
}

