#include <iostream>

using namespace std;

int maksimal = 4;
string arrayMakanan[4];
int top = 0;

//Operasi isFull
bool isFull()
{
	if( top == maksimal){
		return true;
	}
	else{
		return false;
	}
}

//Operasi isEmpty
bool isEmpty()
{
	if( top == 0){
		return true;
	}
	else{
		return false;
	}
}

//Operasi Push
void pushArray(string data)
{
	if( isFull() ){
		cout<< "Data penuh" << endl;
	}
	else{
		arrayMakanan[top] = data;
		top++;
	}
}

//Operasi Pop
void popArray()
{
	if(isEmpty () ){
		cout<< "Data Kosong !!!" << endl;
	}
	else{
		arrayMakanan[top-1] = "";
		top--;
	}
}

//Operasi Display
void displayArray()
{
	if(isEmpty() ){
		cout<< "Data Kosong !!!" << endl;
	}
	else{
		cout<< "Data stack array :" << endl;
		for (int i = maksimal - 1; i>=0; i--){
			if(arrayMakanan[i] != ""){
				cout<< "Data : " <<arrayMakanan[i] << endl;
			}
		}
		cout <<"\n" <<endl;
	}
}

//Operasi Peek
void peekArray(int posisi)
{
	if(isEmpty () ){
		cout<< "Data Kosong !!!" << endl;
	}
	else{
		int index = top;
		for(int i=0; i<posisi; i++){
			index--;
		}
		cout<< "Data posisi ke-" << posisi <<" : " << arrayMakanan[index] << endl;
	}
}


//Operasi Change
void changeArray(string data, int posisi)
{
	if(isEmpty () ){
		cout<< "Data Kosong !!!" << endl;
	}
	else{
		int index = top;
		for(int i=0; i<posisi; i++){
			index--;
		}
		arrayMakanan[index] = data;
	}
}

//Operasi Count
int countArray()
{
	if(isEmpty() ){
		return 0;
	}
	else{
		return top;
	}
}

//Operasi Destroy
void destroyArray()
{
	for(int i=0; i<top; i++){
		arrayMakanan[i] = "";
	}
	top = 0;	
}

//main program
int main()
{
	
	
	pushArray("Nasi Goreng");
	pushArray("Rendang");
	pushArray("Ayam Goreng");
	pushArray("Sate");
	displayArray();
	pushArray("Rawon Daging");
	displayArray();
	
	popArray();
	displayArray();

	cout<< "Apakah data full : " <<isFull() <<endl;
	cout<< "Apakah data kosong : " <<isEmpty() <<endl;
	
	peekArray(1);
	
	cout<< "Banyak data : " << countArray() << endl;
	
	cout<< "\n";
	
	changeArray("Burger", 2);
	displayArray();
	
	destroyArray();
	cout<< "Apakah data full : " <<isFull() <<endl;
	cout<< "Apakah data kosong : " <<isEmpty() <<endl;
	
}

