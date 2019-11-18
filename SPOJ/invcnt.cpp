#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std ;
using namespace __gnu_pbds ;

typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> 
 ordered_set; 

int n ;

void update(int* bit , int ind , int val){
    while(ind <= n){
        bit[ind] += val ;
        ind += -ind&ind ;
    }
}

int query(int* bit , int ind){
   int sum = 0 ;
   while(ind > 0){
       sum += bit[ind] ;
       ind -= -ind&ind ;
   }
   return sum ;
}

int main(){
    ios :: sync_with_stdio(0) ; cin.tie(0) ;
    int t ;
      cin >> t ;
      while(t--){
          cin >> n ;
          int a[n+1] ; 
          int bit[n+1] = {0};
          ordered_set s;
          for(int i = 0 ; i < n ; i++){
              cin >> a[i] ; s.insert(a[i]) ;
          }
          int b[n] ;
          for(int i = 0 ; i < n ; i++){
              b[i] = s.order_of_key(a[i])+1 ;
          }
          long long ans = 0 ; 
          for(int i = n - 1; i >= 0 ; i--){
             ans += query(bit,b[i]) ;
             update(bit, b[i], 1) ;
          }
          cout << ans << '\n' ;
    }
}

