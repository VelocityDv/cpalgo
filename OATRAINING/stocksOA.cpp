#include <bits/stdc++.h>
using namespace std;

// Define the Dividend struct
struct Dividend {
    int amount;
    int days;
};

// Define the Node struct for the segment tree
struct Node {
    int lazy;
};

// Define the FuturePricingEngine class
class FuturePricingEngine {
private:
    int stock_price;
    vector<Dividend> dividends;

public:
    // Constructor to initialize the stock price and dividends
    FuturePricingEngine(int stock_price, vector<Dividend>& dividends)
        : stock_price(stock_price), dividends(dividends) {
        
    }

    // Method to update a dividend
    void update_dividend(int dividend_id, Dividend update_dividend) {
        dividends[dividend_id-1] = update_dividend;
    }

    // Method to calculate future price for a given day
    int calculate_future_price(int days_to_future) {
        int cur_price = stock_price;
        for(auto dividend : dividends){
            if(days_to_future >= dividend.days){
                cur_price -= dividend.amount;
            }
        }

        return cur_price;
    }
};


int main() {
#ifndef LOCAL	
	freopen("input.txt", "r", stdin);     
	freopen("output.txt", "w", stdout);     
#endif
    int stock_price, N, Q;
    cin >> stock_price >> N >> Q;

    vector<Dividend> dividends(N);
    for (int i = 0; i < N; ++i) {
        cin >> dividends[i].amount >> dividends[i].days;
    }

    FuturePricingEngine engine(stock_price, dividends);

    string line;
    cin.ignore();
    for (int i = 0; i < Q; ++i) {
        getline(cin, line);
        stringstream ss(line);
        string op;
        ss >> op;
        if (op == "PRICE") {
            int day;
            ss >> day;
            cout << engine.calculate_future_price(day) << endl;
        } else if (op == "DIVIDEND_UPDATE") {
            int index, amount, days;
            ss >> index >> amount >> days;
            Dividend dividend;
            dividend.amount = amount;
            dividend.days = days;
            engine.update_dividend(index, dividend);
        }
    }

    return 0;
}
