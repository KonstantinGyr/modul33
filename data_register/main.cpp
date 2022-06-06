#include <iostream>
#include <vector>
#include <exception>

template<typename T1,typename T2>

class Register{
    T1 key;
    T2 value;
public:
    Register():key(0),value(0)
    {
    }
    Register(T1 inKey,T2 inValue):key(inKey),value(inValue)
    {
    }
    void add(){
        x_Pair.first=key;
        x_Pair.second=value;
        vec.push_back(x_Pair);
    }
private:
    std::pair<T1,T2>x_Pair;
    std::vector<std::pair<T1,T2>> vec;
};

template<typename T>
T typeDetect(T var){
    bool str= false;
    bool doub = false;
    for(auto elem:var) {
        if (elem > 'A' && elem < 'z') {
        str = true;
        return"string";
    }
        else if(elem=='.'){
            doub==true;
        }
    }
    if(doub){
        return"double";
    }
    return "int";
}

void add(int count){
    if(count>19||count<0){
        throw std::invalid_argument("array full");
    }
    std::string key;
    std::string value;
    int keyInt;
    double keyDb;
    int valueInt;
    double valueDb;
    std::cout << "Enter key: ";
    std::cin >> key;
    std::cout << "Enter value: ";
    std::cin >> value;

    if (typeDetect(key) == "sting" && typeDetect(value) == "string") {
         Register<std::string, std::string>reg (key, value);
         reg.add();
    }
    else if(typeDetect(key)=="int"&& typeDetect(value)=="string"){
        keyInt= std::stoi(key);
         Register<int,std::string>reg (keyInt,value);
    }
    else if(typeDetect(key)=="double"&& typeDetect(value)=="string"){
        keyDb= std::stod(key);
        Register<double,std::string>reg (keyDb,value);
    }
    else if(typeDetect(key)=="int"&& typeDetect(value)=="int"){
        keyInt= std::stoi(key);
        valueInt=std::stoi(value);
         Register<int,int>reg (keyInt,valueInt);
    }
    else if(typeDetect(key)=="string"&& typeDetect(value)=="int"){
        valueInt= std::stoi(value);
         Register<std::string,int>reg (key,valueInt);
    }
    else if(typeDetect(key)=="string"&& typeDetect(value)=="double"){
        valueDb=std::stod(value);
         Register<std::string,double>reg (key,valueDb);
    }
    else if(typeDetect(key)=="double"&& typeDetect(value)=="double"){
        keyDb= std::stod(key);
        valueDb= std::stod(value);
         Register<double,double> reg(keyDb,valueDb);
    }
    else if(typeDetect(key)=="int"&& typeDetect(value)=="double"){
        keyInt= std::stoi(key);
        valueDb=std::stod(value);
         Register<int,double>reg (keyInt,valueDb);
    }
    else if(typeDetect(key)=="double"&& typeDetect(value)=="int"){
        keyDb= std::stod(key);
        valueInt=std::stoi(value);
         Register<double,int>reg (keyDb,valueInt);
    }
}

void remove (std::string key){

}

int main() {
    int count=-1;
    std::string com;
    std::string key;
    do{
        std::cout << "Enter command: ";
        std::cin>>com;
        if(com=="add") {
            ++count;
            try {
                add(count);
            }
            catch (const std::invalid_argument & x){
                std::cerr<<x.what();
            }
        }
        else if(com=="remove"){
            std::cout<<"Enter key for delete: ";
            std::cin>>key;
            remove(key);
        }
    }while(com!="ok");
    return 0;
}
