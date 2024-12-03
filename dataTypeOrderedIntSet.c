/**
* @file dataTypeOrderedIntSet.c
* @brief This file contains all the functions for our menu-driven interface for our program to work.
*
* @authors Adam Davoren King, Andrew Reel, Charlie Brady, Ciaran Knowles, Joey Clancy, Ruairi Seery
* 
* @version 1.0
*/

#include "dataTypeOrderedIntSet.h"
#include "doubleLinkedList.h"
#include "menuFunctions.h"


/**
 * @brief    Create a Set: Prompts the user to create a new ordered set and stores it in SetsArray.
 *
 * @param	 N/a
 * 
 * @return   Returns a new empty ordered set
 */

setReturnValue createOrderedSet(orderedIntSet* s) {
createDoubleLinkedList(s); ///< Calling on the double linked list function to create set.
return CREATED_SET;
}

/**
 * @brief     Delete a set: Deletes an ordered set specified by the user from SetsArray.
 *
 * @param     s  This is the set which is to be deleted.
 * 
 * @return    N/a (this is a void function)
 */

setReturnValue deleteOrderedSet(orderedIntSet* s) {
deleteDoubleLinkedList(s); ///< Calling on the double linked list function to delete set.
free(s); ///< Freeing the memory allocated to the set.
return DELETED_SET;
}

/**
 * @brief     Add an element to a set: Prompts the user to add elements to an ordered set, stopping on a negative input.
 *
 * @param     s  This is the set which the element is to be added to.
 * @param     elem  This is the element to be added to the set.
 * 
 * @return    N/a (this is a void function)
 */

setReturnValue addElement(orderedIntSet* s, int elem) {

}

/**
 * @brief     Remove an element from a set: Prompts the user to remove elements from an ordered set, stopping on a negative input.
 *
 * @param     s  This is the set which the element is to be removed from.
 * @param     elem  This is the element to be removed from the set.
 * 
 * @return    Returns the value NUMBER ADDED if elem has been added to the set or NUMBER ALREADY IN SET if elem is already present in the set.
 */

setReturnValue removeElement(orderedIntSet* s, int elem) {

}

/**
 * @brief     Find the intersection of two sets: Computes the intersection of two sets and stores the result in a third set.
 *
 * @param     s1  This is the first set
 * @param     s2  This is the second set
 * 
 * @return    Returns the value NUMBER REMOVED if elem has been in the set or NUMBER NOT IN SET if elem has not been in the set.

 */

orderedIntSet* setIntersection(const orderedIntSet* s1, const orderedIntSet* s2, orderedIntSet* hash) {
	if (hash->count != 0) {
		//if the passed hash set has values stored in it already then is invalid for funtion use 
		printf("--------------INVALID SET ENTERY---------------\n\n");
		printf("Passed hash set already has elements included in in\n\n");
		return ;
	}
	else {
		int localcounter = 0;
		gotoHead(s1);//go to the start of each set 
		gotoHead(s2);
		gotoNextNode(s1);
		gotoNextNode(s2);
		while (localcounter != s2->count) {//runs while our counter is smaller than the max of the two given sets count
			//find out if first number 
			if (isInSet(s1, s2->current->data) == NUMBER_ALREADY_IN_SET) {
				addElement(hash, s2->current->data);// number is in set so we add it to our hash set 
				gotoNextNode(s2);// go to our next node in s2
			}
			else {
				gotoNextNode(s2);// number is not in s1 so we move to our next node 
			}
			localcounter++;// intirate our local couner 
		}
		return hash;
	}
	


}

/**
 * @brief     Find the union of two sets: Computes the union of two sets and stores the result in a third set.
 *
 * @param     s1  This is the first set
 * @param     s2  This is the second set
 * 
 * @return    Returns a new intSet that contains the result of the union of s1 and s2.
 */

orderedIntSet* setUnion(const orderedIntSet* s1, const orderedIntSet* s2) {

}

/**
 * @brief     Find the difference between two sets: Computes the difference of two sets and stores the result in a third set.
 *
 * @param     s1  This is the first set
 * @param     s2  This is the second set
 * 
 * @return    Returns a new object of class intSet that contains the result of the difference of s1 and s2.
 */

orderedIntSet* setDifference(const orderedIntSet* s1, const orderedIntSet* s2) {

}

/**
 * @brief     Print the set: Prints the set in format {Num_1, Num_2, Num_3, . . ., Num_n}
 *
 * @param     s  This is the set to be printed.
 * 
 * @return    Returns the value ALLOCATION ERROR in all methods if an error from the dynamic data structure prevents inserting new elements.
 */

setReturnValue printToStdout(const orderedIntSet* s) {

}
setReturnValue isInSet(const orderedIntSet* s, int num) {
	setReturnValue result = NUMBER_ALREADY_IN_SET;
	int localcounter = 0;
	gotoHead(s);
	gotoNextNode(s);
	while (s->current->data != num) {
		if (localcounter = s->count) {
			result = NUMBER_NOT_IN_SET;
			break;
		}

		else {
			localcounter++;
			gotoNextNode(s);
		}

	}
	return result;
}