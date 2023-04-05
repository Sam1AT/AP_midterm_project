#include <iostream>
#include "Genome.h"
#include <string>
#include <algorithm>
using namespace std;

void Genome::getDNA(string a,string b){
    DNA1=a;
    DNA2=b;
}

void Genome::getRNA(string c){
    RNA=c;
}
void Genome::makeDNA(){
    string DNA="";
    for(int i=0;i<RNA.length();i++){
        if (RNA[i]=='A'){
            DNA+='T';
        }
        else if (RNA[i]=='T'){
            DNA+='A';
        }
        else if (RNA[i]=='G'){
            DNA+='C';
        }
        else if (RNA[i]=='C'){
            DNA+="G";
        }
    }
    cout<<RNA<<endl;
    cout<<DNA<<endl;
}

void Genome::jahesh_M_RNA(string S1) {
    string S2="";
    for(int i=0;i<S1.length();i++){
        if (S1[i]=='A'){
            S2+='T';
        }
        else if (S1[i]=='T'){
            S2+='A';
        }
        else if (S1[i]=='G'){
            S2+='C';
        }
        else if (S1[i]=='C'){
            S2+="G";
        }
    }
    size_t pos=RNA.find(S1);
    while(pos !=string::npos){
        RNA.replace(pos,S1.length(),S2);
        pos=RNA.find(S1,pos +1);}
    cout<<RNA<<endl;
}

void Genome::jahesh_M_DNA(string S1) {
    string S2="";
    for(int i=0;i<S1.length();i++){
        if (S1[i]=='A'){
            S2+='T';
        }
        else if (S1[i]=='T'){
            S2+='A';
        }
        else if (S1[i]=='G'){
            S2+='C';
        }
        else if (S1[i]=='C'){
            S2+="G";
        }
    }
    size_t pos1,pos2;
    pos1=DNA1.find(S1);
    pos2=DNA2.find(S1);
    if(pos1<pos2){
        DNA1.replace(pos1,S1.length(),S2);
        DNA2.replace(pos1,S2.length(),S1);
    }
    if(pos2<pos1){
        DNA2.replace(pos2,S1.length(),S2);
        DNA1.replace(pos2,S2.length(),S1);
    }
    cout<<DNA1<<endl;
    cout<<DNA2<<endl;
}
void Genome ::jahesh_K_RNA(string S1,string S2, int n) {
    size_t pos=RNA.find(S1);
    for(int i=0;i<n;i++) {
        RNA.replace(pos, 1, S2);
        pos = RNA.find(S1, pos + 1);
        }
    cout<<RNA<<endl;
    }

void Genome ::jahesh_K_DNA(string S1,string S2, int n) {
    string S3;
    if (S2=="A"){
        S3="T";
    }
    else if (S2=="T"){
            S3="A";
    }
    else if (S2=="G"){
            S3="C";
    }
    else if (S2=="C"){
            S3="G";
    }
    string S4;
    if (S1=="A"){
        S4="T";
    }
    else if (S1=="T"){
        S4="A";
    }
    else if (S1=="G"){
        S4="C";
    }
    else if (S1=="C"){
        S4="G";
    }
 int counter=0;
 while(counter<n){
     for(int i=0;i<DNA1.length();i++){
         if(DNA1[i]==S1[0]){
             counter+=1;
             DNA1.replace(i,1,S2);
             if(counter==n){
                 break;}
             }
             if(DNA2[i]==S1[0]){
                 counter+=1;
                 DNA2.replace(i,1,S2);}
                 if(counter==n){
                     break;
                 }
                 else{
                     continue;
                 }
             }
         }
 int counter2=0;
    while(counter2<n){
        for(int j=0;j<DNA1.length();j++){
            if(DNA1[j]==S4[0]){
                counter2+=1;
                DNA1.replace(j,1,S3);
                if(counter2==n){
                    break;}
            }
            if(DNA2[j]==S4[0]){
                counter2+=1;
                DNA2.replace(j,1,S3);}
            if(counter2==n){
                break;
            }
            else{
                continue;
            }
        }
    }
cout<<DNA1<<endl;
cout<<DNA2<<endl;
    }


void Genome::jahesh_B_RNA(string S1, string S2) {
size_t pos=RNA.find(S1);
RNA.replace(pos,S2.length(),S2);
cout<<RNA<<endl;
}

void Genome::jahesh_B_DNA(string S1, string S2) {
    string S3="";
    for(int i=0;i<S2.length();i++){
        if (S2[i]=='A'){
            S3+='T';
        }
        else if (S2[i]=='T'){
            S3+='A';
        }
        else if (S2[i]=='G'){
            S3+='C';
        }
        else if (S2[i]=='C'){
            S3+="G";
        }
    }

size_t pos1,pos2;
pos1=DNA1.find(S1);
pos2=DNA2.find(S1);
if(pos1<pos2){
    DNA1.replace(pos1,S2.length(),S2);
    DNA2.replace(pos1,S3.length(),S3);
}
if(pos2<pos1){
    DNA1.replace(pos2,S3.length(),S3);
    DNA2.replace(pos2,S2.length(),S2);
}
cout<<DNA1<<endl;
cout<<DNA2<<endl;
}








