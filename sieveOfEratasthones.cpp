#include <bits/stdc++.h>
using namespace std;

// int N=1e7;
// vector<int> sieve(N,1);
// void sieveOE(){
//     sieve[0]=sieve[1]=false;
//     for(int i=2;i*i<=N;i++){
//         if(sieve[i]==true){
//             for(int j=i*i;j<=N;j+=i){
//                 sieve[j]=false;
//             }
//         }
//     }
// }
// int main(){
//     sieveOE();
//      for(auto i=sieve.begin();i!=sieve.begin()+20;i++){
//         cout<<*i<<" ";
//      }
// }
int distinctPrimeFactors(vector<int>& nums) {
        vector<int> sieve(1001,1);
        sieve[0]=sieve[1]=0;
        for(int i=2;i*i<=1001;i++){
            if(sieve[i]==1){
                for(int j=i*i;j<=1001;j+=i){
                    sieve[j]=0;
                }
            }
        }
        for(int i=0;i<=20;i++)cout<<sieve[i]<<" ";
        int ans=0;
        for(auto i:nums){
            if(sieve[i]){
                ans++;
            }
        }
        return ans;
    }
    int main(){
        vector<int> v={2,4,3,7,10,6};
        cout<<distinctPrimeFactors(v);
    }