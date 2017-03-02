// Supermarket_Main.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>

#include "Supermarket.h"
void TestGood()
{
    std::vector<CGood *> vecGood;
    vecGood.push_back(new CGood(0, "Apple", 15, 1));

    CGood mGood(0, "Apple", 15, 1);
    std::cout << "剩余商品个数: " << std::endl;
    for (int idx = 0; idx < 18;idx++)
    {
        bool bGet = mGood.Process(idx);
        std::cout << mGood.GetGoodCount() << " ";
    }
    std::cout << std::endl;

    std::vector<int> vecTimeEnd = mGood.GetSaleTimeEnd();
    std::cout << "商品购买时间戳: " << std::endl;
    for (int idx = 0; idx < vecTimeEnd.size();idx++)
    {
        std::cout << vecTimeEnd.at(idx) << " ";
    }
    std::cout << std::endl;
}

void TestCustomer()
{

}

void main()
{
    TestGood();

	CSupermarket mSupermarket;
	mSupermarket.Process();
}
