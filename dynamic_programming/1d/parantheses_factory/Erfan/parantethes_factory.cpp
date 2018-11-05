#include <iostream>
#include <stack> 
using namespace std;

void printStack(stack <char> inp) // Debug Purpose
{ 
    stack <char> s = inp;
    while (!s.empty()) 
    { 
        cerr << s.top() << ' '; 
        s.pop(); 
    } 
    cerr << endl;
}

void PrintArray(int* arr, int length)
{
    for( int i=0; i<length; i++)
        cerr << arr[i] << " ";
    cerr << endl;
}

bool isOpen(char input)
{
    if( input=='(' or input=='[' or input=='{' or input=='<' )
        return true;
    return false;
}

bool isPairWithStackTop(stack<char>& s, char close)
{
    if (s.size() == 0)
        return false;
    char open = s.top();
    if (open=='(' and close==')')
        return true;
    else if (open=='[' and close==']')
        return true;
    else if (open=='{' and close=='}')
        return true;
    else if (open=='<' and close=='>')
        return true;
    return false;    
}

int maxCorrectParentheses(int* report, const char* input, int start, int length)
{
    int result = 0;
    stack<char> openParensStack;
    report[start] = 0;

    for(int i=start; i<length; i++)
    {
        // cerr << i << ". ";
        if (report[i] != 0)
        {
            result += report[i];
            i += report[i]-1;
            // cerr << "skip to " << i << " and result is "<< result<< endl;
        }
        else if (isOpen(input[i]))
        {
            openParensStack.push(input[i]);
            // cerr << input[i] << " pushed to openParensStack: ";
            // printStack(openParensStack);
        }
        else if (isPairWithStackTop(openParensStack, input[i]))
        {
            openParensStack.pop();
            result+=2;
            // cerr << "pair found. result is "<< result << " and stack is ";
            // printStack(openParensStack);
        }
        else
        {
            // cerr << "need return. result "<< result << " and stack is ";
            // printStack(openParensStack);
            return result;
        }
    }
    // cerr << "end of input. result "<< result << " and stack is ";
    // printStack(openParensStack);
    return result;
}

int* getParenthesisReport(const char* input, int length)
{
    int* report = new int[length];
    report[length-1] = 0;
    for ( int i=length-2; i>=0; i--){
        report[i] = maxCorrectParentheses(report, input, i, length);
        // PrintArray(report, length);
    }
    return report;
}

int main()
{
    int length;
    cin >> length;
    char * input = new char[length];
    cin >> input;
    int* final_report = getParenthesisReport(input, length);
    for( int i=0; i<length; i++)
    {
        cout << final_report[i];
        if (i<length-1)
            cout << ' ';
    }

    return 0;
}
