#include <vector>
class StacksQueue{
private:
    std::vector<int> firstStack;
    std::vector<int> secondStack;
    void reverse(std::vector<int>&, std::vector<int>&);
public:
    void push(const int);
    void pop();
    int peek();
};