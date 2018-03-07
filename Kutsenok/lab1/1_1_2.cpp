class A
{
public:
  A() {};

private:
    A (A const& temp);
    void operator=(A const &);
};

A* temp = new A;
temp->data = 5;

A* new_temp = new A(temp); 
