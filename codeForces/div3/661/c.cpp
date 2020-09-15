#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		map<int,int> mp ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
			mp[a[i]]++ ;
		}
		int mx = 0 ;
		for(int i = 2 ; i <= 2*n ; i++){
			map<int,int> temp = mp ;
			int cnt = 0 ;
			for(int j = 0 ; j < n ; j++){
				bool ok = false , hmm = false ; ;
				if(temp[a[j]]) temp[a[j]]-- , hmm = true;
				if(hmm && temp[i-a[j]]){
					ok = true ;
					temp[i-a[j]]-- ;
					cnt++ ;
				}
				if(!ok && hmm) temp[a[j]]++ ;
			}
			mx = max(mx , cnt) ;
		}
		cout << mx  << '\n';
	}
	return 0 ;
}

