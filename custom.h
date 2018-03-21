#pragma once//---------------------------------------------------------------------------



#include "model.h"

//---------------------------------------------------------------------------
// ������ ��������������� �������� (��������� ������� 1)

class TMathPendulum : public TModel
{
    protected:
        static const float g, dE;
        static const float m, l;
        float phi;

    public:
        TMathPendulum( );
        void getRight( const TVector& X, long double t, TVector& Y );
        ~TMathPendulum( );

};

//class TArenstorfModel  : public TModel
//{
//    protected:
//        static const long double m;
//		long double D1, D2;
//    public:
//        TArenstorfModel(  );
//		void getRight( const TVector& X, long double t, TVector& Y );
//};


//---------------------------------------------------------------------------
// ������ ���������� (��������� ������� 2)




//class TArenstorfModel2 : public TArenstorfModel
//{
//    public:
//        TArenstorfModel2(  );
//};
//---------------------------------------------------------------------------
