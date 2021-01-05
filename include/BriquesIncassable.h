#ifndef BRIQUESINCASSABLE_H
#define BRIQUESINCASSABLE_H

#include <Briques.h>


class BriquesIncassable : public Briques
{
    public:
        /** Default constructor */
        BriquesIncassable(double,double);
        /** Default destructor */
        virtual ~BriquesIncassable();
        virtual void afficher(int couleur,int style)const override;
        virtual bool vivant()const override;
        virtual double solidite()const override;
        virtual int couleur()const override;
        virtual int style()const override;
        virtual bool collision(Balle&)override;

    protected:

    private:
};

#endif // BRIQUESINCASSABLE_H
