/* Bowei Kou */

int count(void *head, CriteriaFunction countThis, void *helper);
int deleteSome(void *p2head, CriteriaFunction mustGo, void *helper, ActionFunction disposal, int text);
bool insert(void* p2head, void *data, ComparisonFunction goesInFrontOf, int text);
void iterate(void *head, ActionFunction doThis);
void sort(void *hptr, ComparisonFunction cf);
