
/*********************************************************************
* 版权所有 (C)2017, XXX软件有限公司。
*
* 文件名称： Customer.cpp
* 文件标识：
* 内容摘要： CCustomer类实现文件
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
#include "Customer.h"

/**********************************************************************
* 函数名称： CCustomer（）
* 功能描述： CCustomer 构造函数
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
CCustomer::CCustomer()
{
    this->nWaitimgTimeStart = 0;
    this->nWaitingTimeEnd = 0;
}

/**********************************************************************
* 函数名称： CCustomer（）
* 功能描述： CCustomer 析构函数
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
CCustomer::~CCustomer()
{
}

/**********************************************************************
* 函数名称： Process（）
* 功能描述： CCustomer购买一个Good
* 访问的表：
* 修改的表：
* 输入参数：nTimeSec：时间戳，pGood要购买的物体
* 输出参数：
* 返 回 值：true：购买成功，false：购买失败
* 其它说明：
* 修改日期 版本号 修改人 修改内容
* -----------------------------------------------
* 2017/03/02 V1.0 向川平  初始化
***********************************************************************/
bool CCustomer::Process(int nTimeSec,CGood * pGood)
{
    return pGood->Process(nTimeSec);
}

/**********************************************************************
* 函数名称： SetWaitimgTimeStart（）
* 功能描述： 设置顾客等待付款开始时间
* 访问的表：
* 修改的表：
* 输入参数：nTimeSec：时间戳
* 输出参数：
* 返 回 值：true：设置成功
* 其它说明：
* 修改日期 版本号 修改人 修改内容
* -----------------------------------------------
* 2017/03/02 V1.0 向川平  初始化
***********************************************************************/
bool CCustomer::SetWaitimgTimeStart(int nTimeSec)
{
    nWaitimgTimeStart = nTimeSec;
    return true;
}
/**********************************************************************
* 函数名称： GetWaitimgTimeStart（）
* 功能描述： 返回顾客等待付款开始时间
* 访问的表：
* 修改的表：
* 输入参数：
* 输出参数：
* 返 回 值：返回等待开始时间
* 其它说明：
* 修改日期 版本号 修改人 修改内容
* -----------------------------------------------
* 2017/03/02 V1.0 向川平  初始化
***********************************************************************/
int CCustomer::GetWaitimgTimeStart()
{
    return nWaitimgTimeStart;
}

/**********************************************************************
* 函数名称： SetWaitimgTimeEnd（）
* 功能描述： 设置顾客付款结束时间
* 访问的表：
* 修改的表：
* 输入参数：nTimeSec：时间戳
* 输出参数：
* 返 回 值：true：设置成功
* 其它说明：
* 修改日期 版本号 修改人 修改内容
* -----------------------------------------------
* 2017/03/02 V1.0 向川平  初始化
***********************************************************************/
bool CCustomer::SetWaitimgTimeEnd(int nTimeSec)
{
    nWaitingTimeEnd = nTimeSec;
    return true;
}

/**********************************************************************
* 函数名称： GetWaitimgTimeStart（）
* 功能描述： 返回顾客等待付款结束时间
* 访问的表：
* 修改的表：
* 输入参数：
* 输出参数：
* 返 回 值：返回付款结束时间
* 其它说明：
* 修改日期 版本号 修改人 修改内容
* -----------------------------------------------
* 2017/03/02 V1.0 向川平  初始化
***********************************************************************/
int CCustomer::GetWaitimgTimeEnd()
{
    return nWaitingTimeEnd;
}
