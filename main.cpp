#include <iostream>
#include "pile_header.h"
#include <windows.h> // biblioteca de funções específicas do windows;
#include <stdlib.h>

using namespace std;

int main()
{

    bool exit = true;
    int option, pileSize, valor;

    cout<<"Definir o tamanho: ";
    cin>>pileSize;

    Pilha<int> p(pileSize);

    while(exit){
        system("CLS");
        cout<<"Tamanho maximo da pilha: "<<p.Tamanho<<endl;
        cout<<"Posicao do topo: "<<p.Topo<<endl;
        cout<<"Valor no topo: ";
        if(p.Topo == -1){
            cout<<"Pilha vazia.";
        }
        else{
            cout<<p.ValorNoTopo();
        }

        cout<<"\n\n";

        cout<<"Selecione uma opcao: "<<endl;
        cout<<"1-Empilhar\n2-Desempilhar\n0-SAIR"<<endl;
        cout<<"Opcao: ";
        cin>>option;
        switch(option){
        case 1:
            if(p.PilhaCheia()){
                cout<<"Pilha cheia. Retornando ao MENU"<<endl;
                Sleep(1000); // Comando específico do windows
            }
            else{
                cout<<"Digite o valor: ";
                cin>>valor;
                p.Empilhar(valor);
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
            Sleep(3000);
            break;
        }
    }

    return 0;
}
