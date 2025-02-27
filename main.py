import random

def human_sort(alist): 
    if not alist: return alist

    minval = min(alist)
    alist.remove(minval)
    print(minval, alist)
    return [minval] + human_sort(alist)


def selection_sort(alist): 
    n =  len(alist)
    for i in  range(n-1):
      unsorted = alist[i:] 
      smallest =  min(unsorted) 
      min_i = alist.index(smallest, i)
      alist[i], alist[min_i]  = alist[min_i], alist[i]  
      print("intermediary", alist)
    return alist 


def selection_sort2(alist):
    n = len(alist)
    # STEP 0 - iterate through the list
    for i in range(n-1):
        min_idx = i 
        # STEP 1 - update mini_i with index 
        # of min value in unsorted alist[i+1:]
        for j in range(i+1, n): 
            if alist[j] < alist[min_i]: 
                min_idx = j
        # STEP 2 - swap it with element at index 'i'
        if min_idx != i:
            alist[i], alist[min_idx] = \
            alist[min_idx], alist[i]
    return alist


alist = list(range(1, 6))
random.shuffle(alist)

print("Before sorting", alist)

alist = human_sort(alist)
print("After Human sorting", alist)

random.shuffle(alist)
print("\n=======\n", alist)
print("Before sorting", alist, "\n\n")
alist = selection_sort(alist)
print("After selectionsort", alist)

random.shuffle(alist)
print("\n=======\n", alist)
print("Before sorting", alist, "\n\n")
alist = selection_sort(alist)
print("After selectionsort2", alist)




