/*********************************************************************
* 版权所有 (C)2017, XXX软件有限公司。
*
* 文件名称： Supermarket.cpp
* 文件标识：
* 内容摘要： CSupermarket类实现文件
* 其它说明：
* 当前版本： V1.0
* 作 者：    向川平
* 完成日期： 2017年3月2日
*
* 修改记录1：
* 修改日期：
* 版 本 号：
* 修 改 人：
* 修改内容：
**********************************************************************/
#include "Supermarket.h"
#include <iostream>

/**********************************************************************
* 函数名称： CSupermarket（）
* 功能描述： CSupermarket 类构造函数，初始化Cashier和Good
* 访问的表：
* 修改的表：
* 输入参数：
* 输出参数：
* 返 回 值：
* 其它说明：
* 修改日期 版本号 修改人 修改内容
* -----------------------------------------------
* 2017/03/02 V1.0 向川平  初始化
***********************************************************************/
CSupermarket::CSupermarket()
{
    this->nTimeSec = 0;

	//Supermarket 初始化3个 Cashier
	int nCashierCount = 3;

	for (int nCashierIdx = 0; nCashierIdx < nCashierCount; nCashierIdx++)
	{
		vecCashier.push_back(new CCashier(nCashierIdx));
	}

	//-Supermarket  针对Apple, Macbook, Cookie三种 Good 每种初始化15个到商店库存
	vecGood.push_back(new CGood(0, "Apple", 15,nTimeSec));
	vecGood.push_back(new CGood(1, "Macbook", 15,nTimeSec));
	vecGood.push_back(new CGood(2, "Cookie", 15,nTimeSec));

    this->nOpenTimeStart = 0;
    this->nCloseTimeEnd = 0;

    this->nNextNewCustomerTime = mRand.GetRand(1, 3);
}

/**********************************************************************
* 函数名称： ~CSupermarket（）
* 功能描述： CSupermarket 析构函数，
* 访问的表：
* 修改的表：
* 输入参数：
* 输出参数：
* 返 回 值：
* 其它说明：
* 修改日期 版本号 修改人 修改内容
* -----------------------------------------------
* 2017/03/02 V1.0 向川平  初始化
***********************************************************************/
CSupermarket::~CSupermarket()
{

}

/**********************************************************************
* 函数名称： Process（）
* 功能描述： 产生顾客购买商品和顾客付款，并打印统计信息
* 访问的表：
* 修改的表：
* 输入参数：
* 输出参数：
* 返 回 值：
* 其它说明：
* 修改日期 版本号 修改人 修改内容
* -----------------------------------------------
* 2017/03/02 V1.0 向川平  初始化
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
            //售罄
            break;
        }
    }

    this->nCloseTimeEnd = nTimeSec;

    PrintStatisticalInfo();
}

/**********************************************************************
* 函数名称： CustomerBuyGood（）
* 功能描述： //每隔1~3秒 产生一个 Customer 随机购买一个商品
* 访问的表：
* 修改的表：
* 输入参数：
* 输出参数：
* 返 回 值：
* 其它说明：
* 修改日期 版本号 修改人 修改内容
* -----------------------------------------------
* 2017/03/02 V1.0 向川平  初始化
***********************************************************************/
void CSupermarket::CustomerBuyGood()
{
    if (nTimeSec >= nNextNewCustomerTime)
    {
        CCustomer *pCustomer = new CCustomer();//产生顾客
        int nGoodID = mRand.GetRand(0, 2);//顾客随机买产品       

        bool bCustomerBugGood = false;
        for (int nGoodIdx = 0; nGoodIdx < vecGood.size(); nGoodIdx++)
        {
            CGood * pGood = vecGood.at(nGoodIdx);
            if (pGood->GetGoodID() == nGoodID)//选中商品
            {
                if (pCustomer->Process(nTimeSec,pGood))//购买到商品
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
* 函数名称： CustomerCash（）
* 功能描述： //每隔5~10秒 Cashier 处理一个 Customer 购买请求
* 访问的表：
* 修改的表：
* 输入参数：
* 输出参数：
* 返 回 值：
* 其它说明：
* 修改日期 版本号 修改人 修改内容
* -----------------------------------------------
* 2017/03/02 V1.0 向川平  初始化
***********************************************************************/
void CSupermarket::CustomerCash()
{
    for (int nCashierIdx = 0; nCashierIdx < vecCashier.size(); nCashierIdx++)
    {
        for (int nCustomerIdx = 0; nCustomerIdx < vecCustomer.size(); nCustomerIdx++)
        {
            CCashier * pCashier = vecCashier.at(nCashierIdx);
            CCustomer * pCustomer = vecCustomer.at(nCustomerIdx);

            if (pCustomer->GetWaitimgTimeEnd() == 0)//未收银顾客
            {
                pCashier->Process(nTimeSec, pCustomer);//收银
            }
        }
    }
}
/**********************************************************************
* 函数名称： SupermarketClose（）
* 功能描述： 判断商品是否售罄
* 访问的表：
* 修改的表：
* 输入参数：
* 输出参数：
* 返 回 值：true：已经售罄，false：未售罄
* 其它说明：
* 修改日期 版本号 修改人 修改内容
* -----------------------------------------------
* 2017/03/02 V1.0 向川平  初始化
***********************************************************************/
bool CSupermarket::SupermarketClose()
{
    //判断售罄
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
        if (pCustomer->GetWaitimgTimeEnd() == 0)//未收银顾客
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
* 函数名称： PrintStatisticalInfo（）
* 功能描述： 打印统计信息
* 访问的表：
* 修改的表：
* 输入参数：
* 输出参数：
* 返 回 值：
* 其它说明：
* 修改日期 版本号 修改人 修改内容
* -----------------------------------------------
* 2017/03/02 V1.0 向川平  初始化
***********************************************************************/
void CSupermarket::PrintStatisticalInfo()
{
    //统计打印输出
    //统计出每个顾客平均等待时间
    int nCustomerWaitingTimeCount = 0;
    for (int nCustomerIdx = 0; nCustomerIdx < vecCustomer.size(); nCustomerIdx++)
    {
        CCustomer * pCustomer = vecCustomer.at(nCustomerIdx);
        nCustomerWaitingTimeCount += pCustomer->GetWaitimgTimeEnd() - pCustomer->GetWaitimgTimeStart();
    }

    std::cout << "每个顾客平均等待时间: " << nCustomerWaitingTimeCount / vecCustomer.size() << std::endl;

    //统计出每个商品平均售出时间
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
    std::cout << "每个商品平均售出时间: " << nGoodSaleTimeCount / 45 << std::endl;

    //统计出从开始销售到售罄总共时间
    std::cout << "开始销售到售罄总共时间 : " << this->nCloseTimeEnd - this->nOpenTimeStart << std::endl;

    //统计出每个 Cashier 接待的顾客数量
    std::cout << "每个 Cashier 接待的顾客数量: " << std::endl;
    for (int nCashierIdx = 0; nCashierIdx < vecCashier.size(); nCashierIdx++)
    {
        CCashier *pCashier = vecCashier.at(nCashierIdx);
        std::cout << "Cashier " << nCashierIdx << ":" << pCashier->GetCashierToCustomer() << std::endl;
    }
}