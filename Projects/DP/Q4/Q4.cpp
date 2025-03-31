#include <iostream>
using namespace std;
int DelDigit(long value,int k);
int main(void)
{
	long value;
	int k;

	cout << "Please enter an integer(3001527):" << endl;
	cin >> value;//输入待删除的整数：3001527
	cout << "Please enter the number of digits to be deleted(3):" << endl;
	cin >> k;//输入删除的位数：3
	value = DelDigit(value, k);//----------------调用DelDigit函数从value删除k位得到最小数
	cout << "After deletion, The smallest integer is: " << value << endl;//输出删除后得到的最小数

	system("pause");
	return 0;
}

int DelDigit(long value,int k){
    string num = to_string(value); // 将输入数字转换为字符串形式
    string result; // 用于存储最终结果的字符串
    
    // 遍历num中的每个字符
    for (int i = 0; i < num.size(); ++i) {
        // 当k>0且result不为空且当前字符小于result的最后一个字符时，删除result最后一个字符
        while (k > 0 && !result.empty() && result.back() > num[i]) {
            result.pop_back();
            --k;
        }
        result.push_back(num[i]); // 将当前字符加入到result中
    }

    // 如果还剩有未删除的位数，继续从末尾删除
    while (k > 0 && !result.empty()) {
        result.pop_back();
        --k;
    }

    // 找到第一个非零字符的位置，避免前导零，如果全是0，则返回"0"
    size_t startpos = result.find_first_not_of('0');
    if(startpos == string::npos) return 0; // 若全为0，返回0

    // 转换回整型可能会导致溢出问题，特别是对于非常大的数字。这里直接返回长整型值。
    return stol(result.substr(startpos));
}