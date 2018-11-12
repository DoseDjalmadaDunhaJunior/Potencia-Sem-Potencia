//
// Created by djalma cunha on 10/11/18.
//

#ifndef POTENCIA_POTENCIA_HPP
#define POTENCIA_POTENCIA_HPP
#include "Fracao.hpp"

class Potencia {
public:
    //faz a potencia simples, quando é int elevado por int
    int pot(int var, int n){
        long int val = var;
        long int aux = val;
        for (int i = 1; i < n; i++) {
            val = val * aux;
        }
        respostaInt = val;
        return val;
    }

    //faz a double elevado por int
    float pot(double val, int n){
        float aux = val;
        for (int i = 1; i < n; i++) {
            val = val * aux;
        }
        respostaFloat = val;
        return val;
    }

    //faz a int elevado por double
    float pot(int val, double n){
        Fracao cont;
        cont.transforma(n);
        long long int up,down;
        up = cont.getCima();
        down = cont.getBaixo();
        cont.simplifica(up,down);
        up = cont.getCima();
        down = cont.getBaixo();
        return newton(val,up,down);
    }

    //faz double por double
    float pot(double val , double n){
        Fracao cont;
        cont.transforma(n);
        long long int up,down;
        up = cont.getCima();
        down = cont.getBaixo();
        cont.simplifica(up,down);
        up = cont.getCima();
        down = cont.getBaixo();
        return newton(val,up,down);
    }

    //faz um pivo que é um valor relativamente proximo da raiz
    float pivo(float num, int up,int down){
        float atual = -1;
        float aux;
        int ant = 0;
        int atu = 0;
        while(atual < 1){
            aux = (pot(atu,down) - num);
            //esse if certifica que nao vai ser dividido por zero
            if(aux != 0){
                atual = aux;
            }
            ant = atu;
            atu++;
        }
        return (ant+atu)/2;
    }

    //faz um pivo que é um valor relativamente proximo da raiz
    float pivo(int num, int up,int down){
        float atual = -1;
        float aux;
        int ant = 0;
        int atu = 1;
        while(atual < 0){
            aux = (pot(atu,down) - num);
            //esse if certifica que nao vai ser dividido por zero
            if(aux != 0){
                atual = aux;
            }
            ant = atu;
            atu++;
        }
        return (ant+atu)/2;
    }
private:
    //para fazer com double
    float newton(double num,int up,int down){
        double temp = num;
        num = pot(num,up);
        bool ok = false;
        if(respostaInt > 2147483647){
            respostaInt = respostaInt/100000;
            num = (int)respostaInt;
            ok = true;
        }
        double x = pivo(pot(temp,down),up,down);
        for (int i = 0; i < 100; i++) {
            cout<<x<<endl;
            x = x - ((num - pot(x,down))/((-(down) * pot(x,(down-1)))));
        }
        if(ok){
            return x*100000;
        }
        else {
            return x;
        }
    }
    //para fazer com int
    float newton(int num,int up,int down){
        int temp = num;
        num = pot(num,up);
        bool ok = false;
        if(respostaInt > 2147483647){
            respostaInt = respostaInt/100000;
            num = (int)respostaInt;
            ok = true;
        }
        double x = pivo(pot(temp,down),up,down);
        for (int i = 0; i < 100; i++) {
            x = x - ((num - pot(x,down))/((-(down) * pot(x,(down-1)))));
        }
        if(ok){
            return x*100000;
        }
        else {
            return x;
        }
    }


    long int respostaInt;
    float respostaFloat;
    float respRaiz;
};


#endif //POTENCIA_POTENCIA_HPP
