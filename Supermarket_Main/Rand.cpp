/*********************************************************************
* ��Ȩ���� (C)2017, XXX�������޹�˾��
*
* �ļ����ƣ� Rand.cpp
* �ļ���ʶ��
* ����ժҪ�� CRand��ʵ���ļ�
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
#include "Rand.h"

#include <time.h>
#include <iostream> 
#include <assert.h>

/**********************************************************************
* �������ƣ� CRand����
* ���������� CRand ���캯����
* ���ʵı���
* �޸ĵı���
* ��������� 
* ���������
* �� �� ֵ��
* ����˵����
* �޸����� �汾�� �޸��� �޸�����
* -----------------------------------------------
* 2017/03/02 V1.0 ��ƽ  ��ʼ��
***********************************************************************/
CRand::CRand()
{
	std::srand((unsigned)time(NULL));//srand()��������һ���Ե�ǰʱ�俪ʼ���������
}

/**********************************************************************
* �������ƣ� CRand����
* ���������� CRand ����������
* ���ʵı���
* �޸ĵı���
* ���������
* ���������
* �� �� ֵ��
* ����˵����
* �޸����� �汾�� �޸��� �޸�����
* -----------------------------------------------
* 2017/03/02 V1.0 ��ƽ  ��ʼ��
***********************************************************************/
CRand::~CRand()
{
}

/**********************************************************************
* �������ƣ� GetRand����
* ���������� ���أ�nStart��nEnd����Χ֮�ڵ������
* ���ʵı���
* �޸ĵı���
* ���������nStart����㣬nEnd���յ�
* ���������
* �� �� ֵ�������
* ����˵����
* �޸����� �汾�� �޸��� �޸�����
* -----------------------------------------------
* 2017/03/02 V1.0 ��ƽ  ��ʼ��
***********************************************************************/
int CRand::GetRand(int nStart, int nEnd)
{
	assert(nEnd > nStart);
	return nStart + rand() % (nEnd - nStart + 1);
}