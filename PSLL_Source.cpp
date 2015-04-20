////////////////////////////////////////////////////
//Author: Kenan Tarik Tufekci
//Date:   04/20/2015
//Title:  PSLL Unit Tests
///////////////////////////////////////////////////

#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.h"
#include <iostream>
#include <stdexcept>
#include "PSLL.h"

//Helper Functions compares two elements of type T
template<typename T>
bool equals(const T& a, const T& b) { //Helper function for 
	return (a == b);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////PSLL TEST/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

SCENARIO("PSLL - item at test and [] overloaded function properly", "[Prove item at returns correct number for al positions]"){
	cop3530::PSLL<int> list;	//Initialize the list
	GIVEN("A list filled with 100 element from (0-999)"){
		for (int i = 0; i < 1000; ++i){	//Push 1000 elements into the list
			list.push_back(i);
		}
		WHEN("The list is checked all elements are inseted correcly in appropirate position"){
			THEN("The element at specific location should equal value for item_at()"){
				for (int i = 0; i < 1000; ++i){
					REQUIRE(list.item_at(i) == i);
					REQUIRE(list[i] == i);
					INFO("i=" << i);
				}
			}
		}
	}
}

TEST_CASE("PSLL - push_back/push_front 100 elements", "Prove list size is 1000 and all element in correct location"){
	//This is for list1 that have 1000 elements from 0-999
	cop3530::PSLL<int> list1;	//Initialize the list1
	int i = 0;
	for (i = 0; i < 1000; ++i){	//Push 1000 elements into the list1
		list1.push_back(i);
	}
	int size1 = list1.size();	//size1 is now the size of the list1
	REQUIRE(size1 == 1000);		//check the size to make sure the list is correct size
	for (i = 0; i < size1; ++i){
		REQUIRE(list1.item_at(i) == i);
	}

	//This is for list2 that have 1000 elements from 0-999
	cop3530::PSLL<int> list2;	//Initialize the list1
	for (i = 0; i < 1000; ++i){	//Push 1111 elements into the list1
		list2.push_front(i);
	}
	int size2 = list2.size();	//size2 is now the size of the list2
	REQUIRE(size2 == 1000);
	int k = 0;
	for (i = (size2 - 1); i >= 0; --i){
		REQUIRE(list2.item_at(k) == i);
		++k;
	}
}

TEST_CASE("PSLL - test overloaded operator[]", "Prove the correct value is returned"){
	cop3530::PSLL<int> list;	//Initialize the list
	for (int i = 0; i < 200; ++i){	//Push 1000 elements into the list1
		list.push_back(i);
	}

	//Check if the reassignment operator works
	//Each case is reseting the element at position
	//using the [] overloaded operator
	list[0] = 111;
	list[20] = 222;
	list[40] = 333;
	list[80] = 444;
	list[90] = 555;
	list[110] = 666;
	list[130] = 777;
	list[150] = 888;
	list[170] = 999;
	list[190] = 1111;
	list[199] = 2222;

	//In this check all the positions that were used above 
	//should now contain the new element
	REQUIRE(list[0] == 111);
	REQUIRE(list[20] == 222);
	REQUIRE(list[40] == 333);
	REQUIRE(list[80] == 444);
	REQUIRE(list[90] == 555);
	REQUIRE(list[110] == 666);
	REQUIRE(list[130] == 777);
	REQUIRE(list[150] == 888);
	REQUIRE(list[170] == 999);
	REQUIRE(list[190] == 1111);
	REQUIRE(list[199] == 2222);
}

TEST_CASE("PSLL - resize the list", "Prove that the list shrinks"){
	int i = 0;
	cop3530::PSLL<int> list; //Initialize the list
	for (i = 0; i < 2000; ++i){	//Push 2000 elements into the list1
		list.push_back(i);
	}
	for (i = 0; i < 1000; ++i){
		list.pop_front();
	}

	int size = list.size();	//The new list size after poping 1000 elements off 
	REQUIRE(size == 1000); //The list size should be a 1000 elements left

	for (i = 0; i < 1111; ++i){
		list.push_front(i);
	}

	size = list.size();	//The new list size after pushing 1000 elements in
	REQUIRE(size == 2111); //The list size should be a 2111 elements left

	for (i = 100; i < 200; ++i){
		list.remove(i);
	}

	size = list.size();	//The new list size after poping100 elements in
	REQUIRE(size == 2011); //The list size should be a 1000 elements left

	for (i = 100; i < 200; ++i){
		list.insert(9999, i);
	}

	size = list.size();	//The new list size after pushing 100 elements in
	REQUIRE(size == 2111); //The list size should be a 2111 elements left
}

TEST_CASE("PSLL - returned values check", "Prove that the functions are returning correct elements"){
	cop3530::PSLL<int> list;	//Initialize the list
	//This is for list2 that have 1000 elements from 0-999
	for (int i = 0; i < 1000; ++i){
		list.push_back(i);
	}

	int a, b;
	//Test for pop_front returned values
	for (int i = 0; i < 500; ++i){
		a = list.item_at(0); //Get a copy of the item at position
		b = list.pop_front(); //Remove the first element 
		REQUIRE(a == b);	//The should be the same 
	}
	//Test for pop_back returned values
	for (int i = 0; i < 500; ++i){
		a = list.item_at(list.size() - 1);	//Get a copy of the item at position
		b = list.pop_back();	//Remove the first element 
		REQUIRE(a == b);	//The should be the same 
	}
}

TEST_CASE("PSLL - replace function check", "Prove that the elements are being replaces"){
	cop3530::PSLL<int> list; //Initialize the list
	for (int i = 0; i < 150; ++i){	//Populate the list with 150 elements
		list.push_back(i);
	}

	//Save the values of item_at to an array to compare
	int itemAt[5], returned[5];
	itemAt[0] = list.item_at(0);
	itemAt[1] = list.item_at(10);
	itemAt[2] = list.item_at(25);
	itemAt[3] = list.item_at(32);
	itemAt[4] = list.item_at(49);

	//Save the values of returned element to an array to compare
	returned[0] = list.replace(111, 0);
	returned[1] = list.replace(222, 10);
	returned[2] = list.replace(333, 25);
	returned[3] = list.replace(444, 32);
	returned[4] = list.replace(555, 49);

	//Test if the old element is being returned after being replaced
	for (int i = 0; i < 5; ++i){
		REQUIRE(itemAt[i] == returned[i]);
	}

	//Test if the new values have been put into the list
	REQUIRE(list.item_at(0) == 111);
	REQUIRE(list.item_at(10) == 222);
	REQUIRE(list.item_at(25) == 333);
	REQUIRE(list.item_at(32) == 444);
	REQUIRE(list.item_at(49) == 555);
}

TEST_CASE("PSLL - insert function check", "Prove that the elements are being inserted into the list"){
	cop3530::PSLL<int> list;	//Initialize the list
	for (int i = 0; i < 200; ++i){	//Populate the list with 200 elements
		list.push_back(i);
	}

	//Insert all the following elements into the list
	list.insert(111, 0);
	list.insert(222, 20);
	list.insert(333, 40);
	list.insert(444, 80);
	list.insert(555, 90);
	list.insert(666, 110);
	list.insert(777, 130);
	list.insert(888, 150);
	list.insert(999, 170);
	list.insert(1111, 190);
	list.insert(2222, 199);

	//Check the list to make sure that all the elements are part of the list
	REQUIRE(list.item_at(0) == 111);
	REQUIRE(list.item_at(20) == 222);
	REQUIRE(list.item_at(40) == 333);
	REQUIRE(list.item_at(80) == 444);
	REQUIRE(list.item_at(90) == 555);
	REQUIRE(list.item_at(110) == 666);
	REQUIRE(list.item_at(130) == 777);
	REQUIRE(list.item_at(150) == 888);
	REQUIRE(list.item_at(170) == 999);
	REQUIRE(list.item_at(190) == 1111);
	REQUIRE(list.item_at(199) == 2222);
}


TEST_CASE("PSLL - remove function check", "Prove that the elements are being remove into the list"){
	cop3530::PSLL<int> list;	//Initialize the list
	for (int i = 0; i < 200; ++i){	//Populate the list with 200 elements
		list.push_back(i);
	}

	//replace all the following elements into the list
	list.replace(111, 0);
	list.replace(222, 20);
	list.replace(333, 40);
	list.replace(444, 80);
	list.replace(555, 90);
	list.replace(666, 110);
	list.replace(777, 130);
	list.replace(888, 150);
	list.replace(999, 170);
	list.replace(1111, 190);
	list.replace(2222, 199);

	//Check the list to make sure that all the elements are part of the list
	int itemAt[11], returned[11];	//Create the two array for camparison
	itemAt[0] = list.item_at(0);
	itemAt[1] = list.item_at(20);
	itemAt[2] = list.item_at(40);
	itemAt[3] = list.item_at(80);
	itemAt[4] = list.item_at(90);
	itemAt[5] = list.item_at(110);
	itemAt[6] = list.item_at(130);
	itemAt[7] = list.item_at(150);
	itemAt[8] = list.item_at(170);
	itemAt[9] = list.item_at(190);
	itemAt[10] = list.item_at(199);

	//Remove all the following elements into the list
	int sizeBefore = list.size();
	returned[0] = list.remove(0);
	returned[1] = list.remove(19);
	returned[2] = list.remove(38);
	returned[3] = list.remove(77);
	returned[4] = list.remove(86);
	returned[5] = list.remove(105);
	returned[6] = list.remove(124);
	returned[7] = list.remove(143);
	returned[8] = list.remove(162);
	returned[9] = list.remove(181);
	returned[10] = list.remove(189);

	//Test if the old element is being returned after being replaced
	for (int i = 0; i < 11; ++i){
		REQUIRE(itemAt[i] == returned[i]);
	}
	//Test for resize for removing 5 elements
	int sizeAfter = list.size();
	REQUIRE((sizeBefore - sizeAfter) == 11);
}

TEST_CASE("PSLL - contains function check", "Prove an element in contained in the list"){
	cop3530::PSLL<int> list;	//Initialize the list
	for (int i = 0; i < 2000; ++i) {	//Populate the list with 2000 elements
		list.push_back(i);
	}

	//replace all the following elements into the list
	list.replace(111, 0);
	list.replace(222, 20);
	list.replace(333, 40);
	list.replace(444, 80);
	list.replace(555, 90);
	list.replace(666, 110);
	list.replace(777, 130);
	list.replace(888, 150);
	list.replace(999, 170);
	list.replace(1111, 190);
	list.replace(2222, 199);

	//Using the conatin function to test if the elements were added to the list
	REQUIRE(list.contains(111, equals) == true);
	REQUIRE(list.contains(222, equals) == true);
	REQUIRE(list.contains(333, equals) == true);
	REQUIRE(list.contains(444, equals) == true);
	REQUIRE(list.contains(555, equals) == true);
	REQUIRE(list.contains(666, equals) == true);
	REQUIRE(list.contains(777, equals) == true);
	REQUIRE(list.contains(888, equals) == true);
	REQUIRE(list.contains(999, equals) == true);
	REQUIRE(list.contains(1111, equals) == true);
	REQUIRE(list.contains(2222, equals) == true);

	//Using the conatin function to test if the elements were removed to the list
	REQUIRE(list.contains(0, equals) == false);
	REQUIRE(list.contains(20, equals) == false);
	REQUIRE(list.contains(40, equals) == false);
	REQUIRE(list.contains(80, equals) == false);
	REQUIRE(list.contains(90, equals) == false);
	REQUIRE(list.contains(110, equals) == false);
	REQUIRE(list.contains(130, equals) == false);
	REQUIRE(list.contains(150, equals) == false);
	REQUIRE(list.contains(170, equals) == false);
	REQUIRE(list.contains(190, equals) == false);
	REQUIRE(list.contains(199, equals) == false);
}

TEST_CASE("PSLL - iterator check", "Prove all the element of the iterator is working"){
	cop3530::PSLL<int> list1;	//Initialize the list
	for (int i = 0; i < 2000; ++i) {	//Populate the list with 2000 elements
		list1.push_back(i);
	}

	//Use the copy constructor to set list1 = list2
	const cop3530::PSLL<int> list2 = list1;

	//This is the calling the constructor for iterators
	cop3530::PSLL<int>::iterator iter1 = list1.begin();
	cop3530::PSLL<int>::iterator iter1_1 = list1.begin();
	cop3530::PSLL<int>::const_iterator iter2 = list2.begin();
	cop3530::PSLL<int>::const_iterator iter2_1 = list2.begin();

	//Testing if the == operator has been overloaded correctly
	REQUIRE(iter1 == iter1_1);
	REQUIRE(iter2 == iter2_1);

	//Check if the iterator steps through the list and refers to the correct element in the list
	for (cop3530::PSLL<int>::const_iterator const_iter = list2.begin(); const_iter != list2.end(); ++const_iter) {
		REQUIRE(list1.item_at(*const_iter) == *const_iter);
	}

	//Step through the list using the iterator and then add 5 to each element
	while (iter1 != list1.end()) {
		*iter1++ += 5;
	}

	//Check the original list with the iterator to check if it has been properly changed
	int index = 0;
	for (iter1 = list1.begin(); iter1 != list1.end(); ++index) {
		REQUIRE(*iter1++ == (list1.item_at(index)));
	}
	//Use stepVal to make sure 5 was added to each element in the list
	int stepVal = 5;
	for (iter1 = list1.begin(); iter1 != list1.end(); ++stepVal){
		REQUIRE(*iter1++ == stepVal);
	}

	//check against other iterator to make sure its stayed the same
	for (iter2 = list2.begin(); iter2 != list2.end();){
		for (iter1 = list1.begin(); iter1 != list1.end();){
			REQUIRE(*iter2++ != *iter1++);
		}
	}
}

TEST_CASE("PSLL - test for exceptions", "Prove that all the exceptions are thrown for invalid operations"){

	//------------------------------------------------------
	//Test for empty list expection
	//------------------------------------------------------

	cop3530::PSLL<int> list;	//Initialize the list
	//Test for pop_back() an element when the list is empty
	REQUIRE_THROWS_AS(list.pop_back(), std::domain_error);
	//Test for pop_back() an element when the list is empty
	REQUIRE_THROWS_AS(list.pop_front(), std::domain_error);
	//Test for list[position] overloaded operator an element when the list is empty
	REQUIRE_THROWS_AS(list[20], std::domain_error);
	//Test for list[position] oveloaded operator an element with negative index
	REQUIRE_THROWS_AS(list[-10], std::domain_error);
	//Test for replace(element, position) when the list is empty
	REQUIRE_THROWS_AS(list.replace(111, 20), std::domain_error);
	//Test for remove(position) when the list is empty
	REQUIRE_THROWS_AS(list.remove(120), std::domain_error);
	//Test for item_at(position) when the list is empty
	REQUIRE_THROWS_AS(list.item_at(11), std::domain_error);

	//------------------------------------------------------
	//Test for invalid index expection
	//------------------------------------------------------

	//Fill the list with 1000 elements then test for invalid indexes
	for (int i = 0; i < 1000; ++i){	//Push 1000 elements into the list
		list.push_back(i);
	}

	//Test for list[position] overloaded operator an element for negative index
	REQUIRE_THROWS_AS(list[-10], std::out_of_range);
	//Test for list[position] overloaded operator an element for index larger than list size
	REQUIRE_THROWS_AS(list[1200], std::out_of_range);
	//Test for list.item_at(position) an element for negative index
	REQUIRE_THROWS_AS(list.item_at(-10), std::out_of_range);
	//Test for list.item_at(position) an element for index larger than list size
	REQUIRE_THROWS_AS(list.item_at(1200), std::out_of_range);
	//Test for list.replace(element, position) an element for negative index
	REQUIRE_THROWS_AS(list.replace(111, -5), std::out_of_range);
	//Test for list.replace(element, position) an element for index larger than list
	REQUIRE_THROWS_AS(list.replace(333, 1500), std::out_of_range);
	//Test for list.insert(element, position) an element for negative index
	REQUIRE_THROWS_AS(list.insert(111, -5), std::out_of_range);
	//Test for list.insert(element, position) an element for index larger than list
	REQUIRE_THROWS_AS(list.insert(333, 1500), std::out_of_range);
	//Test for list.remove(position) an element for negative index
	REQUIRE_THROWS_AS(list.remove(-10), std::out_of_range);
	//Test for list.remove(position) an element for index larger than list size
	REQUIRE_THROWS_AS(list.remove(1200), std::out_of_range);
}
