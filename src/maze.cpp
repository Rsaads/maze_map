#include "maze.h"
#include <iostream>
#include <vector>


//Construtor da classe maze
maze::maze(int argc,char *argv[])
{
    if(argc==2){
        readfile readfile(argv[1]);//Declaração do objeto readfile; Passa como argumento um arquivo de texto
        //Laço para copiar a matriz da classe readfile para uma matriz da classe maze
        for(auto i = readfile.maze_map.begin();i!= readfile.maze_map.end();i++)
        {
            map.push_back(*i);
        }
        line = readfile.getlines();      //Copia o numero de linhas da matriz da classe readfile
        column = readfile.getcolumn();   //Copia o numero de colunas da matriz da classe readfile
    }
    //Verificação se existe mais de dois argumento ou nenhum argumento ao executar o programa
    else if(argc>2)
    {
        throw(std::invalid_argument("Passe apenas um arquivo como argumento"));
    }
    else{
        throw(std::invalid_argument("Arquivo de dados não existe "));
    }
}
//Método para achar a posição de inicio e final
void maze::findPos(int lines,int columns)
{
    pos position; //Variavel do tipo pos
    //Laço para percorrer a matriz até achar a letra 'P' e a letra 'E'
    for(int i=0;i<lines;i++){
        for(int j=0;j<columns;j++){
            if(map[i][j]=='P')
            {
                position.y = i;
                position.x = j;
                init = position;    //Atribuição da variavel init a posição inicial
            }
            if(map[i][j]=='E')
            {
                position.y = i;
                position.x = j;
                finall = position;  //Atribuição da variavel finall a posição final
            }
        }
    }
}
void maze::run(){
    
    findPos(line,column);               //Execução do método findInit para achar a posição da letra 'P'
    ia.findSolution(map,init,finall);   //Execução do método para achar o caminho de 'P' Até 'E'
    ia.printmap(line,column);           //Impressão do mapa
}