#pragma once//---------------------------------------------------------------------------



#include "model.h"

//---------------------------------------------------------------------------
// ������ ��������������� ��������

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
// ������ ��������������� ��������

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

//---------------------------------------------------------------------------
// ������ ��������

class TIdealPhysicPendulum : public TModel
{
    protected:
        static const double k;
        static const double m;

    public:
        TIdealPhysicPendulum( );
        void getRight( const TVector& X, long double t, TVector& Y );
        ~TIdealPhysicPendulum( );

};

//---------------------------------------------------------------------------
// ������ ��������

class TViscousPhysicPendulum : public TModel
{
    protected:
        static const double k;
        static const double mu_1, m;

    public:
        TViscousPhysicPendulum( );
        void getRight( const TVector& X, long double t, TVector& Y );
        ~TViscousPhysicPendulum( );

};

//---------------------------------------------------------------------------
// ������ ��������

class TSlydingPhysicPendulum : public TModel
{
    protected:
        static const double g, k;
        static const double mu_2, m;

    public:
        TSlydingPhysicPendulum( );
        void getRight( const TVector& X, long double t, TVector& Y );
        ~TSlydingPhysicPendulum( );

};


