#include <iostream>
#include <memory>
using namespace std;
class temp
{
    int x;
    public:
    temp(int a){x=a;}
    auto getX = [=](){ return x};
};
int main()
{
    std::shared_ptr<temp> sp(new temp(3));
}