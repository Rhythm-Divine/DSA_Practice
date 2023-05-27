
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n+1]={0};
	    for(int i=0; i<n; i++) 
	    {
	        int temp;
	        cin>>temp;
	        a[temp]++;
	    }
	    for(int i=0; i<2; i++)
	    {
	        for(int j=0; j<n-i; j++)
	        {
	            if(a[j]>a[j+1])
	            {
	                swap(a[j],a[j+1]);
	            }
	        }
	    }
	    int temp;
	    if(a[n]%2) temp=a[n]/2+1;
	    else temp=a[n]/2;
	    cout<<max(a[n-1],temp)<<endl;
	}
	
}