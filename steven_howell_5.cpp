
//Steven Howell
#include <iostream>


#include <iostream>
#include <stack>
#include <queue>
#include <array>
#include <bits/stdc++.h>
#include <list>
#include <map>
#include <bits/stdc++.h>
using namespace std;
/*
 * tried to make dictionary to change string to int didn't work
template<class T>
class Dictionary{
    public:
    Dictionary(){
    }
    explicit Dictionary(T data1, T data2){
        key = new map<data1,data2>;
        key[data1]=data2;
        value[data2]=data1;
    }

    private:
    static map<T, T>key;
    static map<T,T>value;

}
*/
void menu(){
    std::cout.width(20);
    std::cout<<"MENU"<<std::endl<<std::endl<<"Depth-First Search (0), Minimum Path Search (1) "<<std::endl;
    std::cout<<"Exit Program (2)"<<std::endl<<"Choose?";

}
map<string, vector<string>>adjacency_list;

void DF(list<string> filled, stack<string> stored);

bool check(list<string> foolist, const string& foovar);

//void MPSS(int source, int destination);
//void MPSS(const string& input, const string& string2);
void MPSS(string input, string string2);
void MPS(list<string> list1, queue<string> stack1, string basicString,int count,vector<string> path = {});

static map<int, vector<int>>adj_int;
static map<string, int>encode;
static map<int,string>decode;
void Build_Dict(){
    encode["A"] =0;
    encode["B"] =1;
    encode["C"] =2;
    encode["D"] =3;
    encode["E"] =4;
    encode["F"] =5;
    encode["G"]=6;
    encode["H"]=7;
    encode["I"]=8;
    decode[0] ="A";
    decode[1] ="B";
    decode[2] ="C";
    decode[3] ="D";
    decode[4] ="E";
    decode[5] ="F";
    decode[6]="G";
    decode[7]="H";
    decode[8]="I";
}

void add_edge(int src, int dest)
{
    adj_int[src].push_back(dest);
    adj_int[dest].push_back(src);
}
/*
void add_edge_string(string src, string dest)
{
    adj_int[src].push_back(dest);
    adj_int[dest].push_back(src);
}
 */
void AMP(){
    Build_Dict();
    /*
    add_edge("A","B");
    add_edge("A","C");
    add_edge("A","D");
    add_edge("B","E");
    add_edge("C","B");
    add_edge("C","G");
    add_edge("D","C");
    add_edge("D","G");
    add_edge("E","C");
    add_edge("E","F");
    add_edge("F","C");
    add_edge("F","H");
    add_edge("G","F");
    add_edge("G","H");
    add_edge("G","I");
    add_edge("H","E");
    add_edge("H","I");
    add_edge("I","F");
    */
    add_edge(encode["A"],encode["B"]);
    add_edge(encode["A"],encode["C"]);
    add_edge(encode["A"],encode["D"]);
    add_edge(encode["B"],encode["E"]);
    add_edge(encode["C"],encode["B"]);
    add_edge(encode["C"],encode["G"]);
    add_edge(encode["D"],encode["C"]);
    add_edge(encode["D"],encode["G"]);
    add_edge(encode["E"],encode["C"]);
    add_edge(encode["E"],encode["F"]);
    add_edge(encode["F"],encode["C"]);
    add_edge(encode["F"],encode["H"]);
    add_edge(encode["G"],encode["F"]);
    add_edge(encode["G"],encode["H"]);
    add_edge(encode["G"],encode["I"]);
    add_edge(encode["H"],encode["E"]);
    add_edge(encode["H"],encode["I"]);
    add_edge(encode["I"],encode["F"]);
}
/*
// example code to test what I wrote
bool MFS(int src, int dest, int v,
         int pred[], int dist[])
{
    // a queue to maintain queue of vertices whose
    // adjacency list is to be scanned as per normal
    // DFS algorithm
    list<int> queue;

    // boolean array visited[] which stores the
    // information whether ith vertex is reached
    // at least once in the Breadth first search
    bool visited[v];

    // initially all vertices are unvisited
    // so v[i] for all i is false
    // and as no path is yet constructed
    // dist[i] for all i set to infinity
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }

    // now source is first to be visited and
    // distance from source to itself should be 0
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);

    // standard MFS algorithm
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj_int[u].size(); i++) {
            if (!visited[adj_int[u][i]]) {
                visited[adj_int[u][i]] = true;
                dist[adj_int[u][i]] = dist[u] + 1;
                pred[adj_int[u][i]] = u;
                queue.push_back(adj_int[u][i]);

                // We stop MFS when we find
                // destination.
                if (adj_int[u][i] == dest)
                    return true;
            }
        }
    }

    return false;
}

// utility function to print the shortest distance
// between source vertex and destination vertex
void SD(int s,
        int dest, int v)
{
    // predecessor[i] array stores predecessor of
    // i and distance array stores distance of i
    // from s
    int pred[v], dist[v];

    if (!MFS(s, dest, v, pred, dist)) {
        cout << "Given source and destination"
             << " are not connected";
        return;
    }

    // vector path stores the shortest path
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    // distance from source is in distance array
    //cout << "Shortest path length is : "
    //     << dist[dest];

    // printing path from source to destination
   // cout << "\nPath is::\n";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << decode[path[i]] << " ";
}
*/
void short_self(string start, string end, map<string,string>dict_store,queue<string>QUEUE,list<string> filled={}){
    string current = QUEUE.front();
    QUEUE.pop();
    filled.push_back(current);
    vector<string>tmp = adjacency_list[current];
    for(const auto& k: tmp){
        if(!check(filled,k)){
            QUEUE.push(k);
            dict_store[k]=current;
        }
      if(k == end){
          string backtrack= end;
          stack<string> min_path;
          min_path.push(end);
          while(backtrack!=start){
              backtrack = dict_store[backtrack];
              min_path.push(backtrack);
          }
          while(!min_path.empty()){
              cout<<min_path.top()<<" ";
              min_path.pop();
          }
          cout<<endl;

          return;
      }
    }
    if(!QUEUE.empty()){
        short_self(start,end,dict_store,QUEUE,filled);
    }
    else{
        cout<<"No Path"<<endl;
    }
}






void A_M(){
    /*
    vector<string> A;
    vector<string> B;
    vector<string> C;
    vector<string> D;
    vector<string> E;
    vector<string> F;
    vector<string> G;
    vector<string> H;
    vector<string> I;
    A.push_back("B");
    A.push_back("C");
    A.push_back("D");
    B.push_back("E");

    C.push_back("B");
    C.push_back("G");
    D.push_back("C");
    D.push_back("G");
    E.push_back("C");
    E.push_back("F");
    F.push_back("C");
    F.push_back("H");
    G.push_back("F");
    G.push_back("H");
    G.push_back("I");
    H.push_back("E");
    H.push_back("I");
    I.push_back("F");
     */
    adjacency_list ["A"].emplace_back("B");
    adjacency_list ["A"].emplace_back("C");
    adjacency_list ["A"].emplace_back("D");
    adjacency_list ["B"].emplace_back("E");

    adjacency_list ["C"].emplace_back("B");
    adjacency_list ["C"].emplace_back("G");
    adjacency_list ["D"].emplace_back("C");
    adjacency_list ["D"].emplace_back("G");
    adjacency_list ["E"].emplace_back("C");
    adjacency_list ["E"].emplace_back("F");
    adjacency_list ["F"].emplace_back("C");
    adjacency_list ["F"].emplace_back("H");
    adjacency_list ["G"].emplace_back("F");
    adjacency_list ["G"].emplace_back("H");
    adjacency_list ["G"].emplace_back("I");
    adjacency_list ["H"].emplace_back("E");
    adjacency_list ["H"].emplace_back("I");
    adjacency_list ["I"].emplace_back("F");
}


void DFS(const string& input){
    list<string> used;
    stack<string> tmp_stack;
    used.push_back(input);
    tmp_stack.push(input);
    DF(used,tmp_stack);
}

void DF(list<string> filled, stack<string> stored) {
    string current = stored.top();
    stored.pop();
    cout<<current<<" ";
    vector<string>tmp = adjacency_list [current];
    for(const auto& k: tmp){
        if(!check(filled,k)){
            //cout<<k<<" ";
            filled.push_back(k);
            stored.push(k);
        }
    }
    if(!stored.empty()) {
        DF(filled, stored);
        cout<<endl;
    }
}

bool check(list<string> foolist, const string& foovar) {
    bool found = (std::find(foolist.begin(), foolist.end(), foovar) != foolist.end());
    return found;

}




void MPSS(string source, string destination){
    //SD(source, destination, 9);
    //cout<<endl;
    map<string,string> dict_store;
    queue<string> QUEUE, ORIG;
    QUEUE.push(source);
    //ORIG.push(-1);
    dict_store[source]="null";
    short_self(source,destination,dict_store,QUEUE);

}
//int min = 100000000;

//int min_tmp = 10000000;
//vector<string> min_path = {};
/*
void MPS(list<string> filled, queue<string> stored, string dest, int count, vector<string> path) {

        string current = stored.front();
        stored.pop();
        path.push_back(current);
        count = count + 1;
        cout << count << endl;
        //cout<<count<<" ";
        //cout<<current<<" ";
        vector<string> tmp = adjacency_list[current];
        if (!(current == dest)) {
            for (auto k: tmp) {
                if (!check(filled, k)) {
                    //cout<<k<<" ";
                    //filled.push_back(k);
                    stored.push(k);
                }
            }

        } else if (min_tmp > count) {
            min_tmp = count;
            min_path = path;

        }
        if(stored.empty())
            return;



        MPS(filled, stored, dest, count, path);

        //filled.pop_back();
        path.pop_back();


}
*/


//static map<string, vector<string>>adj_int;

/*
bool BFS(string src, string dest, int v,
         string pred[], string dist[])
{
    // a queue to maintain queue of vertices whose
    // adjacency list is to be scanned as per normal
    // DFS algorithm
    list<string> queue;

    // boolean array visited[] which stores the
    // information whether ith vertex is reached
    // at least once in the Breadth first search
    bool visited[v];

    // initially all vertices are unvisited
    // so v[i] for all i is false
    // and as no path is yet constructed
    // dist[i] for all i set to infinity
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }

    // now source is first to be visited and
    // distance from source to itself should be 0
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);

    // standard BFS algorithm
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj_int[u].size(); i++) {
            if (visited[adj_int[u][i]] == false) {
                visited[adj_int[u][i]] = true;
                dist[adj_int[u][i]] = dist[u] + 1;
                pred[adj_int[u][i]] = u;
                queue.push_back(adj_int[u][i]);

                // We stop BFS when we find
                // destination.
                if (adj_int[u][i] == dest)
                    return true;
            }
        }
    }

    return false;
}

// utility function to print the shortest distance
// between source vertex and destination vertex
void SD(vector<int> adj_int[], int s,
                           int dest, int v)
{
    // predecessor[i] array stores predecessor of
    // i and distance array stores distance of i
    // from s
    int pred[v], dist[v];

    if (MFS(adj_int, s, dest, v, pred, dist) == false) {
        cout << "Given source and destination"
             << " are not connected";
        return;
    }

    // vector path stores the shortest path
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    // distance from source is in distance array
    cout << "Shortest path length is : "
         << dist[dest];

    // printing path from source to destination
    cout << "\nPath is::\n";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}
*/


// make a disposition based on input
 std::string decision(const std::string& user_input){
    std::string key = "null";

    std::string del = " ";//parameter to use
    std::stringstream ss(user_input);
    std::string word;
    std::vector<std::string> wordlist{};//command vector
/*
while (!ss.eof()) {
    getline(ss, word, del);
    std::cout << word << std::endl;
}
*/

    while (ss >> word) {//splits string by space
        //std::cout << word << std::endl;

        wordlist.push_back(word);//puts the individual strings into a vector
        if(wordlist.size()>50){//if there is are 3 detected inputs then return error
            std::cout<<"Input has too many parameters. Please try again."<<std::endl;
            //wordlist.empty();
            return key;
            //break;
        }
    }
    //checks if the first input matches the command number and is a valid input
    if((wordlist.at(0) == ("1"))&&
       wordlist.size()!=3){
        std::cout<<"No input parameter"<<std::endl;
        return key;
    }

    else if ((wordlist.at(0) == ("0"))
             &&wordlist.size()!=2){
        std::cout<<"too many inputs"<<std::endl;
        return key;
    }

    //check valid input or if the input value is 0
    if(wordlist.size()>1){
    if(wordlist.at(1).size() > 1) {
        for (int k = 1; k < wordlist.size(); k++) {
            for (char i: wordlist.at(k)) {
                if (!std::isalpha(i)) {
                    std::cout << "input is not a char" << std::endl;
                    return key;
                }
            }
        }
    }
    }

    if(wordlist.at(0) == "0"){
        DFS(wordlist.at(1));


    }

    else if(wordlist.at(0) == "1"){
        MPSS(wordlist.at(1),wordlist.at(2));


    }

    else if(wordlist.at(0) == "2"){
        key = "exit"; //pass exit code
    }

    return key;
}





int main() {
    A_M();
    AMP();
    std::string exit = "go";
    //vector<vector<int>> map;
    while(exit != "exit") {

        menu();
        std::string u_input;
        getline(std::cin,u_input);
        exit = decision(u_input);//decide on output checks if it should exit

    }
    std::cout<<"Program finished have a nice day!"<<std::endl;//a friendly message
    return 0;
}