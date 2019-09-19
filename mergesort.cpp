#include <iostream>
#include <vector>
using namespace std;

// function declarations

void mergeSortedLists(vector<int> &a, vector<int> &tmp, int left, int middle, int right) {
    int t = 0;
    int i = left;
    int j = middle + 1;
    //comparing un-merged vector- sorting
    while (i <= middle && j <= right) {
        if (a[i] < a[j]) {
            tmp[t] = a[i];
            i++;
            t++;
        } else {
            tmp[t] = a[j];
            j++;
            t++;
        }

    }
    //copy remaining elements of the left list
    while (i <= middle) {

        tmp[t] = a[i];
        t++;
        i++;
    }

    //copy remaining elements of the right list
    while (j <= right) {

        tmp[t] = a[j];
        t++;
        j++;
    }

    for (int k = left; k <= right; k++) {
        a[k] = tmp[k];
    }
}

void mergeSort(vector<int> &a, vector<int> &tmp, int left, int right) {

    if (left < right) {

        int middle = (right + left) / 2;

        mergeSort(a, tmp, left, middle);//left recursion
        mergeSort(a, tmp, middle + 1, right);//right recursion
        mergeSortedLists(a, tmp, left, middle, right);//merging of 2 sorted

    } else {
        return;
    }
}
int main() {

    // get input: first is random seed, second is vector length
    int seed, length;
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);  // vector to be sorted
    vector<int> t(length);  // temporary workspace

    // unit test for merge
    /* your code here */
    vector<int> test = {2, 1, 5, 3};
    vector<int> test2(5);
    mergeSortedLists(test, test2, 0, 1, 3);
    cout << "Unit Test for Merge Function:" << endl;
    for (int i = 0; i < test.size(); i++) {
        cout << test.at(i) << '\t';
    }
    cout << endl;
    cout << endl;


    // initialize and print input
    cout << "Original vector:" << endl;
    for(int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // sort v
    /* your code here */
    mergeSort(v, t, 0, length - 1);


    // print output
    cout << "Sorted vector:" << endl;
    for(int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // check output, make sure it's sorted
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }

    return 0;
}

/* your code here */
