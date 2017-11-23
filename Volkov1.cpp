#include <stdio.h>
#include <iostream>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include <locale.h>
#include <fstream>
#include <cstring>

#define max 100
using namespace std;

struct cpu{
	char brend[20];
	char model[20];
	int frequency;
	int price;
}buf;

int main(){
	char choice,name[20];
	int x;
start:
	do{
		system("cls");
		cout<<"Choose variant 1-4\n"
		<<"1. Get list\n"
		<<"2. New record\n"
		<<"3. Search\n"
		<<"4. Exit\n";

		switch(choice=getch()){
			case '1':{
				cout<<"Get list\n";
				ifstream fp("proc.dat",ios::binary);
				if (fp ==NULL){
                    printf("Error opening file. Please, create a file\n");
                    getch();
					break;
				}

                while(fp.read((char*)&buf,sizeof(cpu))){
                        cout<<buf.brend<<endl;
                        cout<<buf.model<<endl;
                        cout<<buf.frequency<<endl;
                        cout<<buf.price<<endl<<endl;
                        }
      			fp.close();
                getch();
				break;

            }

				// ifstream fp("proc.txt",ios::binary|ios::in); //Открываем файл в двоичном режиме только для чтения
 //   in.read((char*)&x,sizeof x); //Читаем оттуда информацию и запоминаем её в X
 //in.close(); //Закрываем файл



			case '2':{
				cout<<"New record\n";
				ofstream fp("proc.dat",ios::binary|ios::app);

                    cout<<"brend = "; cin>>buf.brend;
                    cout<<"model = "; cin>>buf.model;
                    cout<<"frequency = "; cin>>buf.frequency;
                    cout<<"price = "; cin>>buf.price;

                    fp.write((char*)&buf,sizeof(cpu));

                fp.close();
                getch();
                break;
            }
			case '3':{
                system("cls");
                cout<<"Search\n";
                cout<<"Choose variant 1-5\n"
                <<"1. brend\n"
                <<"2. model\n"
                <<"3. frequency\n"
                <<"4. price\n"
                <<"5. Exit\n";
                switch(choice=getch()){
                    case '1':{
                        cout<<"Enter a brend name = ";cin>>name;

                        ifstream fp("proc.dat",ios::binary);
                        if (fp ==NULL){
                            printf("Error opening file. Please, create a file\n");
                            getch();
                            break;
                        }

                        while(fp.read((char*)&buf,sizeof(cpu))){
                                if(strcmp(buf.brend,name)==0){
                                    cout<<buf.brend<<endl;
                                    cout<<buf.model<<endl;
                                    cout<<buf.frequency<<endl;
                                    cout<<buf.price<<endl<<endl;
                                }
                        }
                        fp.close();
                        getch();
                        goto start;
                    }
                    case '2':{
                        ifstream fp("proc.dat",ios::binary);
                        if (fp ==NULL){
                            printf("Error opening file. Please, create a file\n");
                            getch();
                            break;break;
                        }
                        cout<<"Enter a model name = ";cin>>name;

                        while(fp.read((char*)&buf,sizeof(cpu))){
                                if(strcmp(buf.model,name)==0){
                                    cout<<buf.brend<<endl;
                                    cout<<buf.model<<endl;
                                    cout<<buf.frequency<<endl;
                                    cout<<buf.price<<endl<<endl;
                                }
                        }
                        fp.close();
                        getch();
                        goto start;
                    }
                    case '3':{
                        ifstream fp("proc.dat",ios::binary);
                        if (fp ==NULL){
                            printf("Error opening file. Please, create a file\n");
                            getch();
                            break;break;
                        }
                        cout<<"Enter >/</=frequency";choice=getch();cin>>x;
                        switch(choice){
                            case '>':{
                                while(fp.read((char*)&buf,sizeof(cpu))){
                                    if(buf.frequency>x){
                                        cout<<buf.brend<<endl;
                                        cout<<buf.model<<endl;
                                        cout<<buf.frequency<<endl;
                                        cout<<buf.price<<endl<<endl;
                                    }
                                }
                            }
                            case '<':{
                                while(fp.read((char*)&buf,sizeof(cpu))){
                                    if(buf.frequency<x){
                                        cout<<buf.brend<<endl;
                                        cout<<buf.model<<endl;
                                        cout<<buf.frequency<<endl;
                                        cout<<buf.price<<endl<<endl;
                                    }
                                }
                            }
                            case '=':{
                                while(fp.read((char*)&buf,sizeof(cpu))){
                                    if(buf.frequency==x){
                                        cout<<buf.brend<<endl;
                                        cout<<buf.model<<endl;
                                        cout<<buf.frequency<<endl;
                                        cout<<buf.price<<endl<<endl;
                                    }
                                }
                            }
                        }
                        fp.close();
                        getch();
                        goto start;
                    }
                    case '4':{
                        ifstream fp("proc.dat",ios::binary);
                        if (fp ==NULL){
                            printf("Error opening file. Please, create a file\n");
                            getch();
                            break;
                        }
                        cout<<"Enter >/</=price ";choice=getch();cin>>x;
                        switch(choice){
                            case '>':{
                                while(fp.read((char*)&buf,sizeof(cpu))){
                                    if(buf.price>x){
                                        cout<<buf.brend<<endl;
                                        cout<<buf.model<<endl;
                                        cout<<buf.frequency<<endl;
                                        cout<<buf.price<<endl<<endl;
                                    }
                                }
                            }
                            case '<':{
                                while(fp.read((char*)&buf,sizeof(cpu))){
                                    if(buf.price<x){
                                        cout<<buf.brend<<endl;
                                        cout<<buf.model<<endl;
                                        cout<<buf.frequency<<endl;
                                        cout<<buf.price<<endl<<endl;
                                    }
                                }
                            }
                            case '=':{
                                while(fp.read((char*)&buf,sizeof(cpu))){
                                    if(buf.price==x){
                                        cout<<buf.brend<<endl;
                                        cout<<buf.model<<endl;
                                        cout<<buf.frequency<<endl;
                                        cout<<buf.price<<endl<<endl;
                                    }
                                }
                            }
                        }
                        fp.close();
                        getch();
                        goto start;
                    }
                    case '5':{
                        goto start;
                    }
                }
            }
			case '4':
				return 0;
		}
	}while(choice!='4');
return 0;
}
