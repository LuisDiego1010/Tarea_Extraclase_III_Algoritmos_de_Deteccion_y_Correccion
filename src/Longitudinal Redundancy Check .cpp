//
// Created by 2001i on 4/6/2021.
//

#define bsize 36+1 //int+char+parity
//representation of bits
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

bitset<bsize> parityGenerator(vector<bitset<bsize>> bitStream, bool evenParity = true) {
    bitset<bsize> parityBits(false);
    bool parity = evenParity;
    for (int j = 0; j < bsize; ++j) {
        parity = evenParity;
        for (int i = 0; i < bitStream.size(); i++) {
            if ((bitStream[i])[j]) {
                parity = !parity;
            }

        }
        parityBits.set(j, !parity);


    }
    return parityBits;
}

vector<bitset<bsize>> parityChecker(vector<bitset<bsize>> bitStream, bool evenParity = true) {
    cout << "stream recieved";
    for (auto &i : bitStream) {
        cout << endl << i;
    }
    cout << endl;
    bool parity = evenParity;
    for (int j = 0; j < bsize; ++j) {
        parity = evenParity;
        for (int i = 0; i < bitStream.size() - 1; i++) {
            if ((bitStream[i])[j]) {
                parity = !parity;
            }

        }
        if (parity == bitStream[bitStream.size() - 1][j]) {
            cout << "error in column :" << j << endl;
        }


    }

    return bitStream;
}

int main() {
    int a = 87946;
    int b = 817946;
    int c = 287946;
    int d = 987946;
    bitset<bsize> aBit(a);
    bitset<bsize> bBit(b);
    bitset<bsize> cBit(c);
    bitset<bsize> dBit(d);
    vector<bitset<bsize>> bitStream({aBit, bBit, cBit, dBit});
    cout << "Initial bits" << endl;
    cout << aBit << endl;
    cout << bBit << endl;
    cout << cBit << endl;
    cout << dBit << endl;


    cout << endl;
    cout << "Parity:" << endl;
    cout << "With Even Parity:" << endl;
    auto parityBits = parityGenerator(bitStream, true);
    cout << parityBits << endl;
    cout << "With Odd Parity (in use to test):" << endl;
    parityBits = parityGenerator(bitStream, false);

    cout << parityBits << endl;
    bitStream.push_back(parityBits);

    cout << endl;
    cout << "Check" << endl;

    cout << endl;
    cout << "rigth" << endl;
    bitStream = parityChecker(bitStream, false);
//    for (auto & i : bitStream) {
//        cout << i << endl;
//
//    }
    cout << endl;
    cout << "1 error" << endl;
    bitStream[1].set(bsize - 2, true);
    bitStream = parityChecker(bitStream, false);
//    for (auto & i : bitStream) {
//        cout << i << endl;
//
//    }

    cout << endl;
    cout << "2 errors" << endl;
    bitStream[0].set(bsize - 2, true);
    bitStream = parityChecker(bitStream, false);
//    for (auto & i : bitStream) {
//        cout << i << endl;
//
//    }




}