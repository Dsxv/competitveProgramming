#include <bits/stdc++.h>
using namespace std ;

int main(){
    int t ;
    cin >> t ;
    for(int x = 1 ; x <= t ; x++){
        string s ;
        cin >> s ;
        int ic = 0, Ic = 0 , count = 0 ;
        for(auto  i : s){
            ic += (i == 'i') ;
            Ic += (i == 'I') ;
            if(i == 'O'){
                if(Ic) Ic-- , count++ ;
                else ic-- ;
            } else if(i == 'o') {
                if(ic) ic-- ;
                else Ic-- ;
            }
        }
        printf("Case #%d: %d\n",x,count) ;
    }
}
