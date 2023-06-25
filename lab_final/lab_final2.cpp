// Implement deleteWord(string s, string s1) function with function to print string s after deleting all strings s1 contained in s.

#include <iostream>
#include <string>

using namespace std;

void deleteWord(string s, string s1)
{
    string result = s;
    int found = result.find(s1);
    while (found != string::npos){
        result.erase(found, s1.length());
        found = result.find(s1);
    }
    cout << result;
}

int main()
{
    string s = "Truong Dai Hoc Bach Khoa, Sai Gon";
    string s1 = "ai ";
    deleteWord(s, s1);
}
