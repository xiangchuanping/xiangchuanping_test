/*********************************************************************
* 版权所有 (C)2017, XXX软件有限公司。
*
* 文件名称： Customer.h
* 文件标识：
* 内容摘要： CCustomer类申明头文件
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
	int nWaitimgTimeStart; //顾客等待开始时间
	int nWaitingTimeEnd;   //顾客等待结束时间

};

