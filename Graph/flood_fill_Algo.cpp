#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newcolor, int delrow[], int delcol[], int inicolor) {
    ans[row][col] = newcolor;
    int n = image.size();
    int m = image[0].size();
    for (int i = 0; i < 4; i++) {
        int nebrow = row + delrow[i];
        int nebcol = col + delcol[i];
        if (nebrow >= 0 && nebrow < n && nebcol >= 0 && nebcol < m &&
            image[nebrow][nebcol] == inicolor && ans[nebrow][nebcol] != newcolor) {
            dfs(nebrow, nebcol, ans, image, newcolor, delrow, delcol, inicolor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    int inicolor = image[sr][sc];
    if (inicolor == newColor) 
    return image; // Avoid infinite recursion if the color is already the same
    
    vector<vector<int>> ans = image;
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};
    dfs(sr, sc, ans, image, newColor, delrow, delcol, inicolor);
    return ans;
}

int main() {
    vector<vector<int>> img = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    // Coordinates provided by the user
    int x = 1;
    int y = 1;

    // New color that has to be filled
    int newClr = 3;

    // Update the image with the flood fill
    vector<vector<int>> updatedImg = floodFill(img, x, y, newClr);

    // Print the updated image
    for (int i = 0; i < updatedImg.size(); i++) {
        for (int j = 0; j < updatedImg[0].size(); j++) {
            cout << updatedImg[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
