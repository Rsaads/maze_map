# maze_map

## Compilando e executando

No linux você pode compilar usando o g++. Apenas faça clone do projeto, e faça:

```bash
g++ src/*.cpp -o maze -Iinclude
./main include/maze.dat
```
## Matriz

É possível criar e testar com diferentes configurações de matriz. Para que o programa aceite o arquivo, é necessário que a matriz tenha apenas os caracteres '#',
' '(espaço),'P','E'. Além disso a primeira linha do arquivo deve conter o número de linhas e o número de colunas respectivamente. Caso essas condições não se satisfaçam o programa mostrará uma mensagem de erro.

## Issues
  Caso o programa ache mais de um caminho, ele mostrará mesmo que não leve a lugar nenhum.
