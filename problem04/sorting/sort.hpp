#ifndef _SORT_HPP
#define _SORT_HPP

#include "List.hpp"

template<typename T> 
inline void quick_sort(List<T>& list, int first, int last)
{
	if (first < last)
	{
		int pivot = partition(list, first, last);
		quick_sort(list, first, pivot - 1);
		quick_sort(list, pivot + 1, last);
	}
}

/** Partition a sub-list by moving items relative to the pivot.
 * Always choose the first item as the pivot.
 * Sub-list is specified with inclusive indices first and last.
 * Assume no duplicates.
 * @param first index of the first item in the sub-list to be partitioned (inclusive)
 * @param last index of the last item in the sub-list to be partitioned (inclusive)
 * @return index of the pivot item after partitioning */
template <typename T>
inline int partition(List<T>& list, int first, int last) {

	//check validity of indexes
	if (first < 0 || last >= list.getLength() || first > last)
	{
		throw std::out_of_range("partition index invalid, must be between 0 and length, first must be less than last and first must be >= 0");
	}

	//choose first item as pivot
	T pivot = list.getEntry(first);

	//index of first item greater than pivot
	int i = first + 1;

	//index of first item less than pivot
	int j = last;

	while (i <= j)
	{
		//move i right until item at i is greater than pivot
		while (i <= j && list.getEntry(i) <= pivot)
		{
			i++;
		}
		//move j left until item at j is less than pivot
		while (i <= j && list.getEntry(j) > pivot)
		{
			j--;
		}
		//if i is less than j, swap items at i and j
		if (i < j)
		{
			//move item from i to j, shifting elements
			list.moveEntry(i,j);
			//move item from j-1 to i, shifting elements
			list.moveEntry(j-1,i);
			i++;
			j--;

		}
	}
	//move pivot from first to final sorted position at j
	list.moveEntry(first,j);

	//return index of pivot
	return j;
}

#endif
