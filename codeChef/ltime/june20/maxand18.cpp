#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n , k ;
		cin >> n >> k ;
		int a = 0 ;
		pair<int,int> cnt[32] = {} ;
		for(int i = 0 ; i <= 31 ; i++) cnt[i].second = i ;
		for(int i = 0 ; i < n ; i++){
			int x; cin >> x ;
			for(int j = 30 ; j >= 0 ; j--){
				cnt[j].first += (bool)((1LL<<j)&x) ;
			}
		}
		sort(cnt , cnt + 32 , [&]( pair<int,int> a , pair<int,int> b){
				int x = a.first * (1LL<<a.second) ;
				int y = b.first * (1LL<<b.second) ;
				if(x != y) return x > y ;
				else return a.second < b.second ;
			}) ;
		int ans = 0 , i = 0 ;
		while(k--){
			ans |= (1LL<<cnt[i].second) ;
			i++ ;
		}
		cout << ans << '\n';
	}
	return 0 ;
}

