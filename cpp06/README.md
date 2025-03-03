## Module 06: Casting
# ex00: Conversion of scalar - static_cast<>()
		- Static method: convert(std::string input)
			```c++
			Syntax
			class ClassName {
				public:
					static returnType functionName(parameters) {
					// Function body implementation
					}
			};
			```
	1️⃣ static_cast → Compile-Time Type Conversion
	🔹 Used for:
		- Converting between related types (e.g., int to double, char* to void*).
		- Upcasting (converting derived class pointers/references to base class).
			EXAMPLE: 
				```c++
				Derived d;
				Base* ptr = static_cast<Base*>(&d);
				```
		- Converting enum values to integers (and vice versa).
		- Implicit type conversions done manually.
	🔸 Restrictions:
		- Does NOT check validity at runtime → Unsafe for downcasting (derived to base).
		- Cannot be used with polymorphic types (i.e., no virtual functions involved).

# ex01: Serialization - reinterpret_cast<>()
	🔹 Used for:
		- Casting between unrelated types (e.g., int* to char*).
		EXAMPLE:
			```c++
			int x = 42;
			int* px = &x;
			char* pch = reinterpret_cast<char*>(px);  // Treat int* as char*
			```
		- Converting pointers to integer types and vice versa.
		EXAMPLE:
			```c++
			uintptr_t address = reinterpret_cast<uintptr_t>(px);  // Convert pointer to integer
			```
		- Casting function pointers.
		- Useful for bitwise reinterpretation of data.
	🔸 Restrictions:
		- Does NOT check compatibility → Unsafe and platform-dependent.
		- Can cause undefined behavior if used incorrectly.
		- Should be avoided unless absolutely necessary.	
	
# ex02: Base - dynamic_cast<class*>(obj) / dynamic_cast<class&>(obj)
	🔹 Used for:
		- Safely converting pointers/references in a polymorphic hierarchy.
		- Downcasting (converting Base* to Derived*).
			EXAMPLE:
				```c++
				Base* b = new Derived();  // Polymorphic base pointer
    			Derived* d = dynamic_cast<Derived*>(b);  // ✅ Safe downcast
				```
		- Checking whether an object is of a certain derived type.
	🔸 Restrictions:
		- Requires at least one virtual function in the base class for RTTI.
		- Returns nullptr for invalid casts when using pointers.
		- Throws std::bad_cast when using references if the cast fails.