#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<stack>
#include<algorithm>

using namespace std;

struct content
{
	float number;
	char symbol;
	bool flag;
};

char operators[6] = {'+','-','*','/','(',')'};

void replaceSymbols(string &numbers)
{
	for(int i=0;i<6;i++)
	{
		for(int j=0; j<numbers.length(); j++)
		{
			if(operators[i]==numbers[j]) numbers[j] = ' ';
		}
	}
}

void makeContentWithNumber(content &node, float numberObtained)
{
	node.number = numberObtained;
	node.flag = true;
}

void makeContentWithSymbol(content &node, char symbolFromInputStringArray)
{
	node.symbol = symbolFromInputStringArray;
	node.flag = false;
}

void parsingInput(string inputString, vector <content> &infix)
{
	string numbers = inputString;
	replaceSymbols(numbers);

	istringstream iss(numbers);

	vector <float> numbersObtained;
	float temp;
	while (iss >> temp)
	{
		numbersObtained.push_back(temp);
	}


	for(int i=0; i<numbers.size(); i++)
	{
		if(numbers[i]== ' ')
		{
			if(i != 0)
			{
				if(numbers[i-1] != ' ')
				{
					content node;
					makeContentWithNumber(node, numbersObtained[0]);
					infix.push_back(node);
					numbersObtained.erase(numbersObtained.begin());

					makeContentWithSymbol(node, inputString[i]);
					infix.push_back(node);
				}
				else
				{
					content node;
					makeContentWithSymbol(node, inputString[i]);
					infix.push_back(node);
				}
			}
			else
			{
				//jodi amra 0 tomo jaigate space pai
				content node;
				makeContentWithSymbol(node, inputString[i]);
				infix.push_back(node);
			}
		}
	}

	if(!numbersObtained.empty())
	{
		content node;
		makeContentWithNumber(node, numbersObtained[0]);
		infix.push_back(node);
		numbersObtained.erase(numbersObtained.begin());
	}

}

bool lowerPrecedence(char infixSymbol , char stackSymbol)
{
	if((infixSymbol=='*'||infixSymbol=='/')&&(stackSymbol=='+'||stackSymbol=='-')) return true;
	else return false;
}

void replaceBracketSign(vector<content> &infix)
{
    for(int i=0; i<infix.size(); i++)
    {
        if(!(infix[i].flag))
        {
            if(infix[i].symbol=='(')
                infix[i].symbol=')';
            else if(infix[i].symbol==')')
                infix[i].symbol='(';
        }
    }

}


void infixToPrefix(vector <content> infix, vector <content> &prefix)
{
	stack <content> myStack;

	content node;
	makeContentWithSymbol(node, '(');
	myStack.push(node);
	makeContentWithSymbol(node, ')');
	infix.push_back(node);

	for(int i=0; i<infix.size(); i++)
	{
		if(infix[i].flag)
		{
			prefix.push_back(infix[i]);
		}
		else
		{
			if(infix[i].symbol == '(')
			{
				myStack.push(infix[i]);
			}
			else if(infix[i].symbol == ')')
			{
				while(1)
				{
					content tempNode = myStack.top();
					if(tempNode.symbol == '(')
					{
						myStack.pop();
						break;
					}
					else
					{
						prefix.push_back(tempNode);
						myStack.pop();
					}
				}
			}
			else
			{
				while(1)
				{
					content tempNode1= myStack.top();
					if(lowerPrecedence(infix[i].symbol, tempNode1.symbol)|| tempNode1.symbol == '(') break;
					prefix.push_back(tempNode1);
					myStack.pop();
				}
				myStack.push(infix[i]);
			}
		}
	}
	reverse(prefix.begin(),prefix.end());
}

float evaluateBasicArithmetic(float a, float b, char symbol)
{
	switch(symbol)
	{
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		default: return a/b;
	}
}

float evaluatePrefixNotation(vector <content> prefix)
{
	stack <float> myStack;

	for(int i=prefix.size()-1; i>=0; i--)
	{
		if(prefix[i].flag)
		{
			myStack.push(prefix[i].number);
		}
		else
		{
			float firstTopNumber, secondTopNumber, result;
			firstTopNumber = myStack.top();
			myStack.pop();
			secondTopNumber = myStack.top();
			myStack.pop();

			result = evaluateBasicArithmetic(firstTopNumber, secondTopNumber, prefix[i].symbol);
			myStack.push(result);
		}
	}
	return myStack.top();
}

void printExpression(vector <content> expVec)
{
	for(int i=0; i<expVec.size(); i++)
	{
		if(expVec[i].flag) cout << expVec[i].number << " ";
		else cout << expVec[i].symbol << " ";
	}
	cout << endl;
}

int main (void)
{
	string inputString;
	//getline(cin, inputString);
    inputString="12+(23-11)*15/(17-13)+11";
	vector <content> infix;
	parsingInput(inputString, infix);

	cout << "Infix is: ";
	printExpression(infix);
	reverse(infix.begin(),infix.end());
	//cout << "reverse Infix is: ";
    //printExpression(infix);
	replaceBracketSign(infix);
	//cout << "After replacing bracket ,Infix is: ";
	//printExpression(infix);

	vector <content> prefix;
	infixToPrefix(infix, prefix);
	cout << "Prefix is: ";
	printExpression(prefix);
	cout << "The Result is: ";
	cout << evaluatePrefixNotation(prefix) << endl;

	//cout << "Result is: " << evaluatePostfix(postfix) << endl;

	return 0;
}
