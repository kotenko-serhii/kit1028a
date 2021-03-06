#include "pch.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <time.h>

using namespace std;

struct node
{
	string country;
	int population;
	int area;
	int revenue;
	struct node *next;
	struct node *prev;
} *start;

class double_llist
{
public:
	void create_list(string country, int population, int area, int revenue);
	void add_begin(string country, int population, int area, int revenue);
	void add_after(string country, int population, int area, int revenue, int position);
	void delete_element(string country, int population, int area, int revenue);
	void display_dlist();
	void count();
	double_llist()
	{
		start = NULL;
	}
};

int main()
{
	srand(time(NULL));
	int choice, position;
	int population, area, revenue;
	string country;
	double_llist dl;
	while (1)
	{
		cout << endl << "----------------------------" << endl;
		cout << endl << "         Operations" << endl;
		cout << endl << "----------------------------" << endl;
		cout << "1.Create Node" << endl;
		cout << "2.Add at begining" << endl;
		cout << "3.Add after position" << endl;
		cout << "4.Delete" << endl;
		cout << "5.Display" << endl;
		cout << "6.Count" << endl;
		cout << "7.Quit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter the country name: ";
			cin >> country;
			population = rand() % 1000000 + 100000;
			area = rand() % 100000 + 10000;
			revenue = rand() % 10000 + 1000;
			dl.create_list(country, population, area, revenue);
			cout << endl;
			break;
		case 2:
			cout << "Enter the country name: ";
			cin >> country;
			population = rand() % 1000000 + 100000;
			area = rand() % 100000 + 10000;
			revenue = rand() % 10000 + 1000;
			dl.add_begin(country, population, area, revenue);
			cout << endl;
			break;
		case 3:
			cout << "Enter the country name: ";
			cin >> country;
			population = rand() % 1000000 + 100000;
			area = rand() % 100000 + 10000;
			revenue = rand() % 10000 + 1000;
			cout << "Insert Element after postion: ";
			cin >> position;
			dl.add_after(country, population, area, revenue, position);
			cout << endl;
			break;
		case 4:
			if (start == NULL)
			{
				cout << "List empty,nothing to delete" << endl;
				break;
			}
			cout << "Enter the country name: ";
			cin >> country;
			dl.delete_element(country, population, area, revenue);
			cout << endl;
			break;
		case 5:
			dl.display_dlist();
			cout << endl;
			break;
		case 6:
			dl.count();
			break;
		case 7:
			exit(1);
		default:
			cout << "Wrong choice" << endl;
		}
	}
	return 0;
}

void double_llist::create_list(string country, int population, int area, int revenue)
{
	struct node *s, *temp;
	temp = new(struct node);
	temp->country = country;
	temp->population = population;
	temp->area = area;
	temp->revenue = revenue;
	temp->next = NULL;
	if (start == NULL)
	{
		temp->prev = NULL;
		start = temp;
	}
	else
	{
		s = start;
		while (s->next != NULL)
			s = s->next;
		s->next = temp;
		temp->prev = s;
	}
}

void double_llist::add_begin(string country, int population, int area, int revenue)
{
	if (start == NULL)
	{
		cout << "First Create the list." << endl;
		return;
	}
	struct node *temp;
	temp = new(struct node);
	temp->prev = NULL;
	temp->country = country;
	temp->population = population;
	temp->area = area;
	temp->revenue = revenue;
	temp->next = start;
	start->prev = temp;
	start = temp;
	cout << "Element Inserted" << endl;
}

void double_llist::add_after(string country, int population, int area, int revenue, int pos)
{
	if (start == NULL)
	{
		cout << "First Create the list." << endl;
		return;
	}
	struct node *tmp, *q;
	int i;
	q = start;
	for (i = 0; i < pos - 1; i++)
	{
		q = q->next;
		if (q == NULL)
		{
			cout << "There are less than ";
			cout << pos << " elements." << endl;
			return;
		}
	}
	tmp = new(struct node);
	tmp->country = country;
	tmp->population = population;
	tmp->area = area;
	tmp->revenue = revenue;
	if (q->next == NULL)
	{
		q->next = tmp;
		tmp->next = NULL;
		tmp->prev = q;
	}
	else
	{
		tmp->next = q->next;
		tmp->next->prev = tmp;
		q->next = tmp;
		tmp->prev = q;
	}
	cout << "Element Inserted" << endl;
}

void double_llist::delete_element(string country, int population, int area, int revenue)
{
	struct node *tmp, *q;
	/*first element deletion*/
	if (start->country == country)
	{
		tmp = start;
		start = start->next;
		start->prev = NULL;
		cout << "Element Deleted" << endl;
		free(tmp);
		return;
	}
	q = start;
	while (q->next->next != NULL)
	{
		/*element deleted in between*/
		if (q->next->country == country)
		{
			tmp = q->next;
			q->next = tmp->next;
			tmp->next->prev = q;
			cout << "Element Deleted" << endl;
			free(tmp);
			return;
		}
		q = q->next;
	}
	/*last element deleted*/
	if (q->next->country == country)
	{
		tmp = q->next;
		free(tmp);
		q->next = NULL;
		cout << "Element Deleted" << endl;
		return;
	}
	cout << "Element " << country << " not found" << endl;
}

void double_llist::display_dlist()
{
	struct node *q;
	if (start == NULL)
	{
		cout << "List empty,nothing to display" << endl;
		return;
	}
	q = start;
	cout << "The Doubly Link List is :" << endl;
	while (q != NULL)
	{
		cout << "\n\nCountry: " << q->country << "\n Population: " << q->population << "\n Area: " << q->area << "\n Revenue: " << q->revenue;
		q = q->next;
	}
}

void double_llist::count()
{
	struct node *q = start;
	int cnt = 0;
	while (q != NULL)
	{
		q = q->next;
		cnt++;
	}
	cout << "Number of elements are: " << cnt << endl;
}

