#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Priority_Queue{

private:

	typedef struct _node{
		int item;
		struct _node *next;  //NEED TO USE STRUCT IN DEFINITION
	}node;

	int nodeCount;  //KEEP COUNT
	node *head;     //POINTER TO HEAD
	node *tail;     //POINTER TO TAIL

	void sort(void);

public:

	Priority_Queue();   //CONSTRUCTOR
	bool empty();       //TEST IF LIST IS EMPTY
	int size();         //RETURN SIZE
	int front();        //ACCESS FIRST NODE (head pointer)
	int back();         //ACCESS LAST NODE  (tail pointer) 
	void enqueue(int);  //ADD 
	void dequeue();     //REMOVE
	void printQueue();  //PRINT
	void deleteQueue(); //DELETE CORRECTLY
};

Priority_Queue::Priority_Queue()
{
	head = NULL;    //INITIALIZE TO NULL
	tail = NULL;    //???
	nodeCount = 0;  //NO NODES TO START
}

bool Priority_Queue::empty()
{
	return (head == NULL);  // IF NULL RETURN TRUE
}

int Priority_Queue::size()
{
	return nodeCount;
}

int Priority_Queue::front()
{
	return ( head->item);  //COULD BE SEG FAULT
	//NEED USER TO CHECK IF STACK IS EMPTY
}

int Priority_Queue::back()
{
	return ( tail->item);
}

void Priority_Queue::enqueue(int addItem)
{
	if( head == NULL )
	{
		head = (node*)calloc( 0, sizeof( node ) ); 
	
		if(head != NULL) //CHECK FOR NULL
		{
			head->item = addItem;
			tail=head;    //ONE ITEM- HEAD AND TAIL ARE THE SAME 

			nodeCount++;  //ADD COUNT TO QUEUE 
		}
		else
		{
			cout <<"Memory Error";
		}
	}
	else
	{
		//node *nodePtr = (node*)malloc( sizeof( node ) );
		node *newNode = (node*)calloc( 0, sizeof( node ) );
		node *nodePtr;

		if( newNode != NULL && nodePtr != NULL )
		{
			newNode->item = addItem;

			nodePtr = head;

			while (nodePtr->next != NULL)
			{
				nodePtr = nodePtr->next;
			}

			nodePtr->next = newNode;
			tail = newNode;

			nodeCount++;
		}
		else
		{
			cout <<"Memory Error";
		}
	}

	sort();

}//END ENQUEUE()

void Priority_Queue::dequeue()
{
	if( head != NULL)
	{
		node *temp = head; //POINTING TO WHAT HEAD IS POINTING AT
		head = head->next; //HEAD JUMPS ONE BACK

		free( temp );      //THE FIRST NODE IS FREED
		temp = NULL;       //REINITIALIZED TO NULL

		nodeCount--;
	}
}

void Priority_Queue::printQueue()
{
	node *temp = head;
	int i = 1;

	cout << "=========LIST OUTPUT===========" << endl;
	while( temp != NULL  )
	{
		cout << "Value at position " << i <<": "<< temp->item << endl;
		temp = temp->next;
		i++;
	}
	cout << "===============================" << endl;
	cout << "Node Count: " << size() << endl;
	cout << "The last value in the list is: " << back() << endl << endl;
	cout << "The first value in the list is: " << front() << endl << endl;

} 

void Priority_Queue::deleteQueue() //CORRECT WAY TO DELETE A LIST 
{
	node *temp;

	while( head != NULL)
	{
		temp = head; //PLACEHOLDER
		head = head->next;
		free( temp );
	}
	temp = NULL;
	nodeCount = 0; //RE-INITIALIZE
}

void Priority_Queue::sort(void)  
{
	node *i;
	node *j;
	node *max;
	int temp; //INT TO HOLD VARIABLE
	

	for(i = head ; i != NULL && i->next != NULL ; i = i->next) 
	{
		max = i;  
	
		for(j = i->next ; j != NULL ; j = j->next) 
		{
			if(  (j->item) > (max->item)  ) //GREATER THAN
			{
				max = j;
			}
		}

		if( max != i )
		{
			temp = max->item;
			max->item = i->item;
			i->item = temp;
		}
	}

	i = NULL;
	j = NULL;
	max = NULL;
}

int main( int argc, char **argv)
{

	Priority_Queue myQueue = Priority_Queue();

	cout << endl << "*******PLEASE ENTER A LIST OF RANDOM NUMBERS BETWEEN 1 AND 100********" << endl;

	int exit = 0;  // variable for while loop
	int j = 1;     // counter for user input
	int input = 0; // int to receive user input
	
	while(exit == 0){

		cout << "Please enter a whole number for queue[" << j << "] :";
		cin >> input;

		if((input >= 1) && (input <= 100)){

			cout << "Your Input Was : " << input << endl; 
			myQueue.enqueue(input); //ADD TO QUEUE

			j++; //INCREMENT TO SHOW NEXT NUMBER FOR USER INPUT
			input = 0; // RESET
		}
		else{

			cout << "Please Enter a Number Between 1 and 100" << endl;
		}
		
		cout << "Press 0 to continue entering numbers, or 1 to exit:";
		cin >> exit;
	}

	myQueue.printQueue();
	myQueue.deleteQueue();    

}