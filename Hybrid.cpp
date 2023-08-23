#include <iostream>
#include <string>

class university{
    protected:
    std::string u_name = "Lutputgiri University";
    public:
    university(){
        std::cout<<"The name of University is "<<u_name<<std::endl;
    }
};  
class a_college : public university{
    protected:
    std::string a_name = "Haggu College";
    public:
    std::string a_disp(){
        std::cout<<"The name of Affailated College is "<<a_name<<std::endl;      
    }
};
class c_college : public university{
    protected:
    std::string c_name = "Chakdhodho College";
    public:
    std::string c_disp(){
        std::cout<<"The name of Consituent College is "<<c_name<<std::endl;      
    }
};
class student : public a_college, public c_college{
    protected:
    std::string s_name = "Pinnacle Puttukumar";
    std::string s_program = "BE-CVIS";
    public:
    std::string s_disp(){
        std::cout<<"Student's name is : "<<s_name<<std::endl;
        std::cout<<"Student's program is :"<<s_program<<std::endl;
    }
};
int main(){
student s;
s.a_disp();
s.c_disp();
}