#include <iostream>
#include <fstream>
#include<string>
using namespace std;

struct nyje{
	string celes;
	nyje* majte;
	nyje*djathte;
	
};

nyje *newNyje(string celes){
	nyje*tmp=new nyje;
	tmp->celes=celes;
	tmp->djathte=NULL;
	tmp->majte=NULL;
	return tmp;
}

bool exist (nyje*rrenje,string text){
	if(rrenje==NULL){
		return false;
	}
	if (rrenje ->celes==text){
		return true;
	}
	bool res1=exist (rrenje->djathte,text);
	bool res2 =exist(rrenje ->majte,text);
	
	return res1|| res2;
}
void pasRendore (nyje*rrenje){
	if (rrenje!=NULL){
		pasRendore(rrenje->majte);
		pasRendore(rrenje->djathte);
		cout<<rrenje->celes<<endl;
	}
}


void add(nyje*rrenje,string text){
	while(rrenje!=NULL){
		if (!rrenje->majte){
			rrenje->majte=newNyje(text);
			break;
		}
		if(!rrenje->djathte){
			rrenje->djathte=newNyje(text);
			break;
		}
		rrenje=rrenje->majte;
	}
}

int main(){
	ifstream in;
	string fjale;
	nyje*Pema=newNyje("");
	int count;
	
	
	in.open("skedari3.txt");
	if(in.is_open()){
		while (!in.eof()){
			in>>fjale;
			if(exist(Pema,fjale)==false){
				add(Pema,fjale);
				count++;
			}
		}
		pasRendore(Pema);
		cout<<count<<"fjale te ndryshme."<<endl;
		
	}
	else{
		cout<<"Error!!!";
	}
	in.close();
	return 0;
}












