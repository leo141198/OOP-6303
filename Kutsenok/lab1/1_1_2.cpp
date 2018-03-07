class A
{
public:
  A() {};

private:
    A (A const& temp);
    void operator=(A const &);
};
