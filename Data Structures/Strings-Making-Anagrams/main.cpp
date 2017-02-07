#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int number_needed(const string &a, const string &b) {

    int hashtableA[26] = {0}, hashtableB[26] = {0};
    for( int i = 0 ; i < a.size() ; i ++ )
        hashtableA[a[i]-'a'] ++;
    for( int i = 0 ; i < b.size() ; i ++ )
        hashtableB[b[i]-'a'] ++;

    int res = 0;
    for( int i = 0 ; i < 26 ; i ++ )
        res += abs( hashtableA[i] - hashtableB[i] );

    return res;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
