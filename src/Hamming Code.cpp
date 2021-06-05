//
// Created by guiso on 04/06/2021.
//

#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    /**
     * p = Cantidad de bits de paridad
     * n = Número de bits de información
     */
    int bits_arr[20],n,p = 0,paridad, intmsg;    //n = no. of data bits, p = no. of redundant bits

    cout<<"* Introduce el número de bits de su mensaje:";
    cin >> n;

    //Encontrar el número de bits redundantes
    while(pow (2, p) < n + p + 1){
        p++;
    }

    cout<<"\n* Introduce el mensaje en bits:";
    cin>>intmsg;

    for(int i = n; i >= 0; i--){
        bits_arr[i]=intmsg %10;
        intmsg /= 10;
    }

    int hamming[n + p],j = 0,k = 1;

    //Encontrar las posiciones de los bit de paridad
    for(int i = 1; i <= n + p; i++){

        if( i == pow( 2, j )){
            hamming[i] = -1;    //-1 es el valor inicial de los bits de paridad
            j++;
        }
        else{
            hamming[i] = bits_arr[k];
            k++;
        }
    }

    k = 0;
    int x, min, max = 0;
    //Encontrar los bit de paridad
    for (int i = 1; i <= n + p; i = pow (2, k)){
        k++;
        paridad = 0;
        j = i;
        x = i;
        min = 1;
        max = i;
        while (j <= n + p){
            for (x = j; max >= min && x <= n + p; min++, x++){
                if (hamming[x] == 1)
                    paridad = paridad + 1;;
            }
            j = x + i;
            min = 1;
        }

        //Comprobar paridad
        if (paridad % 2 == 0){
            hamming[i] = 0;
        }
        else{
            hamming[i] = 1;
        }
    }

    cout<<"\n# El código de Hamming es : ";
    for(int i = 1; i <= n + p; i++)
        cout<<hamming[i]<<" ";

    return 0;
}

/*
 * Ejemplo de programa:
 *  * Introduce el número de bits de su mensaje:4
 *
 *  * Introduce el mensaje en bits:1001
 *
 *  # El código de Hamming es : 0 0 1 1 0 0 1
 */

