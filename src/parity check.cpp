//
// Created by 2001i on 3/6/2021.
//

#define bsize 36+1 //int+parity
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

int main(){
    int a=87946;

    bitset<bsize> aBit(a);
    bitset<bsize> bBit(2*2*2*2);
    cout<<"a "<<aBit<<endl;
    cout<<"b "<<bBit<<endl;
    cout<<"Even:"<<endl;

    aBit=parityGenerator(aBit);
    bBit=parityGenerator(bBit);
    cout<<"a "<<aBit<<endl;
    cout<<"b "<<bBit<<endl;
    cout<<"Odd:"<<endl;


    aBit>>=(1);
    bBit>>=(1);
    aBit=parityGenerator(aBit, false);
    bBit=parityGenerator(bBit, false);
    cout<<"a "<<aBit<<endl;
    cout<<"b "<<bBit<<endl;

}