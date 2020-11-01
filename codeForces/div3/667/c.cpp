#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool ok(vector<int>& v , int x , int y){
	return count(v.begin() , v.end() , x) * count(v.begin() , v.end() , y) ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , x , y ;
		cin >> n >> x >> y ;
		for(int i = 1 ; i <= 50 ; i++){
			for(int st = 1 ; st <= 50 ; st++){
				vector<int> v ;
				for(int j = 0 ; j < n ; j++){
					v.push_back(st + j*i) ;
				}
				if(ok(v , x , y)){
					for(auto i : v) cout << i << " " ;
					goto here ;
				}
			}
		}
here : cout << '\n';
	}
	return 0 ;
}

