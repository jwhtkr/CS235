#include "QS.h"

using namespace std;

void sort3(int *, int *, int *); //helper sort function

/*
* sortAll()
*
* Sorts elements of the array.  After this function is called, every
* element in the array is less than or equal its successor.
*
* Does nothing if the array is empty.
*/
void QS::sortAll()
{
    int pivot (0), oldRight(right), oldLeft(left);
    if (left < right && QS::getSize() > 1 && number < 100 && (right - left) > 0)
    {
        number++;
        // cout << "in sortAll (" << left << ", " << right << ", ";
        pivot = QS::medianOfThree(left,right);
        // cout << pivot << ", ";
        pivot = QS::partition(left, right, pivot);
        // cout << pivot << ") " << endl;
        // if (pivot >= 0)
        // {
            // left = oldLeft;
            right = pivot - 1;
            // cout << left << ", " << right << "...";
            QS::sortAll();
            left = pivot + 1;
            right = oldRight;
            // cout << left << ", " << right << "..." << endl;
            QS::sortAll();
        // }
    }
    else {return;}
}

/*
* medianOfThree()
*
* The median of three pivot selection has two parts:
*
* 1) Calculates the middle index by averaging the given left and right indices:
*
* middle = (left + right)/2
*
* 2) Then bubble-sorts the values at the left, middle, and right indices.
*
* After this method is called, data[left] <= data[middle] <= data[right].
* The middle index will be returned.
*
* Returns -1 if the array is empty, if either of the given integers
* is out of bounds, or if the left index is not less than the right
* index.
*
* @param left
* 		the left boundary for the subarray from which to find a pivot
* @param right
* 		the right boundary for the subarray from which to find a pivot
* @return
*		the index of the pivot (middle index); -1 if provided with invalid input
*/
int QS::medianOfThree(int left, int right)
{
    // cout << "in median of three...";
    if (arrayPosition == 0 || left < 0 || right >= arrayPosition || left >= right)
    {
        return -1;
    }
    else
    {
        int middle = (left + right) / 2;
        if (middle != left && middle != right)
        {
            sort3(arrayptr + left, arrayptr + middle, arrayptr + right);
            return middle;
        }
        else
        {
            if(*(arrayptr + left) > *(arrayptr + right))
            {
                int temp = *(arrayptr + left);
                *(arrayptr + left) = *(arrayptr + right);
                *(arrayptr + right) = temp;
                return middle;
            }
            else {return middle;}
        }
    }
}

/*
* Partitions a subarray around a pivot value selected according to
* median-of-three pivot selection.  Because there are multiple ways to partition a list,
* we will follow the algorithm on page 611 of the course text when testing this function.
*
* The values which are smaller than the pivot should be placed to the left
* of the pivot; the values which are larger than the pivot should be placed
* to the right of the pivot.
*
* Returns -1 if the array is null, if either of the given integers is out of
* bounds, or if the first integer is not less than the second integer, or if the
* pivot is not within the sub-array designated by left and right.
*
* @param left
* 		the left boundary for the subarray to partition
* @param right
* 		the right boundary for the subarray to partition
* @param pivotIndex
* 		the index of the pivot in the subarray
* @return
*		the pivot's ending index after the partition completes; -1 if
* 		provided with bad input
*/
int QS::partition(int left, int right, int pivotIndex)
{
    if(arraySize == 0 || arrayPosition == 0 || left < 0 || right >= arraySize 
        || left >= right || pivotIndex < left || pivotIndex > right)
    {
        return -1;
    }
    else
    {
        int temp;
        if (pivotIndex != left)
        {
            temp = *(arrayptr + pivotIndex);
            *(arrayptr + pivotIndex) = *(arrayptr + left);
            *(arrayptr + left) = temp;
        }
        int up(left + 1), down(right);
        do
        {
            while(*(arrayptr + up) <= *(arrayptr + left) && up < right) {up++;}
            while(*(arrayptr + down) > *(arrayptr + left) && down > left) {down--;}
            if (up < down)
            {
                temp = *(arrayptr + up);
                *(arrayptr + up) = *(arrayptr + down);
                *(arrayptr + down) = temp;
            }
        } while (up < down);
        if (down != left)
        {
            temp = *(arrayptr + left);
            *(arrayptr + left) = *(arrayptr + down);
            *(arrayptr + down) = temp;
        }
        return down;
    }
}

/*
* Produces a comma delimited string representation of the array. For example: if my array
* looked like {5,7,2,9,0}, then the string to be returned would look like "5,7,2,9,0"
* with no trailing comma.  The number of cells included equals the number of values added.
* Do not include the entire array if the array has yet to be filled.
*
* Returns an empty string, if the array is NULL or empty.
*
* @return
*		the string representation of the current array
*/
string QS::getArray() const
{
    // cout << "in get array...";
    ostringstream ss;
    if (arrayptr == NULL || QS::getSize() == 0)
    {
        return "";
    }
    else
    {
        for (int i = 0; i < QS::getSize(); i++)
        {
             ss << *(arrayptr + i);
            //  cout << *(arrayptr + i);
             if (i < QS::getSize()-1)
             {
                 ss << ",";
                 //cout << ",";
             }
        }
        //cout << endl;
    }
    return ss.str();
}

/*
* Returns the number of elements which have been added to the array.
*/
int QS::getSize() const
{
    // cout << "in get size...";
    return arrayPosition;
}

/*
* Adds the given value to the end of the array starting at index 0.
* For example, the first time addToArray is called,
* the give value should be found at index 0.
* 2nd time, value should be found at index 1.
* 3rd, index 2, etc up to its max capacity.
*
* If the array is filled, do nothing.
* returns true if a value was added, false otherwise.
*/
bool QS::addToArray(int value)
{
    // cout << "in add to array ...";
    if (arrayPosition < arraySize)
    {
        arrayptr[arrayPosition] = value;
        arrayPosition++;
        right = arrayPosition - 1;
        return true;
    }
    else {return false;}
}

/*
* Dynamically allocates an array with the given capacity.
* If a previous array had been allocated, delete the previous array.
* Returns false if the given capacity is non-positive, true otherwise.
*
* @param
*		size of array
* @return
*		true if the array was created, false otherwise
*/
bool QS::createArray(int capacity)
{
    // cout << "in creat array...";
    if (capacity > 0 && arrayptr == NULL)
    {
        arraySize = capacity;
        arrayptr = new int[capacity];
        arrayPosition = 0;
        left = 0;
        right = arrayPosition - 1;
        number = 0;
        return true;
    }
    else if (arrayptr != NULL)
    {
        QS::clear();
        return QS::createArray(capacity);
    }
    else {return false;}
}

/*
* Resets the array to an empty or NULL state.
*/
void QS::clear()
{
    // cout << "in clear...";
    delete[] arrayptr;
    // cout << "array deleted...";
    arrayptr = NULL;
    // cout << "ptr nulled...";
    arrayPosition = 0;
    arraySize = 0;
    left = 0;
    right = 0;
    // cout << "position and size at 0...completely cleared..." << endl;
}

//Helper sort function
void sort3 (int * left, int * middle, int * right)
{
    // cout << "in sort3...";
    int temp;
    if (*left > *middle)
    {
        temp = *middle;
        *middle = *left;
        *left = temp;
    }
    if (*middle > *right)
    {
        temp = *middle;
        *middle = *right;
        *right = temp;
    }
    if (*left > *middle)
    {
        temp = *middle;
        *middle = *left;
        *left = temp;
    }
    return;
}