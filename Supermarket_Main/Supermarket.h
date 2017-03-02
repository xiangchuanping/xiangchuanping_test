/*********************************************************************
* ��Ȩ���� (C)2017, XXX������޹�˾��
*
* �ļ����ƣ� Supermarket.h
* �ļ���ʶ��
* ����ժҪ�� CSupermarket������ͷ�ļ�
* ����˵����
* ��ǰ�汾�� V1.0
* �� �ߣ�    ��ƽ
* ������ڣ� 2017��3��2��
*
* �޸ļ�¼1��
* �޸����ڣ�
* �� �� �ţ�
* �� �� �ˣ�
* �޸����ݣ�
**********************************************************************/
#pragma once

#include <vector>

#include "Cashier.h"
#include "Customer.h"
#include "Good.h"
#include "Rand.h"

class CSupermarket
{
public:
	CSupermarket();
	~CSupermarket();

public:
	void Process();

private:
    void CustomerBuyGood();
    void CustomerCash();
    bool SupermarketClose();
    void PrintStatisticalInfo();

private:
	std::vector<CCashier *> vecCashier; 
	std::vector<CGood *> vecGood;
	std::vector<CCustomer *>vecCustomer;

private:
	CRand mRand;

    int nTimeSec;           //��ʱ��

	int nOpenTimeStart;     //��Ʒ����ʱ���
	int nCloseTimeEnd;      //��Ʒ����ʱ���

    int nNextNewCustomerTime; //�¹˿Ͳ���ʱ���
};

