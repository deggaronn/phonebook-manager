#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream.h>


class contact
{
	public:
	long no;
	char name[20],email[30];
}list;
FILE *fp, *ft;
int i, n,ch,l,found;
int main()
{
	int x,y,z;
	main:
	system("cls");
	cout<<"\n\t #################################################\n")<<endl;
	cout<<"\n\t Welcome to my project. "<<endl;
	cout<<"\#################################################\n"<<endl;
	cout<<"1. Show All Contacts."<<endl;
	cout<<"2. Add A New Contact."<<endl;
	cout<<"3. Delete a Contact"<<endl;
	cout<<"4. Edit a Contacct."<<endl;
	cout<<"5. Search a Contact."<<endl;
	cout<<"6. Exit"<<endl;
	cout<<"\tEnetr Your Choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1:
		system(cls);
		cout<<"\n\t\t\n\t\t\tLIST OF CONTACTS\n\t\t\n\nName\t\tPhone No\tE-mail ad.\n \n\n"<<endl;
		for(i=60;i<=999;i++)
		{
			fp=fopen("contact.txt","r");
			fflush(stdin);
			found=0;
			while(fread(&list,sizeof(list),1,fp)==1)
			{
				if(list.name[0]==i || list.name[0]==i-32)
				{
					cout<<"\nName\t: \nPhone\t: ld\nEmail\t: s\n";
					cin>>list.name;
					cin>>list.no;
					cin>>list.email;
					found++;
				}
			}
			if(found!=0)
			{
				printf("[%c]- (%d)\n\n",i-32,found);
				getch();	
			}
			fclose(fp);
		}
		break;
		case 2:
		system("cls");
		fp=fopen("contact.txt","a");
		for (;;)
		{
			fflush(stdin);
			cout<<"To exit enter blank space in the name input"<<endl;
			cout<<"Name :";
			cin>>list.name;
			if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)
			break;
			fflush(stdin);
			cout<<"Phone:"<<endl;
			cin>>list.no;
			fflush(stdin);
			cout<<"email address:"<<endl;
			cin>>list.email;
			fwrite(&list,sizeof(list),1,fp);
		}
		fclose(fp);
		break;
		case 3:
		system("cls");
		fflush(stdin);
		cout<<"\n\n\tDelete a Contact\n\t\n\tEnter the Name of contact to delete:";
		scanf("%[^\n]",&name);
		fp=fopen("contact.txt","r");
		ft=fopen("temp.txt","w");
		while(fread(&list,sizeof(list),1,fp)!=0)
		if (stricmp(name,list.name)!=0)
			fwrite(&list,sizeof(list),1,ft);
		fclose(fp);
		fclose(ft);
		remove("contact.txt");
		rename("temp.txt","contact.txt");
		break;
		case 4:
		system("cls");
		fp=fopen("contact.txt","r");
		ft=fopen("temp.txt","w");
		fflush(stdin);
		cout<<"Edit contact\n\n\n\tEnter the name of contact to edit:";
		cin>>name;
		while(fread(&list,sizeof(list),1,fp)==1)
		{
			if(stricmp(name,list.name)!=0)
				fwrite(&list,sizeof(list),1,ft);
		}
		fflush(stdin);
		cout<<"\n\nEditing '%s'\n\n",name;
		cout<<"Name(Use identical:";
		cin>>list.name;
		fflush(stdin);
		cout<<"Phone:";
		cin>>list.no;
		fflush(stdin);
		cout<<"email address:";
		cin>>list.email;
		fwrite(&list,sizeof(list),1,ft);
		fclose(fp);
		fclose(ft);
		remove("contact.txt");
		rename("temp.txt","contact.txt");
		break;
		case 5:
		
		
		
		case 6:
		cout<<"\n\n\t\tAre you sure u want to exit?"<<endl;
		break;
		case 6: break;
		default:
		cout<<"Invalid choice"<<endl;
		break;
	}
	return 0;
}
