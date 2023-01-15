struct Node 
{
  int data;
  Node *next;
  Node(int d) 
  {
    data = d;
    next = nullptr;
  }
};

struct Queue 
{
  Node *front, *rear;
  Queue() 
  { 
    front = rear = nullptr; 
  }

  void enqueue(int x) 
  {
    Node *temp = new Node(x);

    if (rear == nullptr) 
    {
      front = rear = temp;
      return;
    }

    rear->next = temp;
    rear = temp;
  }

  void dequeue() 
  {
    if (front == nullptr)
      return;

    Node *temp = front;
    front = front->next;

    if (front == nullptr)
      rear = nullptr;

    delete (temp);
  }
};