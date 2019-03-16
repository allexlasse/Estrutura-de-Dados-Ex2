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
    cout<<"EXERCICIO: EMPILHAMENTO DE TRIANGULOS\n\n"<<endl;
    cout<<"Definir o tamanho da pilha: ";
    cin>>pileSize;

    Pilha<Triangulo> p(pileSize);

    while(exit){
        system("CLS");
        cout<<"                 MENU\n"<<endl;
        cout<<"- Tamanho maximo da pilha: "<<(p.Tamanho)<<endl;
        cout<<"- Posicao do topo: "<<p.Topo<<endl;
        cout<<"- Informacoes sobre o triangulo no topo: ";
        if(p.Topo == -1){
            cout<<"Pilha vazia."<<endl;
        }
        else if(p.ValorNoTopo().isTriangulo()){
            cout<<"\n\n     - Tipo de triangulo: ";
            cout<<p.ValorNoTopo().classificacao();
            cout<<"\n     - Area do triangulo: ";
            cout<<p.ValorNoTopo().areaDoTriangulo();
            cout<<"\n     - Valores digitados: ";
            cout<<p.ValorNoTopo().LadoA<<", "<<p.ValorNoTopo().LadoB<<", "<<p.ValorNoTopo().LadoC<<endl;
        }
        else{
            cout<<"Valor no topo nao e um triangulo."<<endl;
            cout<<"- Valores digitados: ";
            cout<<p.ValorNoTopo().LadoA<<", "<<p.ValorNoTopo().LadoB<<", "<<p.ValorNoTopo().LadoC<<endl;
        }

        cout<<"\n\n";

        cout<<"SELECIONE UMA OPCAO: "<<endl;
        cout<<"\n1 - Empilhar um triangulo\n2 - Desempilhar\n0 - SAIR"<<endl;
        cout<<"\nOpcao: ";
        cin>>option;
        //cout<<"\n";
        switch(option){
        case 1:
            if(p.PilhaCheia()){
                cout<<"Pilha cheia. Retornando ao MENU"<<endl;
                Sleep(1000); // Comando específico do windows
            }
            else{
                cout<<"Entre com os valores do triangulo"<<endl;
                cout<<"Lado 1: ";
                cin>>lado1;
                cout<<"Lado 2: ";
                cin>>lado2;
                cout<<"Lado 3: ";
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
            Sleep(1000); // Comando específico do windows
            break;
        }
    }

    return 0;
}
