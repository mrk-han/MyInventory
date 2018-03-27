#pragma once
#include "stdafx.h"
#include "InventoryItem.h"
using namespace std;


class InventoryList
{
private:
	InventoryItem iList[1000];
	int listSize;
public:
	InventoryList();
	int addInventoryItem();
	void displayList();
};