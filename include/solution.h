#ifndef solution_h
#define solution_h
#include <iostream>
#include <string>
#include <vector>
#include "position.h"


class solution{
    private:
    std::vector<std::string> sol_map;                                               //Matriz cópia do mapa em que sera desenhada a solução
    
    public:
    bool isSafe(std::vector<std::string> map,int x,int y);                          //Método que verifica se uma posição é válida
    bool findSolutionUtil(std::vector<std::string> map,int x,int y,pos finall);     //Método que percorre o mapa até achar uma solução
    bool findSolution(std::vector<std::string> map, pos inicial,pos finall);        //Método base da IA
    void printmap(int line,int column);                                             //Método que imprime a matriz que contem a solução(ou não)
};
#endif