#include <bits/stdc++.h>
using namespace std;
vector <int> NS2R(vector <int> v)
{
    stack <int> s;
    vector <int> op;
    for(int i = v.size() - 1 ; i >= 0 ; i--)
    {
        if( s.empty())
            op.push_back(-1);
        else if(!s.empty() and s.top() < v[i])
            op.push_back(s.top());
        else if(!s.empty() and s.top() >= v[i])
        {
            while(!s.empty() and s.top() >= v[i])
            {
                s.pop() ;
            }

            if( s.size() == 0)
            {
                op.push_back(-1);
            }
            else
                op.push_back(s.top());
        }

        s.push(v[i]);
    }
    reverse(op.begin() , op.end());
    return op;
}
vector <int> NS2L(vector <int> v)
{
    stack <int> s;
    vector <int> op ;
    for(int i = 0; i < v.size() ; i++)
    {
        if(s.empty())
            op.push_back(-1);
        else if (!s.empty() && s.top() < v[i])
            op.push_back(s.top());
        else if(!s.empty() and s.top() >= v[i])
        {
            while(s.size() > 0 and s.top() >= v[i])
            {
                s.pop();
            }
            if(s.empty())
                op.push_back(-1);
            else
                op.push_back(s.top());
        }
        s.push(v[i]);
    }
    return op;
}

int main()
{
    int n ;
    cin >> n;
    vector <int> v(n);
    for(int i = 0 ; i < n ; i++ )
     cin >> v[i];
    vector <int> res (n); 
    vector <int> res1 (n); 
    res = NS2R(v);
    res1 = NS2L(v);
    cout << "NEAREST SMALLEST ELEMENT TO RIGHT : " <<endl;
    for(auto i = res.begin() ; i != res.end() ; i ++)
        cout << *i << " ";
    cout << endl;
    cout << "NEAREST SMALLEST ELEMENT TO LEFT :\n";
    for(auto i = res1.begin() ; i != res1.end() ; i ++)
        cout << *i << " ";

    cout << endl ;
    return 0;
}