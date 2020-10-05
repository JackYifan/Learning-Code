#include<bits/stdc++.h>
using namespace std;
class Person{
public:
    string name;
    int age;
public:
Person(string _name,int _age){
    name=_name;
    age=_age;
}
};
void print(Person* person){
    cout<<person->name<<" "<<person->age<<endl;
}
int main()
{
    vector<Person*> v;

	//创建数据
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
    for(vector<Person*>::iterator it=v.begin();
    it!=v.end();it++){
        cout<<(*it)->name<<(*it)->age<<endl;
    }
    for_each(v.begin(),v.end(),print);
    

}