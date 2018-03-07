//---------------------------------------------------------------------------

#include "model.h"

//---------------------------------------------------------------------------
void TModel::addResult( const TVector& X, long double t )
{
	// ��������, ������� �� ������� ����� � ������� ����������� �� ������� ��������� ������
	// ���� ��, �� �������� ���������� ����� �� 1
	if (N == Result.rowCount())
		Result.resize(N + 1, getOrder() + 1);
	// �������� ���������� � ��������� ������ ������� Result
	// ������ ������� ���������� � 0-�� �������, ������ ��������� - � ��������� �������
	Result(N, 0) = t;
    for (int i = X.size(); i > 0 ; i--)
		Result(N, i) = X[i-1];
	// �������� N
	N++;
}

void TModel::clearResult() 
{ 
	// ������� ������� ����������� � ������� ������� �����
	Result.resize(0, 0); 
	N = 0; 
}


void TModel::prepareResult() 
{ 
	// ������� ������� ����������� ����� ������, ����� ����������� ��� �������� ������� ���������
	// � ��������������� �� �������� ������� �� ��������� [t0; t1] � ����� SamplingIncrement
	Result.resize((int)((t1 - t0)/SamplingIncrement) + 1, getOrder() + 1);
	// ������� ������� ����� � ������� �����������
	N = 0; 
}
