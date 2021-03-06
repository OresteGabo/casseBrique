
#include "Cercle.h"

Cercle::Cercle(double r,const Position& p,int c):_rayon{r},_position{p},_couleur{c}
{}
Cercle::~Cercle()
{}
double Cercle::rayon()const{
    return _rayon;
}
void Cercle::rayon(double val){
    _rayon=val;
}
void Cercle::position(const Position& p){
    _position=p;
}
Position Cercle::position()const{
    return _position;
}
double Cercle::diametre()const{return 2*_rayon;}
double Cercle::topY()const{
    return _position.y()-_rayon;
}
double Cercle::rightX()const{
    return _position.x()+_rayon;
}
double Cercle::leftX()const{
    return _position.x()-_rayon;
}
double Cercle::bottomY()const{
    return _position.y()+_rayon;
}
int Cercle::couleur()const{
    return _couleur;
}
void Cercle::couleur(int c){
    _couleur=c;
}
