#include <iostream>
#include <vector>

using namespace std;

bool isSorted(const vector<int>& sequence, int start, int end){
    // cout << start << " " << end;
    for (int i=start; i<end-1; i++)
        if (sequence[i] > sequence[i+1])
            return false;
    return true;
}

void printPreProccedSolution(vector<vector<int>> solution){
    int solution_size = solution.size();
    for (int i=0; i<solution_size; i++){
        for (int j=0; j<=solution_size; j++)
            cout << solution[i][j] << " ";
        cout << endl;
    }
}

vector<vector<int>> preProccessedRunTimes(const vector<int>& sequence){
    
    // initial
    int sequence_size = sequence.size();
    vector<vector<int>> solution( sequence_size, vector<int>(sequence_size+1));

    //fill
    for (int i=sequence_size-1; i>=0; i--){
        for (int j=i; j <= sequence_size; j++){
            if (isSorted(sequence, i,j)){
                // cout << " sorted" << endl;
                solution[i][j] = 1;
            }
            else {
                int mid = (i + j) / 2;
                solution[i][j] = solution[i][mid] + solution[mid][j] + 1;
                // cout  << " " << solution[i][j]<< endl;
            }
        }
    }

    // printPreProccedSolution(solution);
    return solution;

}

int main(){

    // vector<int> sampleSequence{6, 18, 27, 33, 2, 13, 12, 14, 22, 21};
    // preProccessedRunTimes(sampleSequence);
    int input_size, question_count;
    cin >> input_size >> question_count;

    vector<int> input(input_size);
    for (int i=0; i<input_size; i++)
        cin >> input[i];
    vector<vector<int>> solution = preProccessedRunTimes(input);

    for (int i=0; i<question_count; i++){
        int x,y;
        cin >> x >> y;
        cout << solution[--x][--y]<<endl;
    }


}