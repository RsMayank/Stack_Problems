#include <bits/stdc++.h>
using namespace std;


//function 
vector<int> stockSpan(vector<int> v)
{
    vector<int> op;
    stack<pair<int, int>> s;
    for (int i = 0; i < v.size(); i++)
    {
        if (s.empty())
            op.push_back(-1);
        else if (!s.empty() and s.top().first > v[i])
            op.push_back(s.top().second);
        else if (!s.empty() && s.top().first <= v[i])
        {
            while (!s.empty() and s.top().first <= v[i])
            {
                s.pop();
            }
            if (s.empty())
                op.push_back(-1);
            else
                op.push_back(s.top().second);
        }
        s.push({v[i], i});
    }
    for (int i = 0; i < v.size(); i++)
    {
        op[i] = abs(op[i] - i);
    }
    return op;
}
// Main Function // Code By @rsMayank 
int main()
{
  // to print output after full execution of the code
    ios::sync_with_stdio(0);
    cin.tie(0);
  //test Cases
    int t;
    cin >> t;
  // while loop 
while(t--)
{
    int s;
    cin >> s;
    vector<int> v(s);
    for (int i = 0; i < s; i++)
    {
        cin >> v[i];
    }

    vector<int> res(s);

    res = stockSpan(v);
    for (auto i = res.begin(); i != res.end(); i++)
        cout << *i << " ";
    cout << endl;
}
}
