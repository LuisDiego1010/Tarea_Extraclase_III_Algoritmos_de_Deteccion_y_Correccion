//
// Created by 2001i on 3/6/2021.
//

#define bsize 36+1 //int+char+parity
//representation of bits
#include <bitset>
#include <iostream>

using namespace std;

bitset<bsize> parityGenerator(bitset<bsize> word, bool evenParity=true){
 for(int i=0;i<bsize;i++){
     if(word[i]){
         evenParity=!evenParity;
     }
 }
 word<<=(1);
    if (!evenParity){
        word.set(0,true);
    }

    return word;
}

bitset<bsize> parityChecker(bitset<bsize> word, bool evenParity=true){
    bool parity= false;
    cout<<"word recieved:"<<endl<<word<<endl;
    for (int i = 0; i < bsize; ++i) {
        if(word[i]){
            parity=!parity;
        }
    }
    if(parity==evenParity){
        cout<<"error in the code:"<<endl<<word<<endl;
    }
    word>>=(1);

    return word;
}


int main(){
    int a=87946;

    bitset<bsize> aBit(a);
    bitset<bsize> bBit(2*2*2*2);
    cout<<"Initial bits"<<endl;
    cout<<"a "<<aBit<<endl;
    cout<<"b "<<bBit<<endl;

    cout << endl;
    cout<<"Each with Even Parity:"<<endl;

    aBit=parityGenerator(aBit);
    bBit=parityGenerator(bBit);
    cout<<"a "<<aBit<<endl;
    cout<<"b "<<bBit<<endl;

    cout << endl;
    cout<<"Each with Odd Parity (in use to test):"<<endl;


    aBit>>=(1);
    bBit>>=(1);
    aBit=parityGenerator(aBit, false);
    bBit=parityGenerator(bBit, false);
    cout<<"a "<<aBit<<endl;
    cout<<"b "<<bBit<<endl;


    cout << endl;
    cout<<"Check"<<endl;

    cout << endl;
    cout<<"a (error):"<<endl;
    aBit.set(bsize-4, true);
    parityChecker(aBit, false);
    cout<<"b (right):"<<endl;
    parityChecker(bBit, false);
    cout << endl;
    cout<<"Check with +1 error"<<endl;

    cout << endl;
    cout<<"a (2 errors):"<<endl;
    aBit.set(bsize-2, true);
    bBit.set(bsize-4, true);
    parityChecker(aBit, false);
    cout<<"b (1 error):"<<endl;
    parityChecker(bBit, false);






}