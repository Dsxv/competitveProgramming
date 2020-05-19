#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e7 ;
int a[N] = {} ;

int32_t main() {
    vector<int> v ;
    for(int i = 2 ; i < N ; i++){
        if(!a[i]){
            v.push_back(i) ;
            for(int j = i*i ; j < N ; j+=i){
                a[j] = 1 ;
            }
        }
    }
    int t;
    cin >> t ;
    while(t--){
        int n ;
        cin >> n ;
        cout << v[n]*v[n] << '\n' ;
    }
	return 0 ;
}

