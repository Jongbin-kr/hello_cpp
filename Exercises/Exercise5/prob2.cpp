#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int levenshteinDistance(const std::string& s, const std::string& t) {
    int m = s.size();
    int n = t.size();

    // TODO 1: Initialize DP matrix (n+1) x (m+1)
    int** matrix = new int*[m];
    for (int i=0; i <= n; ++i){
        for (int j=0; j <= m; ++j){
            if (i == 0 || j == 0){
                matrix[i][j] = std::max(i, j);
            }
            else{
                matrix[i][j] = 0;
            }
        }
    }
    
    // TODO 2: Implement Levenshtein distance algorithm
    for (int i=1; i <= n; ++i){
        for (int j=1; j <= m; ++j){
            if (s[i-1] == t[j-1]){
                matrix[i][j] = matrix[i-1][j-1];
            }
            else{
                matrix[i][j] = 1 + std::min({matrix[i][j-1], matrix[i-1][j-1], matrix[i-1][j]});
            }
        }
    }
    
    // TODO 3: Return the final answer
    return matrix[n][m];
}

int main() {
    std::string s = "data";
    std::string t = "depth";

    int distance = levenshteinDistance(s, t);
    std::cout << "Levenshtein Distance: " << distance << std::endl; // Levenshtein Distance: 3

    return 0;
}




