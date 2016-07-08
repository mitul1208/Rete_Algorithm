// RETE_DEMO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include "string.h"

struct stPassenger
{
	char pTickitNo[50];
	char pMobNo[50];
	char pDob[50];
	char pName[50];
	char pAdd[50];
	char pEmailID[50];
};
struct stCompare
{	
	bool MobNo;
	bool Dob;
	bool Name;
	bool Add;
	bool EmailID;
	bool AndOR;
};

void findRule(stPassenger st[100],int icount,stCompare stCompare_)
{		
	int iAlreadyFoundIndex[100];
	int iAlreadyFoundcount = 0;

	if(stCompare_.Add)
	{	
		for(int i = 0; i < icount-1; i++)
		{
			bool bmatchfound = false;
			bool bcontinue = false;
			for(int k=0; k < iAlreadyFoundcount; k++)
			{
				if( iAlreadyFoundIndex[k] == i)
					bcontinue = true;
			}
			if( bcontinue )
				continue;

			for(int j = i+1; j < icount; j++)
			{				
				if(strcmp(st[i].pAdd , st[j].pAdd) == 0)
				{
					iAlreadyFoundIndex[iAlreadyFoundcount] = j;
					iAlreadyFoundcount++;

					if(stCompare_.AndOR == false)/// or operation
					{
						if( !bmatchfound )
						{							
							printf("\nTicketNo : %s -- Address : '%s'\nTicketNo : %s -- Address : '%s'",
								&st[i].pTickitNo,st[i].pAdd,
								&st[j].pTickitNo,st[j].pAdd);
							bmatchfound = true;
						}
						else
						{							
							printf("\nTicketNo : %s -- Address : '%s'",								   
								&st[j].pTickitNo,st[j].pAdd);
						}
						continue;
					}
					else if(stCompare_.Dob && (strcmp(st[i].pDob , st[j].pDob)==0))
					{
						if( !bmatchfound )
						{							
							printf("\nTicketNo : %s -- Address : '%s'  YYYY : %s\nTicketNo : %s -- Address : '%s'  YYYY : %s",
								&st[i].pTickitNo,st[i].pAdd,&st[i].pDob,
								&st[j].pTickitNo,st[j].pAdd,&st[j].pDob);
							bmatchfound = true;
						}
						else
						{							
							printf("\nTicketNo : %s -- Address : '%s'  YYYY : %s",						   
								&st[j].pTickitNo,st[j].pAdd,&st[j].pDob);
						}
						continue;
					}
					else if(stCompare_.EmailID && ( strcmp(st[i].pEmailID,st[j].pEmailID) == 0 ))
					{
						if( !bmatchfound )
						{							
							printf("\nTicketNo : %s -- Address : '%s'  EmailId : '%s'\nTicketNo : %s -- Address : '%s'  EmailId : '%s'",
								&st[i].pTickitNo,st[i].pAdd,st[i].pEmailID,
								&st[j].pTickitNo,st[j].pAdd,st[j].pEmailID);
							bmatchfound = true;
						}
						else
						{							
							printf("\nTicketNo : %s -- Address : '%s'  EmailId : '%s'",						   						   
								&st[j].pTickitNo,st[j].pAdd,st[j].pEmailID);
						}
						continue;
					}
					else if(stCompare_.MobNo && (strcmp(st[i].pMobNo , st[j].pMobNo)==0))
					{
						if( !bmatchfound )
						{							
							printf("\nTicketNo : %s -- Address : '%s'  MobNo : %s\nTicketNo : %s -- Address : '%s'  MobNo : %s",
								&st[i].pTickitNo,st[i].pAdd,&st[i].pMobNo,
								&st[j].pTickitNo,st[j].pAdd,&st[j].pMobNo);
							bmatchfound = true;
						}
						else
						{							
							printf("\nTicketNo : %s -- Address : '%s'  MobNo : %s",							   
								&st[j].pTickitNo,st[j].pAdd,&st[j].pMobNo);
						}

						continue;
					}
					else if(stCompare_.Name && ( strcmp(st[i].pName,st[j].pName) == 0 ))
					{
						if( !bmatchfound )
						{							
							printf("\nTicketNo : %s -- Address : '%s'  Name : '%s'\nTicketNo : %s -- Address : '%s'  Name : '%s'",
								&st[i].pTickitNo,st[i].pAdd,st[i].pName,
								&st[j].pTickitNo,st[j].pAdd,st[j].pName);
							bmatchfound = true;
						}
						else
						{							
							printf("\nTicketNo : %s -- Address : '%s'  Name : '%s'",							   
								&st[j].pTickitNo,st[j].pAdd,st[j].pName);
						}
						continue;
					}						
				}	
			}
		}
	}
	else if(stCompare_.Dob)
	{	
		for(int i = 0; i < icount-1; i++)
		{
			bool bmatchfound = false;
			bool bcontinue = false;
			for(int k=0; k < iAlreadyFoundcount; k++)
			{
				if( iAlreadyFoundIndex[k] == i)
					bcontinue = true;
			}
			if( bcontinue )
				continue;

			for(int j = i+1; j < icount; j++)
			{
				if(strcmp(st[i].pDob , st[j].pDob)==0)
				{
					iAlreadyFoundIndex[iAlreadyFoundcount] = j;
					iAlreadyFoundcount++;

					if(stCompare_.AndOR == false)/// or operation
					{
						if( !bmatchfound )
						{
							printf("\nTicketNo : %s -- YYYY : %s\nTicketNo : %s -- YYYY : %s",
								&st[i].pTickitNo,&st[i].pDob,
								&st[j].pTickitNo,&st[j].pDob);
							bmatchfound = true;
						}
						else
						{
							printf("\nTicketNo : %s -- YYYY : %s",							   
								&st[j].pTickitNo,&st[j].pDob);
						}
						continue;
					}					
					else if(stCompare_.EmailID && ( strcmp(st[i].pEmailID,st[j].pEmailID) == 0 ))
					{
						if( !bmatchfound )
						{
							printf("\nTicketNo : %s -- YYYY : %s  EmailId : '%s'\nTicketNo : %s -- YYYY : %s  EmailId : '%s'",
								&st[i].pTickitNo,&st[i].pDob,st[i].pEmailID,
								&st[j].pTickitNo,&st[j].pDob,st[j].pEmailID);
							bmatchfound = true;
						}
						else
						{
							printf("\nTicketNo : %s -- YYYY : %s  EmailId : '%s'",							   
								&st[j].pTickitNo,&st[j].pDob,st[j].pEmailID);
						}
						continue;
					}
					else if(stCompare_.MobNo && (strcmp(st[i].pMobNo , st[j].pMobNo)==0))
					{
						if( !bmatchfound )
						{
							printf("\nTicketNo : %s -- YYYY : %s  MobNo : %s\nTicketNo : %s -- YYYY : %s  MobNo : %s",
								&st[i].pTickitNo,&st[i].pDob,&st[i].pMobNo,
								&st[j].pTickitNo,&st[j].pDob,&st[j].pMobNo);
							bmatchfound = true;
						}
						else
						{
							printf("\nTicketNo : %s -- YYYY : %s  MobNo : %s",							   
								&st[j].pTickitNo,&st[j].pDob,&st[j].pMobNo);
						}
						continue;
					}
					else if(stCompare_.Name && ( strcmp(st[i].pName,st[j].pName) == 0 ))
					{
						if( !bmatchfound )
						{
							printf("\nTicketNo : %s -- YYYY : %s  Name : '%s'\nTicketNo : %s -- YYYY : %s  Name : '%s'",
								&st[i].pTickitNo,&st[i].pDob,st[i].pName,
								&st[j].pTickitNo,&st[j].pDob,st[j].pName);
							bmatchfound = true;
							continue;
						}
						else
						{
							printf("\nTicketNo : %s -- YYYY : %s  Name : '%s'",							   
								&st[j].pTickitNo,&st[j].pDob,st[j].pName);
							continue;
						}
					}						
				}	
			}
		}
	}
	else if(stCompare_.EmailID)
	{	
		for(int i = 0; i < icount-1; i++)
		{
			bool bmatchfound = false;
			bool bcontinue = false;
			for(int k=0; k < iAlreadyFoundcount; k++)
			{
				if( iAlreadyFoundIndex[k] == i)
					bcontinue = true;
			}
			if( bcontinue )
				continue;

			for(int j = i+1; j < icount; j++)
			{				
				if(strcmp(st[i].pEmailID , st[j].pEmailID) == 0)
				{		
					iAlreadyFoundIndex[iAlreadyFoundcount] = j;
					iAlreadyFoundcount++;
					if(stCompare_.AndOR == false)/// or operation
					{
						if( !bmatchfound )
						{
							printf("\nTicketNo : %s -- EmailId : '%s'\nTicketNo : %s -- EmailId : '%s'",
								&st[i].pTickitNo,st[i].pEmailID,
								&st[j].pTickitNo,st[j].pEmailID);
							bmatchfound = true;
						}
						else
						{
							printf("\nTicketNo : %s -- EmailId : '%s'",							
								&st[j].pTickitNo,st[j].pEmailID);
							continue;
						}						
					}					
					else if(stCompare_.MobNo && (strcmp(st[i].pMobNo , st[j].pMobNo)==0))
					{
						if( !bmatchfound )
						{
							printf("\nTicketNo : %s -- EmailId : '%s'  MobNo : %s\nTicketNo : %s -- EmailId : '%s'  MobNo : %s",
								&st[i].pTickitNo,st[i].pEmailID,&st[i].pMobNo,
								&st[j].pTickitNo,st[j].pEmailID,&st[j].pMobNo);
							bmatchfound = true;						
						}
						else
						{
							printf("\nTicketNo : %s -- EmailId : '%s'  MobNo : %s",							   
								&st[j].pTickitNo,st[j].pEmailID,&st[j].pMobNo);						
						}		
						continue;
					}
					else if(stCompare_.Name && ( strcmp(st[i].pName,st[j].pName) == 0 ))
					{
						if( !bmatchfound )
						{
							printf("\nTicketNo : %s -- EmailId : '%s'  Name : '%s'\nTicketNo : %s -- EmailId : '%s'  Name : '%s'",
								&st[i].pTickitNo,st[i].pEmailID,st[i].pName,
								&st[j].pTickitNo,st[j].pEmailID,st[j].pName);
							bmatchfound = true;						
						}
						else
						{
							printf("\nTicketNo : %s -- EmailId : '%s'  Name : '%s'",							   
								&st[j].pTickitNo,st[j].pEmailID,st[j].pName);						
						}
						continue;

					}						
				}	
			}
		}
	}
	else if(stCompare_.MobNo)
	{	
		for(int i = 0; i < icount-1; i++)
		{
			bool bmatchfound = false;
			bool bcontinue = false;
			for(int k=0; k < iAlreadyFoundcount; k++)
			{
				if( iAlreadyFoundIndex[k] == i)
					bcontinue = true;
			}
			if( bcontinue )
				continue;

			for(int j = i+1; j < icount; j++)
			{
				if(st[i].pMobNo == st[j].pMobNo)
				{
					iAlreadyFoundIndex[iAlreadyFoundcount] = j;
					iAlreadyFoundcount++;
					if(stCompare_.AndOR == false)/// or operation
					{
						if( !bmatchfound )
						{
							printf("\nTicketNo : %s -- MobNo : %s\nTicketNo : %s -- MobNo : %s",
								&st[i].pTickitNo,&st[i].pMobNo,
								&st[j].pTickitNo,&st[j].pMobNo);
							bmatchfound = true;					
						}
						else
						{
							printf("\nTicketNo : %s -- MobNo : %s",							   
								&st[j].pTickitNo,&st[j].pMobNo);						
						}					
						continue;
					}					
					else if(stCompare_.Name && ( strcmp(st[i].pName,st[j].pName) == 0 ))
					{
						if( !bmatchfound )
						{
							printf("\nTicketNo : %s -- MobNo : %s  Name : '%s'\nTicketNo : %s -- MobNo : %s  Name : '%s'",
								&st[i].pTickitNo,&st[i].pMobNo,st[i].pName,
								&st[j].pTickitNo,&st[j].pMobNo,st[j].pName);
							bmatchfound = true;							
						}
						else
						{
							printf("\nTicketNo : %s -- MobNo : %s  Name : '%s'",							   
								&st[j].pTickitNo,&st[j].pMobNo,st[j].pName);						
						}					
						continue;
					}						
				}	
			}
		}
	}
	else if(stCompare_.Name)
	{	
		for(int i = 0; i < icount-1; i++)
		{
			bool bmatchfound = false;
			bool bcontinue = false;
			for(int k=0; k < iAlreadyFoundcount; k++)
			{
				if( iAlreadyFoundIndex[k] == i)
					bcontinue = true;
			}
			if( bcontinue )
				continue;

			for(int j = i+1; j < icount; j++)
			{
				if(strcmp(st[i].pName , st[j].pName) == 0)
				{		
					iAlreadyFoundIndex[iAlreadyFoundcount] = j;
					iAlreadyFoundcount++;
					if(stCompare_.AndOR == false)/// or operation
					{  
						if( !bmatchfound )
						{
							printf("\nTicketNo : %s -- Name : '%s'\nTicketNo : %s -- Name : '%s'",
								&st[i].pTickitNo,st[i].pName,
								&st[j].pTickitNo,st[j].pName);
						}
						else
						{
							printf("\nTicketNo : %s -- Name : '%s'",							   
								&st[j].pTickitNo,st[j].pName);
						}
						continue;
					}									
				}	
			}
		}
	}	
}

int _tmain(int argc, _TCHAR* argv[])
{		

	stPassenger stp[100];

	printf("\nRETE DEMO\n");
	printf("\n================================================================\n");

	/*
	printf("\nNOTE:Insert Passenger Detail in Following Sequence:");
	printf("\ne.g.Sequence:-> TickitID,Name,Address,Mobile Number,Email ID,Year Of Birth(YYYY).");
	printf("\nTickitID is must be unique.\n\n");
	printf("\n================================================================\n\n\n");

	char ch;
	ch = 'N';
	//int iCount = 0;
	while( ch == 'N' )
	{
	printf("\nPassenger Detail(N for new passenger and D for done!!):\n");
	scanf("%c",&ch);
	if(ch == 'D')
	break;

	scanf("%s,%s,%s,%s,%s,%s",&stp[iCount].pTickitNo,stp[iCount].pName
	,stp[iCount].pAdd,&stp[iCount].pMobNo,stp[iCount].pEmailID,stp[iCount].pDob);
	iCount++;
	}
	*/

	int iCount = 0;

	FILE *fp;
	fp = fopen("D:\\PassengerDetail.txt","r");

	if(!fp)
		return 0;		

	printf("\n\n======================");
	for(int i = 0; i < 11; i++)
	{
		fscanf(fp,"%s %s %s %s %s %s",&stp[iCount].pTickitNo,stp[iCount].pName
			,stp[iCount].pAdd,&stp[iCount].pMobNo,stp[iCount].pEmailID,stp[iCount].pDob);

		printf("\n%s,%s,%s,%s,%s,%s",&stp[iCount].pTickitNo,stp[iCount].pName
			,stp[iCount].pAdd,&stp[iCount].pMobNo,stp[iCount].pEmailID,stp[iCount].pDob);
		iCount++;
	}

	fclose(fp);

	printf("\n\nMake Rule for Passengers:\n");
	printf("\n\n(NOTE: N for Name,A for Address,M for MobNo,E for Email, Y for YearOfBirth, press D for rule complete)\n");
	printf("\n\nFor AND Operation Press +\n");
	printf("\n\nFor OR Operation Press |\n");
	printf("\n\n(e.g) N+M means Match rule Name and Mobile Number. \n");

	char chOp1,chOp2,chOperator;
	printf("\n\nPlease Define Rule: \n");
	scanf("%c%c%c",&chOp1,&chOperator,&chOp2);

	/*char chOp1,chOp2,chOperator;
	printf("\n\nPlease Define Rule2: \n");
	scanf("%c%c%c",chOp1,chOperator,chOp2);*/


	//N,A,M,E,Y
	stCompare stCompare_;
	stCompare_.MobNo = false;	
	stCompare_.Dob = false;	
	stCompare_.Name = false;	
	stCompare_.Add = false;	
	stCompare_.EmailID = false;	

	stCompare_.AndOR = (chOperator == '+' ) ? true : false;	
	switch(chOp1)
	{
	case 'N':
		stCompare_.Name = true;
		break;
	case 'A':
		stCompare_.Add = true;
		break;
	case 'M':
		stCompare_.MobNo = true;
		break;
	case 'E':
		stCompare_.EmailID = true;
		break;
	case 'Y':
		stCompare_.Dob = true;
		break;
	}
	switch(chOp2)
	{
	case 'N':
		stCompare_.Name = true;
		break;
	case 'A':
		stCompare_.Add = true;
		break;
	case 'M':
		stCompare_.MobNo = true;
		break;
	case 'E':
		stCompare_.EmailID = true;
		break;
	case 'Y':
		stCompare_.Dob = true;
		break;
	}

	findRule(stp,iCount,stCompare_);

	printf("\n");

	return 0;
}

