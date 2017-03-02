/*********************************************************************
* ��Ȩ���� (C)2017, XXX������޹�˾��
*
* �ļ����ƣ� Cashier.h
* �ļ���ʶ��
* ����ժҪ�� CCashier������ͷ�ļ�
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
#include "Customer.h"
#include "Rand.h"

class CCashier
{
public:
	CCashier(int nCashierID);
	~CCashier();

public:
	bool Process(int nTimeSec,CCustomer * pCustomer);
	int GetCashierID();
    int GetCashierToCustomer();

private:
	int nCashierID;
	int nCustomerCount;         //����˿�����;

	int nNextProcCustomeTime;   //�����¸��˿�ʱ���

private:
    CRand mRand;
};

