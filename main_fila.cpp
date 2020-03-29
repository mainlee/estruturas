//
// Created by Anderson on 28/03/2020.
//

#include <iostream>

using namespace std;

//Declaração do No - Aceita qualquer tipo
template <typename T>
class No{
public:
    T valor;
    No<T>* prx;
};

//Declaração da Fila - Aceitando qualquer tipo
template <typename T>
class Fila{
private:
    No<T>* pri;
    No<T>* ult;

public:
    Fila(){
        pri = NULL;
        ult = NULL;
    }
    //Desconstrutor
    ~Fila(){
        while(Desenfileira());
    }

    bool Insere(T valor){
        //cria o novo No
        No<T>* novo = new No<T>;
        novo->valor = valor;
        novo->prx = NULL;

        //insere na primeira posição caso a fila esteja vazia
        if(pri == NULL){
            pri = novo;
            ult = novo;
            cout << "Enfileirou: " << novo->valor << endl;
            return true;
        }

        No<T>* controle = NULL;
        No<T>* proximo = pri;
        while(proximo){
            controle = proximo;
            proximo = proximo->prx;
        }
        delete proximo;
        //sai do while quando não existe mais proximo
        controle->prx = novo;
        ult = novo;
        cout << "Enfileirou: " << novo->valor << endl;

        return true;
    }

    bool Desenfileira() {
        No<T>* controle = pri;
        //Verifica se nao ja itens na fila
        if(pri == NULL) {
            cout << "Nao ha mais itens!" << endl;
            return false;
        }

        //Verifica se há 1 item na fila
        if(pri == ult){
            cout << "Ultimo item desenfileirado: "<< pri->valor << endl;
            pri = NULL;
            ult = NULL;
            delete controle;
            return true;
        } else {
            cout << "Desenfileirou o :" << pri->valor << endl;
            pri = pri->prx;
            delete controle;
            return true;
        }

    }

    void Imprime(){
        No<T>* controle = pri;
        while(controle){
            cout << controle->valor << endl;
            controle = controle->prx;
        }
    }
};


int main2() {
    Fila<int> f;
    f.Insere(78);
    f.Insere(92);
    f.Insere(81);
    f.Insere(45);
    f.Insere(36);
    f.Insere(98);

    //f.Imprime();

    while (f.Desenfileira());
    return 0;
}