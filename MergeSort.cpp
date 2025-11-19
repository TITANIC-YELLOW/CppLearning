#include <iostream>
#include <vector>
using namespace std;

// 合并两个有序区间 [l, mid] 和 [mid+1, r]
void merge(vector<int>& a, int l, int mid, int r) {
    int i = l, j = mid + 1;
    vector<int> temp;

    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) temp.push_back(a[i++]);
        else temp.push_back(a[j++]);
    }

    // 把剩余元素加入
    while (i <= mid) temp.push_back(a[i++]);
    while (j <= r) temp.push_back(a[j++]);

    // 拷贝回原数组
    for (int k = 0; k < temp.size(); ++k) {
        a[l + k] = temp[k];
    }
}

// 归并排序
void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;   // 一个元素不需要排序

    int mid = l + (r - l) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    merge(a, l, mid, r);
}

int main() {
    vector<int> a = {5, 2, 3, 1, 7, 6, 4};

    mergeSort(a, 0, a.size() - 1);

    for (int x : a) cout << x << " ";
    return 0;
}
