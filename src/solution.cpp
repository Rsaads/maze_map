#include "solution.h"
//Método para impressão do mapa
void solution::printmap(int line,int col)
{
    //Laço que percorre cada posição do mapa
    for(int i=0;i<line;i++){
        for(int j=0;j<col;j++){
            std::cout<<sol_map[i][j];
        }
        std::cout<<"\n";
    }
}
//Método que verifica se uma posição é válida
bool solution::isSafe(std::vector<std::string> map,int x,int y)
{
    if(map[y][x]==' ' || map[y][x]=='P'){
        return true;
    }
    return false;
}

//Método que percorre o mapa para achar o caminho de 'P' até 'E'
bool solution::findSolutionUtil(std::vector<std::string> map,int x,int y,pos finall)
{
    //Condição de parada da recursão
    //Caso x e y sejam a posição de E
    if(x==finall.x && y==finall.y)
    {
        return true;
    }
    
    if(isSafe(map,x,y)) //Verificação se a posição passada é válida
    {
        if(sol_map[y][x] == '<' || sol_map[y][x] == '^' || sol_map[y][x] == 'v' || sol_map[y][x] == '>')            //Condicional para verificar se ja foi passado por determinada posição
        {
            return false;
        }
        sol_map[y][x]= '>';
        if(findSolutionUtil(map,x+1,y,finall)==true)                                                                //chamada recursiva uma posição para direita
        {
            return true;
        }
        if(!isSafe(sol_map,x+1,y) && !isSafe(sol_map,x-1,y) && !isSafe(sol_map,x,y+1) && !isSafe(sol_map,x,y-1)){  //Verificação se existe algum caminho livre
            return false;
        }
        sol_map[y][x]= 'v';
        if(findSolutionUtil(map,x,y+1,finall)==true)                                                                //chamada recursiva uma posição para baixo
        {
            return true;
        }
        if(!isSafe(sol_map,x+1,y) && !isSafe(sol_map,x-1,y) && !isSafe(sol_map,x,y+1) && !isSafe(sol_map,x,y-1)){   //verificação se existe algum caminho livre
            return false;
        }
        sol_map[y][x]= '<';
        if(findSolutionUtil(map,x-1,y,finall)==true)                                                                //chamada recursiva uma posição para esquerda
        {
            return true;
        }
        if(!isSafe(sol_map,x+1,y) && !isSafe(sol_map,x-1,y) && !isSafe(sol_map,x,y+1) && !isSafe(sol_map,x,y-1)){   //verificação se existe algum caminho livre
            return false;
        }
        sol_map[y][x]= '^';
        if(findSolutionUtil(map,x,y-1,finall)==true)                                                                //chamada recursiva uma posição para cima
        {
            return true;
        }
        return false;
    }

    return false;
}
//Método inicial para achar a solução
bool solution::findSolution(std::vector<std::string> map, pos inicial,pos finall)
{
    //Laço que copia o map para sol_map
    for(auto i = map.begin(); i != map.end(); ++i){
        sol_map.push_back(*i);
    }

    //Primeira chamada do método findsolutionutil
    if(!findSolutionUtil(map,inicial.x,inicial.y,finall))
    {
        sol_map[inicial.y][inicial.x] = 'P';//desenhando 'P' na posição inicial
        std::cout<<"Não foram encontradas soluções"<<std::endl;
        return false;
    }
    sol_map[inicial.y][inicial.x] = 'P';    //Desenhando 'P' na posição inicial
    return true;
}