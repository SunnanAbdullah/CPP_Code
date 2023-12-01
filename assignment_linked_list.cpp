#include <iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		
	node(int val)
	{
		data = val;
		next = nullptr;
	}
};

class Node_double {
public:
    int data;
    Node_double* prev;
    Node_double* next;

    Node_double(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoubleCircularLinkedList {
private:
    Node_double* head;

public:
    DoubleCircularLinkedList() {
        head = nullptr;
    }

    void AddFirst(int val) {
        Node_double* newNode = new Node_double(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }

        Node_double* temp = head->prev;
        newNode->next = head;
        newNode->prev = temp;
        head->prev = newNode;
        temp->next = newNode;
        head = newNode;
    }

    void AddLast(int val) {
        Node_double* newNode = new Node_double(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }

        Node_double* temp = head->prev;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
    }

    void DeleteFirst() {
        if (head == nullptr) {
            cout << "The list is empty. Cannot delete." << endl;
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node_double* temp = head->prev;
        head = head->next;
        head->prev = temp;
        temp->next = head;
    }

    void DeleteLast() {
        if (head == nullptr) {
            cout << "The list is empty. Cannot delete." << endl;
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node_double* temp = head->prev->prev;
        delete head->prev;
        head->prev = temp;
        temp->next = head;
    }

    void InsertAt(int val, int index) {
        if (index < 0) {
            cout << "Invalid index." << endl;
            return;
        }

        if (index == 0) {
            AddFirst(val);
            return;
        }

        Node_double* newNode = new Node_double(val);
        Node_double* temp = head;

        for (int i = 0; i < index - 1; ++i) {
            temp = temp->next;
            if (temp == head) {
                cout << "Index out of range." << endl;
                delete newNode;
                return;
            }
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    bool Search(int val) {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return false;
        }

        Node_double* temp = head;
        do {
            if (temp->data == val) {
                cout << "Found: " << val << " in the list." << endl;
                return true;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Not found: " << val << " in the list." << endl;
        return false;
    }

    int CountNodes() {
        if (head == nullptr) {
            return 0;
        }

        int count = 0;
        Node_double* temp = head;
        do {
            ++count;
            temp = temp->next;
        } while (temp != head);

        return count;
    }

    void Max() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
        }

        int maxValue = head->data;
        Node_double* temp = head->next;

        do {
            if (temp->data > maxValue) {
                maxValue = temp->data;
            }
            temp = temp->next;
        } while (temp != head);

        cout<<"maximun value is "<<maxValue;
    }

    void Average() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
        }

        int sum = 0;
        int count = 0;
        Node_double* temp = head;

        do {
            sum += temp->data;
            ++count;
            temp = temp->next;
        } while (temp != head);

        cout<<"Average of all Nodes is = "<< (sum) / count<<endl;
    }

    void Reverse() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node_double* current = head;
        Node_double* prevNode = nullptr;
        Node_double* nextNode = nullptr;

        do {
            nextNode = current->next;
            current->next = prevNode;
            current->prev = nextNode;

            prevNode = current;
            current = nextNode;
        } while (current != head);

        head = prevNode;
    }

    bool DetectLoop() {
        if (head == nullptr || head->next == head) {
            return false;
        }

        Node_double* slowPtr = head;
        Node_double* fastPtr = head;

        while (fastPtr != nullptr && fastPtr->next != nullptr) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;

            if (slowPtr == fastPtr) {
                return true;
            }
        }

        return false;
    }

    void Display() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node_double* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

class CircularSinglyLinkList {
	node* head;
	int count;
	public:
		CircularSinglyLinkList() : head(nullptr), count(0) { }
		
		void Display()
		{
			node* curr = head;
			
			if(head == NULL)
			{
				cout << "Circular Singly Linked List is empty" << endl;
				return;
			}
			
			do{
				cout << curr->data << " ";
				curr = curr->next;
			}	while(curr != head);
			cout << endl;
		}
		
		void AddFirst(int val)
		{
			node* new_node = new node(val);
			
			if(head == nullptr)
			{
				head = new_node;
				head->next = head;
				count++;
				return;
			}
			
			node* curr = head;
			
			while(curr->next != head)
			{
				curr = curr->next;
			}
			
			curr->next = new_node;
			new_node->next = head;
			head = new_node;
			count++;
		}
		
		void AddLast(int val)
		{
			node* new_node = new node(val);
			
			if(head == nullptr)
			{
				head = new_node;
				head->next = head;
				count++;
				return;
			}
			
			node* curr = head;
			
			while(curr->next != head)
			{
				curr = curr->next;
			}
			curr->next = new_node;
			new_node->next = head;
			count++;
		}
		
        void InsertAt(int val,int index)
		{
			if(index < 0 || index > count)
			{
				cout << "Given index is not correct" << endl;
				return;
			}
			
			if(index == 0)
			{
				AddFirst(val);
				return;
			}

			node* new_node = new node(val);
			
			if(head == NULL)
			{
				head = new_node;
				head = head->next;
				count++;
				return;
			}
			
			node* curr = head;
			
			for(int i=0; i<index-1 && curr != head; i++)
				curr = curr->next;	
				
			new_node->next = curr->next;
			curr->next = new_node;
			count++;
		}
		
		void DeleteFirst()
		{
			if(head == nullptr)
			{
				cout << "List is empty" <<endl;
				return;
			}
			
			node* curr = head;
			node* temp = nullptr;
			if(head->next == head)
			{
				delete head;
				head = nullptr;
				count--;
				return;
			}
			while(curr->next != head)
			{
				curr = curr->next;
			}
			temp = head;
			head = head->next;
			curr->next = head;
			delete temp;
			count--;
		}
		
		void DeleteLast()
		{
			if(head == nullptr)
			{
				cout << "List is empty" <<endl;
				return;
			}
			if(head->next == head)
			{
				delete head;
				head = nullptr;
				count--;
				return;
			}
			node* curr = head;
			node* temp = nullptr;
			while(curr->next->next != head)
			{
				curr = curr->next;
			}
			temp = curr->next;
			curr->next = temp->next;
			delete temp;
			count--;
			return;
		}
		
		void Reverse()
		{
			node* curr = head;
			node* prev = head;
			node* next = NULL;
			
			while(prev->next != head)
				prev = prev->next;
			
			do{
				next = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next;
			} while(curr != head);
			head = prev;
		}
		
		void Max()
		{
			node* curr = head;
			int max = 0;
				
			do
			{
				if(curr->data > max)
				{
					max = curr->data;
				}
				curr = curr->next;
			} while(curr != head);
			cout << "Max : " << max << endl;
		}
		
		int CountNodes() {	return count; }
		
		void DetectLoop()
		{
			node* slow = head;
			node* fast = head;
			bool loop = false;
			
			while(fast != nullptr && fast->next != nullptr)
			{
				slow = slow->next;
				fast = fast->next->next;
				if(fast == slow)
				{
					loop = true;
					break;
				}
			}
			if(loop)
			{
				cout << "This list is in loop" << endl;
			}else{
				cout << "This list is not in loop" << endl;
			}
		}
		
		void Search(int val){
			node* curr = head;
			bool found = false;
			int i = 0;
			
			do{
				if(curr->data == val){
					cout << "Value found at " << i << " index" << endl;
					found = true;
				}
				curr = curr->next;
				i++;
			} while(curr != head);
			if(!found)
			{
				cout << "Value Not Found....Make sure you enter the right value " << endl;
			}
		}
		
		void Average(){
			node* curr = head;
			double avg = 0;
			
			do{
				avg = avg + curr->data;
				curr = curr->next;
			} while(curr != head);
			
			avg = avg/count;
			cout << "Average : " << avg << endl;
		}
	
};

class SinglyLinkedList{
		node* head;
		int count;
	public:
		SinglyLinkedList() : head(nullptr), count(0) {	}
		
		void Display()
		{
			if(head == NULL)
			{
				cout << "Linked List is empty" << endl;
				return;
			}
			node* curr = head;
			
			while(curr != nullptr)
			{
				cout << curr->data << " ";
				curr = curr->next;
			}
			cout << endl;
		}
		
		void AddFirst(int val)
		{
			node* new_node = new node(val);
			
			if(head == nullptr)
			{
				head = new_node;
				count++;
				return;
			}
		
			new_node->next = head;
			head = new_node;
			count ++;
		}
		
		void AddLast(int val)
		{
			node* new_node = new node(val);
			
			if(head == NULL)
			{
				head = new_node;
				count ++;
				return;
			}
		
			node* curr = head;
		
			while(curr->next != nullptr)
			{
				curr = curr->next;
			}
		
			curr->next = new_node;
			count ++;
		}
	
		void DeleteFirst()
		{
			if(head == nullptr)
			{
				cout << "List is empty" <<endl;
				return;
			}
			node* temp = head;
			head = head->next;
			delete temp;
			count--;
		}
		
		void DeleteLast()
		{
			if(head == nullptr)
			{
				cout << "List is empty" <<endl;
				return;
			}
			node* curr = head;
			node* temp = nullptr;
			if(head->next == nullptr)
			{
				delete curr;
				head = NULL;
				count--;
				return;
			}
			while(curr->next->next != nullptr)
			{
				curr = curr->next;
			}
			temp = curr->next;
			curr->next = nullptr;
			delete temp;
			count--;
		}
	
		void InsertAt(int val,int pos)
		{
			if(pos > count || pos < 0)
			{
				cout << "Given index is not Correct " << endl;
				return;
			}
			
			if(pos == 0)
			{ 
				AddFirst(val);
				return;
			}	
			
			node* new_node = new node(val);
		
			if(head == NULL)
			{
				head = new_node;
				count++;
				return;
			}
			
			node* curr = head;
		
			for(int i=0; i<pos-1 && curr != NULL; i++)
			{
				curr = curr->next;
			}
		
			new_node->next = curr->next;
			curr->next = new_node;
			count++;
		}
		
		void Search(int val)
		{
			node* curr = head;
			bool found = false;
			int i = 0;
			
			if(head == nullptr)
				return;
			
			while(curr != nullptr)
			{
				if(curr->data == val)
				{
					cout << "Value found at index " << i << endl;
					found = true;
				}
				curr = curr->next;
				i++;
			}
			
			if(!found)
			{
				cout << "Value Not Found....Make sure you enter the right value " << endl;
			}
		}
		
		void isPalindrome(){
			node* curr = head;
			int reverse = 0;
			int n = 0;
			
			while(curr != nullptr)
			{
				n = n*10 + curr->data;
				curr = curr->next;
			}
			
			node* head_rev = Reverse();
			curr = head_rev;
			
			while(curr != NULL)
			{
				reverse = reverse*10 + curr->data;
				curr = curr->next;
			}
			if(n == reverse){
				cout << "Given list is Palindrome" << endl;
			}else{
				cout << "Given list is not Palindrome" << endl;
			}
		}
		
		int CountNodes() {	return count;	}
			
		void Max()
		{
			node* curr = head;
			int max = curr->data;
			
			while(curr != nullptr)
			{
				if(curr->data > max)
				{
					max = curr->data;
				}
				curr = curr->next;
			}
			cout << "Max value is " << max << endl;
		}
		
		void Average()
		{
			node* curr = head;
			double avg = 0;
			
			while(curr != nullptr)
			{
				avg = avg + curr->data;
				curr = curr->next;
			}
			
			avg = avg/count;
			cout << "Average : " << avg << endl;
		}
		
		node* Reverse()
		{
			node* curr = head;
			node* next = nullptr;
			node* prev = nullptr;
			
			while(curr != nullptr)
			{
				next = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next;
			}
			head = prev;
			return prev;
		}
		
		void DetectLoop()
		{
			node* fast = head;
			node* slow = head;
			bool loop = false;
			
			while(fast != nullptr)
			{
				slow = slow->next;
				fast = fast->next->next;
				
				if(fast == slow)
					loop = true;
			}
			
			if(loop)
			{
				cout << "This list is in loop" << endl;
			}else{
				cout << "This list is not in loop " << endl;
			}
	}
};

class DoublyLinkedList {
public:
    Node_double* head;
    Node_double* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

	void Display()
		{
			if(head == nullptr)
			{
				cout << "Linked List is empty" << endl;
				return;
			}
			Node_double* curr = head;
			
			while(curr != nullptr)
			{
				cout << curr->data << " ";
				curr = curr->next;
			}
			cout << endl;
		}

    void AddFirst(int value) {
        Node_double* newNode = new Node_double(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void AddLast(int value) {
        Node_double* newNode = new Node_double(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void DeleteFirst() {
        if (head) {
            Node_double* temp = head;
            if (head == tail) {
                head = tail = nullptr;
            } else {
                head = head->next;
                head->prev = nullptr;
            }
            delete temp;
        }
    }

    void DeleteLast() {
        if (tail) {
            Node_double* temp = tail;
            if (head == tail) {
                head = tail = nullptr;
            } else {
                tail = tail->prev;
                tail->next = NULL;
            }
            delete temp;
        }
    }

    void InsertAt(int value, int index) {
        Node_double* newNode = new Node_double(value);
        Node_double* current = head;
        for (int i = 0; i < index - 1 && current; ++i) {
            current = current->next;
        }
        if (current) {
            newNode->prev = current;
            newNode->next = current->next;
            if (current->next) {
                current->next->prev = newNode;
            }
            current->next = newNode;
        } else {
            cerr << "Index out of range" << endl;
        }
    }

    bool Search(int value) {
        Node_double* current = head;
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int CountNodes() {
        int count = 0;
        Node_double* current = head;
        while (current->next != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void Max() {
    if (!head) {
        cerr << "List is empty" << endl; 
    }
    int maxValue = head->data;
    Node_double* current = head->next;
    while (current->next != nullptr) {
        if (current->data > maxValue) {
            maxValue = current->data;
        }
        current = current->next;
    }
    cout<< "maximun value is "<< maxValue<<endl;
}

    void Average() {
    if (!head) {
        cerr << "List is empty" << endl;
    }
    int total = 0;
    int count = 0;
    Node_double* current = head;
    while (current->next != nullptr) {
        total += current->data;
        count++;
        current = current->next;
    }
    cout<<"Average of all Nodes is = "<< (total) / count<<endl;
}

    void Reverse() {
        Node_double* current = head;
        while (current->next != nullptr) {
            swap(current->prev, current->next);
            current = current->prev;
        }
        swap(head, tail);
    }

    bool DetectLoop() {
        Node_double* slow = head;
        Node_double* fast = head;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }

    // Destructor to free memory
    ~DoublyLinkedList() {
        Node_double* current = head;
        while (current) {
            Node_double* next = current->next;
            delete current;
            current = next;
        }
    }
};

void display_main_options(){
        cout << "\n-- MENU --" << endl;
        cout << "1. Singly Linked List" << endl;
        cout << "2. Circular Singly Linked List" << endl;
        cout << "3. Doubly Linked List" << endl;
        cout << "4. Doubly Circular Linked List" << endl;
        cout << "5. Exit" << endl;
        cout << "Select Linked List: ";
}

void display_singly_link_list_options(){
    cout << "\nSingly Linked List Operations:" << endl;
    cout << "1. Add First" << endl;
    cout << "2. Add Last" << endl;
    cout << "3. Delete First" << endl;
    cout << "4. Delete Last" << endl;
    cout << "5. Insert At" << endl;
    cout << "6. Search" << endl;
    cout << "7. Display" << endl;
    cout << "8. Reverse" << endl;
    cout << "9. Detect Loop" << endl;
    cout << "10. Count Nodes" << endl;
    cout << "11. Max" << endl;
    cout << "12. Average" << endl;
    cout << "13. Is Palindrome" << endl;
    cout << "14. Exit to main menu" << endl;
    cout << "Select Operation: ";
}

void display_all_other_link_list_options(){
    cout << "1. Add First" << endl;
    cout << "2. Add Last" << endl;
    cout << "3. Delete First" << endl;
    cout << "4. Delete Last" << endl;
    cout << "5. Insert At" << endl;
    cout << "6. Search" << endl;
    cout << "7. Display" << endl;
    cout << "8. Reverse" << endl;
    cout << "9. Detect Loop" << endl;
    cout << "10. Count Nodes" << endl;
    cout << "11. Max" << endl;
    cout << "12. Average" << endl;
    cout << "13. Exit to main menu" << endl;
    cout << "Select Operation: ";
}

void interface(){
    CircularSinglyLinkList csll;
    DoublyLinkedList  dll;
    SinglyLinkedList sll;
    DoubleCircularLinkedList dcll;
    int choice_main;
    int choice_inner;
    int val, pos;
    bool running = true;
    while (running) {
        display_main_options();
        while (!(cin >> choice_main)) {
            cout << "\nInvalid input! \n";
            cout << "Select Linked List: ";
            cin.clear();
            cin.ignore();
        }
        if (choice_main == 1 ){
            while(true){
            display_singly_link_list_options();
            while (!(cin >> choice_inner)  ) {
                cout << "\nInvalid input! \n";
                cout << "Select Operation: ";
                cin.clear();
                cin.ignore();
            }
            if(choice_inner == 1){
                cout << "Enter value to add at the beginning: ";
                while (!(cin >> val)) {
                    cout << "Invalid input! Please enter an integer: ";
                    cin.clear();
                    cin.ignore();
                }
                sll.AddFirst(val);
            }

            else if(choice_inner == 2){
                cout << "Enter value to add at the last: ";
                while (!(cin >> val)) {
                    cout << "Invalid input! Please enter an integer: ";
                    cin.clear();
                    cin.ignore();
                }
                sll.AddLast(val);
            }

            else if(choice_inner == 3){
                sll.DeleteFirst();
            }

            else if(choice_inner == 4){
                sll.DeleteLast();
            }

            else if(choice_inner == 5){
                cout << "Enter value to add at particular index: ";
                while (!(cin >> val)) {
                    cout << "Invalid input! Please enter an integer: ";
                    cin.clear();
                    cin.ignore();
                }
                cout << "Enter particular index: ";
                while (!(cin >> pos)) {
                    cout << "Invalid input! Please enter valid position: ";
                    cin.clear();
                    cin.ignore();
                }
                sll.InsertAt(val,pos);
            }

            else if(choice_inner == 6){
                cout << "Enter value to search: ";
                while (!(cin >> val)) {
                    cout << "Invalid input! Please enter an integer: ";
                    cin.clear();
                    cin.ignore();
                }
                sll.Search(val);
            }

            else if(choice_inner == 7){
                sll.Display();
            }
            
            else if(choice_inner == 8){
                sll.Reverse();
            }

            else if(choice_inner == 9){
                sll.DetectLoop();
            }

            else if(choice_inner == 10){
                cout<<"Current Number of Nodes = "<<sll.CountNodes()<<endl;
            }

            else if(choice_inner == 11){
                sll.Max();
            }

            else if(choice_inner == 12){
                sll.Average();
            }

            else if(choice_inner == 13){
                sll.isPalindrome();
            }

            else if(choice_inner == 14){
                break;
            }

            else {
                cout<<"\n invalid input \n";
            }
        }
        }
        
        else if (choice_main == 2){
            while(true){
            cout << "\nCircular Singly Linked List Operations:" << endl;
            display_all_other_link_list_options();
            while (!(cin >> choice_inner)  ) {
                cout << "\nInvalid input! \n";
                cout << "Select Operation: ";
                cin.clear();
                cin.ignore();
            }
            if(choice_inner == 1){
                cout << "Enter value to add at the beginning: ";
                while (!(cin >> val)) {
                    cout << "Invalid input! Please enter an integer: ";
                    cin.clear();
                    cin.ignore();
                }
                csll.AddFirst(val);
            }

            else if(choice_inner == 2){
                cout << "Enter value to add at the last: ";
                while (!(cin >> val)) {
                    cout << "Invalid input! Please enter an integer: ";
                    cin.clear();
                    cin.ignore();
                }
                csll.AddLast(val);
            }

            else if(choice_inner == 3){
                csll.DeleteFirst();
            }

            else if(choice_inner == 4){
                csll.DeleteLast();
            }

            else if(choice_inner == 5){
                cout << "Enter value to add at particular index: ";
                while (!(cin >> val)) {
                    cout << "Invalid input! Please enter an integer: ";
                    cin.clear();
                    cin.ignore();
                }
                cout << "Enter particular index: ";
                while (!(cin >> pos)) {
                    cout << "Invalid input! Please enter valid position: ";
                    cin.clear();
                    cin.ignore();
                }
                csll.InsertAt(val,pos);
            }

            else if(choice_inner == 6){
                cout << "Enter value to search: ";
                while (!(cin >> val)) {
                    cout << "Invalid input! Please enter an integer: ";
                    cin.clear();
                    cin.ignore();
                }
                csll.Search(val);
            }

            else if(choice_inner == 7){
                csll.Display();
            }
            
            else if(choice_inner == 8){
                csll.Reverse();
            }

            else if(choice_inner == 9){
                csll.DetectLoop();
            }

            else if(choice_inner == 10){
                cout<<"Current Number of Nodes = "<<sll.CountNodes()<<endl;
            }

            else if(choice_inner == 11){
                csll.Max();
            }

            else if(choice_inner == 12){
                csll.Average();
            }

            else if(choice_inner == 13){
                break;
            }

            else {
                cout<<"\n invalid input \n";
            }
        }
        }
        else if (choice_main == 3){
            while(true){
            cout << "\nDoubly Linked List Operations:" << endl;
            display_all_other_link_list_options();
            while (!(cin >> choice_inner)  ) {
                cout << "\nInvalid input! \n";
                cout << "Select Operation: ";
                cin.clear();
                cin.ignore();
            }
            if(choice_inner == 1){
                cout << "Enter value to add at the beginning: ";
                while (!(cin >> val)) {
                    cout << "Invalid input! Please enter an integer: ";
                    cin.clear();
                    cin.ignore();
                }
                dll.AddFirst(val);
            }

            else if(choice_inner == 2){
                cout << "Enter value to add at the last: ";
                while (!(cin >> val)) {
                    cout << "Invalid input! Please enter an integer: ";
                    cin.clear();
                    cin.ignore();
                }
                dll.AddLast(val);
            }

            else if(choice_inner == 3){
                dll.DeleteFirst();
            }

            else if(choice_inner == 4){
                dll.DeleteLast();
            }

            else if(choice_inner == 5){
                cout << "Enter value to add at particular index: ";
                while (!(cin >> val)) {
                    cout << "Invalid input! Please enter an integer: ";
                    cin.clear();
                    cin.ignore();
                }
                cout << "Enter particular index: ";
                while (!(cin >> pos)) {
                    cout << "Invalid input! Please enter valid position: ";
                    cin.clear();
                    cin.ignore();
                }
                dll.InsertAt(val,pos);
            }

            else if(choice_inner == 6){
                cout << "Enter value to search: ";
                while (!(cin >> val)) {
                    cout << "Invalid input! Please enter an integer: ";
                    cin.clear();
                    cin.ignore();
                }
                dll.Search(val);
            }

            else if(choice_inner == 7){
                dll.Display();
            }
            
            else if(choice_inner == 8){
                dll.Reverse();
            }

            else if(choice_inner == 9){
                dll.DetectLoop();
            }

            else if(choice_inner == 10){
                cout<<"Current Number of Nodes = "<<sll.CountNodes()<<endl;
            }

            else if(choice_inner == 11){
                dll.Max();
            }

            else if(choice_inner == 12){
                dll.Average();
            }

            else if(choice_inner == 13){
                break;
            }

            else {
                cout<<"\n invalid input \n";
            }
        }
        }
        else if (choice_main == 4){
            while(true){
            cout << "\nCircular Doubly Linked List Operations:" << endl;
            display_all_other_link_list_options();
            while (!(cin >> choice_inner)  ) {
                cout << "\nInvalid input! \n";
                cout << "Select Operation: ";
                cin.clear();
                cin.ignore();
            }
            if(choice_inner == 1){
                cout << "Enter value to add at the beginning: ";
                while (!(cin >> val)) {
                    cout << "Invalid input! Please enter an integer: ";
                    cin.clear();
                    cin.ignore();
                }
                dcll.AddFirst(val);
            }

            else if(choice_inner == 2){
                cout << "Enter value to add at the last: ";
                while (!(cin >> val)) {
                    cout << "Invalid input! Please enter an integer: ";
                    cin.clear();
                    cin.ignore();
                }
                dcll.AddLast(val);
            }

            else if(choice_inner == 3){
                dcll.DeleteFirst();
            }

            else if(choice_inner == 4){
                dcll.DeleteLast();
            }

            else if(choice_inner == 5){
                cout << "Enter value to add at particular index: ";
                while (!(cin >> val)) {
                    cout << "Invalid input! Please enter an integer: ";
                    cin.clear();
                    cin.ignore();
                }
                cout << "Enter particular index: ";
                while (!(cin >> pos)) {
                    cout << "Invalid input! Please enter valid position: ";
                    cin.clear();
                    cin.ignore();
                }
                dcll.InsertAt(val,pos);
            }

            else if(choice_inner == 6){
                cout << "Enter value to search: ";
                while (!(cin >> val)) {
                    cout << "Invalid input! Please enter an integer: ";
                    cin.clear();
                    cin.ignore();
                }
                dcll.Search(val);
            }

            else if(choice_inner == 7){
                dcll.Display();
            }
            
            else if(choice_inner == 8){
                dcll.Reverse();
            }

            else if(choice_inner == 9){
                dcll.DetectLoop();
            }

            else if(choice_inner == 10){
                cout<<"Current Number of Nodes = "<<sll.CountNodes()<<endl;
            }

            else if(choice_inner == 11){
                dcll.Max();
            }

            else if(choice_inner == 12){
                dcll.Average();
            }

            else if(choice_inner == 13){
                break;
            }

            else {
                cout<<"\n invalid input \n";
            }
        }
        }
        else if (choice_main == 5){
            cout << "Exiting... Goodbye!" << endl;
            break;
        }
        
    }
}

int main(){
    interface();
    return 0;
}
