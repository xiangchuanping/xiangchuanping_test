/*********************************************************************
* ��Ȩ���� (C)2017, XXX������޹�˾��
*
* �ļ����ƣ� Supermarket.cpp
* �ļ���ʶ��
* ����ժҪ�� CSupermarket��ʵ���ļ�
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
#include "Supermarket.h"
#include <iostream>

/**********************************************************************
* �������ƣ� CSupermarket����
* ���������� CSupermarket �๹�캯������ʼ��Cashier��Good
* ���ʵı�
* �޸ĵı�
* ���������
* ���������
* �� �� ֵ��
* ����˵����
* �޸����� �汾�� �޸��� �޸�����
* -----------------------------------------------
* 2017/03/02 V1.0 ��ƽ  ��ʼ��
***********************************************************************/
CSupermarket::CSupermarket()
{
    this->nTimeSec = 0;

	//Supermarket ��ʼ��3�� Cashier
	int nCashierCount = 3;

	for (int nCashierIdx = 0; nCashierIdx < nCashierCount; nCashierIdx++)
	{
		vecCashier.push_back(new CCashier(nCashierIdx));
	}

	//-Supermarket  ���Apple, Macbook, Cookie���� Good ÿ�ֳ�ʼ��15�����̵���
	vecGood.push_back(new CGood(0, "Apple", 15,nTimeSec));
	vecGood.push_back(new CGood(1, "Macbook", 15,nTimeSec));
	vecGood.push_back(new CGood(2, "Cookie", 15,nTimeSec));

    this->nOpenTimeStart = 0;
    this->nCloseTimeEnd = 0;

    this->nNextNewCustomerTime = mRand.GetRand(1, 3);
}

/**********************************************************************
* �������ƣ� ~CSupermarket����
* ���������� CSupermarket ����������
* ���ʵı�
* �޸ĵı�
* ���������
* ���������
* �� �� ֵ��
* ����˵����
* �޸����� �汾�� �޸��� �޸�����
* -----------------------------------------------
* 2017/03/02 V1.0 ��ƽ  ��ʼ��
***********************************************************************/
CSupermarket::~CSupermarket()
{

}

/**********************************************************************
* �������ƣ� Process����
* ���������� �����˿͹�����Ʒ�͹˿͸������ӡͳ����Ϣ
* ���ʵı�
* �޸ĵı�
* ���������
* ���������
* �� �� ֵ��
* ����˵����
* �޸����� �汾�� �޸��� �޸�����
* -----------------------------------------------
* 2017/03/02 V1.0 ��ƽ  ��ʼ��
***********************************************************************/
void CSupermarket::Process()
{
    while (true)
    {
        nTimeSec++;

        CustomerBuyGood();
        CustomerCash();

        if (SupermarketClose() == true)
        {
            //����
            break;
        }
    }

    this->nCloseTimeEnd = nTimeSec;

    PrintStatisticalInfo();
}

/**********************************************************************
* �������ƣ� CustomerBuyGood����
* ���������� //ÿ��1~3�� ����һ�� Customer �������һ����Ʒ
* ���ʵı�
* �޸ĵı�
* ���������
* ���������
* �� �� ֵ��
* ����˵����
* �޸����� �汾�� �޸��� �޸�����
* -----------------------------------------------
* 2017/03/02 V1.0 ��ƽ  ��ʼ��
***********************************************************************/
void CSupermarket::CustomerBuyGood()
{
    if (nTimeSec >= nNextNewCustomerTime)
    {
        CCustomer *pCustomer = new CCustomer();//�����˿�
        int nGoodID = mRand.GetRand(0, 2);//�˿�������Ʒ       

        bool bCustomerBugGood = false;
        for (int nGoodIdx = 0; nGoodIdx < vecGood.size(); nGoodIdx++)
        {
            CGood * pGood = vecGood.at(nGoodIdx);
            if (pGood->GetGoodID() == nGoodID)//ѡ����Ʒ
            {
                if (pCustomer->Process(nTimeSec,pGood))//������Ʒ
                {
                    bCustomerBugGood = true;
                    pCustomer->SetWaitimgTimeStart(nTimeSec);
                    vecCustomer.push_back(pCustomer);
                    nNextNewCustomerTime += mRand.GetRand(1, 3);

                    return;
                }
            }
        }

        if (bCustomerBugGood == false)
        {
            delete pCustomer;
            pCustomer = NULL;
        }
    }
}

/**********************************************************************
* �������ƣ� CustomerCash����
* ���������� //ÿ��5~10�� Cashier ����һ�� Customer ��������
* ���ʵı�
* �޸ĵı�
* ���������
* ���������
* �� �� ֵ��
* ����˵����
* �޸����� �汾�� �޸��� �޸�����
* -----------------------------------------------
* 2017/03/02 V1.0 ��ƽ  ��ʼ��
***********************************************************************/
void CSupermarket::CustomerCash()
{
    for (int nCashierIdx = 0; nCashierIdx < vecCashier.size(); nCashierIdx++)
    {
        for (int nCustomerIdx = 0; nCustomerIdx < vecCustomer.size(); nCustomerIdx++)
        {
            CCashier * pCashier = vecCashier.at(nCashierIdx);
            CCustomer * pCustomer = vecCustomer.at(nCustomerIdx);

            if (pCustomer->GetWaitimgTimeEnd() == 0)//δ�����˿�
            {
                pCashier->Process(nTimeSec, pCustomer);//����
            }
        }
    }
}
/**********************************************************************
* �������ƣ� SupermarketClose����
* ���������� �ж���Ʒ�Ƿ�����
* ���ʵı�
* �޸ĵı�
* ���������
* ���������
* �� �� ֵ��true���Ѿ�������false��δ����
* ����˵����
* �޸����� �汾�� �޸��� �޸�����
* -----------------------------------------------
* 2017/03/02 V1.0 ��ƽ  ��ʼ��
***********************************************************************/
bool CSupermarket::SupermarketClose()
{
    //�ж�����
    bool bGoodOver = false;
    for (int nGoodIdx = 0; nGoodIdx < vecGood.size(); nGoodIdx++)
    {
        CGood * pGood = vecGood.at(nGoodIdx);

        if (pGood->GetGoodCount() != 0)
        {
            bGoodOver = false;
            break;
        }
        else
        {
            bGoodOver = true;
        }
    }

    bool bCustomerOver = false;
    for (int nCustomerIdx = 0; nCustomerIdx < vecCustomer.size(); nCustomerIdx++)
    {
        CCustomer * pCustomer = vecCustomer.at(nCustomerIdx);
        if (pCustomer->GetWaitimgTimeEnd() == 0)//δ�����˿�
        {
            bCustomerOver = false;
            break;
        }
        else
        {
            bCustomerOver = true;
        }
    }

    if (bGoodOver && bCustomerOver == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**********************************************************************
* �������ƣ� PrintStatisticalInfo����
* ���������� ��ӡͳ����Ϣ
* ���ʵı�
* �޸ĵı�
* ���������
* ���������
* �� �� ֵ��
* ����˵����
* �޸����� �汾�� �޸��� �޸�����
* -----------------------------------------------
* 2017/03/02 V1.0 ��ƽ  ��ʼ��
***********************************************************************/
void CSupermarket::PrintStatisticalInfo()
{
    //ͳ�ƴ�ӡ���
    //ͳ�Ƴ�ÿ���˿�ƽ���ȴ�ʱ��
    int nCustomerWaitingTimeCount = 0;
    for (int nCustomerIdx = 0; nCustomerIdx < vecCustomer.size(); nCustomerIdx++)
    {
        CCustomer * pCustomer = vecCustomer.at(nCustomerIdx);
        nCustomerWaitingTimeCount += pCustomer->GetWaitimgTimeEnd() - pCustomer->GetWaitimgTimeStart();
    }

    std::cout << "ÿ���˿�ƽ���ȴ�ʱ��: " << nCustomerWaitingTimeCount / vecCustomer.size() << std::endl;

    //ͳ�Ƴ�ÿ����Ʒƽ���۳�ʱ��
    int nGoodSaleTimeCount = 0;
    for (int nGoodIdx = 0; nGoodIdx < vecGood.size(); nGoodIdx++)
    {
        CGood * pGood = vecGood.at(nGoodIdx);
        std::vector<int> vecGoodTimeEnd = pGood->GetSaleTimeEnd();
        for (int idx = 0; idx < vecGoodTimeEnd.size();idx++)
        {
            nGoodSaleTimeCount += (vecGoodTimeEnd.at(idx) - pGood->GetSaleTimeStart());
        }
    }
    std::cout << "ÿ����Ʒƽ���۳�ʱ��: " << nGoodSaleTimeCount / 45 << std::endl;

    //ͳ�Ƴ��ӿ�ʼ���۵������ܹ�ʱ��
    std::cout << "��ʼ���۵������ܹ�ʱ�� : " << this->nCloseTimeEnd - this->nOpenTimeStart << std::endl;

    //ͳ�Ƴ�ÿ�� Cashier �Ӵ��Ĺ˿�����
    std::cout << "ÿ�� Cashier �Ӵ��Ĺ˿�����: " << std::endl;
    for (int nCashierIdx = 0; nCashierIdx < vecCashier.size(); nCashierIdx++)
    {
        CCashier *pCashier = vecCashier.at(nCashierIdx);
        std::cout << "Cashier " << nCashierIdx << ":" << pCashier->GetCashierToCustomer() << std::endl;
    }
}