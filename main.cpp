#include <iostream>
#include <fstream>
#include "Ponto.h"
#include "TFila.h"

using namespace std;
using std::fstream;
using std::ofstream;
using std::ifstream;

#define MAXL 1000
#define MAXC 1000

int maxL=0, maxC=0;
Ponto imagem[MAXL][MAXC];

void imprime_matriz(){
    for(int i=0;i<maxL;i++){
        if(i==0){
            for(int j=0;j<maxC;j++){
                if(j<10){
                    if(j==0){
                        cout << "   0" << j;
                    }else{
                        cout << " 0" << j;
                    }
                }else{
                    cout << " " << j;
                }
            }
            cout << endl;
        }
        if(i<10){
            cout << "0" << i << " ";
        }else{
            cout << i << " ";
        }

        for(int j=0;j<maxC;j++){
            cout << " " << imagem[i][j].getCor() << " ";
        }
        cout << endl;
    }
}

bool isValid(int m,int n){
    ///Verifica se as coordenadas da matriz são válidas
    return !(m<0||m>=n);
}

void floodFill(char seed, Ponto &inicio, char novaCor){
    TFila<Ponto> *fila;
    Ponto aux;

    fila = new TFila<Ponto>();
    fila->add(inicio);
    fila->isEmpty();

    imagem[inicio.getX()][inicio.getY()].setCor(novaCor);
    int mx[] = {-1, 1, 0, 0, -1, 1, 1, -1}, my[] = {0, 0, -1, 1, -1, -1, 1, 1};

    while(!fila->isEmpty()){
        aux=fila->poll();

        for(unsigned i = 0; i < sizeof(mx) / sizeof(int); i++) {
            int nx = aux.getX() + mx[i];
            int ny = aux.getY() + my[i];
            if(isValid(nx, maxL)&&isValid(ny,maxC)&&imagem[nx][ny].getCor()==seed){
                fila->add(imagem[nx][ny]);
                imagem[nx][ny].setCor(novaCor);
            }
        }
    }

    system("cls");
    imprime_matriz();
}

int main(){

    string line;
    int linha=0,row,col;
    char seed, novaCor;

    ///Lendo o arquivo

    ifstream myfile ("mepassa.txt"); // ifstream = padrão ios:in

      if (myfile.is_open())
      {
        while (!myfile.eof() ) //enquanto end of file for false continua
        {
            getline (myfile,line);
            maxL++;
            maxC = line.size();
            for(int i=0; i<maxC; i++){
                imagem[linha][i]= Ponto(line.at(i), linha, i);

            }
            linha++;
        }
      }

    else cout << "Unable to open file";

  imprime_matriz();

  cout << "Indique a linha do ponto de inicio: ";
  cin >> row;
  cout << "Indique a coluna do ponto de inicio: ";
  cin >> col;
  cout << "Escolha um caracter para ser a nova cor: ";
  cin >> novaCor;

  seed=imagem[row][col].getCor();

  floodFill(seed, imagem[row][col], novaCor);

    return 0;
}
