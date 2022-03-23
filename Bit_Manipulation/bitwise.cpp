#include <iostream>
using namespace std;
// Gets the bit(0 or 1) at i'th position of a number
int getBit(int n, int pos) {
    return ((n & (1<<pos))!=0);
}
// Sets the bit to 1 at given pos
int setBit(int n, int pos) {
    return (n | (1<<pos));
}
// Sets the bit to 0 at given pos
int clearBit(int n, int pos) {
    return (~(1<<pos) & n);
}
// Mix of set and clear
int updateBit(int n, int pos, int val) {
    int mask = ~(1<<pos);
    n = (n & mask);
    return (n | (val<<pos));
}
signed main() {
    // 5 = 101
    int a = 5;
    cout<<getBit(a, 2)<<endl; // 1

    cout<<setBit(a, 1)<<endl; // 7 = 111

    cout<<clearBit(a, 2)<<endl; // 1 = 001

    cout<<updateBit(a, 1, 1)<<endl; // 7 = 111
    return 0;
}