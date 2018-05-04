/*
 ============================================================================
 Name        : Question3.c
 Author      : Samuel
 Version     :
 Copyright   : public
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/**
 * Includes.
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * Structure myClass with a int and a pointer tpo a function.
 */
struct myClass {
	int m_x;
	void (*func)(struct myClass*, int);
};

/**
 * Structure Derived with a structure myClass.
 */
struct Derived {
	struct myClass myClass;
};

/**
 * Structure Derived2 with a structure myClass and a int.
 */
struct Derived2 {
	int m_y;
	struct myClass myClass;
};

/**
 * This method received a struct myClass and a int, and add to the int of my class the int.
 */
void add(struct myClass* myclass, int y) {
	myclass->m_x += y;
}

/**
 * This method received a struct myClass and a int, and 'do xor' to the int of my class the int.
 */
void xor(struct myClass* myclass, int y) {
	myclass->m_x ^= y;
}

/**
 * This method received a struct myClass and a int, and add to the int of my class the intn and make the m_y = y.
 */
void add2(struct myClass* myclass, int y) {
	struct Derived2* derived2 = (struct Derived2*) myclass;
	derived2->m_y = y;
	derived2->myClass.m_x += y;
}

/**
 * This function test myClass.
 */
void testMyClass() {
	struct myClass test;
	test.m_x = 9;
	printf("m_x : %d\n", test.m_x);
	test.func = add;
	puts("Running of the function add...");
	test.func(&test, 4);
	printf("m_x after the change : %d\n", test.m_x);
}

/**
 * This function test Derived.
 */
void testDerived() {
	struct Derived test;
	test.myClass.m_x = 7;
	printf("m_x : %d\n", test.myClass.m_x);
	test.myClass.func = xor;
	puts("Running of the function xor...");
	test.myClass.func(&test.myClass, 4);
	printf("m_x after the change : %d\n", test.myClass.m_x);
}

/**
 * This function test Derived2.
 */
void testDerived2() {
	struct Derived2 test;
	test.m_y = 6;
	printf("m_y : %d\n", test.m_y);
	test.myClass.m_x = 7;
	printf("m_x : %d\n", test.myClass.m_x);
	test.myClass.func = add2;
	puts("Running of the function add2...");
	test.myClass.func((struct myClass*) &test, 5);
	printf("m_y after the change : %d\n", test.m_y);
	printf("m_x after the change : %d\n", test.myClass.m_x);
}

/**
 * The main function to do test.
 */
int main() {
	puts("Welcome !");
	puts("Test myClass");
	testMyClass();
	puts("Test Derived");
	testDerived();
	puts("Test Derived2");
	testDerived2();
	return 0;
}
