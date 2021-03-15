#include <bits/stdc++.h>
using namespace std ;

ios:: sync_with_stdio(0);
cin.tie(0) ;

// Fuction to clalculate smallest left index 
vector <int> smallestLeft(vector <int> v)
{
    stack <pair <int ,int > > s;
    vector <int> op;
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(s.empty())
            op.push_back(-1);
        else if(!s.empty() and s.top().first < v[i])
            op.push_back(s.top().second) ;
        else if(!s.empty() and s.top().first >= v[i])
        {
            while(!s.empty() and s.top().first >= v[i])
            {
                s.pop() ;
            }
            if(s.empty())
                op.push_back(-1);
            else
                op.push_back(s.top().second) ;
        }

        s.push({v[i], i}) ;
    }

    return op;
}



//Function To Clalculate Smallest right element 

vector < int > smallestRight(vector <int> v)
{
    stack <pair <int ,int> > s;
    vector < int > op ;
  
  // Psuedo Index thats Assume the last index is Size of Vector ( if vector array = { 1 , 2 , 3 } , index [ 0 , 1 , 2 ] respectively so pi will be 3;
    int pi = v.size();

    for(int i = v.size() - 1 ; i >= 0 ; i-- )
    {
        if(s.size() == 0 )
            op.push_back(pi);
        else if(!s.empty() && s.top().first < v[i] )
            op.push_back(s.top().second);
        else
        {
            while(!s.empty() && s.top().first >= v[i])
            {
                s.pop();
            }
            if(s.empty())
                op.push_back(pi);
            else
                op.push_back(s.top().second);
        }
        s.push({v[i], i});
    }


reverse(op.begin(), op.end());
return op;
}

//Function 

//Fucntion to calcuate """ Maximum Area Histogram """"

// This will return max area in 1 D array ;
int MAH (vector <int> v)
{
    int n = v.size() ;
    vector <int> left , right , width(n) ;
    left = smallestLeft(v);
    right = smallestRight(v);
    for(int i = 0 ; i < v.size() ; i++)
        width[i] = right[i] - left[i] - 1;
    vector <int> area ;
    for(int i = 0 ; i < n ; i++)
        area.push_back(v[i] * width[i]) ;
    int mx = *max_element(area.begin(),area.end()) ;
    return mx ;

}

// fucntion to calculate max area in 0 & 1 matrix Histogram

int maxArea(vector <vector<int>> v)
{
    int row = v.size() ; 
    int cl = v[0].size() ;
    vector <int> temp ;

    for(int j = 0 ; j < row ; j++)
        temp.push_back(v[0][j]);

    int mx = MAH(temp) ;

    for(int i = 1 ; i < row ; i++)
    {
        for(int j = 0 ; j < cl ; j++ )
        {
            if (v[i][j] == 0)
                temp[j] = 0;
            else
                temp[j] =temp[j] + v[i][j] ;
        }
        mx = max(mx  , MAH(temp));
    }

    return mx;
    
}

//End Of function Definitions 

// Main Function // Code By @rsMayank




int main()
{
    int m , n ; 
    // Row * column
    cin >>  m >> n ;
    vector <vector <int>> v;
    for(int i = 0 ; i < m ; i ++)
    {
        vector <int> t(n) ;
        for(int j = 0 ; j < n ; j++)
        {
            cin >> t[j];
        }
        v.push_back(t);
        t.empty();
    }

    int res = maxArea(v);
    cout << res << endl ;
    return 0;
}
