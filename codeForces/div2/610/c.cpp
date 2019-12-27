#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int tc ;
	cin >> tc ;
	while(tc--){
		int n , T , a , b ;
		cin >> n >> T >> a >> b ;
		int v[n] ;
		vector<int> ez , hrd ;
		for(int i = 0 ; i < n ; i++) cin >> v[i] ;
		for(int i = 0 ; i < n ; i++){
			int x ;
			cin >> x ;
			if(v[i]) hrd.push_back(x) ;
			else ez.push_back(x) ;
		}
		sort(ez.begin(),ez.end());
		sort(hrd.begin(),hrd.end()) ;
		int t = 0 ; // cur time if we leave at this
		int ans = 0 ;
		int i = 0, j = 0 ; // i for ez , j for hrd
		while(i < ez.size() && j < hrd.size()) {
			if(t < min(hrd[j],ez[i]) && t <= T 
					&& t >= i*a + j*b) ans = i+j ;
			if(hrd[j] < ez[i]){
				if(t >= hrd[j] || t + a >= hrd[j]) {
					t += b ; j++ ;
				} else {
					t += a ; i++ ;
				}
			} else {
				t += a ; i++ ; continue ;
			}
		}
		while(i < ez.size()){
		   if(t >= b*j + a*i && t < ez[i] && t <= T) {
			   ans = i + j ; t += a ;
		   } i++ ;
		}
		while(j < hrd.size()){
			if(t >= b*j + a*i && t < hrd[j] && t <= T) {
				ans = i + j ; t += b ;
			} j++ ;
		}
		if(T >= i*a + j*b) ans = i + j ;
		cout << ans << endl ;
	}
		

	return 0 ;
}

