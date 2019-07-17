#include "sort.h"
#include<time.h>
#include<cstdlib>
#include<cstring>
Sort::Sort()
{

}

Sort::Sort(int size)
{
    generateRandomArray(size,0,size);
}

Sort::Sort(int size, int minValue, int maxValue)
{
    generateRandomArray(size,minValue,maxValue);
}


void Sort::swap(vector<int> &arr, int i, int j)
{
    int temp =arr[i];
    arr[i] = arr[j] ;
    arr[j] = temp   ;
    //    arr[i] = arr[i] ^ arr[j];
    //    arr[j] = arr[i] ^ arr[j];
    //    arr[i] = arr[i] ^ arr[j];
}

void Sort::stdSort(const vector<int> &arr)
{
    arr2 =arr;
    std::sort(arr2.begin(),arr2.end());
}
void Sort::stdswap(vector<int> &arr, int i, int j)
{
    std::swap(arr[i],arr[j]);
}

void Sort::printf(const vector<int> &arr)
{
    cout<<__FUNCTION__<<endl;
    for(auto i:arr){
        cout<< i<<" ";
    }
    cout<<endl;
    cout<<endl;
}

void Sort::generateRandomArray(int size, int minValue, int maxValue)
{
    arr.resize(size);
    srand(time(0));
    for(int i=0;i<size ;i++){
        arr[i] =   (rand())% (maxValue -minValue +1) +minValue;
    }
}

bool Sort::check_result(vector<int> &arr, vector<int> &arr2)
{
    if(arr.size() !=arr2.size()){
        return false;
    }else{
        for(int i=0;i<arr.size();i++){
            if(arr[i] != arr2[i]){
                return false;
            }
        }
        return true;
    }
}

vector<int> Sort::getArr() const
{
    return arr;
}

void Sort::setArr(const vector<int> &value)
{
    arr = value;
}

// ð������

void Sort::BubbleSort(vector<int> &arr)
{
    cout<<__FUNCTION__<<endl;
    if(arr.size() <2){
        return ;
    }
    bool hasSorted = false; //����
    //   1  ?�Ƚ����ڵ�Ԫ�ء������һ���ȵڶ����󣬾ͽ�������������
    //   2  ?��ÿһ������Ԫ����ͬ���Ĺ������ӿ�ʼ��һ�Ե���β�����һ�ԣ�
    //      ����������Ԫ��Ӧ�û�����������
    //   3  ?������е�Ԫ���ظ����ϵĲ��裬�������һ����
    //   4  ?�ظ�����1~3��ֱ��������ɡ�
    //    ԭʼ
    //    38 50 53 83 36 30 21 97
    //    BubbleSort
    //                         97       1
    //                      83 97       2
    //                   53 83 97       3
    //                50 53 83 97       4
    //          36 38 50 53 83 97       5
    //    21 30 36 38 50 53 83 97       6 OK
    for (int end = arr.size() - 1; end > 0 && (!hasSorted); end--) {
        hasSorted =true;
        for (int i = 0; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr, i, i + 1);
                hasSorted = false;
            }
        }
        //        if(hasSorted)
        //            return;
    }
}
// ��������

void Sort::insertionSort(vector<int> &arr)
{
    //    cout<<__FUNCTION__<<endl;
    if(arr.size() <2){
        return ;
    }
    //    i�ǵڼ��ζԱȵ����ݣ�i-1��֮ǰ���������
    //    .....    5   3   4   8   9
    //    .....   i-1  i��������������������-������ i�����������
    //    .....   i-1  i
    //    .....    j   j=[i-1]��
    //    26 3 79 99 86 77 0 10
    //
    //    3 26
    //    3 26 79
    //    3 26 79 99
    //    3 26 79 86 99
    //    3 26 77 79 86 99
    //    0 3 26 77 79 86 99
    //    0 3 10 26 77 79 86 99
    //     ?�ӵ�һ��Ԫ�ؿ�ʼ����Ԫ�ؿ�����Ϊ�Ѿ�������
    //     ?ȡ����һ��Ԫ�أ����Ѿ������Ԫ�������дӺ���ǰɨ�裻
    //     ?�����Ԫ�أ������򣩴�����Ԫ�أ�����Ԫ���Ƶ���һλ�ã�
    //     ?�ظ�����3��ֱ���ҵ��������Ԫ��С�ڻ��ߵ�����Ԫ�ص�λ�ã�
    //     ?����Ԫ�ز��뵽��λ�ú�
    //     ?�ظ�����2~5��


#if 1
    for (int i = 1; i < arr.size(); i++) {
#if 0
        int j = i - 1;
        for (; j >= 0 && arr[j] > arr[j + 1]; j--) {
            swap(arr, j, j + 1);
        }
#else
        //        �Ż��汾 ERR
        int temp = arr[i];
        int newPos = i-1;
        /* i ֮ǰ��Ԫ�ض�������ģ��ҵ���tempС�Ĳ��뵽�����棬
         * ��temp��ģ���Ҫ����Ųһ��λ��*/
        for (; newPos >= 0 && arr[newPos] > temp; newPos--) {
            arr[newPos+1] = arr[newPos];
        }
        arr[newPos+1] = temp;

        for(auto i:arr){
            cout<<i<<" ";
        }
        cout<<endl;
#endif
    }
#endif

}

// ѡ������

void Sort::selectionSort(vector<int> &arr)
{
    cout<<__FUNCTION__<<endl;
    if(arr.size() <2){
        return ;
    }


    //    ?��ʼ״̬��������ΪR[1..n]��������Ϊ�գ�
    //    ?��i������(i=1,2,3��n-1)��ʼʱ����ǰ���������������ֱ�ΪR[1..i-1]��R(i..n����
    //     ��������ӵ�ǰ��������-ѡ���ؼ�����С�ļ�¼ R[k]���������������ĵ�1����¼R������
    //     ʹR[1..i]��R[i+1..n)�ֱ��Ϊ��¼��������1�������������ͼ�¼��������1��������������
    //     ?n-1�˽��������������ˡ�

    //    printf
    //    2 32 42 45 29 72 52 74
    //    selectionSort
    //    2   32 42 45 29 72 52 74
    //    2 29   42 45 32 72 52 74
    //    2 29 32   45 42 72 52 74
    //    2 29 32 42   45 72 52 74
    //    2 29 32 42 45   72 52 74
    //    2 29 32 42 45 52   72 74
    //    2 29 32 42 45 52 72   74
    //    result :1
    for (int i = 0; i < arr.size() - 1; i++) {
        int minIndex = i; //�ӵ�A[i=0]�����ݿ�ʼ�������������ֵ����minIndexλ��
        //        ÿ��ѡ��һ�������� [i+1]...>��������Сֵ
        for (int j = i + 1; j < arr.size(); j++) {
            minIndex = arr[j] < arr[minIndex] ? j : minIndex;
        }
        swap(arr, i, minIndex);
    }
}


// ������

void Sort::heapSort(vector<int> &arr)
{
    //    ?����ʼ������ؼ�������(R1,R2��.Rn)�����ɴ󶥶ѣ��˶�Ϊ��ʼ����������
    //     ?���Ѷ�Ԫ��R[1]�����һ��Ԫ��R[n]������
    //      ��ʱ�õ��µ�������(R1,R2,����Rn-1)���µ�������(Rn),
    //      ������R[1,2��n-1]<=R[n]��
    //     ?���ڽ������µĶѶ�R[1]����Υ���ѵ����ʣ�
    //      �����Ҫ�Ե�ǰ������(R1,R2,����Rn-1)����Ϊ�¶ѣ�
    //      Ȼ���ٴν�R[1]�����������һ��Ԫ�ؽ�����
    //      �õ��µ�������(R1,R2��.Rn-2)���µ�������(Rn-1,Rn)��
    //     �����ظ��˹���ֱ����������Ԫ�ظ���Ϊn-1�����������������ɡ�

    cout<<__FUNCTION__<<endl;
    if(arr.size() <2){
        return ;
    }
    for (int i = 0; i < arr.size() ; i++) {
        heapInsert(arr, i); //����������� β�� arr[0]�Ǵ󶥶ѡ�
    }
    int size = arr.size() ;
    swap(arr, 0, --size); //�󶥶ѣ�����һ�εĴ�Ѷ�������arr[size-1];
    //�Դ󶥶ѣ�arr[0]  <---->  arr[size-1]���жѵ���;
    while (size > 0) {
        heapify(arr, 0, size);
        swap(arr, 0, --size);
    }
}

void Sort::heapInsert(vector<int> &arr, int index)
{
    //    �ڵ�ֵ>���ڵ㣬����

    while (arr[index] > arr[(index - 1) / 2]) {
        swap(arr, index, (index - 1) / 2);
        index = (index - 1) / 2; //�ڵ�ĸ���
    }
}
void Sort::heapify(vector<int> &arr, int index, int size)
{

    int left = index * 2 + 1;

    while (left < size) {
        int largest = left + 1 < size && arr[left + 1] > arr[left] ? left + 1 : left;
        largest = arr[largest] > arr[index] ? largest : index;
        if (largest == index) {
            break;
        }
        swap(arr, largest, index);
        index = largest;
        left = index * 2 + 1;
    }
}
// ������

void Sort::quickSort(vector<int> &arr)
{
    if (arr.size() < 2) {
        return;
    }
    quickSort(arr, 0, arr.size() - 1);
}

void Sort::quickSort(vector<int> &arr, int l, int r)
{

    //     ?������������һ��Ԫ�أ���Ϊ ����׼����pivot����
    //     ?�����������У�����Ԫ�رȻ�׼ֵС�İڷ��ڻ�׼ǰ�棬
    //     ����Ԫ�رȻ�׼ֵ��İ��ڻ�׼�ĺ��棨��ͬ�������Ե���һ�ߣ���
    //     ����������˳�֮�󣬸û�׼�ʹ������е��м�λ�á�
    //     �����Ϊ������partition��������
    //     ?�ݹ�أ�recursive����С�ڻ�׼ֵԪ�ص������кʹ��ڻ�׼ֵԪ�ص�����������

    if (l < r) {
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p, r);
    }
}

int Sort::partition(vector<int> &arr, int l, int r)
{
    int less = l - 1;
    int more = r;
    while (l < more) {
        if (arr[l] < arr[r]) {
            swap(arr, ++less, l++);
        } else if (arr[l] > arr[r]) {
            swap(arr, --more, l);
        } else {
            l++;
        }
    }
    swap(arr, more, r);
    return l;
}
// �鲢����

void Sort::mergeSort(vector<int> &arr, int l, int r)
{
    if (l == r) {
        return;
    }
    int mid = l + ((r - l) >> 1);
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

void Sort::mergeSort(vector<int> &arr)
{
    if (arr.size() < 2) {
        return;
    }
    mergeSort(arr, 0, arr.size() - 1);
}

void Sort::merge(vector<int> &arr, int l, int m, int r)
{

    //    ��������������кϲ����õ���ȫ��������У�
    //    ����ʹÿ��������������ʹ�����жμ�����
    //    �������������ϲ���һ���������Ϊ2-·�鲢��

    //     ?�ѳ���Ϊn���������зֳ���������Ϊn/2�������У�
    //     ?�������������зֱ���ù鲢����
    //     ?����������õ������кϲ���һ�����յ��������С�


    vector<int> help(r - l + 1 , 0);
    int i = 0;
    int p1 = l;
    int p2 = m + 1;
    while (p1 <= m && p2 <= r) {
        help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
    }
    while (p1 <= m) {
        help[i++] = arr[p1++];
    }
    while (p2 <= r) {
        help[i++] = arr[p2++];
    }
    for (i = 0; i < help.size(); i++) {
        arr[l + i] = help[i];
    }
}





// ��������

void Sort::countingSort(vector<int> &arr)
{
    cout<<__FUNCTION__<<endl;

    //    ?�ҳ��������������������С��Ԫ�أ�
    //     ?ͳ��������ÿ��ֵΪi��Ԫ�س��ֵĴ�������������C�ĵ�i�
    //     ?�����еļ����ۼӣ���C�еĵ�һ��Ԫ�ؿ�ʼ��ÿһ���ǰһ����ӣ���
    //     ?�������Ŀ�����飺��ÿ��Ԫ��i����������ĵ�C(i)�
    //    ÿ��һ��Ԫ�ؾͽ�C(i)��ȥ1��
    // only for 0~200 value
    if ( arr.size() < 2) {
        return;
    }
    int max = INT32_MIN;
    for (int i = 0; i < arr.size() ; i++) {
        max = std::max(max, arr[i]);
    }
    vector<int> bucket(max + 1 , 0);
    for (int i = 0; i < arr.size(); i++) {
        bucket[arr[i]]++;
    }
    int i = 0;
    for (int j = 0; j < bucket.size(); j++) {
        while (bucket[j]-- > 0) {
            arr[i++] = j;
        }
    }
}

// Ͱ����

void Sort::bucketSort(vector<int> &arr)
{
    cout<<__FUNCTION__<<endl;

    //    ?����һ�����������鵱����Ͱ��
    //     ?�����������ݣ����Ұ�����һ��һ���ŵ���Ӧ��Ͱ��ȥ��
    //     ?��ÿ�����ǿյ�Ͱ��������
    //     ?�Ӳ��ǿյ�Ͱ����ź��������ƴ��������

    // only for 0~200 value
    if ( arr.size() < 2) {
        return;
    }
    int max = INT32_MIN;
    for (int i = 0; i < arr.size() ; i++) {
        max = std::max(max, arr[i]);
    }

    vector<int> bucket(max + 1 , 0);
    for (int i = 0; i < arr.size(); i++) {
        bucket[arr[i]]++;
    }
    int i = 0;
    for (int j = 0; j < bucket.size(); j++) {
        while (bucket[j]-- > 0) {
            arr[i++] = j;
        }
    }
}
int Sort::maxbits(vector<int> &arr)
{
    int max = INT32_MIN;
    for (int i = 0; i < arr.size(); i++) {
        max = std::max(max, arr[i]);
    }
    int res = 0;
    while (max != 0) {
        res++;
        max /= 10;
    }
    return res;
}
// ��������

void Sort::radixSort(vector<int> &arr, int begin, int end, int digit)
{
    volatile int radix = 10;
    int i = 0, j = 0;
    //    int[] count = new int[radix];
    //    int[] bucket = new int[end - begin + 1];

    //    ?ȡ�������е����������ȡ��λ����
    //     ?arrΪԭʼ���飬�����λ��ʼȡÿ��λ���radix���飻
    //     ?��radix���м����������ü�������������С��Χ�����ص㣩��


    vector<int> count(radix);
    vector<int> bucket(end - begin + 1);

    for (int d = 1; d <= digit; d++) {
        for (i = 0; i < radix; i++) {
            count[i] = 0;
        }
        for (i = begin; i <= end; i++) {
            j = getDigit(arr[i], d);
            count[j]++;
        }
        for (i = 1; i < radix; i++) {
            count[i] = count[i] + count[i - 1];
        }
        for (i = end; i >= begin; i--) {
            j = getDigit(arr[i], d);
            bucket[count[j] - 1] = arr[i];
            count[j]--;
        }
        for (i = begin, j = 0; i <= end; i++, j++) {
            arr[i] = bucket[j];
        }
    }
}

int Sort::getDigit(int x, int d)
{
    return ((x / ((int) std::pow(10, d - 1))) % 10);
}


// only for no-negative value
//��������
void Sort::radixSort(vector<int> &arr)
{
    if ( arr.size() < 2) {
        return;
    }
    radixSort(arr, 0, arr.size()  - 1, maxbits(arr));
}
// shell����
void Sort::shellSort(vector<int> &arr)
{
    //    ?ѡ��һ����������t1��t2������tk������ti>tj��tk=1��
    //    ?���������и���k�������н���k ������
    //    ?ÿ�����򣬸��ݶ�Ӧ������ti�����������зָ�����ɳ���Ϊm �������У�
    //    �ֱ�Ը��ӱ����ֱ�Ӳ������򡣽���������Ϊ1 ʱ��
    //    ����������Ϊһ�������������ȼ�Ϊ�������еĳ��ȡ�

    int gap = arr.size()/2; //����Ĭ��
    while(gap > 0){
        int beg = gap -1;   //��ʼ�Ƚϵ�λ�ã�һ���ǰһ�����ݿ�ʼ��ǰ
        while(beg >= 0 ){
            shellInsert(arr,beg,gap);
            beg--;
        }
        gap = gap / 2;
    }
}

void Sort::shellInsert(vector<int> &arr,int beg, int gap)
{
    for (int i = beg+gap; i < arr.size(); i+=gap) {
#if 0
        int j = i - gap;
        for (; j >= 0 && arr[j] > arr[j + gap]; j-=gap) {
            swap(arr, j, j + gap);
        }
#else
        //        �Ż��汾 ERR
        int temp = arr[i];
        int newPos = i-gap;
        for (; newPos >= 0 && arr[newPos] > temp; newPos-=gap) {
            arr[newPos+gap] = arr[newPos];
        }
        arr[newPos+gap] = temp;
#endif
    }
}

