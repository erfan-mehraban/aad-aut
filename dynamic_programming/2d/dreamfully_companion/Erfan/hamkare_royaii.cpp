#include <iostream>
using namespace std;

// For Debugging
void printDBarray(int** a, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (a[i][j])
                cout << a[i][j]<< " ";
            else
                cout << "- ";
        }
        cout << endl;
    }
}


int getMaxPaperAmount(int* costs, int** maxPaperAmount, int paperIndex, int freeTime)
{
    // cout << "getMaxPaperAmount called by " << paperIndex << " " << freeTime << endl;
    // printDBarray(maxPaperAmount, , );

    if (paperIndex == 0){
        // if javad cant choose peek first paper
        if (freeTime<0)
            return 0;
        // if javad can
        return 1;
    }
    else if (maxPaperAmount[paperIndex][freeTime] != 0)
        // if array was filled before (top-down)
        return maxPaperAmount[paperIndex][freeTime];
    else
    {
        // calculate maximum paper amount when let erfan peek current paper:
        int erfan_peek = getMaxPaperAmount(costs, maxPaperAmount, paperIndex-1, costs[paperIndex]);
        // cout << "if erfan peeked then maximum was " << erfan_peek << endl;

        // calculate  maximum paper amount when javad peek current paper:
        // javad loose costs[paperIndex] minute if he peek paperIndex
        int javadFreeTime = freeTime - costs[paperIndex];
        int javadPaperIndex = paperIndex-1;
        // count down untill reach to papaer wich javad can choose
        while(javadPaperIndex>0 && javadFreeTime<0)
        {
            javadFreeTime += costs[javadPaperIndex];
            javadPaperIndex --;
        }
        int javad_peek = getMaxPaperAmount(costs, maxPaperAmount, javadPaperIndex, javadFreeTime);
        javad_peek++;
        // cout << "if javad peeked then maximum was " << erfan_peek << endl;

        // fill and return maximum amount of paper javad can have
        return maxPaperAmount[paperIndex][freeTime] = max(javad_peek, erfan_peek);
    }
}

int main(){
    /////////// initail
    int paper_amount;
    int max_time=0;

    cin >> paper_amount;
    int* costs = new int[paper_amount];
    for (int i=0; i<paper_amount; i++){
        cin >> costs[i];
        if (costs[i]>max_time)
            max_time = costs[i];
    }

    // maxPaperAmount[i][j] means if javad has choice to choose i'th paper and also he is j minute further than erfan
    int** maxPaperAmount = new int*[paper_amount];
    for (int i=0; i<paper_amount; i++)
        maxPaperAmount[i] = new int[max_time+1];
    ///////////

    cout << getMaxPaperAmount(costs, maxPaperAmount, paper_amount-1, 0);
    return 0;
}