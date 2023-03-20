#include <stdlib.h>
#include"dog.h"

/**
 * init_dog - initializes a variable of type struct dog
 * @d: A dog structure
 * @name: Name of the dog
 * @age: The age of the dog
 * @owner: The owner of the dog
 *
 * Return: Nothing
*/
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		d = malloc(sizeof(struct dog));
	d->name = name;
	d->age = age;
	d->owner = owner;
}
