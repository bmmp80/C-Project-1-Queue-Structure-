// Name: Brandon Prenger
// Email: prenger.30@wright.edu
// Course Number: CS3100
// Course: Data Structures and Algorithms
// Instructor: Meilin Liu
// Date: 06/12/2019
// Project: Queue (Project #1)


//#ifndef _QueueClass_
//#define  _QueueClass_

#include <cstdlib>
#include <string>
#include "Qqueue.h"
#include <iostream>
using namespace std;


//constructor
Qqueue::Qqueue (int cap)
{
	num = 0;
	front = 0;
	back = 0;
	Capacity = cap;
	DynamicQueue = new string[cap];
}

//copy contstructor
Qqueue::Qqueue(const Qqueue& s)
{
	Capacity = s.getCapacity(); //copying size from other queue
	DynamicQueue = new string[Capacity];
	for (int i = 0; i < Capacity; i++)
	{
		DynamicQueue[i] = s.DynamicQueue[i];
	}
	front = s.front;
	num = s.num;
	back = s.back;
}

//destructor
Qqueue::~Qqueue()
{
	delete[] DynamicQueue;
}

void Qqueue::enqueue(const std::string& s)
{
	if(num == Capacity)
	{
		cout << "Error: queue is full";
	}
	else
	{
		if (num != 0)				//queue is not empty
		{
			back++;
		}

		if (back == Capacity)			//wrap around
		{
			back = 0;
		}
		DynamicQueue[back] = s;
		num++;
	}	
}

std::string Qqueue::dequeue()
{
	if (num == 0)
	{
		cout << "Error: Queue is empty"; 
		return " ";
	}
	else
	{
		string frontValue;
		frontValue = DynamicQueue[front];
		num--;
		front++;
		if (front == Capacity)
		{
			front = 0;			//wrap around
		}
		return frontValue;
	}
}

// The member function front: Precondition: the queue is not empty.
std::string& Qqueue::getfront() const
{
	
	if (num == 0)
	{
		cout << "Error: Queue is empty"; //original code
	}
	return DynamicQueue[front];
}

// The member function back: Precondition: the queue is not empty.
std::string& Qqueue::getback() const
{
	if (num == 0)
	{
		cout << "Error: Queue is empty"; //original code
	}
		return DynamicQueue[back];
}

bool Qqueue::IsEmpty() const
{
	if (num == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//printing all the elements in the queue
void Qqueue::print() const
{
	int index = front;
	for (int i = 0; i < num; i++)
	{
		cout << DynamicQueue[index] << endl;
		index++;
		if (index == Capacity)		//wrap around
		{
			index = 0;				
		}
	}
}

int Qqueue::size() const 
{
	return num;
}

int Qqueue::getCapacity() const
{
	return Capacity;
}

//Returns true if the two queues contain exactly the same element values in the same order. Identical in behavior to the == operator.
bool Qqueue::equals(const Qqueue& q) const
{
	if ((Capacity != q.Capacity) || (num != q.num) || (front != q.front) || (back != q.back))
	{
		return false;
	}
	int index = front;
	for (int i = 0; i < num; i++)
	{
		if (DynamicQueue[index] != q.DynamicQueue[index])
		{
			return false;
		}
		index++;
		if (index == Capacity)		//wrap around
		{
			index = 0;
		}
	}
	return true;
}



