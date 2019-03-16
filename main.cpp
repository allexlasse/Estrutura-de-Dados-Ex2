#include <iostream>
#include "pile_header.h"
#include "triangulo.h"
#include <windows.h> // biblioteca de funções específicas do windows;
#include <stdlib.h>

using namespace std;

int main()
{

    bool exit = true;
    int option, pileSize, valor, lado1, lado2, lado3;
    Triangulo T;

    cout<<"Definir o tamanho da pilha: ";
    cin>>pileSize;

    Pilha<Triangulo> p(pileSize);

    while(exit){
        system("CLS");
        cout<<"Tamanho maximo da pilha: "<<(p.Tamanho - 1)<<endl;
        cout<<"Posicao do topo: "<<p.Topo<<endl;
        cout<<"Informacoes sobre o triangulo no topo: "<<endl;
        if(p.Topo == -1){
            cout<<"Pilha vazia."<<endl;
        }
        else if(T.isTriangulo()){
            cout<<"\nTipo de triangulo: ";
            cout<<T.classificacao();
            cout<<"\nArea do triangulo: ";
            cout<<T.areaDoTriangulo();
        }
        else{
            cout<<"Valor no topo nao e um triangulo."<<endl;
        }

        cout<<"\n\n";

        cout<<"Selecione uma opcao: "<<endl;
        cout<<"1-Empilhar um triangulo\n2-Desempilhar\n0-SAIR"<<endl;
        cout<<"Opcao: ";
        cin>>option;
        switch(option){
        case 1:
            if(p.PilhaCheia()){
                cout<<"Pilha cheia. Retornando ao MENU"<<endl;
                Sleep(1000); // Comando específico do windows
            }
            else{
                cout<<"Entre com os lados do triangulo"<<endl;
                cout<<"\nLado 1: ";
                cin>>lado1;
                cout<<"\nLado 2: ";
                cin>>lado2;
                cout<<"\nLado 3: ";
                cin>>lado3;
                T = Triangulo(lado1, lado2, lado3);
                p.Empilhar(T);
            }
            break;

        case 2:
            if(p.PilhaVazia()){
                cout<<"Pilha vazia. Retornando ao MENU"<<endl;
                Sleep(1000); // Comando específico do windows
            }
            else{
                p.Desempilhar();
            }
            break;

        case 0:
            cout<<"SAIR!!!";
            exit = false;
            break;

        default:
            cout<<"Comando inválido. Retornando ao MENU.";
            Sleep(3000); // Comando específico do windows
            break;
        }
    }

    return 0;
}
