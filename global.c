/*
* you can check in the runtime with the debugger that variable global
* will be stored in the RW segment instead of the stack or heap.
*/
int global = 200;

int main(void)
{
	int local = global;
	return 0;
}
