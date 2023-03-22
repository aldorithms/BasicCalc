#include <iostream>
#include <memory>
#include <string>

using std::unique_ptr;
using std::cin;
using std::cout;

template <typename T> void do_operation(const unique_ptr<char> &, const unique_ptr<T> &, const unique_ptr<T> &);
template <typename T> inline void increment(unique_ptr<T> &);
template <typename T> inline T sum_of(const unique_ptr<T> &, const unique_ptr<T> &);
template <typename T> inline T difference_of(const unique_ptr<T> &, const unique_ptr<T> &);
template <typename T> inline T product_of(const unique_ptr<T> &, const unique_ptr<T> &);
template <typename T> inline T quotient_of(const unique_ptr<T> &, const unique_ptr<T> &);
template <typename T> inline T moduolo_of(const unique_ptr<T> &, const unique_ptr<T> &);

int main(int agrc, char** argv)
{
    unique_ptr<int> n1(new int);
    unique_ptr<int> n2(new int);
    unique_ptr<char> op(new char);
    char key;

    cout << "Type in your equation:\n";
    while(true)
    {
        cin >> key >> (*n1) >> (*op) >> (*n2);
        if(key == '=')
        {
            cout << "\t= ";
            do_operation(op, n1, n2);
        }
        cout << "\n";
    }
    return 0;
}

template <typename T> void do_operation(const unique_ptr<char> &op, const unique_ptr<T> &n1, const unique_ptr<T> &n2)
{
        if(*op == '+') 
            cout << sum_of(n1,n2);
        else if(*op == '-') 
            cout << difference_of(n1,n2);
        else if(*op == '*') 
            cout << product_of(n1,n2);
        else if(*op == '/') 
            cout << quotient_of(n1,n2);
        else 
            cout << "\nError\n";
}

/*
template <typename T> 
inline void increment(unique_ptr<T> &num)
{
    (*num)++;
}
*/

template <typename T> 
inline T sum_of(const unique_ptr<T> &a,const unique_ptr<T> &b)
{
    return (*a) + (*b);
}

template <typename T> 
inline T difference_of(const unique_ptr<T> &a,const unique_ptr<T> &b)
{
    return (*a) - (*b);
}

template <typename T> 
inline T product_of(const unique_ptr<T> &a, const unique_ptr<T> &b)
{
    return (*a) * (*b);
}

template <typename T> 
inline T quotient_of(const unique_ptr<T> &a,const unique_ptr<T> &b)
{
    return (*a) / (*b);
}

template <typename T> inline T moduolo_of(const unique_ptr<T> &a, const unique_ptr<T> &b)
{
    return (*a) % (*b);
}
