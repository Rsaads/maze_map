#include <iostream>
#include <vector>
#include <exception>
#include "maze.h"


int main(int argc,char *argv[]){
    
    try
    {
        maze maze(argc,argv);   //Objeto da classe maze
        maze.run();             //Método onde executa a base do programa
    }
    catch(const std::exception& e)//Captura de exceções
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}