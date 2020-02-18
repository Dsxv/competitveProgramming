#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	int ans = 0 ;
	while(t--){
		int n ;
		cin >> n ;
		map<pair<int,int>,int> mp;
		for(int i = 0 ; i < n ; i++){
			char ch ; int  x ; 
			cin >> ch >> x ;
			mp[{ch-'A'+1,x/3}]++ ;
		}
		int a[] = {1,2,3,4} ;
		int b[] = {1,2,3,4} ;
		int max_val = INT_MIN ;
		do{
			do{	
				int val = 0 ;
				for(int i = 0 ; i < 4 ; i++){ //index is timing
					if(mp.count({i+1,a[i]})){ // a[i] is movie
						val += mp[{i+1,a[i]}]*b[i]*25 ; // b[i] is cost
					} else {
						val -= 100 ;
					}
				}
				max_val = max(val,max_val) ;
			} while(next_permutation(b,b+4)) ;
		} while(next_permutation(a,a+4)) ;
		cout << max_val << endl ;
		ans += max_val ;
	} cout << ans ;
	return 0 ;
}

