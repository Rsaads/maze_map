#include "readfile.h"
#include <iostream>

//Construtor da classe readfile
readfile::readfile(std::string file)
{
    if(file.empty())
    {
        //Verificação se o arquivo foi passado como parâmetro
        throw(std::invalid_argument("Arquivo de dados não informado."));
    }
    
    std::ifstream myfile(file); //Abertura do arquivo

    if(!myfile.good())
    {
        throw(std::invalid_argument("Arquivo de dados não existe"));
    }
    else
    {
        myfile >> lines;        //Leitura do numero de linhas
        myfile >> column;       //Leitura do numero de colunas

        if(lines<=1)
        {
            throw(std::invalid_argument("Número de linhas menor que 2 e portanto inválido"));//Verificação do número de linhas
        }
        if(column<=1)
        {
            throw(std::invalid_argument("Número de colunas menor que 2 e portanto inválido"));//verificação do número de colunas
        }
        
        std::string line;
        int lineCount = 0;
        
        //Leitura da matriz
        while(getline(myfile, line))        //pega cada linha do arquivo
        {
            if(lineCount>0){                //ignora a primeira linha do arquivo
                maze_map.push_back(line);   //Copia cada linha do arquivo para a matriz maze_map
            }
            lineCount++;
        }

        int P_cont=0;//Contador da letra P
        int E_cont=0;//Contador da letra E

        for(int i=0;i<lines;i++){
            for(int j =0;j<column;j++){
                if(maze_map[i][j] != 'E' && maze_map[i][j] != 'P' && maze_map[i][j] != '#' && maze_map[i][j] != ' ')
                {
                    throw(std::invalid_argument("Caractere inválido"));//Verificação se existe algum caractere inválido
                }
                if(maze_map[i][j]== 'E')//Soma do contador da letra 'E'
                {
                    E_cont++;
                }
                else if(maze_map[i][j]== 'P')//Soma do contador da letra 'P'
                {
                    P_cont++;
                }
            }
        }
        //Condicionais para verificar se existe mais de uma letra 'E' e 'P' e se tem pelo menos uma de cada
        if(E_cont>1)
        {
            throw(std::invalid_argument("Existe mais de uma letra 'E'"));
        }
        else if(E_cont==0)
        {
            throw(std::invalid_argument("Não foi colocado a letra 'E' no arquivo"));
        }
        if(P_cont>1)
        {
            throw(std::invalid_argument("Existe mais de uma letra 'P'"));
        }
        else if(P_cont == 0)
        {
            throw(std::invalid_argument("Não foi colocado a letra 'P' no arquivo"));
        }
        //Verificação se os números de linhas e colunas são iguais ao da matriz
        if(lineCount-1 != lines)
        {
            throw(std::invalid_argument("O número de linhas informado está diferente do número de linhas da matriz"));
        }
        else if(maze_map[1].length()-1 != column){
            throw(std::invalid_argument("O número de colunas informado está diferente do número de colunas da matriz"));
        }
    }
}

//Método que retorna o numero de linhas da matriz
int readfile::getlines()
{
    return lines;
}
//Método que retorna o numero de colunas da matriz
int readfile::getcolumn()
{
    return column;
}