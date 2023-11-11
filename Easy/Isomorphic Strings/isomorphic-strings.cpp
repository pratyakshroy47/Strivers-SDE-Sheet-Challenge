//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
   bool areIsomorphic(string str1, string str2)
    {
        if(str1.length() != str2.length())
        {
            return false;
        }
        else if(str1.length() == 1)
        {
            return true;
        }
        else
        {
            //Maps char of str1 with char of str2
            unordered_map<char,char> a;
            unordered_map<char,char> b;

            //itr1,itr2 can be used to check directly in case the element is found
            unordered_map<char,char>::iterator itr1;
            unordered_map<char,char>::iterator itr2;

            for(int i = 0; i < str1.length(); i++)
            {
                if((itr1 = a.find(str1[i])) != a.end())
                {
                    if(itr1->second != str2[i])
                        return false;
                }
                else if((itr2 = b.find(str2[i])) != b.end())
                {
                    if(itr2->second != str1[i])
                        return false;
                }
                a[str1[i]] = str2[i];
                b[str2[i]] = str1[i];
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends