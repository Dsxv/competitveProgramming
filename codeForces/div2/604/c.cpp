#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n] ;
		vector<pair<int,int>> l ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		int sum = 0 ;
		for(int i = 0 ; i < n ; i++){
			int j = i ;
			while(j < n && a[i] == a[j]) ++j ;
			if(sum + j - i > n/2) break ;
			else sum += j - i ;
			l.push_back({a[i],j-i}) ;
			i = j - 1 ; 
		}
		if(l.size() > 0){
			int i = 1 ;
			int g = l[0].second , s = 0 , b = 0 ;
			while(i < l.size() && s <= g){
				s += l[i++].second ;
			}
			while(i < l.size()){
				b += l[i++].second ;
			}
			if(s > g && b > g) cout << g <<" "<<s<<" "<<b ;
		    else cout << 0 << " " << 0 << " " << 0 ;
		} else {
			cout << 0 << " " << 0 << " " << 0 ;
		}
	}
	return 0 ;
}

