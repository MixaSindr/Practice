#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream in("guest.txt");
    int n;//колво гостей
    in >> n;
    vector<vector<int>> matrix(n, vector<int>(n));

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            in >> matrix[i][j];
        }
    }

    
    if (n == 0) {
        cout << -1 << endl;
        return 0;
    }

    
    int k = 0;
    for (int i = 1; i < n; i++) {
        if (matrix[k][i] == 1) {
            k = i;
        }
    }

    
    for (int i = 0; i < n; i++) {
        if (matrix[i][k] != 1) {
            cout << -1 << endl;
            return 0;
        }
    }

    
    for (int j = 0; j < n; j++) {
        if (j == k) {
            if (matrix[k][j] != 1) {
                cout << -1 << endl;
                return 0;
            }
        }
        else {
            if (matrix[k][j] != 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    
    cout << k << endl;
    return 0;
}
