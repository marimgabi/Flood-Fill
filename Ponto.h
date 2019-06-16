#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED

class Ponto{
    char cor;
    int x;
    int y;
public:
    Ponto();
    Ponto(char _cor,int _x,int _y);
    void setCor(char _cor);
    char getCor();
    void setCoordenadas(int _x, int _y);
    int getX();
    int getY();
};

int Ponto::getY()
{
    return y;
}

int Ponto::getX()
{
    return x;
}

void Ponto::setCoordenadas(int _x, int _y)
{
    x=_x;
    y=_y;
}

char Ponto::getCor()
{
    return cor;
}

void Ponto::setCor(char _cor)
{
    cor=_cor;
}

 Ponto::Ponto(char _cor, int _x, int _y)
{
    cor=_cor;
    x=_x;
    y=_y;
}

 Ponto::Ponto(){

 }





#endif // PONTO_H_INCLUDED
