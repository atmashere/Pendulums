//---------------------------------------------------------------------------

#include "custom.h"
#include <math.h>

#include "array.h"
//---------------------------------------------------------------------------
// Задача Аренсторфа (начальные условия 1)

const float TMathPendulum::g  = 9.81;
const float TMathPendulum::m = 0.2;
const float TMathPendulum::l = 0.1;
const float TMathPendulum::dE = 0.0;

TMathPendulum::TMathPendulum() : TModel()
{
    X0.resize(2);
    X0[0] = 2.;
    X0[1] = 0.;
}
//---------------------------------------------------------------------------

void TMathPendulum::getRight( const TVector& X, long double t, TVector& Y )
{
    Y.resize(2);
    //double FE = pow(X[1],1);
    Y[0] = X[1];
    Y[1] = - g/l*sin(X[0]);

}

//---------------------------------------------------------------------------
// Задача Аренсторфа (начальные условия 2)

/*ArenstorfModel2::TArenstorfModel2() : TArenstorfModel()
{
	X0.resize(4);
    X0[0] = 0.994;
    X0[1] = 0;
    X0[2] = 0;
    X0[3] = -2.0317326295573368357302057924;
}*/
//---------------------------------------------------------------------------

