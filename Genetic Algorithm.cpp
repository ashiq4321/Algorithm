#include <iostream>

using namespace std;
int values[4];
string String;
int decimal[5]={1,2,4,8,16};
string chromosoms[4]={"01101","11000","01000","10011"};//starting population
string newgeneration[4]=chromosoms;
double OSN[4];
int StringIntoValue(string p){
    int value=0;
    int k=0;
    for(int i=p.length()-1;0<=i;i--){
      if(p.at(i)=='1'){
       value=value+decimal[k];
       k++;
      }
      else{
        k++;
      }
    }
    return value;
}
 int AON(double a){
     int rounded=a;
 if((a-rounded)>=.5){
   return ++rounded;
 }
 return rounded;
 }

void GA(string s[4]){
    int ft=0;
for(int i=0;i<4;i++){
    String =s[i];
   values[i]= StringIntoValue(String);//value of variable
   values[i]=values[i]*values[i]; //fitness function
   ft=ft+values[i];
}
double favg=ft/4;
for(int i=0;i<4;i++){
    OSN[i]=values[i]/favg; //Offspring Number
   OSN[i]=AON(OSN[i]);//Actual Offspring Number
}
string temp,temp2;
for(int i=0;i<2;i++){//crossover
    int gene=rand()% 4;
    int partner;
    do{
     partner= rand()% 4;//cross over partner
    }
    while(gene==partner);
    int point;
    do{
        point=rand()% 5;//random cross over point
    }
    while(point==4);
        cout<<"1st: "<<gene<<" "<<"2nd: "<<partner<<" cross over point: "<<point<<endl;

    for(int i=0;i<=point;i++){
        temp=chromosoms[gene].at(i);
        temp2=chromosoms[partner].at(i);
        newgeneration[gene].replace(i,1,temp2);
        newgeneration[partner].replace(i,1,temp);
    }
}

}
int main()
{
GA(chromosoms);
cout<<"----New Generation---"<<endl;
for(int i=0;i<4;i++){
    cout<<newgeneration[i]<<endl;
}
    return 0;
}
