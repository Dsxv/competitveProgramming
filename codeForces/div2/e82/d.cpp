#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >>t ;
	while(t--){
		int b[64] = {0} ;
		int x ; cin >> x ;
		bitset<64> a(x) ;
		int temp ; cin >> temp ;
		while(temp--){
			cin >> x ;
			int pw = log2(x) ;
			b[pw]++ ;
		}
		bool found = true ;
		int count = 0 ;
		for(int i = 0 ; i < 63 ;){
			if(!a[i]){
				b[i+1] += b[i]/2 ;
				i++ ;
				continue ;
			}
			if(b[i]){
				b[i]-- ;
				b[i+1] += b[i]/2 ;
				i++ ; continue ;
			} else {
				int ind = -1 ;
				for(int j = i+1 ; j < 63 ; j++){
					if(b[j]) {ind = j ; break ;}
				}
				if(ind == -1) {found = false ; break ;}
				b[ind]-- ;
				count += ind - i ;
				for(int j = ind-1 ; j > i ; j--){
					b[j]++;
				}
				b[i] += 2 ;
			}

		}
		if(found)
			cout << count << endl ;
		else cout << -1 << endl ;
	}
		

	return 0 ;
}

