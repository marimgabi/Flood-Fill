#include <iostream>
#include <fstream>
#include "Ponto.h"
#include "TFila.h"

using namespace std;
using std::fstream;
using std::ofstream;
using std::ifstream;

Ponto *imagem[20][25];

void imprime_matriz(){
    for(int i=0;i<20;i++){
        if(i==0){
            for(int j=0;j<25;j++){
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

        for(int j=0;j<25;j++){
            cout << " " << imagem[i][j]->getCor() << " ";
        }
        cout << endl;
    }
}

void floodFill(char seed, Ponto* &inicio){
    TFila<Ponto> *fila;

    fila = new TFila<Ponto>();
    fila->add(*inicio);
    fila->isEmpty();

//    while(!fila->isEmpty()){
//        cout << "coxinha";
//    }

}

int main(){

    string line;
    int linha=0,row,col;
    char seed, novaCor;

    ///Lendo o arquivo

    ifstream myfile ("img3.txt"); // ifstream = padrão ios:in
      if (myfile.is_open())
      {
        while (! myfile.eof() ) //enquanto end of file for false continua
        {
            getline (myfile,line);
            for(int i=0; i<25; i++){
                imagem[linha][i]=new Ponto(line.at(i), linha, i);

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

  seed=imagem[row][col]->getCor();

  floodFill(seed, imagem[row][col]);

    return 0;
}
