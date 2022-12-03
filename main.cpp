
//Steven Howell
#include <iostream>


#include <iostream>
#include <stack>
#include <queue>
#include <array>
#include <bits/stdc++.h>
#include <list>
#include <map>
using namespace std;

void menu(){
    std::cout.width(20);
    std::cout<<"MENU"<<std::endl<<std::endl<<"Depth-First Search (0), Minimum Path Search (1) "<<std::endl;
    std::cout<<"Exit Program (2)"<<std::endl<<"Choose?";

}
map<string, vector<string>>adjacency_list;

void DF(list<string> list1, stack<string> stack1);

bool check(list<string> list1, string basicString);


void MPS(list<string> list1, stack<string> stack1, string basicString,int count,vector<string> path = {});

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
    adjacency_list ["A"].push_back("B");
    adjacency_list ["A"].push_back("C");
    adjacency_list ["A"].push_back("D");
    adjacency_list ["B"].push_back("E");

    adjacency_list ["C"].push_back("B");
    adjacency_list ["C"].push_back("G");
    adjacency_list ["D"].push_back("C");
    adjacency_list ["D"].push_back("G");
    adjacency_list ["E"].push_back("C");
    adjacency_list ["E"].push_back("F");
    adjacency_list ["F"].push_back("C");
    adjacency_list ["F"].push_back("H");
    adjacency_list ["G"].push_back("F");
    adjacency_list ["G"].push_back("H");
    adjacency_list ["G"].push_back("I");
    adjacency_list ["H"].push_back("E");
    adjacency_list ["H"].push_back("I");
    adjacency_list ["I"].push_back("F");
}


void DFS(string input){
    list<string> used;
    stack<string> tmp_stack;
    used.push_back("H");
    tmp_stack.push(input);
    DF(used,tmp_stack);
}

void DF(list<string> filled, stack<string> stored) {
    string current = stored.top();
    stored.pop();
    cout<<current<<" ";
    vector<string>tmp = adjacency_list [current];
    for(auto k: tmp){
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

bool check(list<string> foolist, string foovar) {
    bool found = (std::find(foolist.begin(), foolist.end(), foovar) != foolist.end());
    return found;

}

void MPSS(string input,string go){
    list<string> used;
    stack<string> tmp_stack;
    used.push_back("H");
    tmp_stack.push(input);
    int count=0;
    vector<string> path = {};
    MPS(used,tmp_stack,go,count,path);
}
//int min = 100000000;

int min_tmp = 10000000;
vector<string> min_path = {};

void MPS(list<string> filled, stack<string> stored, string dest, int count, vector<string> path) {
    string current = stored.top();
    stored.pop();
    path.push_back(current);
    count = count +1;
    //cout<<count<<" ";
    //cout<<current<<" ";
    vector<string>tmp = adjacency_list [current];
    if(!(current == dest)) {
        for (auto k: tmp) {
            if (!check(filled, k)) {
                //cout<<k<<" ";
                filled.push_back(k);
                stored.push(k);
            }
        }
        if(!stored.empty()) {
            MPS(filled, stored,dest,count,path);
        }
    }
    else if(min_tmp>count){
        min_tmp = count;
        min_path = path;
    }
    path.pop_back();

}







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
    if(wordlist.at(1).size() > 1){
        for(int k = 1; k<wordlist.size();k++) {
            for (char i: wordlist.at(k)) {
                if (!std::isalpha(i)) {
                    std::cout << "input is not a char" << std::endl;
                    return key;
                }
            }
        }

    }




    if(wordlist.at(0) == "0"){
        DFS(wordlist.at(1));


    }

    else if(wordlist.at(0) == "1"){
        MPSS(wordlist.at(1),wordlist.at(2));
        /*
        if(!(min_tmp==10000000)) {
            cout << min_tmp << endl;
        }
         */
        if(!min_path.empty()){
            for(auto x: min_path){
                cout<<x<<" ";
            }
            cout<<endl;
        }

    }

    else if(wordlist.at(0) == "2"){
        key = "exit"; //pass exit code
    }

    return key;
}





int main() {
    A_M();
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