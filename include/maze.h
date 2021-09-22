#include "position.h"
#include "readfile.h"
#include "solution.h"

class maze{
    private:
    int line;                               //Número de linhas
    int column;                             //Número de colunas
    std::vector<std::string> map;           //Matriz que representa o mapa
    pos init;                               //posição inicial
    pos finall;                             //posição final
    solution ia;                            //Objeto da classe solution, responsável por achar o caminho de 'P' Até 'E'

    public:
    maze(int argc, char *argv[]);           //Construtor da classe maze
    void run();                             //Método onde roda a base do programa
    void findPos(int line,int column);      //Método para achar a opsição inicial

};