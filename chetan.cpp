// A Naive recursive C++ program to find the number of
// times the second string occurs in the first string,
// whether continuous or discontinuous
#include <iostream>
using namespace std;

// Recursive function to find the number of times
// the second string occurs in the first string,
// whether continuous or discontinuous
int count(string a, string b, int m, int n)
{
	// If both first and second string is empty,
	// or if second string is empty, return 1
	if ((m == 0 && n == 0) || n == 0)
		return 1;

	// If only first string is empty and second
	// string is not empty, return 0
	if (m == 0)
		return 0;

	// If last characters are same
	// Recur for remaining strings by
	// 1. considering last characters of both strings
	// 2. ignoring last character of first string
	if (a[m - 1] == b[n - 1])
		return count(a, b, m - 1, n - 1) +
			count(a, b, m - 1, n);
	else
		// If last characters are different, ignore
		// last char of first string and recur for
		// remaining string
		return count(a, b, m - 1, n);
}

// Driver code
int main()
{ 
    string a;
    cin>>a;
    string arr[8]={"00000", "01010", "10001", "11011", "00100", "01110", "10101", "11111"};
int ans=0;
	for(int i=0;i<8;i++){
        ans+=count(a, arr[i], a.size(), arr[i].size());
    }

	//cout << count(a, b, a.size(), b.size()) << endl;
    cout<<ans<<"\n";
	return 0;
}
