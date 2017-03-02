/*********************************************************************
* 版权所有 (C)2017, XXX软件有限公司。
*
* 文件名称： Supermarket.h
* 文件标识：
* 内容摘要： CSupermarket类申明头文件
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

    int nTimeSec;           //计时器

	int nOpenTimeStart;     //商品开卖时间戳
	int nCloseTimeEnd;      //商品售罄时间戳

    int nNextNewCustomerTime; //新顾客产生时间点
};

