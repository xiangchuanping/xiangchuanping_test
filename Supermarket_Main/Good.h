/*********************************************************************
* 版权所有 (C)2017, XXX软件有限公司。
*
* 文件名称： Good.h
* 文件标识：
* 内容摘要： CGood类申明头文件
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
    int nGoodID;            //商品种类ID
	int nGoodCount;         //商品总数
    int nSaleTimeStart;     //开始上架时间
	std::string strGoodName;//商品名称

    std::vector<int>vecGoodTimeEnd; //记录每个商品被销售时间
};

