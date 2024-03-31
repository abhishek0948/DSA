#include <bits/stdc++.h>
using namespace std;

template<typename T>

class Graph{
    public:
    int **arr;
    int weight;
    int nodes;

    Graph(int num){
        this->nodes=num;

        arr=new int*[nodes];
        for(int i=0;i<nodes;i++){
            arr[i]=new int[nodes];
            for(int j=0;j<nodes;j++){
                arr[i][j]=0;
            }
        }
        this->weight=0;
    }

    void insert(T i,T j,bool direction=false){
        For undirected graph
        arr[i][j]=1;

        if(!direction)
            arr[j][i]=1;
        return ;
    }

    void delete_edge(T i,T j,bool direction=false){
        arr[i][j]=0;
        if(!direction)
            arr[j][i]=0;
    }

    void print(){
        for(int i=0;i<nodes;i++){
            for(int j=0;j<nodes;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph<int> graph(5);
    graph.insert(0,1,true);
    graph.insert(0,2,true);
    graph.insert(1,4,true);
    graph.insert(3,2);
    graph.print();

    graph.delete_edge(0,2);
    graph.print();
    return 0;
}