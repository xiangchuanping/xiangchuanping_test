/*********************************************************************
* ��Ȩ���� (C)2017, XXX������޹�˾��
*
* �ļ����ƣ� Good.h
* �ļ���ʶ��
* ����ժҪ�� CGood������ͷ�ļ�
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
#include <string>
#include <vector>
class CGood
{
public:
    CGood(int nGoodID, std::string strGoodName, int nGoodCount, int nSaleTimeStart);
	~CGood();

public:
	bool Process(int nTimeSec);
    
	int GetGoodID();
    int GetGoodCount();
    int GetSaleTimeStart();
    std::vector<int> GetSaleTimeEnd();
    
private:
    int nGoodID;            //��Ʒ����ID
	int nGoodCount;         //��Ʒ����
    int nSaleTimeStart;     //��ʼ�ϼ�ʱ��
	std::string strGoodName;//��Ʒ����

    std::vector<int>vecGoodTimeEnd; //��¼ÿ����Ʒ������ʱ��
};

