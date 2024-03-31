#include <vector>

using namespace std;

class FenwickTree2D {
private:
    vector<vector<int>> tree;
    int n, m;

    // Function to update the tree
    void update(int x, int y, int delta) {
        for (int i = x; i <= n; i += i & -i) {
            for (int j = y; j <= m; j += j & -j) {
                tree[i][j] += delta;
            }
        }
    }

    // Function to query the tree
    int query(int x, int y) {
        int sum = 0;
        for (int i = x; i > 0; i -= i & -i) {
            for (int j = y; j > 0; j -= j & -j) {
                sum += tree[i][j];
            }
        }
        return sum;
    }

public:
    // Constructor to initialize the Fenwick Tree
    FenwickTree2D(int rows, int cols) {
        n = rows;
        m = cols;
        tree.assign(n + 1, vector<int>(m + 1, 0));
    }

    // Function to update a cell in the 2D Fenwick Tree
    void updateCell(int x, int y, int delta) {
        update(x, y, delta);
    }

    // Function to query the sum of elements in a rectangle with top-left corner at (x1, y1) and bottom-right corner at (x2, y2)
    int queryRectangle(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
    }
};

int main() {
    // Example usage
    int rows = 5, cols = 5;
    FenwickTree2D ft(rows, cols);

    ft.updateCell(1, 1, 3); // Update cell at (1, 1) by adding 3
    ft.updateCell(2, 2, 2); // Update cell at (2, 2) by adding 2
    ft.updateCell(3, 3, 5); // Update cell at (3, 3) by adding 5

    // Query sum of elements in rectangle from (1, 1) to (3, 3)
    int sum = ft.queryRectangle(1, 1, 3, 3);
    cout << "Sum of elements in rectangle: " << sum << endl;

    return 0;
}
