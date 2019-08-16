#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>
using namespace std;




int main(int argc, char const *argv[])
{
    pid_t pid;
    int num = 100;
    pid = fork();
    if(pid == 0) {
        cout<<"this is child process"<<endl;
        cout<<"num in child process: "<<num<<endl;
        while (true) {
            num ++;
            cout<<"num in child process: "<<num<<endl;
            sleep(1);
        }
    }else if(pid>0) {
        cout<<"this is parent process"<<endl;
        cout<<"child pid= "<<pid<<endl;
        cout<<"num in parent process: "<<num<<endl;
        while (true) {
            num --;
            cout<<"num in parent process: "<<num<<endl;
            sleep(1);
        }
    }else if (pid < 0) {
        cout<<"error"<<endl;
    }


    return 0;
}

