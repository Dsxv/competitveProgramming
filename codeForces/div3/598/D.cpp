#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int q ;
	cin >> q ;
	while(q--){
		string s ;
		int k ;
		int n ;
		cin >> n >> k >> s ;
		int count = 0 ;
		vector<int> pos ;
		string ans(n,'x') ;
		vector<char> temp ;
		for(int i = 0 ; i < n ; i++){
			if(s[i] == '0'){		
				if(k >= i-count){
					k -= i-count ;
					pos.push_back(count) ;
					ans[count] = '0' ;
					count++ ;
				}else{
					if(k == 0) {
						temp.push_back('0') ;
					}else{
						ans[i-k] = '0' ;
						k = 0 ;
					}
				}
			}else{
				temp.push_back('1') ;
			}
		}
		for(int i = 0 , j = 0 ; i < temp.size() && j < n; j++){
				if(ans[j] == 'x'){
					ans[j] = temp[i++] ;
				}
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

