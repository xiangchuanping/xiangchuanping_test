/*********************************************************************
* ��Ȩ���� (C)2017, XXX������޹�˾��
*
* �ļ����ƣ� Customer.h
* �ļ���ʶ��
* ����ժҪ�� CCustomer������ͷ�ļ�
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
#include "Good.h"

class CCustomer
{
public:
	CCustomer();
	~CCustomer();

public:
	bool Process(int nTimeSec,CGood * pGood);

	bool SetWaitimgTimeStart(int nTimeSec);
	int GetWaitimgTimeStart();

	bool SetWaitimgTimeEnd(int nTimeSec);
	int GetWaitimgTimeEnd();

private:
	int nWaitimgTimeStart; //�˿͵ȴ���ʼʱ��
	int nWaitingTimeEnd;   //�˿͵ȴ�����ʱ��

};

