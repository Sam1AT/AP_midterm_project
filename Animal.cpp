#include <iostream>
#include <string>
#include <vector>
#include "Animal.h"
#include <time.h>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <chrono>
#include <thread>

using namespace std;

int Animal::getEditDistance(string first, string second)
{
    int m = first.length();
    int n = second.length();
 
    int T[m + 1][n + 1];
    for(int i=0; i < m+1;i++)
    {
        for(int j=0; j < n+1; j++)
        {
            T[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        T[i][0] = i;
    }
 
    for (int j = 1; j <= n; j++) {
        T[0][j] = j;
    }
 
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int weight = first[i - 1] == second[j - 1] ? 0: 1;
            T[i][j] = min(min(T[i-1][j] + 1, T[i][j-1] + 1), T[i-1][j-1] + weight);
        }
    }
 
    return T[m][n];
}



float Animal::findStringSimilarity(string first, string second) {
    float max_length = max(first.length(), second.length());
    if (max_length > 0) {
        return (max_length - getEditDistance(first, second)) / max_length;
    }
    return 1.0;
}

float Animal::simularity(Animal s)
{
    cout << "Im here" << endl;
    int m = this->c.CHR.size();
    int n = s.c.CHR.size();
    vector<float> awnsers;

    for(int i=0; i < m;i++)
    {
            cout << "Im here ! ! !" << endl;

        float sum_per = 0;

        for(int j=0 ; j < n;j++)
        {
                cout << "Im here 2" << endl;

            sum_per = max(sum_per , max(findStringSimilarity(this->c.CHR[i].DNA2 , s.c.CHR[j].DNA2) , max(findStringSimilarity(this->c.CHR[i].DNA1 , s.c.CHR[j].DNA2) , max(findStringSimilarity(this->c.CHR[i].DNA2 , s.c.CHR[j].DNA1) , findStringSimilarity(this->c.CHR[i].DNA1 , s.c.CHR[j].DNA1)))));
            
        }
        cout << "per sm is : " << sum_per << endl;
        awnsers.push_back(sum_per);
    }
float sumMax = 0;
for (int i = 0; i < awnsers.size(); i++)
    sumMax += awnsers[i];


return (sumMax / max(m,n) * 1.0 ) * 100;
}

bool Animal::operator ==(Animal obj)
{
return (this->simularity(obj) > 70)? 1 : 0;
}

Animal Animal::asexual_reproduction()
{
   unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
            cout <<"man injam !" << endl;
    
    cout <<"man injam ! !" << endl;

while(1)
{
    cout <<"man injam ! ! ! ! " << endl;
    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));
    Animal tmp;
    vector<Genome> doubleCromozom = this->c.CHR;
    for(int i=0; i < this->c.CHR.size() ; i++)
    {
        doubleCromozom.push_back(this->c.CHR[i]);
    }
    

    shuffle(doubleCromozom.begin(), doubleCromozom.end(), e);

    for(int i=0;i < this->c.CHR.size();i++)
        tmp.c.CHR.push_back(doubleCromozom[i]);

    cout << this->simularity(tmp) << endl;
    if(this->simularity(tmp) > 70)
    {
        return tmp;
    }
}
 
}



Animal Animal::operator +(Animal obj) 
{
    Animal obj1 = this->asexual_reproduction();
    Animal obj2 = obj.asexual_reproduction();
    
for(int i=0 ;i < 200000000;i++)
{
    Animal child;
    vector<Genome> obj1_cp = obj1.c.CHR;
    vector<Genome> obj2_cp = obj2.c.CHR;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);

    shuffle(obj1_cp.begin(), obj1_cp.end(), e);
    shuffle(obj2_cp.begin(), obj2_cp.end(), e);

    for(int i=0; i < obj1.c.CHR.size()/2;i++)
    {
        cout << "man injam baraye bar : " << i +1 << endl;
        child.c.CHR.push_back(obj1.c.CHR[i]);
        child.c.CHR.push_back(obj2.c.CHR[i]);
    }


    if(child.simularity(obj1) > 70 && child.simularity(obj2) > 70)
    {
        cout << "injaye" <<child.c.CHR.size() <<endl;
        return child;
        
    }
}
Animal child;

return child;
}

  
void Animal::death()
{
    this->c.death();
    cout << "Done !";   
}



bool Virus::canInfect(Animal a)
{
    vector<string> substrings;
    substrings = a.c.getInterAll();

    struct compare {
    inline bool operator()(const std::string& first,
            const std::string& second) const
    {
        return first.size() < second.size();
    }
};

    
compare c;
sort(substrings.begin(), substrings.end(), c);


cout << "The chromosome inc common substrings are : ";
    for(int i=0; i < substrings.size() ; i++)
        cout << substrings[i] << " ";
    cout << endl;
vector<string> biggestSS;
int len = substrings[substrings.size() - 1].length();
int looplen = len;
for(int i=substrings.size() - 1 ; looplen == len;i--)
{
    biggestSS.push_back(substrings[i]);
    looplen = substrings[i - 1].length();
}
cout << "The biggest substrings are : ";
for(int i=0; i < biggestSS.size() ; i++)
    cout << biggestSS[i] << " ";
cout << endl;

vector<string> ans;
ans = eshterak(this->r.findSubstrings() , biggestSS);
cout << "The in common substrings are : ";
for(int i=0; i < ans.size() ; i++)
    cout << ans[i] << " ";
cout << endl;
return (ans.size() != 0)?  1 :  0;

}