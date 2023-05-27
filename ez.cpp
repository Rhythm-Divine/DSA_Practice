#include<bits/stdc++.h>
using namespace std;
	int minCoins(int coins[], int M, int V) 
	{
	    int ans=0;
	    int i=0;
	    sort(coins,coins+M,greater<>());
	    while(i<M && V>0){
	        if(V>=coins[i]){
	            V-=coins[i];
	            ans++;
	        }else{
	            i++;
	        }
	    }
	    if(V!=0){
	        return -1;
	    }else{
	        return ans;
	    }
	} 
int main(){
    int arr[2]={6,5};
    int ans=minCoins(arr,2,40);
    cout<<ans<<endl;
}