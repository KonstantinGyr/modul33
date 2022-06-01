#include <iostream>
#include <ctime>
#include <exception>

class LuckyFishing:public std::exception{
public:
    const char* what()const noexcept override{
        return "You caught a fish!";
    }
};

class BootFish:public std::exception{
public:
    const char* what()const noexcept override{
      return  " Unsuccessful fishing! Your prey is boot";
    }
};

struct Plot{
    std::string who;
    Plot(){
        who="empty";
    }
    Plot(std::string _who){
        who=_who;
    }
};
void fishing(int num,Plot lake[9]){
    if(num>9||num<1){
        throw std::invalid_argument("incorrect plot number ");
    }
    if (lake[num].who =="fish"){
        throw LuckyFishing();

    }
    else if(lake[num].who=="boot"){
        throw BootFish();
    }
    else{
        std::cout<<"this plot is empty"<<std::endl;
    }
}

int main() {
    Plot lake [9];
    int plotLake;
    for(int i=0;i<9;i++){
        lake[i]=Plot();
    }
    std::srand(std::time(nullptr));
    lake[std::rand() % 9] =  Plot("fish");
    for(int i=0;i<3;i++){
        int num=std::rand() % 9;
        while (lake[num].who!="empty"){
            num++;
        }
        lake[num]= Plot("boot");
    }
    bool flag= true;
    int count=0;
    while (flag) {
        count++;
        std::cout << "Enter number of plot from 1 to 9 : ";
        std::cin >> plotLake;
        try{
            fishing(plotLake,lake);
        }
        catch (const std::invalid_argument &x){
            std::cerr<<x.what()<<std::endl;
            count--;
        }
        catch (const BootFish &y){
            std::cerr<<y.what()<<std::endl;
            flag= false;
        }
        catch (const LuckyFishing &l){
            std::cout<<l.what()<<"\n You have "<<count<<" shots";
            flag= false;
        }
    }
    return 0;
}
