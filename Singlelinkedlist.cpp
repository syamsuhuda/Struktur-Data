#include <iostream>

using namespace std;

//deklarasi
struct tas{
	string merek, desainer;
	int keluaran;
	
	tas *next;
};

tas *head, *tail, *cur, *newNode, *del;

//membuat single linked list
void createSingleLinkedList(string merek, string desainer, int keluaran){
	head = new tas();
	head->merek = merek;
	head->desainer = desainer;
	head->keluaran = keluaran;
	head->next = NULL;
	tail = head;
}

void addFirst(string merek, string desainer, int keluaran){
	newNode = new tas();
	newNode->merek = merek;
	newNode->desainer = desainer;
	newNode->keluaran = keluaran;
	newNode->next = head;
	head = newNode;
}

void addLast(string merek, string desainer, int keluaran){
	newNode = new tas();
	newNode->merek = merek;
	newNode->desainer = desainer;
	newNode->keluaran = keluaran;
	newNode->next = NULL;
	tail->next = newNode;
	newNode = tail;
}

void deleteFirst(){
	del = head;
	head = head->next;
	delete del;
}


//print single linked list
void printSingleLinkedList(){
	cur = head;
	while(cur != NULL){
		cout<<"Merek Tas : " << cur->merek << endl;
		cout<<"Desainer Tas : " << cur->desainer << endl;
		cout<<"Keluaran Tas : " << cur->keluaran << endl;
		
		cur = cur->next;
	}
}


int main()
{
	//inisialisasi program
	createSingleLinkedList("Gucci", "Tom Ford", 2021);
	printSingleLinkedList();
	
	cout<<"\n\n" <<endl;
	addFirst("Balenciaga", "Ezaguirre", 2018);
	printSingleLinkedList();
	
	cout<<"\n\n" <<endl;
	addLast("Dior", "Christian Dior", 2022);
	printSingleLinkedList();
	
	cout<<"\n\n" <<endl;
	deleteFirst();
	printSingleLinkedList();
	
}
