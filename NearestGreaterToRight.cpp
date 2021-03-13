#include <bits/stdc++.h>
using namespace std;

vector<int> NG2R(vector<int> v);

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> res(n);
    res = NG2R(v);
    for (auto i = res.begin(); i != res.end(); i++)
        cout << *i << " ";
}

vector<int> NG2R(vector<int> v)
{
    stack<int> s;
    vector<int> op;
    for (int i = v.size() - 1; i >= 0 ; i--)
    {
        if (s.size() == 0)
            op.push_back(-1);
        else if (s.size() > 0 && s.top() > v[i])
            op.push_back(s.top());
        else if (s.size() >= 0 && s.top() <= v[i])
        {
            while (s.size() > 0 && s.top() <= v[i])
            {
                s.pop();
            }
            if (s.empty())
                op.push_back(-1);
            if (s.top() > v[i])
                op.push_back(s.top());
        }
        s.push(v[i]);
    }

    return op;
}
