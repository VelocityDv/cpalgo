
// Define the FenwickTree class
class FenwickTree {

public:

    vector<int> tree;

    FenwickTree(int n) {
        tree.resize(n + 1, 0);
    }

    // realise that delta is the change in the amount we want to be updated
    // for example at index 2 has value -3
    // to change index 2 to value 7
    // delta is 10. 
    void update(int index, int delta) {
        for (int i = index + 1; i < tree.size(); i += (i & -i)) {
            tree[i] += delta;
        }
    }

    // this method find the sum of our array at sub length
    // realise that if we want to get the sum from left index to right index
    // call query(right index) - query(left index - 1)
    int query(int index) {
        int sum = 0;
        for (int i = index + 1; i > 0; i -= (i & -i)) {
            sum += tree[i];
        }
        return sum;
    }
};



fenwick_tree(arr.size()) {
for (int i = 0; i < arr.size(); ++i) {
    fenwick_tree.update(i, arr[i]);
}
