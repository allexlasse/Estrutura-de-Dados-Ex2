#ifndef PILE_HEADER_H_INCLUDED
#define PILE_HEADER_H_INCLUDED
template <typename Tipo>

struct Pilha{

    Tipo *P;
    int Topo;
    unsigned int Tamanho;

    //construtores

    Pilha(){
    }

    Pilha(int tamanho){
        Tamanho = tamanho;
        Topo = -1;
        P = new Tipo[tamanho];
    }

    ~Pilha(){
        delete P;
    }

    //metodos

    void Empilhar(Tipo valor){
        P[++Topo] = valor;
    }

    Tipo Desempilhar(){
        Tipo temp = P[Topo];
        Topo--;
        return temp;
    }

    Tipo ValorNoTopo(){
        return P[Topo];
    }

    //Verificações

    bool PilhaCheia(){
        return Topo == Tamanho - 1;
    }

    bool PilhaVazia(){
        return Topo == -1;
    }



};

#endif // PILE_HEADER_H_INCLUDED
