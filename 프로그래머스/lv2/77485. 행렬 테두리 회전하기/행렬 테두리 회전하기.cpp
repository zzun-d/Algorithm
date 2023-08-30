
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> arr;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<int> row;
    for (int i=1; i<=rows*columns; i++) {
        row.push_back(i);
        if (i%columns == 0) {
            arr.push_back(row);
            row.clear();
        }
    }
    
    for (int i=0; i<queries.size(); i++) {
        int nm = rows*columns;
        int x1 = queries[i][0]-1, y1 = queries[i][1]-1, x2 = queries[i][2]-1, y2 = queries[i][3]-1;
        int tmp = arr[x1][y1];
        for (int x = x1; x < x2; x++) {
            arr[x][y1] = arr[x+1][y1];
            if (nm > arr[x][y1]) nm=arr[x][y1];
        }
        for (int y=y1; y<y2;y++) {
            arr[x2][y] = arr[x2][y+1];
            if (nm > arr[x2][y]) nm=arr[x2][y];
        }
        for (int x=x2; x>x1; x--) {
            arr[x][y2] = arr[x-1][y2];
            if (nm > arr[x][y2]) nm=arr[x][y2];
        }
        for (int y=y2; y>y1+1; y--) {
            arr[x1][y] = arr[x1][y-1];
            if (nm > arr[x1][y]) nm=arr[x1][y];
        }
        arr[x1][y1+1] = tmp;
        if (nm > tmp) nm = tmp;
        answer.push_back(nm);
    }
    
    return answer;
}