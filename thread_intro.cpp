/*
QUESTIONS
1. What do you understand by thread and give one example in C++?

ANSWER
0. In every application there is a default thread which is main(), in side this we create other threads.
1. A thread is also known as lightweight process. Idea is achieve parallelism by dividing a process into multiple threads. 
   For example:
   (a) The browser has multiple tabs that can be different threads. 
   (b) MS Word must be using multiple threads, one thread to format the text, another thread to process inputs (spell checker)
   (c) Visual Studio code editor would be using threading for auto completing the code. (Intellicence)

WAYS TO CREATE THREADS IN C++11
1. Function Pointers
2. Lambda Functions
3. Functors
4. Member Functions
5. Static Member functions
*/

#include<bits/stdc++.h>
#include<thread>
#include <chrono>
using namespace std::chrono;
using namespace std;
typedef unsigned long long int ull;

// ull oddSum = 0;
// ull evenSum = 0;

// void even(ull s, ull e)
// {
//     for(ull i = s ; i <= e ; i++)
//     {
//         if((i & 1) == 0)  evenSum += i;
//     }
//     return;
// }

// void odd(ull s, ull e)
// {
//     for(ull i = s ; i <= e ; i++)
//     {
//         if(i & 1)  oddSum += i;
//     }
//     return;
// }

// // 1) Function Pointer
// int main()
// {
//     ull s = 0, end = 1900000000;

//     auto start = high_resolution_clock::now();

//     thread t1(even,s,end);
//     thread t2(odd,s,end);
//     // Using join we join the thread with main thread.
//     t1.join();
//     t2.join();

//     even(s,end);
//     odd(s,end);

//     auto stop = high_resolution_clock::now();
//     auto duration = duration_cast<microseconds>(stop - start);

//     cout<<"Even: "<<evenSum<<endl;
//     cout<<"Odd : "<<oddSum<<endl;
//     cout << "Time: " << fixed << setprecision(2) << (double)((double)(duration.count())/1000000) << endl;

    
     


// }

// 2) Lambda Expression
// int main()
// {
//     // auto fun = [](int x)
//     // {
//     //     while(x--)  cout<<x<<endl;
//     // };  

//     auto start = high_resolution_clock::now();

//     thread t1([](int x)
//     {
//         while(x--)  cout<<x<<endl;
//     },10);
//     thread t2([](int x)
//     {
//         while(x--)  cout<<x<<endl;
//     },10);
//     t1.join();
//     t2.join();

//     auto stop = high_resolution_clock::now();
//     auto duration = duration_cast<microseconds>(stop - start);

//     cout << "Time: " << fixed << setprecision(2) << (double)((double)(duration.count())/1000000) << endl;

//     return 0;
// }

// 3) Functor (Function Object)

// class Base
// {   
//     public:
//     void operator()(int x)
//     {
//         while(x--)  cout<<x<<endl;
//         return;
//     }
// };

// int main()
// {
//     auto start = high_resolution_clock::now();

//     thread t1((Base()),10);
//     thread t2((Base()),10);
//     t1.join();
//     t2.join();

//     auto stop = high_resolution_clock::now();
//     auto duration = duration_cast<microseconds>(stop - start);

//     cout << "Time: " << fixed << setprecision(2) << (double)((double)(duration.count())/1000000) << endl;


//     return 0;
// }


// 4) Non-Static Member Function

// class Base
// {
//     public:
//     void run(int x)
//     {
//         while(x--)  cout<<x<<endl; 
//     }
// };

// int main()
// {
//     auto start = high_resolution_clock::now();

//     Base B;

//     thread t1(&Base::run,&B,10);
//     thread t2(&Base::run,&B,10);

//     t1.join();
//     t2.join();

//     auto stop = high_resolution_clock::now();
//     auto duration = duration_cast<microseconds>(stop - start);

//     cout << "Time: " << fixed << setprecision(2) << (double)((double)(duration.count())/1000000) << endl;

//     return 0;
// }

// 5) Static Member Function

// class Base
// {
//     public:
//     static void run(int x)
//     {
//         while(x--)  cout<<x<<endl; 
//     }
// };

// int main()
// {
//     thread t1(&Base::run,10);
//     thread t2(&Base::run,10);
//     t1.join();
//     t2.join();

//     return 0;
// }