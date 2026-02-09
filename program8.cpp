 // Write a program  to implement the static queue using array size of the queue is 10 . 
 #include <iostream>
using namespace std;

#define SIZE 10

int queue[SIZE];
int front = -1, rear = -1;


void inqueue(int value)
{
    if (rear == SIZE - 1)
    {
        cout << "Queue Overflow\n";
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        cout << "Inserted: " << value << endl;
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue Underflow\n";
    }
    else
    {
        cout << "Deleted: " << queue[front] << endl;
        front++;
    }
}


void display()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty\n";
    }
    else
    {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
}

int main()
{
    inqueue(10);
    inqueue(20);
    inqueue(30);

    display();

    dequeue();
    display();

    return 0;
} 