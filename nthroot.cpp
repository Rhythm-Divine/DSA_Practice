#include<bits/stdc++.h>
using namespace std;


int NthRoot(int n, int m)
	{
	    long long int lo=0;
	    long long int hi=m;
	    
	    while(lo<=hi){
	        long long int mid=floor((hi+lo)/2);
	        long long int root=pow(mid,n);
	        if(m==root){
	            return mid;
	        }
	        else if(root>m){
	            hi=mid-1;
	        }else{
	            lo=mid+1;
	        }
	    }
	    return -1;
	}
    int main(){
        int ans=NthRoot(2,16);
        cout<<ans<<endl;
    }