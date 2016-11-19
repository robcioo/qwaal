#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>
#include <vector>
using namespace std;
static vector<int> generateData(int size_x, int size_y, int ammount){
    vector < int > data;
    for(int i=0; i<3*ammount;++i){
        data.push_back(rand()%100+1);
    }
    return data;
}
int main(int argc, char* argv[])//FILE/OUT MODE, SIZE_X, SIZE_Y, ELEMENTS_AMMOUNT
{
    bool fileMode;
    ofstream file;
    if(argc!=4+1){
        return 1;
    }
    if((string)argv[1]=="-o"){
        fileMode=false;
    }else if((string)argv[1]=="-f"){
        fileMode=true;
    }
    else return 1;
    int size_x=atoi(argv[2]);
    int size_y=atoi(argv[3]);
    int ammount=atoi(argv[4]);
    /*size_x=10;
    size_y=10;
    ammount=30;*/
    if(size_x<=0 || size_y<=0 || ammount<=0){
        return 1;
    }
    srand (time(NULL));
    vector < int > data=generateData(size_x,size_y,ammount);
    if(fileMode){
        file.open ("data.txt", ios::out | ios::trunc);
        file<<size_x<<" ";
        file<<size_y<<" ";
        file<<ammount;
    }
    else{
        cout<<size_x<<" ";
        cout<<size_y<<" ";
        cout<<ammount;
    }
   // cout<<"jest    "<<data.size();
    for(int i=0; i<data.size();++i){
        if(fileMode){
            if(i%3==0){
                file<<"\n";
            }
            file<<data.at(i)<<" ";
        }
        else{
            if(i%3==0){
                cout<<"\n";
            }
            cout<<data.at(i)<<" ";
        }
    }
    return 0;
}


