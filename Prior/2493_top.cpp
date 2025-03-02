#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> findTower(int n,vector<int>& heights) {
    vector<int> result(n,0);
    stack<pair<int, int>> s;

    for (int i=0; i<n; i++){
        while (!s.empty() && s.top().second < heights[i]){
            s.pop();
        }
        if (!s.empty()){
            result[i] = s.top().first + 1;
        }

        s.push({i,heights[i]});
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i<n; i++){
        cin >> heights[i];
    }

    vector<int> result = findTower(n,heights);

    for (int i=0; i<n; i++){
        cout << result[i] << " ";
    }
}