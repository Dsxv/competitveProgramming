#include <bits/stdc++.h>
using namespace std ;

#define int long long
pair<int,int> a , b ;
int odd , even ;
int32_t main(){
	string s ;
	cin >> s ;
	int n = s.size() ;
	s = "x" + s ;
	for(int i = 1 ; i <= n; i++){
		if(i%2){
			if(s[i] == 'a'){
				odd += a.first ;
				even += a.second ;
				a.first++ ;
			} else {
				odd += b.first ;
				even += b.second ;
				b.first++ ;
			}
		} else {
			if(s[i] == 'a'){
				odd += a.second ;
				even += a.first ;
				a.second++ ;
			} else {
				odd += b.second ;
				even += b.first ;
				b.second++ ;
			}
		} odd++ ;
	}
	cout << even << " " << odd ;
	return 0 ;
}

