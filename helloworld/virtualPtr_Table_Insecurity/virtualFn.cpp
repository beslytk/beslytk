// C++ program to demonstrate how a virtual function
// is used in a real life scenario

class Employee {
public:
	virtual void raiseSalary()
	{
		// common raise salary code
	}

	virtual void promote()
	{
		// common promote code
	}
};

class Manager : public Employee {
	virtual void raiseSalary()
	{
		// Manager specific raise salary code, may contain
		// increment of manager specific incentives
	}

	virtual void promote()
	{
		// Manager specific promote
	}
};

// Similarly, there may be other types of employees

// We need a very simple function
// to increment the salary of all employees
// Note that emp[] is an array of pointers
// and actual pointed objects can
// be any type of employees.
// This function should ideally
// be in a class like Organization,
// we have made it global to keep things simple
void globalRaiseSalary(Employee* emp[], int n)
{
	for (int i = 0; i < n; i++) {
		// Polymorphic Call: Calls raiseSalary()
		// according to the actual object, not
		// according to the type of pointer
		emp[i]->raiseSalary();
	}
}

// How does the compiler perform runtime resolution?
// The compiler maintains two things to serve this purpose:

// vtable: A table of function pointers, maintained per class. 
// vptr: A pointer to vtable, maintained per object instance (see this for an example).
// The compiler adds additional code at two places to maintain and use vptr.

// 1. Code in every constructor. This code sets the vptr of the object being created. This code sets vptr to point to the vtable 
// of the class. 

// 2. Code with polymorphic function call (e.g. bp->show() in above code). Wherever a polymorphic call is made, the compiler 
// inserts code to first look for vptr using a base class pointer or reference (In the above example, since the pointed or referred 
// object is of a derived type, vptr of a derived class is accessed). Once vptr is fetched, vtable of derived class can be accessed. 
// Using vtable, the address of the derived class function show() is accessed and called.

// Is this a standard way for implementation of run-time polymorphism in C++? 
// The C++ standards do not mandate exactly how runtime polymorphism must be implemented, but compilers generally use minor 
// variations on the same basic model.

// Is it wise to use virtual method? 
// As it can be seen, through base class pointer, call to derived class method is being dispatched. Everything seems to be working fine. Then what is the problem? 
// If a virtual routine is called many times (order of hundreds of thousands), it drops the performance of system, reason being each time the routine is called, its address needs to be resolved by looking through VTable using VPtr. Extra indirection (pointer dereference) for each call to a virtual method makes accessing VTable a costly operation and it is better to avoid it as much as we can.

// Curiously Recurring Template Pattern (CRTP) 
// Usage of VPtr and VTable can be avoided altogether through Curiously Recurring Template Pattern (CRTP). 
// CRTP is a design pattern in C++ in which a class X derives from a class template instantiation using X itself as template argument.
//  More generally it is known as F-bound polymorphism. 