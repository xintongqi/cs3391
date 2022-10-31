//
//  main.cpp
//  week14_508_gene_matching
//
//  Created by Xintong Qi on 4/4/2022.
//

//#include <iostream>
//#include <string>
//
//using namespace std;
//
////int findPattern(string pattern, string text)
////{
////
////    int result=0;
////    if (pattern.size()==1){
////        const char* c=pattern.c_str();
////        for (int i=0; i<text.size(); i++) {
////            if (text[i]==*c) {
////                result++;
////            }
////        }
////        return result;
////    }
////
////
////    int text_len = text.length();
////    int pattern_len = pattern.length();
////
////    int lps[pattern_len];
////    lps[0] = 0;
////    int len = 0;
////    int index = 1;
////
////    while (index<pattern_len) {
////        if (pattern[index] == pattern[len]) {
////            len++;
////            lps[index] = len;
////            index++;
////        }else {
////            if (len != 0) {
////                len = lps[len - 1];
////            }else {
////                lps[index] = len;
////                index++;
////            }
////        }
////    }
////
////    int i=0, j=0;
////    int next_i = 0;
////
////    while (i < text_len)
////    {
////        if (pattern[j] == text[i])
////        {
////            j++;
////            i++;
////        }
////        if (j == pattern_len)
////        {
////            j = lps[j-1];
////            result++;
////        }else if (i < text_len && pattern[j] != text[i]){
////            if (j != 0)
////                j = lps[j - 1];
////            else
////                i = i + 1;
////        }
////    }
////    return result;
////}
//
//int kmp(string pat, string txt)
//{
//    int result=0;
//
//    int patlen = (int)pat.size();
//    int txtlen = (int)txt.size();
//
//    int lps[patlen];
//    lps[0] = 0;
//
//    int ctr = 1;
//    int len = 0;
//    while (ctr < patlen) {
//        if (pat[ctr] == pat[len]) {
//            len++;
//            lps[ctr] = len;
//            ctr++;
//        } else {
//            if (len != 0) {
//                len = lps[len - 1];
//            } else {
//                lps[ctr] = 0;
//                ctr++;
//            }
//        }
//    }
//
//    int i = 0;
//    int j = 0;
//    while (i < txtlen) {
//        if (pat[j] == txt[i]) {
//            j++;
//            i++;
//        }
//
//        if (j == patlen) {
//            result++;
//            j = lps[j - 1];
//        } else if (i < txtlen && pat[j] != txt[i]) {
//            if (j != 0)
//                j = lps[j - 1];
//            else
//                i = i + 1;
//        }
//    }
//
//    return result;
//}


#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

struct suffix {
    int index;
    char *suff;
};

int cmp(struct suffix a, struct suffix b) {
    return strcmp(a.suff, b.suff) < 0? 1 : 0;
}

int* buildSuffixArray(char *txt, int n) {
    struct suffix suffixes[n];

    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].suff = (txt+i);
    }

    sort(suffixes, suffixes+n, cmp);

    int *suffixArr = new int[n];
    for (int i = 0; i < n; i++)
        suffixArr[i] = suffixes[i].index;
    
    return  suffixArr;
}

void printArr(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void search(char *pat, char *txt, int *suffArr, int n)
{
    int m = strlen(pat);
    int l = 0, r = n-1;
    while (l <= r) {
        int mid = l + (r - l)/2;
        int res = strncmp(pat, txt+suffArr[mid], m);

        if (res == 0) {
//            cout << "Pattern found at index " << suffArr[mid];
            return;
        }
        
        if (res < 0)
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << "Pattern not found";
}

// Driver program to test above function
int main()
{
    char txt[] = "AAAAA";  // text
    char pat[] = "AA";   // pattern to be searched in text

    // Build suffix array
    int n = strlen(txt);
    int *suffArr = buildSuffixArray(txt, n);

    // search pat in txt using the built suffix array
    search(pat, txt, suffArr, n);

    return 0;
}


int main() {
    int test_cases;
    cin>>test_cases;
    for(int t=1;t<test_cases+1;t++){
        string str;
        cin>>str;
        int num_of_patterns;
        cin>>num_of_patterns;
        printf("Case #%d\n", t);
        while (num_of_patterns--) {
            string pattern;
            cin>>pattern;
            
        }
    }
    
    return 0;
}
