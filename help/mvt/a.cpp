#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool check(int& ct , int &wtx , int &wty , int &wtz , int x){
		if(x >= i && wtx <= ct){
			wtx = ct + i ;
		} else if( y >= i && wty <= ct){
			wty = ct + i ;
		} else if( z >= i && wtz <= ct){
			wtz = ct + i ;
		} else {
			
		}
		return true ;
}

int solution(vector<int>&c , int x , int y , int z){
	int ans = 0 ;
	int wtx = 0 , wty = 0 , wtz = 0 ;
	int ct = 0 ;
	for(auto i : c){
		bool found = false ;
		while(max(wtx , wty , wtz) > ct){
			if(check(ct , wtx , wty , wtz , x)){
				found = true ;
				break ;
			}
		}
		if(!found) return 0 ;
	}
}		


int32_t main(){
	int n ; cin >> n ;
	vector<int> c(n) ;
	for(int i = 0 ; i < n ; i++){
		cin >> c[i] ;
	}
	cout << solution(c , x , y , z) ;
	return 0 ;
}

