
#include <iostream>

using namespace std;
int main()
{
    int d[5];
    int *ptr=d;
    int b[5];
    int c;
    cout<<sizeof(c)<<endl;
    int a=sizeof(*ptr);
    cout << "the size is" << a<<" b"<<sizeof(b);
    return 0;
}
