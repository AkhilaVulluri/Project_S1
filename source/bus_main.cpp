//BUS RESERVATION MANAGEMENT SYSTEM PROJECT

//header files

#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include "star.h"
#include "email2.h"

using namespace std;

//declaration of varabiles

static int static_point = 0;


class BusRev
{
  char busn[5], driver[10], from[10], to[10], seat[8][4][10];
  int arrival, depart;
public:
  void install ();
  void allotment ();
  void empty ();
  void show ();
  void avail ();
  void position (int SeatPosition);
}

bus[10];
//add bus installaion

void
BusRev::install ()
{
  cout << "\n\n\n\t\t\tEnter bus no: ";
  cin >> bus[static_point].busn;
  cout << "\n\t\t\tEnter Driver's name: ";
  cin >> bus[static_point].driver;
  cout << "\n\t\t\tArrival time: ";
  cin >> bus[static_point].arrival;
  cout << "\n\t\t\tDeparture time: ";
  cin >> bus[static_point].depart;
  cout << "\n\t\t\tFrom: ";
  cin >> bus[static_point].from;
  cout << "\n\t\t\tTo: ";
  cin >> bus[static_point].to;
  bus[static_point].empty ();
  static_point++;

  cout << "\n\t\t\tBus added Sucessfully ";
}

//allotment of bus (bus reservation counter)

void
BusRev::allotment ()
{
  int seat;
  char number[5];
top:
  cout << "\n\n\n\t\t\tBus no: ";
  cin >> number;
  int bus_num;
  for (bus_num = 0; bus_num <= static_point; bus_num++)
    {
      if (strcmp (bus[bus_num].busn, number) == 0)
	break;
    }
  while (bus_num <= static_point)
    {
      cout << "\n\t\t\tSeat Number: ";
      cin >> seat;
      if (seat > 32)
	{
	  cout << "\n\t\t\tThere are only 32 seats available in this bus.";
	}
      else
	{
	  if (strcmp (bus[bus_num].seat[seat / 4][(seat % 4) - 1], "Empty") ==
	      0)
	    {
	      cout << "\n\t\t\tEnter passanger's name: ";
	      cin >> bus[bus_num].seat[seat / 4][(seat % 4) - 1];

	      cout << "\n\t\t\tSeat Reserved Sucessfully ";
	      break;
	    }
	  else
	    cout << "\n\t\t\tThe seat no. is already reserved.\n";
	}
    }
  if (bus_num > static_point)
    {
      cout << "\n\t\t\tEnter correct bus no.\n";
      goto top;
    }
}

//remaining bus seats available  

void
BusRev::empty ()
{
  for (int SeatRow = 0; SeatRow < 8; SeatRow++)
    {
      for (int SeatColumn = 0; SeatColumn < 4; SeatColumn++)
	{
	  strcpy (bus[static_point].seat[SeatRow][SeatColumn], "Empty");
	}
    }
}


//gives the details of the bus and remaining sets available


void
BusRev::show ()
{
  int bus_num;
  char number[5];
  cout << "\n\t\t\tEnter bus no: ";
  cin >> number;
  for (bus_num = 0; bus_num <= static_point; bus_num++)
    {
      if (strcmp (bus[bus_num].busn, number) == 0)
	break;
    }
  while (bus_num <= static_point)
    {
      vline ('*');
      cout << "\n\t\t\tBus no: " << bus[bus_num].busn
	<< "\n\t\t\tDriver: " << bus[bus_num].driver
	<< "\n\t\t\tArrival time: " << bus[bus_num].arrival
	<< "\n\t\t\tDeparture time: " << bus[bus_num].depart
	<< "\n\t\t\tFrom: " << bus[bus_num].from
	<< "\n\t\t\tTo: " << bus[bus_num].to << "\n";
      vline ('*');
      bus[0].position (bus_num);
      int a = 1;
      for (int SeatRow = 0; SeatRow < 8; SeatRow++)
	{
	  for (int SeatColumn = 0; SeatColumn < 4; SeatColumn++)
	    {
	      a++;
	      if (strcmp (bus[bus_num].seat[SeatRow][SeatColumn], "Empty") !=
		  0)
		cout << "\n\t\t\tThe seat no " << (a - 1)
		  << " is reserved for "
		  << bus[bus_num].seat[SeatRow][SeatColumn] << ".\n";
	    }
	}
      vline ('*');
      break;
    }
  if (bus_num > static_point)
    cout << "\n\t\t\tEnter correct bus no: ";

}

//allotment of the set of the passanger 
//according to there set numbers


void
BusRev::position (int SeatPosition)
{
  int Flag = 0;
  static_point = 0;
  for (int SeatRow = 0; SeatRow < 8; SeatRow++)
    {
      cout << "\n";
      for (int SeatColumn = 0; SeatColumn < 4; SeatColumn++)
	{
	  Flag++;
	  if (strcmp (bus[SeatPosition].seat[SeatRow][SeatColumn], "Empty") ==
	      0)
	    {
	      cout.width (5);
	      cout.fill (' ');
	      cout << Flag << ".";
	      cout.width (10);
	      cout.fill (' ');
	      cout << bus[SeatPosition].seat[SeatRow][SeatColumn];
	      static_point++;
	    }
	  else
	    {
	      cout.width (5);
	      cout.fill (' ');
	      cout << Flag << ".";
	      cout.width (10);
	      cout.fill (' ');
	      cout << bus[SeatPosition].seat[SeatRow][SeatColumn];
	    }
	}
    }
  cout << "\n\n\t\t\tThere are " << static_point << " seats empty in Bus No: "
    << bus[SeatPosition].busn;
}


//All types of buses with full details  

void
BusRev::avail ()
{

  for (int bus_num = 0; bus_num < static_point; bus_num++)
    {
      vline ('*');
      cout << "\n\t\t\tBus no: " << bus[bus_num].busn
	<< "\n\t\t\tDriver: " << bus[bus_num].driver
	<< "\n\t\t\tArrival time: " << bus[bus_num].arrival
	<< "\n\t\t\tDeparture Time: " << bus[bus_num].depart
	<< "\n\t\t\tFrom: " << bus[bus_num].from
	<< "\n\t\t\tTo: " << bus[bus_num].to << "\n";
      vline ('*');
    }
}



// main memu display board

void
welcomeScreen ()
{


  cout << "\n\n\n\n";
  cout << "\t\t\t================================================\n";
  cout << "\t\t\t||                  WELCOME TO                ||\n";
  cout << "\t\t\t||                                            ||\n";
  cout << "\t\t\t||      BUS RESERVATION SYSTEM MANAGEMENT     ||\n";
  cout << "\t\t\t||                                            ||\n";
  cout << "\t\t\t||                    PROJECT                 ||\n";
  cout << "\t\t\t================================================\n\n\n";

}

//main function

int
main ()
{

// declaration of varabiles

  welcomeScreen ();
  int Choice, age;
  string EmailAddress;
  float emailinvaild;

  char gender, passinvaild;
  char name[50];
  char pass[20];

  //reading user name
  cout << "\n Enter User Name  :  ";
  cin >> name;
  

  //reading the Password

  cout << "\n Enter Password  :  ";
  cin >> pass;
  try
  {
    //This section is used to verify the number of characters.

    if (strlen (pass) < 6)
      {
	cout << "\n Password must be at least 6 Characters Long..." << endl;
	throw "passinvaild";
      }

    //This section is used to verify the digits in the string.

    bool digit_yes = false;
    bool char_yes = false;
    bool valid;
    int len = strlen (pass);
    for (int count = 0; count < len; count++)
      {
	if (isdigit (pass[count]))
	  {

	    //true condition

	    digit_yes = true;
	  }
      }
    for (int countj = 0; countj < len; countj++)
      {
	if (isalpha (pass[countj]))
	  {

	    //true condition

	    char_yes = true;
	  }
      }

    if (!digit_yes && char_yes)
      {
	valid = false;
	cout << "\n Password must have at least One Digit (0-9)" << endl;
	throw "passinvaild";
      }
    else if (digit_yes && !char_yes)
      {
	valid = false;
	cout << "\n Password must have at least One Character (A-Z/a-z)" <<
	  endl;
	throw "passinvaild";
      }
    else if (!digit_yes && !char_yes)
      {
	valid = false;
	cout <<
	  "\n Password must have at least One Character (A-Z/a-z) and One Digit (0-9)"
	  << endl;
	throw "passinvaild";
      }
    else
      {

	valid = true;
	cout << "\n Password is Accepted\n";

	//reading of email-address

	cout << "\n Enter your Email-Id:\n" << endl;
	cin >> EmailAddress;
	if (Email_check (EmailAddress))
	  cout << "\n Your Email-Id is valid" << endl;
	else
	  {
	    throw "emailinvaild";
	  }

	//reading of age

	cout << "\n Enter your age: ";
	cin >> age;

	//condition to check eligility

	if (age >= 18)
	  {
	    cout << "\n Yor are  eligible " << endl;
	  }
	else
	  {
	    throw "ageinvaild";
	  }

	//Reading gender from user

	cout << "\n Enter gender (M/m or F/f ): ";
	cin >> gender;

	switch (gender)
	  {
	  case 'M':
	  case 'm':
	    cout << "\n Male";
	    cout << "\n\t\t\t\t Login Succesfull\n";
	    break;
	  case 'F':
	  case 'f':
	    cout << "\n Female";
	    cout << "\n\t\t\t\t Login Succesfull\n";
	    break;

	  default:
	    throw;

	  }



	while (1)
	  {

	    //main menu baord

	    cout << "\n\n\n";
	    cout <<
	      "\n\t\t\t================================================";

	    cout << "\n\n\t\t\t\t\tBus Reservation System \n\n";

	    cout <<
	      "\n\t\t\t-------------------------------------------------\n" <<
	      "\t\t\t1.Add Bus\n\t\t\t" <<
	      "\n\t\t\t-------------------------------------------------\n" <<
	      "\t\t\t2.Buses Available.\n\t\t\t" <<
	      "\n\t\t\t-------------------------------------------------\n" <<
	      "\t\t\t3.Bus Reservation\n\t\t\t" <<
	      "\n\t\t\t-------------------------------------------------\n" <<
	      "\t\t\t4.Details of the Bus\n\t\t\t" <<
	      "\n\t\t\t-------------------------------------------------\n" <<
	      "\t\t\t5.Exit" <<
	      "\n\t\t\t-------------------------------------------------\n";
	    cout << "\n\t\t\tEnter your choice:-> ";

	    //Choice Option 

	    cin >> Choice;
	    switch (Choice)
	      {
	      case 1:
		bus[static_point].install ();
		break;
	      case 2:
		bus[0].avail ();
		break;
	      case 3:
		bus[static_point].allotment ();
		break;
	      case 4:
		bus[0].show ();

		break;
	      case 5:
		cout <<
		  "\n\t\t\t Thanks for using our project...!!! \t\t\t\n";
		cout << "\n\t\t\t Have a nice day...!!!\t\t\t\n\n";
		exit (0);

	      }
	  }

      }
  }

  //Inaild Statements

  catch (char passinvaild)
  {
    cout << "\n Invalid Password Format!!!and try again";
  }
  catch (int ageinvaild)
  {
    cout << "\n You are not eligible ";
    cout << "\n\t\t\t Thanks for using our project...!!!\t\t\t\n";
    cout << "\n\t\t\t Have a nice day...!!!\t\t\t\n\n";
  }
  catch (float emailinvaild)
  {
    cout << "\n Your Email-Id is invalid and try again";
  }

  catch ( ...)
  {
    cout << "\n Invalid Format!!!and try again \n";
    cout << "\n Please re-verify your details and try again\n";
    cout << "\n Thanks for using our project...!!!\t\t\t\n";
    cout << "\n Have a nice day...!!!\t\t\t\n\n";
  }


  return 0;


}
