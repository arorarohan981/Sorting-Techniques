/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RadixSort.h
 * Author: rohan
 *
 * Created on 26 July 2021, 6:17 PM
 */

#ifndef RADIXSORT_H
#define RADIXSORT_H
#define NO_OF_ELEMENTS 5
#define NO_OF_BUCKETS 10
/* Radix Sort also called as Bucket Sort.
 * Comparing 12 digit Number takes a lot of time ,where 1 digit number takes less
 * Time.
 * In Radix/Bucket Sort we will not compare the elements even once.
 * 
 * Here we arrange the numbers in first pass by comparing their unit's place then
 * pop out elements from left to Right and Bottom to top and continue the process
 * until the last place is encountered and we get an sorted array.
 *(Until the digits of the largest Numbers).
 * 
 * Number of Passes of Radix/Bucket Sort is No of digits in the largest Number 
 * of list.
 * 
 * Space Required is Constant in the Algorithm.
 * Time Complexity is  O(d*(n+b)) where d is the number of digits in the given list,
 *  n is the number of elements in the list, and b is the base or bucket size used
 * 
 * We Can only use Radix Sort with Positive Integer Values.
 *
 */
class RadixSort{
    
    
    
public:
    /*
     * Radix Sort takes in array of type int as a parameter and size of array
     * as the 2nd parameter,Boolean Value True if we want array in ascending order
     * or False if we want array in descending order
     */
   void static radixSort(int array[], size_t arraySize,bool order) {
        std::cout<<std::endl<<"Elements Before Sorting are "<<std::endl;
        displayArray(array,arraySize);
       
    int i;
    int j;
    int k;
    int counter;
    int divisor ;
    int digitPlaceValue;
    int no_of_digits; // No of digits in largest number
    int largest ;
    int buckets[ NO_OF_BUCKETS ][ NO_OF_ELEMENTS ];

    //Assume the 1st element to be largest
    largest = array[0];
    //Find the largest element by comparing it against rest of the elements
    //starting from 2nd position
    for (i = 1; i < NO_OF_ELEMENTS; i++) {
        if (array[ i ] > largest) {
            largest = array[ i ];
        }
    }

    //Find number of digits in the largest number
    no_of_digits = 0;
    while (largest != 0) {
        largest /= 10;
        no_of_digits++;
    }
    
    counter = 1;
    divisor = 1; // Used to find the digit at placeValue(unit,tens,hundred...)
    while (counter <= no_of_digits) {
        initbukt(buckets); //reset the buckets after every pass
        
        for (i = 0; i < NO_OF_ELEMENTS; i++) {
//            Find the digit in the element
            digitPlaceValue = (array [ i ] / divisor) % 10;
//            Find the position in the bucket to insert the element
            for (j = 0; buckets[ digitPlaceValue ][ j ] != -1; j++);
//            Place the element in the bucket
            buckets[ digitPlaceValue ][ j ] = array[ i ];
        }
        
//      pop elements from all buckets and place them back into the array
        for (k = 0, i = 0; i < NO_OF_BUCKETS; i++) {
            for (j = 0; (buckets[i][j] != -1 && k < NO_OF_ELEMENTS); j++) {
                array[ k++ ] = buckets[ i ][ j ];
            }
        }
        divisor = divisor * 10;
        counter++;
    }
    
    if(!order){
        reversearr(array,arraySize);
    }
    //    To understand the change after every pass
    //    displayBuckets( buckets );
    //    To see the transformation happening after every pass
        std::cout<<std::endl<<"Elements After Sorting are "<<std::endl;
        displayArray(array,arraySize);
    return;
}

private: 
 /*Method to display buckets .Takes in 2-d Array as a paramater.*/   
void static displayBuckets(int buk[][NO_OF_ELEMENTS]) {
    printf("\nThe contents of the bucket\n");
    for (int i = 0; i < NO_OF_BUCKETS; i++) {
        printf("\n Bucket %d ]", i);
        for (int j = 0; j < NO_OF_ELEMENTS; j++) {
            printf("\t%d", buk[ i ][ j ]);
        }
    }
}


/*
         * It reverses the elements of the supplied array.
         */
        template <typename T>
        static void reversearr(T arr[],int size){
            
            T temp;
            int half=std::floor(size/2);
            
            for(int i=0;i<half;i++){
                temp=arr[i];
                arr[i]=arr[size-i-1];
                arr[size-i-1]=temp;
            }
            
        }

/*Initializes the buckets with value -1*/
void static initbukt(int buk[][NO_OF_ELEMENTS]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < NO_OF_ELEMENTS; j++) {
            buk[ i ][ j ] = -1;
        }
    }
    return;
}


/*Method used to display elements of the array.
 Takes in array of type int and arraySize as a parameter.*/
void static displayArray(int array[], size_t arraySize) {
    std::cout<<"Elements in array are : ";
            for (int i=0;i<arraySize;i++){
                std::cout<<" "<<array[i]<<" ";
            }
   
    return;
}   
    
        
     
        
};


#endif /* RADIXSORT_H */

