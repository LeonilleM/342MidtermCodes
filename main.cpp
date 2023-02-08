#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

vector<int> tripleVectorElements(vector<int> &myVector);
void printVector(vector<int> myVector);
vector<int> sameElements(vector<int> &vec, vector<int> &vec2);
void doubleVec(vector<int> &vec);
vector<int> combineVec(vector<int> &vec1, vector<int> &vec2);
bool singleCharDiff(string a, string b);
char frequentChar(string s);

int main(){
    vector<int> myVector{2,5,6,1};
    tripleVectorElements(myVector);
    printVector(myVector);
    myVector.clear();

    //Question #7
    vector<int> vec2{2,5,6,10};
    vector<int> vec3{5,10,2,20};
    vector<int> vecCombined = sameElements(vec2,vec3);
    printVector(vecCombined);
    vec2.clear();
    vec3.clear();


    // Question #8
    vector<int> vec4{2,4,6};
    doubleVec(vec4);
    printVector(vec4);
    vec4.clear();

    // Question #9
    vector<int> nums1{2,5,6};
    vector<int> nums2{3,5,7,20};
    vector<int> ans = combineVec(nums1,nums2);
    printVector(ans);

    // Question #10
    cout << singleCharDiff("help", "yelp") << endl;


    // Question #14
    string s = "leetcode";
    cout << frequentChar(s) << endl;
}

// #6
vector<int> tripleVectorElements(vector<int> &myVector){
    vector<int> vec = myVector;
    for(int i =0; i < 3; i++){
        for(int j = 0; j < vec.size(); j++){
            myVector.push_back(myVector[j]);
        }
    }
    return vec;
}

// #7
vector<int> sameElements(vector<int> &vec, vector<int> &vec2){
    vector<int> myVec;
    for(int i = 0; i < vec.size(); i++){
        for(int j = 0; j < vec2.size(); j++){
            if(vec[i] == vec2[j]){
                myVec.push_back(vec[i]);
            }
        }
    }
    return myVec;
}

// #8
void doubleVec(vector<int> &vec){
    for(int i = 0; i < vec.size() ; i++){
        vec[i] *= 2;
    }
}

// #9 only combines two sorted vectors
vector<int> combineVec(vector<int> &vec1, vector<int> &vec2){
    vector<int> combined;
    int i = 0, j =0;
    while(i < vec1.size() && j < vec2.size()){
        if(vec1[i] < vec2[j]){
            combined.push_back(vec1[i]);
            i++;
        }else{
             combined.push_back(vec2[j]);
             j++;
        }
    }
    //filing the rest
    while(i < vec1.size()){
        combined.push_back(vec1[i]);
        i++;
    }
    while(j < vec2.size()){
        combined.push_back(vec2[j]);
        j++;
    }
    
    return combined;
}

// #10
bool singleCharDiff(string a, string b){
    int diffChar = 0;

    for(int i =0; i < a.length(); i++){
       if(a[i] != b[i]){
        diffChar++;
       }
    }
    return diffChar == 1;
}

// #11
int largestIndex(vector<int> vec){
    for(int i = vec.size() - 1; i >= 0; i--){
        if(vec[i] == i % 10){
            return i;
        }
    }

    return -1;
}

// #12
int binSearch(vector<int> &nums, int target) {
 int lo = 0;
 int hi = nums.size() - 1;
 while (lo <= hi) {
   int mid = lo + (hi - lo) / 2;
   if (nums[mid] == target) {
     return mid;
   }
   if (nums[mid] < target) {
     lo = mid + 1;
   } else {
     hi = mid - 1;
   }
 }
 return -1;
}

// #13
char nextGreatestChar(vector<char> &letters, char target){
    int lo = 0;
    int hi = letters.size() - 1;
    char ans = letters[lo];
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(letters[mid] <= target){
            lo = mid + 1;
        }else{
            ans = letters[mid];
            hi = mid -1;
        }
    }
    return ans;
}

// #14
char frequentChar(string s){
    unordered_map<char, int> myMap;
    for(int i =0 ; i < s.length();i++){
        myMap[s[i]]++;
    }
    char ans = myMap[0];
    for(int i =0; i< s.length();i++){
        for(int j = 0; j < s.length(); j++){
            if(myMap[s.at(i)] > myMap[s.at(j)] )
            char ans = myMap[s.at(i)];
            else
            char ans = myMap[s.at(j)];
        }
    }
    return ans;

}

void printVector(vector<int> myVector){
    for(int n: myVector){
        cout << n << " ";
    }
    cout << endl;
}