// A C++ program to demonstrate that we can directly
// manipulate VPtr. Note that this program is based
// on the assumption that compiler store vPtr in a
// specific way to achieve run-time polymorphism.
#include <iostream>
using namespace std;

#pragma pack(1)

// A base class with virtual function foo()
class CBase {
public:
	virtual void foo() noexcept
	{
		cout << "CBase::Foo() called" << endl;
	}

protected:
	int mData;
};

// A derived class with its own implementation
// of foo()
class CDerived : public CBase {
public:
	void foo() noexcept
	{
		cout << "CDerived::Foo() called" << endl;
	}

private:
	char cChar;
};

// Driver code
int main()
{
	// A base type pointer pointing to derived
	CBase* pBase = new CDerived;

	// Accessing vPtr
	int* pVPtr = *(int**)pBase;

	// Calling virtual method
	((void (*)())pVPtr[0])();

	// Changing vPtr
	delete pBase;
	pBase = new CBase;
	pVPtr = *(int**)pBase;

	// Calls method for new base object
	((void (*)())pVPtr[0])();

	return 0;
}


// What are VTable and VPtr? 
// When a method is declared virtual in a class, compiler creates a virtual table (aka VTable) and stores addresses of 
// virtual methods in that table. A virtual pointer (aka VPtr) is then created and initialized to point to that VTable. 
// A VTable is shared across all the instances of the class, i.e. compiler creates only one instance of VTable to be shared 
// across all the objects of a class. Each instance of the class has its own version of VPtr. If we print the size of a class 
// object containing at least one virtual method, the output will be sizeof(class data) + sizeof(VPtr). 
// Since address of virtual method is stored in VTable, VPtr can be manipulated to make calls to those virtual methods thereby 
// violating principles of encapsulation. See below example: 