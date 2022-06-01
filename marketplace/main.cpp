#include <iostream>
#include <exception>
#include <map>

template<typename T1,typename T2,typename T3>

void remove(T1 item,T2 num, T3 &market, T3 &basket){
    std::pair<T1,T2>xPair(item,num);
    if(basket.empty()){
        throw std::exception();
    }
    if(!basket.count(item)){
        throw std::invalid_argument("no item in basket");
    }
    else{
        if(basket.at(item)<num){
            throw std::invalid_argument("quantity less in basket");
        }
        else{
            basket.at(item)-=num;
            if(market.count(item)){
                market.at(item)+=num;
            }
            else{
                market.insert(xPair);
            }
            if (basket.at(item)==0) {
                basket.erase(item);
            }
        }
    }
}

template<typename T1,typename T2>

void add(T1 item,T2 num, std::map<T1, T2> &market, std::map<T1, T2> &basket){
    std::pair<T1,T2>xPair(item,num);
    if(market.empty()){
        throw std::exception();
    }
    if(!market.count(item)){
       throw std::invalid_argument("no item in market");
    }
    else{
        if(market.at(item)<num){
           throw std::invalid_argument("quantity less in market");
        }
        else{
            market.at(item)-=num;
            if(basket.count(item)){
                basket.at(item)+=num;
            }
            else{
                basket.insert(xPair);
            }
            if(market.at(item)==0){
                market.erase(item);
            }
        }
    }
}
void basketPrint(const std::map<std::string,int>&basket){
    if (basket.empty()) {
        std::cout << "basket empty"<<std::endl;
    }
    else {
        for (const auto& it: basket) {
            std::cout << "In basket: " << it.first << " " << it.second << " pieces" << std::endl;
        }
    }
}

int main() {
    std::map<std::string,int>market={{"soap",3},{"milk",5},{"beer",4},{"sugar",5}};
    std::map<std::string,int>basket;
    std::string oper;
    std::string item;
    int quant;
    while (oper!="ok") {
        std::cout << "Add or remove : ";
        std::cin >> oper;
        if(oper=="ok"){
            basketPrint(basket);
            break;
        }
        if (oper == "add") {
            std::cout<<"Input item and quantity: ";
            std::cin>> item >> quant;
            try {
                add(item, quant, market, basket);
            }
            catch (const std::invalid_argument &x) {
                std::cerr << x.what() << std::endl;
            }
            catch (const std::exception &y){
                std::cerr<<y.what()<<" market empty "<<std::endl;
            }
        }
        else if (oper == "remove") {
            std::cout<<"Input item and quantity: ";
            std::cin>> item >> quant;
            try {
                remove(item, quant, market, basket);
            }
            catch (const std::invalid_argument &x) {
                std::cerr << x.what() << std::endl;
            }
            catch (const std::exception &y){
                std::cerr<<y.what()<<" basket empty "<<std::endl;
            }
        }
        else{
            std::cerr<<"incorrect operator!"<<std::endl;
        }
        basketPrint(basket);
    }
    return 0;
}




