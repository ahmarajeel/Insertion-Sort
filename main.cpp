/*
Ahmar Mohammed
23132761
*/

#include <iostream>
#include <fstream>
using namespace std;

class ListNode
{
	public: 
	int data;
	ListNode* next; 
	ListNode()
	{
		next = NULL;
	}
	
	ListNode(int item)
	{
		data = item;
		next = NULL;
	}
	
	~ListNode() {}
};

class LinkedListStack 
{
	public: 
	ListNode* listHead; 
	LinkedListStack()
	{
		listHead = new ListNode(-9999);	
	}
	
	ListNode* findSpot(int item)
	{
		ListNode* spot = listHead;
		while(spot->next != NULL && spot->next->data < item)
		{
			spot = spot->next;
		}
		return spot;
	}
	
	void listInsert(int data)
	{
		ListNode* spot;	
		spot = findSpot(data);
		ListNode* newNode;
		newNode = new ListNode(data);
		newNode->next = spot->next;
		spot->next = newNode;
	}
	
	void printList(int data, ofstream &outFile)
	{
			outFile << "Inserting " << data << ": ";
			outFile << "listHead->" << "(-9999,";
			ListNode* current;
			current = listHead;
			while(current->next != NULL)
			{
				outFile << current->next->data <<")->(" << current->next->data << ",";
				current = current->next;
			}
			outFile << "-1)";
			outFile << endl;
	}
	
	bool isEmpty()
	{
		if(listHead->next == NULL)
			return true; 
		else
			return false;
	}
};
	
	int main(int argc, char* argv[])
	{
		ifstream myFile;
		ofstream outFile(argv[2]);
		myFile.open(argv[1]);
		int intItem;
		LinkedListStack myList;
		
		while (myFile >> intItem)
		{
			myList.listInsert(intItem);
			myList.printList(intItem, outFile);
		}
	
	myFile.close();
	outFile.close();
	return 0;
	
	
	}
		





//
//void printOut()
//	{
//			cout << "listHead->" << "(-9999,";
//			ListNode* spot;
//			spot = listHead;
//			while(spot->next != NULL)
//			{
//				cout << spot->next->data <<")->(" << spot->next->data << ",";
//				spot = spot->next;
//			}
//			cout << "-1)";
//			
//	}
//	void printList()
//	{
//		cout << "printing list" << endl;
//		ListNode* spot;
//		spot = listHead;
//		while(spot->next != NULL)
//		{
//			cout << spot->next->data << endl;
//			spot = spot->next;	
//		}	
//	}
//	
