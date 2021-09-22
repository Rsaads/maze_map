#ifndef readfile_h
#define readfile_h
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

//Classe responsável pela leitura e validação dos dados do arquivo
class readfile{
    private:
    int column;                         //Número de colunas
    int lines;                          //Número de linhas

    public:
    std::vector<std::string> maze_map;  //Matriz que corresponde ao mapa

    public:
    readfile(std::string file);         //construtor readfile
    int getcolumn();                    //Método que retorna o numero de colunas
    int getlines();                     //Método que retorna o numero de linhas
};
#endif