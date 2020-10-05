#include <iostream>
#include <string>
using namespace std;
int main() {
	string Ori, Target;
	getline(cin, Ori);
	getline(cin, Target);
	int pos = Ori.find(Target);   //查找是否含有目标字符串
	while (pos != string::npos) {	//查询不到时结束循环
		Ori.erase(pos, Target.size());	//擦除目标字符串
		pos = Ori.find(Target);	  //继续查找是否含有目标字符串
	}
	cout << Ori << endl;
	return 0;
}
