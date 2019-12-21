#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t; 
	cin >> t;
	while(t--){
		int n; 
		cin >> n ;
		n *= 2 ;
		map<int,int> mp ;
		int a[n+2] = {0};
		for(int i = 0 ; i < n ; i++) cin >> a[i+1] ;
		int count = 0 ;
		mp[0] = n+1;
		for(int i = n ; i > n/2 ; i--){
			count += a[i] == 1 ;
			int st = count , bl = (n-i-count+1) ;
			mp[st-bl] = i ;
		}
	   //cout << "map\n";
		//for(auto i : mp) cout << i.first << " " << i.second << endl ;
		count = 0 ;
		int ans = INT_MAX ;
		for(int i = 1 ; i <= n/2 + 1; i++){
			count += a[i-1] == 1 ;
			int st = count , bl = i - count - 1;
			//cout << bl - st << " ";
			if(mp.count(bl-st)) {
				int r = mp[bl-st] ;
				//cout << r << ":" << i << " ";
				ans = min(ans,r-i) ;
			}
		}
		cout << ans << endl ;
	}
	return 0 ;
}

