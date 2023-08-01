#include <iostream>
#include <string>
class MessagePrint{
    public: 
        MessagePrint(){

        };
        ~MessagePrint(){

        }
        void PrintMessage(){
            std::cout << input_ << std::endl;
        }
    private:
        std::string input_ = "test";
};

template<typename PrintClass>
class TemplateClass{
public:
    TemplateClass(){

    };
    ~TemplateClass(){

    }
    bool Print(PrintClass print_instance){
        print_instance.PrintMessage();  // template이 정의되는 시점에는 해당 함수가 template instance에 존재하는지 알수 없다. 
        return true;
    }
private:

};

int main(){

    
    MessagePrint instance;
    TemplateClass<MessagePrint> template_classs;    // 실제 instance가 정의되었을 때 해당 template type에 필요한 함수가 정의되어 있는지 확인
    template_classs.Print(instance);

    return 0;
}