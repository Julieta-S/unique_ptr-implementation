#include "unique_pointer.h"
#include "unique_pointer.cpp"

int main()
{
	unique_pointer<Resource> res1(new Resource);
	unique_pointer<Resource> res2;
	res2 = move(res1);
	unique_pointer<Resource> res3 = make_uniquee<Resource>(7);
	cout << res2->get() << " " << res3->get() << endl;

	res2.swap(res3);
	cout << res2->get() << " " << res3->get() << endl;

	Resource* res4 = res2.release();
	cout << res4->get() << endl;

	cout << *res4 << endl;

}