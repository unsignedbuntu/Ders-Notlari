// 211213075_ODEV31.cpp : This file contains the 'main' function. Program execution begins and ends there.
 #include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{

        cout << "S --> ";
        string S;
        getline(cin, S);
        cout << "X --> ";
        string X;
        getline(cin, X);

        vector<string> S_rules;
        size_t pos = 0;
        while ((pos = S.find("|")) != string::npos) {
            string ruleS = S.substr(0, pos);
            S_rules.push_back(ruleS);
            S.erase(0, pos + 1);
        }
        S_rules.push_back(S);

        vector<string> X_rules;
        pos = 0;
        while ((pos = X.find("|")) != string::npos) {
            string ruleX = X.substr(0, pos);
            X_rules.push_back(ruleX);
            X.erase(0, pos + 1);
        }
        X_rules.push_back(X);

        unordered_set<string> unique;
        unordered_set<string> repeated;
        for (const string& ruleS : S_rules) {
            vector<string> products;
            products.push_back(ruleS);
            while (products[0].find("X") != string::npos) {
                vector<string> newProducts;
                for (const string& product : products) {
                    for (const string& ruleX : X_rules) {
                        string newProduct = product;
                        size_t pos = newProduct.find("X");
                        newProduct.replace(pos, 1, ruleX);
                        newProducts.push_back(newProduct);
                    }
                }
                products = newProducts;
            }
            for (const string& product : products) {
                if (!unique.insert(product).second) {
                    repeated.insert(product);
                
            }
        }
        cout << "Uretilen kelimeler: ";
        for (const string& word : unique) {
            cout << word << " ";
        }
        cout << endl;
        cout << "Tekrarlanan kelimeler: ";
        for (const string& word : repeated) {
            cout << word << " ";
        }
        cout << endl;

        return 0;
    }



        ""
