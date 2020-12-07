#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista *poz;
struct lista 
{
	int el;
	poz next;
};

int SortUnos(int, poz);
int Ispis(poz);
int Unija(poz, poz, poz);
int Presjek(poz, poz, poz);

int main()
{
	struct lista head1, head2, u, p;
	head1.next = NULL;
	head2.next = NULL;
	u.next = NULL;
	p.next = NULL;

	char ime[100];
	printf("Unesi ime datoteke: \n");
	scanf("%s", ime);

	FILE* datoteka = fopen(ime, "r");
	if (!datoteka)
		printf("Krivo otvorena datoteka! \n");

	while (!feof(datoteka))
	{
		if (fgetc(datoteka) != '\n')
		{
			fscanf(datoteka, " %d", &head1.el);
			SortUnos(head1.el, &head1);
		}
		else
		{
			while (!feof(datoteka))
			{
				fscanf(datoteka, "%d ", &head2.el);
				SortUnos(head2.el, &head2);
			}
		}
	}

	printf("Prva lista: \n");
	Ispis(&head1);

	printf("Druga lista: \n");
	Ispis(&head2);

	printf("Unija lista: \n");
	Unija(&head1, &head2, &u);
	Ispis(&u);

	printf("Presjek lista; \n");
	Presjek(&head1, &head2, &p);
	Ispis(&p);

	return 0;
}

int Unija(poz p, poz q, poz r)
{
	p = p->next;
	q = q->next;

	while (p != NULL && q != NULL)
	{
		if (p->el == q->el)
		{
			SortUnos(p->el, r);

			p = p->next;
			q = q->next;
		}
		else if (p->el < q->el)
		{
			SortUnos(p->el, r);

			p = p->next;
		}
		else
		{
			SortUnos(q->el, r);

			q = q->next;
		}
	}
	if (p == NULL)
	{
		while (q != NULL)
		{
			SortUnos(q->el, r);

			q = q->next;
		}
	}
	if (q == NULL)
	{
		while (p != NULL)
		{
			SortUnos(p->el, r);

			p = p->next;
		}
	}
	return 0;
}

int Presjek(poz p, poz q, poz r)
{
	p = p->next;
	q = q->next;

	while (p != NULL && q != NULL)
	{
		if (p->el == q->el)
		{
			SortUnos(p->el, r);

			p = p->next;
			q = q->next;
		}
		else if (p->el < q->el)
			p = p->next;
		else
			q = q->next;
	}
	return 0;
}

int SortUnos(int x, poz p)
{
	poz q;

	while (p->next != NULL && p->next->el < x)
		p = p->next;

	q = (poz)malloc(sizeof(struct lista));
	q->el = x;

	q->next = p->next;
	p->next = q;

	return 0;
}

int Ispis(poz p)
{
	p = p->next;
	if (p == NULL)
		printf("Lista je prazna! \n");
	while (p != NULL)
	{
		printf("%d \n", p->el);
		p = p->next;
	}
	return 0;
}