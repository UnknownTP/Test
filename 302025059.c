#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define Inf 1e9
#define ll long long int
#define ull unsigned long long int

int compare_asc(const void *a, const void *b);
int compare_desc(const void *a, const void *b);
void sort(ll arr[], ll n);
void rsort(ll arr[], ll n);
ll find(ll arr[], ll length, ll key);
ll lower_bound(ll arr[], ll length, ll key);
ll upper_bound(ll arr[], ll length, ll key);

int main(void){
    srand((unsigned int)time(NULL));
    
    return 0;
}

int compare_asc(const void *a, const void * b){
    if (*(ll*)a < *(ll*)b) return -1;
    else if (*(ll*)a > *(ll*)b) return 1;
    return 0;
}
int compare_desc(const void *a, const void * b){
    if (*(ll*)a < *(ll*)b) return 1;
    else if (*(ll*)a > *(ll*)b) return -1;
    return 0;
}

void sort(ll arr[], ll n){
    qsort(arr, n, sizeof(ll), compare_asc);
}
void rsort(ll arr[], ll n){
    qsort(arr, n, sizeof(ll), compare_desc);
}

ll find(ll arr[], ll length, ll key){
    for(ll i=0;i<length;i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

ll lower_bound(ll arr[], ll length, ll key){

    ll left, right, mid;
    left = 0, right = length;

    while(left < right){

        mid = left + ((right - left) / 2);

        if(arr[mid] < key){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    return left;
}
ll upper_bound(ll arr[], ll length, ll key){

    ll left, right, mid;
    left = 0, right = length;

    while(left < right){

        mid = left + ((right - left) / 2);

        if(arr[mid] > key){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return left;
}