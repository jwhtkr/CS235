#include<sstream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<fstream>
#include<cctype>
#include<iostream>
#include<list>

using namespace std;

void getWord(string &);
void print(set<string> &, ofstream &);
void print(vector<string> &, ofstream &);
void print(map<string, string> &, ofstream &);

int main()
{
    string fileName (""), token (""), previous (""), state("");
    int random(0), M(2);
    
    cout << "Input name of file (without file extension) to open: ";
    cin >> fileName;
    // fileName += ".txt";
    ifstream inFile (fileName + ".txt");
    
    set <string> mySet;
    vector <string> myVec;
    ofstream outFile;
    map<string, string> wordmap1;
    map<string, vector<string>> wordmap2;
    map<list<string>, vector<string>> wordmap3;
    list<string> listState;
    for (int i = 0; i < M; i++)
    {
        listState.push_back("");
    }
    srand(time(NULL));
    
    if (inFile.is_open())
    {
        cout << "Opening " << fileName << ".txt" << endl;
        while(inFile >> token)
        {
            getWord(token);
            // cout << token << " ";
            if (token != "-")
            {
                mySet.insert(token);
                myVec.push_back(token);
            }
        }
        
    }
    else
    {
        cout << "File name was invalid." << endl;
    }
    
    outFile.open(fileName + "_set.txt");
    print (mySet, outFile);
    outFile.close();
    
    outFile.open(fileName + "_vector.txt");
    print (myVec, outFile);
    outFile.close();
    
    for (vector<string>::iterator it = myVec.begin(); it != myVec.end(); it++)
    {
        wordmap1[previous] = *it;
        previous = *it;
    }
    
    outFile.open(fileName +"_1_1.txt");
    print (wordmap1, outFile);
    outFile.close();
    
    for (int i = 0; i < 100; i++)
    {
        cout << wordmap1[state] << " ";
        state = wordmap1[state];
    }
    cout << endl << endl;
    
    previous = "";
    for (vector<string>::iterator it = myVec.begin(); it != myVec.end(); it++)
    {
        wordmap2[previous].push_back(*it);
        previous = *it;
    }
    
    map<string, vector<string>>::iterator it = wordmap2.begin();
    it++;
    it++;
    it++;
    it++;
    it++;
    
    cout << it->first << ":" << endl;
    for (const auto & i : it->second)
    {
        cout << i << ", ";
    }
    cout << endl << endl;
    
    // for (const auto & i : wordmap2["Nephi"])
    // {
    //     cout << i << ", ";
    // }
    // cout << endl << endl;
    
    state = "";
    for (int i = 0; i < 100; i++)
    {
        random = rand() % wordmap2[state].size();
        cout << wordmap2[state][random] << " ";
        state = wordmap2[state][random];
    }
    cout << endl;
    
    for (vector<string>::iterator it = myVec.begin(); it != myVec.end(); it++)
    {
        wordmap3[listState].push_back(*it);
        listState.push_back(*it);
        listState.pop_front();
    }
    
    listState.clear();
    for (int i = 0; i < M; i++)
    {
        listState.push_back("");
    }
    for (int i = 0; i < 100; i++)
    {
        random = rand() % wordmap3[listState].size();
        cout << wordmap3[listState][random] << " ";
        listState.push_back(wordmap3[listState][random]);
        listState.pop_front();
    }
    cout << endl << endl;
    
}



void getWord(string & token)
{
    for (int i = 0; i < token.size(); i++)
    {
        if (!isalpha(token[i]) && token.size() > 1)
        {
            // cout << "erasing " << token[i] << " ...";
            token.erase(i,1);
            i--;
            // cout << "erased... i = " << i << "...";
            // cout << "size = " << token.size() << "...";
            // cout << endl;
        }
        else if (!isalpha(token[i]))
        {
            token = "-";
        }
    }

    // cout << token << endl;
}

void print(set<string> & mySet, ofstream & outFile)
{
    cout << "printing the set" << endl;
    
    for (const auto & i : mySet)
    {
        outFile << i << endl;
    }
}

void print(vector<string> & myVec, ofstream & outFile)
{
    cout << "printing the vector" << endl;
    
    for (const auto & i : myVec)
    {
        outFile << i << endl;
    }
}

void print(map<string, string> & wordmap, ofstream & outFile)
{
    cout << "printing the wordmap" << endl;
    
    for (const auto & i : wordmap)
    {
        outFile << i.first << ", " << i.second << endl;
    }
}
