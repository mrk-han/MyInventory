#include "stdafx.h"
#include "InventoryItem.h"


InventoryItem::InventoryItem()
{
	itemName = "";
	itemID = "";
	cost = 0;
	qty = 0;
}

InventoryItem::~InventoryItem()
{
}

int InventoryItem::getInventoryItem()
{
	cout << "Name? ";
	getline(cin, itemName);
	cout << "ID? ";
	getline(cin, itemID);
	cout << "Cost? ";
	cin >> cost;
	if (!cin.good())
	{
		cout << "failure to read cost." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return ERROR1;
	}
	cout << "Quantity? ";
	cin >> qty;
	if (!cin.good())
	{
		cout << "failure to read qty." << endl;
		cin.clear();
		cin.ignore(256, '\n');
		return ERROR1;
	}
	cin.clear();
	cin.ignore(256, '\n');
	return 0;
}

int InventoryItem::addInventory(int num)
{
	if (num < 0)
		return ERROR1;
	qty += num;
	return 0;
}

int InventoryItem::shipInventory(int num)
{
	if (num < 0 || num > qty)
		return ERROR1;
	qty -= num;
	return 0;
}

ostream & operator<<(ostream &os, const InventoryItem &item)
{
	os << "**** ITEM ****" << endl;
	os << "name: " << item.itemName << endl;
	os << "ID: " << item.itemID << endl;
	os << "QTY: " << item.qty << endl;
	os << "Cost: " << item.cost << endl;
	return os;
}