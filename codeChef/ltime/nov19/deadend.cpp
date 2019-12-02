#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	 int t ;
	 cin >> t ;
	 while(t--){
		 int n ;
		 cin >>  n;
		 map<int,int> mp ;
		 int a[n] ;
		 for(int i = 0 ; i < n ; i++){
			 cin >> a[i] ;
			 mp[a[i]] = 1 ;
		 }
		 sort(a,a+n) ;
		 for(int i = 0 ; i < n ; i++){
			 if(mp.count(a[i]-1) || mp.count(a[i]+1)) continue ;
			 mp[a[i]+1] = 1 ;
		 }
		 cout << mp.size() - n << '\n' ;
	 }
	return 0 ;
}

