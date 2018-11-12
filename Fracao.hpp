//
// Created by djalma cunha on 10/11/18.
//

#ifndef POTENCIA_FRACAO_HPP
#define POTENCIA_FRACAO_HPP
#include <iostream>
using namespace std;
class Fracao {
public:
    void transforma(double a){
        long int down = 10000000;
        float up = a * down;
        simplifica(up,down);
    }
    void simplifica(int up,int down){
        int cont1 = 0, cont2 = 0;
        while (cont2 == 0) {
            if ((up % 2 == 0) && (down % 2 == 0)) {
                up = up / 2;
                down = down / 2;
                cont1++;
            }
            if ((up % 3 == 0) && (down % 3 == 0)) {
                up = up / 3;
                down = down / 3;
                cont1++;
            }
            if ((up % 5 == 0) && (down % 5 == 0)) {
                up = up / 5;
                down = down / 5;
                cont1++;
            }
            if ((up % 7 == 0) && (down % 7 == 0)) {
                up = up / 7;
                down = down / 7;
                cont1++;
            }
            if (cont1 == 0) {
                cont2 = 1;
            }
            else{
                cont1 = 0;
            }
        }
        cima = up;
        baixo = down;
    }
    int getCima(){
        return cima;
    }
    int getBaixo(){
        return baixo;
    }

private:
    int cima;
    int baixo;
};

#endif //POTENCIA_FRACAO_HPP
