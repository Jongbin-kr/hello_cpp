#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int LCS(const string& S, const string& T) {
    int m = S.size();
    int n = T.size();

    // TODO 1: Initialize LCS matrix (n+1) x (m+1)
    vector<vector<int>> matrix(n+1, vector<int>(m+1, 0));
    // TODO 2: Implement LCS algorithm
    for (int i=1; i <= m; ++i){
        for (int j=1; j <= n; ++j){
          if (S[i-1] == T[j-1]){
            matrix[i][j] = matrix[i-1][j-1] + 1;
          }  
          else{
            matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]);  // max(지금 다루고 있는 i번째 문자열을 넣지 않은 경우, 넣은 경우)
          }
        }
    }
    // TODO 3: Return the final answer
    return matrix[n][m];
}

int main() {
    string S = "ABAZDC";
    string T = "BACBAD";

    int result = LCS(S, T);
    cout << "LCS length: " << result << endl; // LCS length: 4

    return 0;
}




