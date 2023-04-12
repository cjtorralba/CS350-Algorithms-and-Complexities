# Algorithms and Complexities - CS350 - David Ely
Office: FAB 120-17
Hours: TBA

Text: Introduction to the Design and Analysis of Algorithms, Third Edition, Anany Levitin

Grading Policy:
- Homework/Lab: 30% (lowest score will be dropped)
- Midterm: 35% of frade
- Final: 35% of grade
- 0 on either the final or the midterm will result in a failure of the class


## Notes 04/04/2023
What is a computer algorithms?
- A set of instruction

Sorting algorithms:
- Merge sort
- Bubble
- Quick
- Selection
- BOGO

In Algorithms there are two things we care about
- **Time complexity**
  - How much constant time operation was there?
  - Ex: x = x + 1;

- **Space complexity:**
  - How much memory overhead are we using?

To measure either Time or Space complexity we use:
-   Asymptotic Analysis, aka: Big '0'

## Notes 03/12/2023: 

**Homework, due next week Wednesday before class (04/19/2023):**
- Merge sort
- To canvas, upload a .c or .cpp file
- From scratch, a single file
- **Input**:
  - n: where n is the amount of data
  - data: double data type, any numbers you want
  - Something like this:
```c 
int n;
double x[1000], data;

scanf("%d", &n); // n is number of data item the user will input next

for( int i = 0; i < n ++i) {
    scanf("%lf", &data);
    x[i] = data;
}
```
- **Output**:
  - Print the unsorted data
  - Run merge sort
  - Print data again

### Heap Sort:

T(n) = n * lg(n)

|   | 0  |1 |2 |3 |4 |5 |6 |7 |8 |9 | 10 | 11 | 12 | 13 | 14 |
|---|----|---|---|---|---|---|---|---|---|---|----|----|------|----|----|
| A |95 | 83 | 74 | 80 | 50 | 62 | 70 | 43 | 76 | 49 | 15 | 12 | 60 | 14 | 64 |
```
              95              
           /      \           
      83              74      
     /  \            /  \     
  80      50      62      70  
 /  \    /  \    /  \    /  \
43  76  49  15  12  60  14  65
```

So what is the index of the left child of any given node?
- **2x + 1**

The right child?
- **2x + 2**

Now what is the parents index from a given child?
- $$ x-1 /over 2 $$