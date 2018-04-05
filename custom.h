#pragma once//---------------------------------------------------------------------------



#include "model.h"

//---------------------------------------------------------------------------
// Модель математического маятника

class TIdealMathPendulum : public TModel
{
    protected:
        static const double g;
                     double l;

    public:
        TIdealMathPendulum( );
        void getRight( const TVector& X, long double t, TVector& Y );
        ~TIdealMathPendulum( );

};

//---------------------------------------------------------------------------
// Модель математического маятника

class TRealMathPendulum : public TModel
{
    protected:
        static const double g;
                     double l, beta;

    public:
        TRealMathPendulum( );
        void getRight( const TVector& X, long double t, TVector& Y );
        ~TRealMathPendulum( );

};


