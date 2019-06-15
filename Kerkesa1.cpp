#include <iostream>
#include <string>
#include <fstream>

using namespace std;
 struct list
 {
 	 string celes;
 	 list*pas;
 };
  list * newList(string celes){
  	list*a = new list;
  	
  	a->celes= celes;
  	a->pas=NULL;
  	
  }
   void afisho(list*l){
   	while(l!=NULL){
   		cout<<l->celes<<endl;
   		l=l->pas;
   		
	   }
	   cout<<endl;
	   
   }
   
   
   
   
   void shto(list*l,string t){
   	list*tmp=newList(t);
   	
   	
   	if (l==NULL){
   		l->celes=t;
   		l->pas=NULL;
	   }else{
	   	while(l->pas!=NULL){
	   		l=l->pas;
		   }
		   l->pas=tmp;
	   }
   }
   
   
   
   bool kerko (list*koka,string g){
   	list*tmp=koka;
   	while(tmp!=NULL){
   		if(tmp->celes==g){
   			
   			return true;
   				
		   }
		   tmp=tmp->pas;
	   }
	   return false;
   }
   
   
   
   
  int main(){
  	ifstream in ;
  	 list *l=newList(" ");
  	 int count=0;
  	 string fjale;
  	 in.open("skedari2.txt");
  	 if(in.is_open()){
  	 	while(!in.eof()){
  	 		in>>fjale;
  	 		if(kerko(l,fjale)==false){
  	 			count++;
  	 			shto(l,fjale);
  	 			
			   }
		   }
		   
		   afisho(l);
		   cout<<count<<"fjale te ndryshme."<<endl;
		   in.close();
	   }
	  else{
	  	cout<<"Error!!!"<<endl;
	  } 
	  in.close();
	  return 0;
  } 
   
   
   
   
   
   
   
   
   
   
