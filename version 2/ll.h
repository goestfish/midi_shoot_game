

/* header file for list */
#include <stdbool.h>

/* these are the function pointer signatures needed */

typedef void (* ActionFunction)( void *data);
typedef bool (* ComparisonFunction)(void *data1, void *data2);
typedef bool (* CriteriaFunction)(void *data, void *helper);


/* signatures that the list code provides to the outside world */

/* insert and delete need to be able to change the head pointer so you pass
 * in the address of the head pointer */

/* int returns FALSE when it fails to do the insert */
bool insert(void *p2head, void *data, ComparisonFunction goesInFrontOf, 
		int text);
int deleteSome(void *p2head, CriteriaFunction mustGo, void *helper,
		ActionFunction disposal, int text);

/* iterate, count, and sort do not change the nodes, so you pass in the head
 * pointer and not the address of the head pointer */
void iterate(void *head, ActionFunction doThis);

int count (void *head, CriteriaFunction countThis, void *helper);

void sort(void *hptr, ComparisonFunction cf);

