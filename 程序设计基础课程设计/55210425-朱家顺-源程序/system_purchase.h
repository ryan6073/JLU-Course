#pragma once
#ifndef SYSTEM_PURCHASE_H
#define SYSTEM_PURCHASE_H
struct FruitStock {
	char f_name[10];//果蔬类型，同一水果不同类型 ，需要了解不同季节长春在售水果情况；也有可能是同一水果同一类型不同供货商 
	double f_price;//进货价格波动  
	char f_rank;//根据形状大小不同，磕碰腐烂的情况，定做不同的等级分类 ，后续关于腐烂可以用一个随机数生成实现概率判断，
	char f_manufacture;//生产日期，即进货日期
	int f_shelf;//保质期，作为天数，按序递减，减至0时促销 
};//链表处理 ，给到结构体，就相当于已购 
struct FruitStorage {
	char f_name[10];//果蔬类型，同一水果不同类型 ，不考虑不同供货商 
	int f_storage;//果蔬储量，关于单位是个还是斤或者其他，直接根据水果种类判定 ，据此给出库存提醒 
};
#endif