#include "BriquesIncassable.h"

BriquesIncassable::BriquesIncassable(double x,double y):
    Briques{x,y}
{
    //ctor
}

BriquesIncassable::~BriquesIncassable()
{
    //dtor
}

bool BriquesIncassable::vivant()const{
    return true;
}
double BriquesIncassable::solidite()const{
    return 1;
}
int BriquesIncassable::couleur()const{
    return 1;
}

int BriquesIncassable::style()const{
    return 2;
}
bool BriquesIncassable::collision(Balle& balle){

    double ballTop = balle.position().y() - 10;
    double ballBottom = balle.position().y() + 10;
    double ballLeft = balle.position().x() - 10;
    double ballRight = balle.position().x() + 10;

    // If it's a collision
    if (ballTop < brickBottom() && ballBottom > brickTop() && ballRight > brickLeft() && ballLeft < brickRight()){
        double distanceX1 = abs(ballRight - brickLeft());
        double distanceX2 = abs(ballLeft - brickRight());
        double distanceY1 = abs(ballTop - brickBottom());
        double distanceY2 = abs(ballBottom - brickTop());

        // bas
        if (balle.direction().y() < 0 && distanceY1 < distanceY2 && distanceY1 < distanceX1 && distanceY1 < distanceX2){
            balle.direction(Position(balle.direction().x(),-1*balle.direction().y()));
            balle.ajusterVitesse(*this);
            return true;
        }
        // haut
        if (balle.direction().y() > 0 && distanceY2 < distanceY1 && distanceY2 < distanceX1 && distanceY2 < distanceX2){
            balle.direction(Position(balle.direction().x(),-1*balle.direction().y()));
            balle.ajusterVitesse(*this);
            return true;
        }
        // gauche

        if (balle.direction().x() > 0 && distanceX1 < distanceX2 && distanceX1 < distanceY1 && distanceX1 < distanceY2){
            balle.direction(Position(-1*balle.direction().x(),balle.direction().y()));
            balle.ajusterVitesse(*this);
            return true;
        }
        // droite
        if (balle.direction().x() < 0 && distanceX2 < distanceX1 && distanceX2 < distanceY1 && distanceX2 < distanceY2){
            balle.direction(Position(-1*balle.direction().x(),balle.direction().y()));
            balle.ajusterVitesse(*this);
            return true;
        }
    }
    return false;
}