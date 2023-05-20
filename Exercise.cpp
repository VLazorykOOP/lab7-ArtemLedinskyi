#include <iostream>
#include <cstring>
using namespace std;
template<typename T>
const T& findMin(const T& a, const T& b) {
    return (a < b) ? a : b;
}

template<typename T>
const T& findMax(const T& a, const T& b) {
    return (a > b) ? a : b;
}

template<>
const char* const& findMin(const char* const& a, const char* const& b) {
    return (strcmp(a, b) < 0) ? a : b;
}

template<>
const char* const& findMax(const char* const& a, const char* const& b) {
    return (strcmp(a, b) > 0) ? a : b;
}

void ex1() {
    cout<<"Enter first number "<<endl;
        int first;
        cin>>first;
    cout<<"Enter second number "<<endl;
        int second;
        cin>>second;
    int min = findMin(first,second);
    cout<<"Min number is "<<min<<endl;
    int max = findMax(first,second);
    cout<<"Max number is "<<max<<endl;


    char* a = "Vova";
    char* b = "Artem";
    char* Max = findMax(a,b);
    cout<<"Max is "<<Max<<endl;
    char* Min = findMin(a,b);
    cout<<"Min is "<<Min<<endl;
}


template<typename T>
void SelectionSort(T arr[],int size){// методом "Вилучення"
    for(int i=0;i<size-1;i++){
        int MinIndex=i;
    for(int j=i+1;j<size;j++){
        if(arr[j]<arr[MinIndex]){
            MinIndex=j;
        }
    }
    if(MinIndex !=i){
        swap(arr[i],arr[MinIndex]);
    }
    }
}
template<>
void SelectionSort<char*>(char* arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (strcmp(arr[j], arr[minIndex]) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}
void ex2(){
     cout<<"Enter lenght "<<endl;
     int lenght;
     cin>>lenght;
     int *Arr;
     Arr=new int[lenght];
     for(int i=0;i<lenght;i++){
         cout<<"Enter Number :"<<endl;
         cin>>Arr[i];
     }  
     SelectionSort(Arr,lenght);
     cout<<"Sorted Array :"<<endl;
     for(int i=0;i<lenght;i++){
         cout<<Arr[i]<<" "<<endl;
     }
     delete[] Arr;
    // char *STRArr;
    // int lenghtstr ;
    // cout<<"Enter lenght "<<endl;
    // cin>>lenghtstr;
    // STRArr=new char[lenghtstr];
    // for(int i=0;i<lenghtstr;i++){
    //     cout<<"Enter word :"<<endl;
    //     cin>>STRArr[i];
    // }
    // SelectionSort(STRArr,lenghtstr);
    // cout<<"Sorted array :"<<endl;
    // for(int i=0;i<lenghtstr;i++){
    //     cout<<STRArr[i]<<" "<<endl;
    // }
    // delete []STRArr;
 char* charArray[] = { "Artem","Yura","Gleb"};
    int charArraySize = sizeof(charArray) / sizeof(char*);
    SelectionSort(charArray, charArraySize);

    cout << "Sorted string array: "<<endl;
    for (int i = 0; i < charArraySize; i++) {
        cout << charArray[i] << " "<<endl;
    } 
}
template<typename T>
class LinkedList {
private:
    class Node {
    public:
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void clear() {
        Node* currentNode = head;
        while (currentNode != nullptr) {
            Node* nextNode = currentNode->next;
            delete currentNode;
            currentNode = nextNode;
        }

        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~LinkedList() {
        clear();
    }

    void add(const T& value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }


    class Iterator {
    private:
        Node* current;

    public:
        Iterator(Node* node) : current(node) {}

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        bool operator!=(Iterator& other){
            return current != other.current;
        }

        T& operator*(){
            return current->data;
        }
    };

    Iterator begin(){
        return Iterator(head);
    }

    Iterator end(){
        return Iterator(nullptr);
    }
};

void ex4() {
    LinkedList<int> myList;
    myList.add(1);
    myList.add(2);
    myList.add(3);
// for (LinkedList<int>::Iterator it = list.begin(); it != list.end(); ++it) {
//         std::cout << *it << " ";
//     }
    for (auto& item : myList) {
        cout << item << " \t";
    }
    cout <<endl;
}


template <typename T>
class List {
private:
    class Node {
    public:
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    List() : head(nullptr) {}

    ~List() {
        while (head != nullptr) {
            Node* current = head;
            head = head->next;
            delete current;
        }
    }

    void add(const T& value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

     void remove(const T& value) {
         if (head->data == value) {
             Node* current = head;
             head = head->next;
             delete current;
             return;
         }

         Node* current = head;
         while (current->next != nullptr && current->next->data != value) {
             current = current->next;
         }

         if (current->next != nullptr) {
             Node* nodeToRemove = current->next;
             current->next = current->next->next;
             delete nodeToRemove;
         }
     }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout <<endl;
    }
};

void ex3() {
    List<int> list;

    list.add(10);
    list.add(20);
    list.add(30);

    list.print(); 

    list.remove(20);

    list.print(); 

}


int main(){
    cout<<"Choose exercise "<<endl;
    int e;
    cin>>e;
    if(e==1){
    ex1();
    }
    if(e==2){
    ex2();
    }
    if(e==3){
    ex3();
    }
    if(e==4){
    ex4();
    }
    return 0;
}

