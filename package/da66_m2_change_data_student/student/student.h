#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>
using namespace std;
using std::string;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    // your code here
    stack<std::vector<std::queue<int>>> s;
    while(!a.empty()){
        auto &tmp=a.top();
        for(auto &x:tmp){
            queue<int> temp;
            while(!x.empty()){
                if(x.front()==from){
                    temp.push(to);
                }
                else{
                    temp.push(x.front());
                }
                x.pop();
            }
            x=temp;
        }
        s.push(tmp);
        a.pop();
    }
    while(!s.empty()){
        a.push(s.top());
        s.pop();
    }   
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    // your code here
    for(auto &x:a){
        if(x.second.second==from){
            x.second.second=to;
        }
        priority_queue<int> temp;
        auto &pq=x.second.first;
        while(!pq.empty()){
            if(pq.top()==from){
                temp.push(to);
            }
            else{
                temp.push(pq.top());
            }
            pq.pop();
        }
        pq=temp;
    }
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{
    // your code here
    set<pair<list<int>,map<int,pair<int,string>>>> newset;
    for(auto &x:a){
        list<int> templist;
        for(auto &y:x.first){
            if(y==from){
                templist.push_back(to);
            }
            else{
                templist.push_back(y);
            }
        }
        map<int,pair<int,string>> newmap;
        for(auto &z:x.second){
            int temp=z.first;
            int temp2=z.second.first;
            if(z.first==from){
                temp=to;
            }
            if(z.second.first==from){
                temp2=to;
            }
            newmap[temp]={temp2,z.second.second};
        }
        newset.insert({templist,newmap});
    }
    a=newset;
    
}

#endif
