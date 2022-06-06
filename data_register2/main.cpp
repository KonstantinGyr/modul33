#include <iostream>
#include <vector>
#include <string>

template<typename T1,typename T2>

class Register{
    std::pair<T1,T2>x_Pair;
    std::vector<std::pair<T1,T2>> vec;
public:

    void add(T1 a,T2 b){
        x_Pair.first=a;
        x_Pair.second=b;
        vec.push_back(x_Pair);
    }
    void remove(T1 a){
        bool flag= false;
        for(int i=0;i<vec.size();i++){
            if(vec[i].first==a){
                flag= true;
                vec.erase(vec.begin()+i);
            }
        }
        if(!flag)throw std::invalid_argument("no such key exists");
    }
    void find(T1 a){
        bool flag= false;
        for(int i=0;i<vec.size();i++){
            if(vec[i].first==a){
                flag=true;
                std::cout<<"key: "<<a<<"value: "<<vec[i].second<<std::endl;
            }
        }
        if(!flag)throw std::invalid_argument("no such key exists");
    }
    void print(){
        for(int i=0;i<vec.size();i++){
            std::cout<<"key: "<<vec[i].first<<"value: "<<vec[i].second<<std::endl;
        }
    }
};

int main() {
    std::string com;
    std::string key;
    std::string value;
    Register<std::string,std::string>reg;
    do{
        std::cout << "Enter command: ";
        std::cin>>com;
        if(com=="add") {
            std::cout<<"Enter key and value: ";
            std::cin>>key>>value;
            reg.add(key,value);
        }
        else if(com=="remove"){
            std::cout<<"Enter key for delete: ";
            std::cin>>key;
            try {
                reg.remove(key);
            }
            catch (const std::invalid_argument &x){
                std::cout<<x.what()<<std::endl;
            }
        }
        else if(com=="find"){
            std::cout<<"Enter key for find: ";
            std::cin>>key;
            try {
                reg.find(key);
            }
            catch (const std::invalid_argument &x){
                std::cout<<x.what()<<std::endl;
            }
        }
        else if(com=="print"){
            reg.print();
        }
    }while(com!="ok");
    return 0;
}
