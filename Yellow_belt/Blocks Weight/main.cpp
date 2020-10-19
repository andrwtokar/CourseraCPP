#include <iostream>
#include <cstdint>

using namespace std;

int main() {
    int number = 0;
    int density = 0;
    cin >> number >> density;
    uint64_t Sum_of_volumes = 0;

    for (int i = 0; i < number; i ++) {
        uint64_t W = 0;
        uint64_t H = 0;
        uint64_t D = 0;
        cin >> W >> H >> D;
        Sum_of_volumes += W*H*D;
    }

    cout << Sum_of_volumes*density;
}