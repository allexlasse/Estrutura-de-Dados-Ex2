#ifndef TRIANGULO_H_INCLUDED
#define TRIANGULO_H_INCLUDED
#include<math.h>
#include<string>
using std::string;

struct Triangulo{

    unsigned int LadoA, LadoB, LadoC;

    //construtor

    Triangulo(){
    }

    Triangulo(int ladoA, int ladoB, int ladoC){
        LadoA = ladoA;
        LadoB = ladoB;
        LadoC = ladoC;
    }

    // Metodos

    bool isTriangulo(){
        return LadoA<LadoB+LadoC && LadoB<LadoA+LadoC && LadoC<LadoA+LadoB;
    }

    float perimetro(){
        return LadoA + LadoB + LadoC;
    }

    float semiperimetro(){
        return perimetro() / 2;
    }

    float areaDoTriangulo(){
        return sqrt(semiperimetro() * (semiperimetro() - LadoA) * (semiperimetro() - LadoB) * (semiperimetro() - LadoC));
    }

    string classificacao(){
        if(LadoA == LadoB && LadoA == LadoC)
            return "Equilatero";
        else if(LadoA == LadoB || LadoA == LadoC || LadoB == LadoC)
            return "Isosceles";
        else
            return "Escaleno";
    }


};

#endif // TRIANGULO_H_INCLUDED
