#include <iostream>

using namespace std;

//Declaração do No - Aceita qualquer tipo
template <typename T>
class No{
public:
    T valor;
    No<T>* ant;
};

//Declaração da Fila - Aceitando qualquer tipo
template <typename T>
class Pilha{
private:
    No<T>* topo;

public:
     Pilha(){
         //Inicia topo como NULL
        topo = NULL;
    }
    //Destrutor
    ~Pilha(){
        while(Desempilha());
    }

    //Função empilha
    bool Empilha(T valor){
        No<T>* novo = new No<T>;
        novo->valor = valor;
        novo->ant = NULL;

        //Verifica se há itens na pilha
        if(topo == NULL){
            topo = novo;
            return true;
        }

        //No para manutenção
        No<T>* controle = topo;
        topo = novo;
        //Faz com que o novo topo aponte para o valor anterior da pilha
        topo->ant = controle;
        return true;
    }

    bool Desempilha() {
         //Se há itens na pilha
         if(topo){
             No<T>* controle = topo;
             cout << "Desenfilerou: "<< topo->valor << endl;
             topo = topo->ant;
             //Deleta nó desempilhado
             delete controle;
             return true;
         }
         return false;

     }

    void Imprime(){
         No<T>* controle = topo;
         while(controle){
             cout << controle->valor << endl;
             controle = controle->ant;
         }
         delete controle;
         if(!topo){
             cout << "Nao ha mais itens" << endl;
         }
     }
};


int main() {
    Pilha<int> p;

    p.Empilha(0);
    p.Empilha(1);
    p.Empilha(3);
    p.Empilha(5);
    p.Empilha(8);
    p.Imprime();

    /*p.Desempilha();
    p.Imprime();

    p.Empilha(10);
    p.Imprime();*/

    while(p.Desempilha());
    p.Imprime();

    return 0;
}
