// Name: Brandon Prenger
// Email: prenger.30@wright.edu
// Course Number: CS3100
// Course: Data Structures and Algorithms
// Instructor: Meilin Liu
// Date: 06/12/2019
// Project: Queue (Project #1)


#include "Qqueue.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	//file to open: C:\Users\Brandon\Desktop\CS3100\Projects\Project1\all.last.txt
	cout << "input queue capacity (0 to 100) ";				
	int capacity;
	cin >> capacity;
	while (capacity < 0 || capacity > 100)
	{
		cout << "Error: capacity must be between 0 and 100";
		cout << "input queue capacity (0 to 100)";
		cin >> capacity;
	}

	Qqueue myQueue(capacity);
	string filename;
	cout << "which file do you want to open? ";					
	cin >> filename;
	
	ifstream my_stream;
	my_stream.open(filename);	
	if (my_stream.is_open())
	{
		cout << "open file" << endl;
		string line;
		for (int i = 0; i < capacity - 10; i++)  //allows user to add up to 10 additional names		
		{
			getline(my_stream, line);
			cout << "line: " << line << endl;
			myQueue.enqueue(line);
		}
		//copying queue
		Qqueue newQueue(myQueue);

		//testing back
		cout << "testing back" << endl;		
		string back = myQueue.getback();
		cout << "back: " << back << endl;

		//testing isEmpty
		cout << "testing isEmpty" << endl;
		bool empty = myQueue.IsEmpty();
		cout << empty << endl;

		bool quit = false;
		int option = 100;
		while (!quit)
		{
			
			cout << "1 to enqueue" << endl;
			cout << "2 to dequeue" << endl;
			cout << "3 to check front" << endl;
			cout << "4 to check if queues are equal" << endl;		
			cout << "5 to print queue" << endl;
			cout << "6 to save elements to disk" << endl;
			cout << "7 to quit" << endl;
			cin >> option;
			string front;
			string lastName;
			//switch statement for menu
			switch (option)
			{

			case 1:
				//enqueue							
				cout << "Enter a last name: ";
				cin >> lastName;
				newQueue.enqueue(lastName);
				cout << "queue size: " << newQueue.size() << endl;

				//print out last 5 elements
				if (newQueue.size() > 5)
				{
					Qqueue Qcopy(newQueue);
					for (int i = 0; i < newQueue.size() - 5; i++)
					{
						string name = Qcopy.dequeue();
					}
					for (int i = 0; i < 5; i++)
					{
						cout << Qcopy.dequeue() << endl;
					}
				}
				break;

			case 2:
				//dequeue						
				int numberFromUser;
				cout << "Enter the number of names you'd like to dequeue: ";
				cin >> numberFromUser;
				if (newQueue.size() > numberFromUser)
				{
					for (int i = 0; i < numberFromUser; i++)
					{
						string lastName = newQueue.dequeue();
						cout << lastName << endl;
					}
				}
				else
				{
					for (int i = 0; i < newQueue.size(); i++)
					{
						string lastName = newQueue.dequeue();
						cout << lastName << endl;
					}
				}
				break;
			case 3:
				//check front
				front = newQueue.getfront();
				cout << "front: " << front << endl;				//why doesn't it print "front: "?
				break;
			case 4:
				//check if equal
				cout << myQueue.equals(newQueue) << endl;		//get a 0 here: are they not equal?
				break;
			case 5:
				/*Print: Print all the elements in the queue onto the screen. */
				newQueue.print();
				cout << endl;
				break;
			case 6:
			{
				/*Save: save all the elements in the queue to a file on the disk.*/
				cout << "Enter output file name: ";
				string fileName;
				cin >> fileName;
				Qqueue Qcopy(newQueue);
				ofstream outfile(fileName);
				int size = newQueue.size();
				for (int i = 0; i < size; i++)
				{
					string lastName = Qcopy.dequeue();
					outfile << lastName << endl;
				}
				outfile.close();
				break;
			}
			case 7:
				quit = true;
				break;
			default: 
				cout << "Error: reached default case" << endl;
				break;
			}

		}
		my_stream.close();
	}
	else
	{
		cout << "Error: unable to open file";
	}
	return 0;
}