/*
JOIN NOTES
0. Once a thread is started we wait for this thread to finish by calling join() function on thread object.
1. Double join will result into program termination.
2. If needed we should check thread is joinable before joining. ( using joinable() function)

DETACH NOTES
0. This is used to detach newly created thread from the parent thread.
1. Always check before detaching a thread that it is joinable otherwise we may end up double detaching and 
   double detach() will result into program termination.
2. If we have detached thread and main function is returning then the detached thread execution is suspended.

NOTES:
Either join() or detach() should be called on thread object, otherwise during thread object�s destructor it will 
terminate the program. Because inside destructor it checks if thread is still joinable? if yes then it terminates 
the program.
*/


#include<bits/stdc++.h>
#include<thread>
#include <chrono>
using namespace std::chrono;
using namespace std;
typedef unsigned long long int ull;

void run(int n)
{
   while(n--)  cout<<"FNC"<<endl;
   // this_thread::sleep_for(chrono::seconds(3));
}

// Join

// int main()
// {
//     thread t1(run,10);
//     cout<<"Main Before"<<endl;
//     if(t1.joinable())   t1.join();  // here we will first check if t1 is joinable and then 
//                                     // wait for the thread to complete its execution before moving further.
//     cout<<"Main After"<<endl;
//     return 0;
// }

// Detach

int main()
{
   thread t1(run,10);
   cout<<"main before"<<endl;
   if(t1.joinable()) t1.detach();
   cout<<"main after"<<endl;
   this_thread::sleep_for(chrono::seconds(1));
   return 0;

}