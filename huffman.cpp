// THIS WILL TAKE INPUT FROM A TEXT FILE NAMED input.txt

#include <iostream>
#include <fstream>
#include<vector>

using namespace std;

struct node
{
    node *left,*right;
    string letter,bits;
    int frequency;
};
vector <node*> arrayOfNode;

node* findMinimum()
{
    int temp=INT_MAX;
    vector <node*> :: iterator  it1,it2;
    node *temp1;
    for(it1 = arrayOfNode.begin(); it1 != arrayOfNode.end(); it1++)
    {
        temp1 = *it1;
        if(temp > temp1[0].frequency)
        {
            it2=it1;
            temp = temp1[0].frequency;
        }
    }
    node *tempNode;
    tempNode=(*it2);
    arrayOfNode.erase(it2);
    return tempNode;


}

node* creatHuffmanTree(void)
{
    while(!arrayOfNode.empty())
    {
        node *newNode,*tempNode1,*tempNode2;
        newNode=new node[1];
        tempNode1=new node[1];
        tempNode2=new node[1];
        tempNode1 = findMinimum();
        tempNode2 = findMinimum();
        newNode[0].frequency=tempNode1[0].frequency+tempNode2[0].frequency;
        newNode[0].left=tempNode1;
        newNode[0].right=tempNode2;
        arrayOfNode.push_back(newNode);

        if(arrayOfNode.size() == 1)
        {
            break;
        }
    }
    return arrayOfNode[0];
}

bool readFromFileAndInitialize(void)
{
	ifstream iFile;

	// THIS WILL TAKE INPUT FROM A TEXT FILE NAMED input.txt

	iFile.open("input.txt");
	if(iFile.is_open())
	{
		int nuberOfInputs;
		iFile >> nuberOfInputs;
		for(int i=0; i<nuberOfInputs; i++)
		{
		    node *newNode;
		    newNode= new node[1];
			int frequency;
			string letter;
			iFile >> letter;
			iFile >> frequency;

            newNode[0].letter=letter;
            newNode[0].frequency = frequency;
            newNode[0].left=NULL;
            newNode[0].right=NULL;
            arrayOfNode.push_back(newNode);
		}

		iFile.close();
	}
	else
	{
		cout << "Could not open file" << endl;
		return false;
	}
	return true;
}

void codeGeneration(node *current,string s)
{
    node *root1;
    root1=new node[1];
    root1=current;

    root1[0].bits=s;

    if(root1 == NULL)
    {

    }
    else if((root1[0].left == NULL) && (root1[0].right == NULL))
    {
        cout << "code of " << root1[0].letter << " is " << root1[0].bits << endl;
    }
    else
    {
          root1[0].left[0].bits=s.append("0");
          s.erase(s.end()-1);
          root1[0].right[0].bits=s.append("1");
          s.erase(s.end()-1);

          codeGeneration(root1[0].left,s.append("0"));
          s.erase(s.end()-1);
          codeGeneration(root1[0].right,s.append("1"));
          s.erase(s.end()-1);
    }
    /*
    ofstream oFile;
	oFile.open("output.txt", ofstream::out);
	if(oFile.is_open())
	{
        node *root1;
        root1=new node[1];
        root1=current;

        root1[0].bits=s;

        if(root1 == NULL)
        {

        }
        else if((root1[0].left == NULL) && (root1[0].right == NULL))
        {
            cout << "code of " << root1[0].letter << " is " << root1[0].bits << endl;
            //oFile << "code of " << root1[0].letter << " is " << root1[0].bits << endl;
        }
        else
        {
              root1[0].left[0].bits=s.append("0");
              s.erase(s.end()-1);
              root1[0].right[0].bits=s.append("1");
              s.erase(s.end()-1);

              codeGeneration(root1[0].left,s.append("0"));
              s.erase(s.end()-1);
              codeGeneration(root1[0].right,s.append("1"));
              s.erase(s.end()-1);
        }

		oFile.close();
	}
	else
	{
		cout << "Could not open file" << endl;
	}
	*/
}


int main(void)
{
    if(!readFromFileAndInitialize()) return -1;
    node *root = creatHuffmanTree();

    codeGeneration(root,"");


    return 0;
}
