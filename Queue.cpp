#include <iostream>
using namespace std;

struct antrianAtmLL{
  string nama;
  int umur;

  antrianAtmLL *next;
};

int maksimalAntrianLinkedList = 5;
antrianAtmLL *head, *tail, *cur, *del, *newNode;

int countLinkedList()
{
  if( head == NULL ){
    return 0;
  }else{
    int banyak = 0;
    cur = head;
    while( cur != NULL ){
      cur = cur->next;
      banyak++;
    }
    return banyak;
  }
}

bool isFullLinkedList()
{
  if( countLinkedList() == maksimalAntrianLinkedList ){
    return true;
  }else{
    return false;
  }
}

bool isEmptyLinkedList()
{
  if( countLinkedList() == 0 ){
    return true;
  }else{
    return false;
  }
}

void enqueueLinkedList( string nama, int umur ){

  if( isFullLinkedList() ){
    cout << "Antrian Penuh!!!" << endl;
  }else{
    
    if( isEmptyLinkedList() ){
      head = new antrianAtmLL();
      head->nama = nama;
      head->umur = umur;
      head->next = NULL;
      tail = head;
    }else{
      newNode = new antrianAtmLL();
      newNode->nama = nama;
      newNode->umur = umur;
      newNode->next = NULL;
      tail->next = newNode;
      tail = newNode;
    }

  }

}

void dequeueLinkedList()
{
  if( isEmptyLinkedList() ){
    cout << "Data Antrian Kosong!!" << endl;
  }else{
    del = head;
    head = head->next;
    del->next = NULL;
    delete del;
  }
}

void clearLinkedList()
{
  if( isEmptyLinkedList() ){
    cout << "Data Antrian Kosong!!" << endl;
  }else{
    cur = head;
    while( cur != NULL ){
      del = cur;
      cur = cur->next;
      del->next = NULL;
      delete del;
    }
    head = NULL;
    tail = NULL;
  }
}



void displayLinkedList()
{
  cout << "Data Antrian : " << endl;
  if( isEmptyLinkedList() ){
    cout << "Data Antrian Kosong!!" << endl;
  }else{
    cout << "Banyak data antrian : " << countLinkedList() << endl;
    cur = head;
    int nomor = 1;
    while( nomor <= maksimalAntrianLinkedList ){
      
      if( cur != NULL ){
        cout << nomor << ". " << cur->nama << " - " << cur->umur << " tahun." << endl;
        cur = cur->next;
      }else{
        cout << nomor << ". " << "(kosong)" << endl;
      }

      nomor++;
    }

  }

  cout << "\n" << endl;

}


int main()
{

  enqueueLinkedList("Joni", 19);
  displayLinkedList();

  enqueueLinkedList("Mamat", 20);
  enqueueLinkedList("Siti", 18);
  enqueueLinkedList("Bambang", 20);
  enqueueLinkedList("Rudi", 23);
  displayLinkedList();

  enqueueLinkedList("Example", 23);
  displayLinkedList();

  dequeueLinkedList();
  displayLinkedList();

  clearLinkedList();
  displayLinkedList();

  cout << countLinkedList() << endl;

}

