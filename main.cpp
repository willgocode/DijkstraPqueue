#include <iostream>
#include <fstream>
#include <vector> 
#include <queue>

using namespace std;

struct AdjNode{
	int next;
	double weight;
};

struct AdjList{
	vector<AdjNode> nodes;
};

vector<AdjList> fillVector();

int main(){
	vector<AdjList> myList = fillVector();
	for(int i = 0; i < 5 ; i++){
		for(int j = 0; j < myList.size(); j++){
			cout << myList[i].nodes[j].next<<endl;
		}
	}
	return 0;
}

vector<AdjList> fillVector(){
	ifstream graph;
    double line;
    int numNodes;
    vector<AdjList> myList;

    graph.open("graph1.txt");

    if(graph.is_open()){
        AdjNode tempNode;
        AdjList tempList;

        graph >> numNodes;

        for(int i = 0; i < numNodes; i++){
            graph >> line;  //read the current node
            cout << "Looping " << i << endl;

            for(int j = 0; tempNode.next != -1 ; j++){      //loop to fill out current node
                graph >> tempNode.next;

                if(tempNode.next == -1)
                    break;

                graph >> tempNode.weight;
                tempList.nodes.push_back(tempNode);
            }
            
            tempNode.next = 0;              //cleaning up
            myList.push_back(tempList);     //pushing into myList
            tempList.nodes.clear();         //cleaning up
        }
        graph.close();
    }
	return myList;
}
