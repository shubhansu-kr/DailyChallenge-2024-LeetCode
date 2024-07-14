// https://leetcode.com/problems/number-of-atoms/?envType=daily-question&envId=2024-07-14

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    typedef unordered_map<string, int> AtomMap;

    string countOfAtoms(string chemicalFormula) {
        int length = chemicalFormula.length();
        
        stack<AtomMap> atomStack;
        atomStack.push(AtomMap());

        int index = 0;

        while (index < length) {
            if (chemicalFormula[index] == '(') {
                atomStack.push(AtomMap());
                index++;
            } else if (chemicalFormula[index] == ')') {
                AtomMap innerMap = atomStack.top();
                atomStack.pop();
                index++;
                string numberStr;
                while (index < chemicalFormula.length() && isdigit(chemicalFormula[index])) {
                    numberStr += chemicalFormula[index];
                    index++;
                }
                if (!numberStr.empty()) {
                    int multiplier = stoi(numberStr);
                    for (auto& [element, quantity] : innerMap) {
                        innerMap[element] = quantity * multiplier;
                    }
                }

                for (auto& [element, quantity] : innerMap) {
                    atomStack.top()[element] += quantity;
                }
            } else {
                string element;
                element += chemicalFormula[index];
                index++;
                while (index < chemicalFormula.length() && islower(chemicalFormula[index])) {
                    element += chemicalFormula[index];
                    index++;
                }

                string quantityStr;
                while (index < chemicalFormula.length() && isdigit(chemicalFormula[index])) {
                    quantityStr += chemicalFormula[index];
                    index++;
                }

                int quantity = quantityStr.empty() ? 1 : stoi(quantityStr);
                atomStack.top()[element] += quantity;
            }
        }
        
        map<string, int> sortedAtoms(begin(atomStack.top()), end(atomStack.top()));

        string result;
        for (auto& [element, quantity] : sortedAtoms) {
            result += element;
            if (quantity > 1) {
                result += to_string(quantity);
            }
        }

        return result;
    }
};

int main () {
    
    return 0;
}