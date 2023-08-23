#include <iostream>
#include <stdlib.h>
using namespace std;
class candidate_b;
class candidate_c;
class candidate_a{
    protected:
    string a_name = "HagguKumar Rawat";
    int a_count = 0;
};
class candidate_b{
    protected:
    string b_name = "Kamal Prasad Tolagani";
    int b_count = 0;
};
class candidate_c{
    protected:
    string c_name = "Joe Biden";
    const int c_count = 0;
};
class voter : public candidate_a, public candidate_b, public candidate_c{
    protected: 
    string v_name;
    int v_age;
    string v_address;
    string v_elligible[2] = {"Kausaltar" , "kausaltar"}; 
    public:
    void getVoterInfo(){
        cout<<"Enter your name : ";
        cin>> v_name;
        cout<<endl;
        cout<<"Enter your age : ";
        cin>> v_age;
        cout<<endl;
        cout<<"Enter your address : ";
        cin>> v_address;
        cout<<endl;
    }
    void checkAge(){
        if(v_age < 18){
            cout<<endl;
            cout<<"Unelligible voter. Try again after you're 18.\n";
            exit(1);
        }
        else{
            cout<<endl;
            cout<<"Voter elligible. Starting the voting process.\n";
        }
    }
    int vote_a(){
        return a_count = a_count+1;
    }
    int vote_b(){
        return b_count = b_count+1;
    }
    int vote_c(){
        return c_count;
    }
    int showVotes(){
    cout<<"\nThe vote count is the following for Each candidate :"<<endl;
    cout<<a_name<<" has "<<a_count<<" votes. \n";
    cout<<b_name<<" has "<<b_count<<" votes. \n";
    cout<<c_name<<" has "<<c_count<<" votes. \n";
    }
};
int exit_or_not(){
    char exitx;
    cout<<"\nPress X to exit and Y to redo the process : ";
    cin>>exitx;
    if (exitx == 'x' || exitx == 'X'){
        exit(1);
    }
    else{
        cout<<"Invalid option\nBack to Voting process.\n\n";
    }
    }
int main(){
    int x;
    voter v;
    v.getVoterInfo();
    v.checkAge();
    while (1){    
    cout<<"Press 1 to vote for HagguKumar Rawat \nPress 2 to vote for Kamal Prasad Tolagani\nPress 3 to vote for Joe Biden\n";
    cin>>x;
    switch (x)
    {
    case 1:
        v.vote_a();
        break;
    case 2:
        v.vote_b();
        break;
    case 3:
        v.vote_c();
        break;
    default:
        cout<<"\nInvalid Option. Retry";
        break;
    }
    v.showVotes();
    exit_or_not();
    }
}

