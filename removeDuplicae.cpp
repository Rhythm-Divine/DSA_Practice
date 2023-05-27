 #include<bits/stdc++.h>
 using namespace std;

  int removeDuplicates(vector<int>& nums) {
        int x=0;
        for(auto i=nums.begin();i!=nums.end();i++){
            if(*i==*(i+1)){
                x++;
                nums.erase(i);
                i--;
            }
        }
        return nums.size()-x;
    }
 int main(){
    vector<int> v={0,0,1,1,1,2,2,3,3,4};
    int ans=removeDuplicates(v);
    cout<<ans<<endl;
 }
 
