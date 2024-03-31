#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int>> m;
    int nodes_num;

    Graph(int num){
        this->nodes_num=num;
    }

    void insert(int src,int dest,bool direction=false){
        m[src].push_back(dest);

        if(!direction){
            m[dest].push_back(src);
        }
    }

    void delete_edge(int src,int dest,bool direction=false){
        list<int> :: iterator it=find(m[src].begin(),m[src].end(),dest);
        m[src].erase(it);

        if(!direction){
            list<int> :: iterator it=find(m[dest].begin(),m[dest].end(),src);
            m[dest].erase(it);
        }
    }

    void print(){
        for(auto i:m){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<" ";
            }cout<<endl;
        }
    }
};

int main(){
    Graph graph(5);
    graph.insert(0,1);
    graph.insert(0,2);
    graph.insert(1,4);
    graph.insert(3,2);
    graph.print();

    return 0;
}