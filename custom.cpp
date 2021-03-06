//---------------------------------------------------------------------------
#include <math.h>

#include "custom.h"
#include "array.h"

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//

const double TIdealMathPendulum::g  = 9.81;

TIdealMathPendulum::TIdealMathPendulum() : TModel()
{
    l = 1;
    X0.resize(2);
    X0[0] = 0.5236;
    X0[1] = 0.;
}
//---------------------------------------------------------------------------

void TIdealMathPendulum::getRight( const TVector& X, long double t, TVector& Y )
{
    Y.resize(2);
    Y[0] = X[1];
    Y[1] = -g/l*sin(X[0]);


}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//

const double TRealMathPendulum::g  = 9.81;

TRealMathPendulum::TRealMathPendulum() : TModel()
{
    l = 1.;
    beta = 0.8;

    X0.resize(2);
    X0[0] = 0.5236;
    X0[1] = 0.;
}
//---------------------------------------------------------------------------

void TRealMathPendulum::getRight( const TVector& X, long double t, TVector& Y )
{
    Y.resize(2);
    Y[0] = X[1];
    Y[1] = - g/l*sin(X[0]) - beta*X[1];
}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//
const double TIdealPhysicPendulum::k  = 1.;
const double TIdealPhysicPendulum::m  = 1.;

TIdealPhysicPendulum::TIdealPhysicPendulum() : TModel()
{
    X0.resize(2);
    X0[0] = 1.;
    X0[1] = 0.;
}
//---------------------------------------------------------------------------

void TIdealPhysicPendulum::getRight( const TVector& X, long double t, TVector& Y )
{
    Y.resize(2);
    Y[0] = X[1];
    Y[1] = (-k*X[0])/m;
}


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//
const double TViscousPhysicPendulum::k  = 1.;
const double TViscousPhysicPendulum::mu_1  = 0.4;
const double TViscousPhysicPendulum::m  = 1.;

TViscousPhysicPendulum::TViscousPhysicPendulum() : TModel()
{
    X0.resize(2);
    X0[0] = 1.;
    X0[1] = 0.;
}
//---------------------------------------------------------------------------

void TViscousPhysicPendulum::getRight( const TVector& X, long double t, TVector& Y )
{
    Y.resize(2);
    Y[0] = X[1];
    Y[1] = (-k*X[0])/m - mu_1*X[1];
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//
const double TSlydingPhysicPendulum::k  = 1.;
const double TSlydingPhysicPendulum::g  = 9.81;
const double TSlydingPhysicPendulum::m  = 1.;

TSlydingPhysicPendulum::TSlydingPhysicPendulum() : TModel()
{
    mu_2 = 0.015;
    X0.resize(2);
    X0[0] = 2.;
    X0[1] = 0.;
}
//---------------------------------------------------------------------------

void TSlydingPhysicPendulum::getRight( const TVector& X, long double t, TVector& Y )
{

    if (X[1] > 0)
        { mu_2 = -0.015; }
    else
        if (X[1] < 0)
            { mu_2 = 0.015; }
        else
            {  mu_2 = 0.; }


    Y.resize(2);
    Y[0] = X[1];
    Y[1] = mu_2*g -(k/m*X[0]) ;
}

