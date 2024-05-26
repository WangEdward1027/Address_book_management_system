//通讯录管理系统
#include <iostream>
#include <string>
using namespace std;
#define MAX 5  //通讯录人数上限

//联系人结构体
struct ContactPerson{
    string name;
    string sex;
    int age;
    string phoneNumber;
    string address;
};

//通讯录结构体:数组 + 容量
struct AddressBook{
    struct ContactPerson personArray[MAX];
    int size;
};

//显示菜单
void showMenu(){
    cout << "***********************" << endl;
    cout << "***** 1.添加联系人 *****" << endl;
    cout << "***** 2.显示联系人 *****" << endl;
    cout << "***** 3.删除联系人 *****" << endl;
    cout << "***** 4.查找联系人 *****" << endl;
    cout << "***** 5.修改联系人 *****" << endl;
    cout << "***** 6.清空联系人 *****" << endl;
    cout << "***** 7.退出通讯录 *****" << endl;
    cout << "***********************" << endl;
}

//1.添加联系人
void addPerson(AddressBook &abs){
    cout << "添加联系人,通讯录当前联系人个数:" << abs.size << endl;
    if(abs.size == MAX){
        cout << "通讯录已满,无法添加" << endl;
        return;
    }
    //姓名
    string name;
    cout << "请输入姓名" << endl;
    cin >> name;
    abs.personArray[abs.size].name = name;
    //性别
    string sex;
    cout << "请输入性别" << endl;
    while(true){
        cin >> sex;
        if(sex == "男" || sex == "女"){
            abs.personArray[abs.size].sex = sex;
            break;
        }
        cout << "输入有误,请重新输入性别,男 或 女" << endl;
    }
    //年龄
    int age;
    cout << "请输入年龄" << endl;
    cin >> age;
    abs.personArray[abs.size].age = age;
    //电话
    string phoneNumber;
    cout << "请输入电话" << endl;
    cin >> phoneNumber;
    abs.personArray[abs.size].phoneNumber= phoneNumber;
    //家庭住址
    string address;
    cout << "请输入家庭住址" << endl;
    cin >> address;
    abs.personArray[abs.size].address = address;
    //更新通讯录人数
    abs.size++;
    cout << "添加成功。" << endl;
    return;
}

//2.显示所有联系人
void showPerson(AddressBook &abs){
    if(abs.size == 0)  cout << "当前记录为空,没有联系人。" << endl;
    else{
        for(int i = 0; i < abs.size; ++i){
            cout << "姓名:" << abs.personArray[i].name << "    ";
            cout << "性别:" << abs.personArray[i].sex << "    ";
            cout << "年龄:" << abs.personArray[i].age << "    ";
            cout << "电话:" << abs.personArray[i].phoneNumber << "    ";
            cout << "住址:" << abs.personArray[i].address << endl;
        }
    }
}

//3.检测联系人是否存在:若存在,返回联系人在通讯录中的位置;若不存在,返回-1
int isExist(AddressBook abs,string name){
    for(int i = 0; i < abs.size; ++i){  //数组下标从0开始
        if(abs.personArray[i].name == name)  return i;
    }
    return -1;
}

//3.删除联系人
void deletePerson(AddressBook &abs){
    string name;
    cout << "请输入要删除的联系人姓名" <<endl;
    cin >> name;
    int ret = isExist(abs,name);
    if(ret != -1){
        for(int i = ret; i < abs.size; ++i){ //从要删除的位置ret开始,数组中每个数据都前移
            abs.personArray[i] = abs.personArray[i+1]; //数据前移,逻辑删除
        }
        abs.size--; //更新人员数
        cout << "删除成功。" << endl;
    }else{ //ret == -1
        cout << "查无此人。" << endl;
    }
}

//4.查找指定的联系人的信息
void findPerson(AddressBook abs){
    cout << "请输入您要查找的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs,name);
    if(ret != -1){
        cout << "姓名:" << abs.personArray[ret].name << "    ";
        cout << "性别:" << abs.personArray[ret].sex << "    ";
        cout << "年龄:" << abs.personArray[ret].age << "    ";
        cout << "电话:" << abs.personArray[ret].phoneNumber << "    ";
        cout << "住址:" << abs.personArray[ret].address << endl;
    }else{
        cout << "查无此人" << endl;
    }
}

//5.修改联系人
void modifyPerson(AddressBook &abs){
    cout << "请输入要修改的联系人姓名" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs,name);
    if(ret != -1){
        //姓名
        cout << "将姓名改为:" << endl;
        string name = "";
        cin >> name;
        abs.personArray[ret].name = name;
        //性别
        cout << "将性别改为:" << endl;
        string sex = "";
        while(true){
            cin >> sex;
            if(sex == "男" || sex == "女"){
                abs.personArray[ret].sex = sex;
                break;  //输入正确,退出循环
            }
            cout << "输入有误,请重新输入" << endl;
        }
        //年龄
        cout << "将年龄改为:" << endl;
        int age = 0;
        cin >> age;
        abs.personArray[ret].age = age;
        //联系电话
        cout << "将电话改为:" << endl;
        string phoneNumber = "";
        cin >> phoneNumber;
        abs.personArray[ret].phoneNumber = phoneNumber;
        //家庭住址
        cout << "将家庭住址改为:" << endl;
        string address = "";
        cin >> address;
        abs.personArray[ret].address = address;
        cout << "修改成功!" << endl;
    }else{
        cout << "查无此人" << endl;
    }
}

//6.清空联系人 (逻辑删除)
void clearPerson(AddressBook &abs){
    cout << "确认是否要清空所有联系人? 确认请输入 1" << endl;
    string str;
    cin >> str;
    if(str == "1"){
        abs.size = 0;
        cout << "联系人目录已清空。" << endl;
    }else{
        cout << "已放弃清空操作。" << endl;
    }
}

int main() {
    AddressBook abs; //创建一个通讯录对象
    abs.size = 0;

    while(true){
        cout << endl;
        showMenu(); //菜单调用

        cout << "请输入您选择的功能编号" << endl;
        int select = 0; //用户选择
        cin >> select;

        if (cin.fail()) { // 检查是否输入错误
            cin.clear(); // 清除cin的错误状态
            cin.ignore(); // 清除缓冲区直到下一个换行符
            // 输出错误信息并继续循环
            cout << "输入无效，请输入一个数字。" << endl;
            continue;
        }

        switch(select) {  //switch-case结构
            case 1:
                addPerson(abs);
                break;
            case 2:
                showPerson(abs);
                break;
            case 3:
                deletePerson(abs);
                break;
            case 4:
                findPerson(abs);
                break;
            case 5:
                modifyPerson(abs);
                break;
            case 6:
                clearPerson(abs);
                break;
            case 7:
                cout << "欢迎下次使用,再见。" << endl;
                return 0;
            default:
                cout << "功能数字不存在" << endl;
        }
    }
}
