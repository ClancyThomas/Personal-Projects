#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>

using namespace std;

class Account {
        
        int amount;  //pennies
        
        public:
            Account() {
                amount = 0;
            }
            void deposit(int newAmount) { 
                amount += newAmount;
            }

            int transfer(int takeAmount) {
                if(amount>=takeAmount) {
                    amount -= takeAmount;
                    return takeAmount;
                }
                else {
                    return 0;
                }
            }
            int getBalance() {
                return amount;
            }
            void printBalance(ostream &out=cout) {
                out << amount << " pennies" << endl;
            }
};

class Accounts { 

    vector<Account> accounts;
    int maxAccounts = 0;

    protected:
        int randomAccount() {
            return rand()%maxAccounts;
        }
        int getBalance(int account) {
            return accounts[account].getBalance();
        }
        void doExchange() {
            int accountA = randomAccount();
            int accountB = randomAccount();
            int maxTransaction = 0;

            if(getBalance(accountA) > getBalance(accountB)) {
                maxTransaction = getBalance(accountB);
            }
            else {
                maxTransaction = getBalance(accountA);

            }
            
            int exchangeAmount = rand()%maxTransaction;

            if(rand()%100 > 50) {
                accounts[accountA].transfer(exchangeAmount);
                accounts[accountB].deposit(exchangeAmount);
            }
            else {
                accounts[accountA].transfer(exchangeAmount);
                accounts[accountB].deposit(exchangeAmount);
            }
        }
    public:
        void createModel(int numAccounts) {
        for(int i=0; i<numAccounts; i++) {
        Account temp;
        maxAccounts = numAccounts;
        temp.deposit(10000);
        accounts.push_back(temp);
        }
        }
        void modelSimulation(int numSimulations) {
            for (int i = 0; i < numSimulations; i++) {
                doExchange();
            }
        }
        void printInfo(ostream &out=cout) {
            for (int i = 0; i<maxAccounts; i++) {
                out << i << " ";
                accounts[i].printBalance();
            }
        }  
};

int main() {
    
    srand(time(NULL));
    int numAccounts = 0;
    int numSimulations = 0;
    Accounts modelEconomy;

    cout << "How many people will be participating in the economic experiment today?" <<endl;
    cin >> numAccounts;

    modelEconomy.createModel(numAccounts);

    cout << "How many simulated exchanges will the experiment perform today?" <<endl;
    cin >> numSimulations;

    cout << "Initial Model Values" <<endl;
    modelEconomy.printInfo();
    modelEconomy.modelSimulation(numSimulations);
    cout << "Post Simulation Model Values" <<endl;
    modelEconomy.printInfo();
   
    return 0;
}


