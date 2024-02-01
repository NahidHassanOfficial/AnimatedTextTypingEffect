#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    IOS;
    //Animated Hello World Text Typing Effect in C++
    string msg = "hello world", res = "";

    for (size_t i = 0; i < msg.size(); i++)
    {
        if (isspace(msg[i])) { res += ' '; continue; }

        cout << "\r" << res;
        for (size_t j = 'a'; j <= 'z'; j++)
        {
            cout << char(j) << flush;
            this_thread::sleep_for(chrono::milliseconds(100));
            cout << "\b";

            if (msg[i] == j) { res += j; break; }
        }
    }
    cout << "\r" << res;
    this_thread::sleep_for(chrono::seconds(1));
    return 0;
}