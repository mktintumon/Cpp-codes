#include <bits/stdc++.h>
using namespace std;
 
#define V 4
#define INF 99999
 
void floydWarshall(int matrix[][V]){ 
    for (int k = 0; k < V; k++) {
        // visit all cells of matrix
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if(matrix[i][k] == INF || matrix[k][j] == INF){
                    continue;
                }
                else if(matrix[i][j] == INF){
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
                else{
                    matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }
}

void printMatrix(int matrix[][V]){
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (matrix[i][j] == INF)
                cout << "INF" << "  ";
            else
                cout << matrix[i][j] << "    ";
        }
        cout << endl;
    }
}
 

int main(){
    int matrix[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0} 
                      };
 
    cout << "Given Matrix :" << endl;
    printMatrix(matrix);
    cout << endl;
    floydWarshall(matrix);
    cout << "All path shortest distance Matrix :" << endl;
    printMatrix(matrix);
    return 0;
}
 