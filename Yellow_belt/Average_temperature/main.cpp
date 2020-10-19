#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main() {
    int number = 0;
    cin >> number;
    int_fast64_t sum = 0;
    vector<int_fast64_t> temperatures(number);

    for (auto i = 0; i < temperatures.size(); i++) {
        cin >> temperatures[i];
        sum += temperatures[i];
    }

    int_fast64_t average = sum/number;
    vector<int> numbers;
    number = 0;

    for (auto i = 0; i < temperatures.size(); i++) {
        if (temperatures[i] > average) {
            number +=1;
            numbers.push_back(i);
        }
    }

    cout << number << endl;
    for (int i : numbers) {
        cout << i << " ";
    }


}