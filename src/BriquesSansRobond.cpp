#include "BriquesSansRobond.h"

BriquesSansRobond::BriquesSansRobond(double x,double y,int v):
    BriquesCassable{x,y,v}
{
    //ctor
}

BriquesSansRobond::~BriquesSansRobond()
{
    //dtor
}

int BriquesSansRobond::style()const{
    return 8;
}
bool BriquesSansRobond::collision(Balle& balle){
    if (_vie > 0){
        // If it's a collision
        if (balle.topY() < bottomY() && balle.bottomY() > topY() && balle.rightX() > leftX() && balle.leftX() < rightX()){
            balle.direction(Position(-1*balle.direction().x(),-1*balle.direction().y()));
            balle.ajusterVitesse(*this);
            _vie --;
            return true;
        }
    }
    return false;
}
