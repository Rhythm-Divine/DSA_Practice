#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BrowserHistory {
public:
    vector<string> v;
    int curr;
    BrowserHistory(string homepage) {
        v.clear();
        curr=0;
        v.push_back(homepage);
    }
    
    void visit(string url) {
        v.push_back(url);
        curr=v.size()-1;
    }
    
    string back(int steps) {
        if(steps>curr){
            curr=0;
            return v[0];
        }else{
            curr=curr-steps;
            return v[curr];
        }
    }
    
    string forward(int steps) {
        if(steps>v.size()-curr-1){
            curr=v.size()-1;
            return v.back();
        }else{
            curr=curr+steps;
            return v[curr]; 
        }
    }
};

int main() {
    BrowserHistory browser("leetcode.com");
    browser.visit("google.com");
    browser.visit("facebook.com");
    browser.visit("youtube.com");
    cout << browser.back(1) << endl;  // should print "facebook.com"
    cout << browser.back(1) << endl;  // should print "google.com"
    cout << browser.forward(1) << endl;  // should print "facebook.com"
    browser.visit("linkedin.com");
    cout << browser.forward(2) << endl;  // should print "linkedin.com"
    cout << browser.back(2) << endl;  // should print "google.com"
    cout << browser.back(7) << endl;  // should print "leetcode.com"
    return 0;
}