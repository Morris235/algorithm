#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int arr[5] = {0,1,2,3,4};
    int* ptr = arr;

    // printf("%s\n", ptr == arr ? "true" : "false");
    // printf("%d\n", *ptr);

    printf("%d\n", *ptr);
    ptr++;
    printf("%d\n", *ptr);
    ptr++;
    printf("%d\n", *ptr);
    return 0;
}