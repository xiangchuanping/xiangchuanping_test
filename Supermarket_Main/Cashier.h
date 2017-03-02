/*********************************************************************
* 版权所有 (C)2017, XXX软件有限公司。
*
* 文件名称： Cashier.h
* 文件标识：
* 内容摘要： CCashier类申明头文件
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
	int nCustomerCount;         //处理顾客总数;

	int nNextProcCustomeTime;   //处理下个顾客时间点

private:
    CRand mRand;
};

