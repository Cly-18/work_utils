#include <stack>
#include <mutex>
#include <condition_variable>

template <class T>
class Mutex_Stack
{
private:
    std::mutex m;
    std::stack<T> data_stack;

public:
    Mutex_Stack()
    {
    }
    Mutex_Stack(const Mutex_Stack &other)
    {
        std::unique_lock<std::mutex> ulk(other.m);
        data_stack = other.data_stack;
    }
    ~Mutex_Stack()
    {
    }
    bool empty()
    {
        std::unique_lock<std::mutex> ulk(m);
        return data_stack.empty();
    }
    int size()
    {
        std::unique_lock<std::mutex> ulk(m);
        return data_stack.size();
    }
    void push(const T &item)
    {
        std::unique_lock<std::mutex> ulk(m);
        data_stack.push(item);
    }
    void push(T &&item)
    {
        std::unique_lock<std::mutex> ulk(m);
        data_stack.push(std::move(item));
    }
    void pop()
    {
        std::unique_lock<std::mutex> ulk(m);
        if (!data_stack.empty())
            data_stack.pop();
    }
    T &top()
    {
        std::unique_lock<std::mutex> ulk(m);
        return data_stack.top();
    }
};
