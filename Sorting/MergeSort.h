/* 
 * File:   MergeSort.h
 * Author: rohan
 *
 * Created on 26 July 2021, 8:57 AM
 */

#ifndef MERGESORT_H
#define MERGESORT_H
#include <iostream>

/*
 * Merge Sort uses Divide and Conquer Strategy.
 * We Divide the array into partition Recursively until we get array of size 1.
 * In each pass we divide the array by size n/2.
 * In Conquer Phase,We Recursively Sort Each Partition, and Merge the partitions
 * by taking union of the partitions. (while comparing each element of partition
 * So we get the sorted merged array from partitions)
 * 
 * Time Complexity is O(nlogn)
 * The height h of the merge-sort tree is O(log n).(as at each recursive call we
 * divide in half the array)
 * The overall amount of work done at the nodes of depth i is O(n).
 * Hence Total running time is O(nlogn). 
 */


class MergeSort{
    
public :
    /* Sort Method takes in Array of any Type T (which has <,> operator overloaded ),
     * Number of Elements of type int  and 
     * a Boolean value (True if we want the elements to be sorted in Ascending order 
     * or False if we want the elements to be sorted in Descending Order 
     * as a Paramater.
     */
    template <typename T>
    void static sort(T unsorted_arr[],int size,bool sorting){
        std::cout<<std::endl<<"Elements Before Sorting are : "<<std::endl;
        printarray(unsorted_arr,size);
        
        T temp_arr[size];
        m_sort(unsorted_arr,temp_arr,0,size-1);
        
        if(!sorting){
            reversearr(unsorted_arr,size);
        }
        std::cout<<std::endl<<"Elements After Sorting are : "<<std::endl;
        printarray(unsorted_arr,size);
        
    }
            
            
private:
    /*Print Array methods takes in Array of any Type T ,
         and No of Elements (type int) as a Parameter  */
        template <typename T>
        static void printarray(T arr[],int no_of_elements){
            std::cout<<"Elements in array are : ";
            for (int i=0;i<no_of_elements;i++){
                std::cout<<" "<<arr[i]<<" ";
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
        
        
        /*This Method divides the Array Recursively until we get array/list of size1.
         Once we get array/list of size 1 .We pass it in Merge Method.
         */
        template<typename T>
        void static m_sort(T orig_arr[],T temp[],int left,int right){
            int center;
            
            if(left<right){
                center=std::floor((left+right)/2);
                m_sort(orig_arr,temp,left,center);
                m_sort(orig_arr,temp,center+1,right);
                merge(orig_arr,temp,left,center+1,right);
            }
        }
        
        /* Merge Method Compares the "a" array i.e Original Array . With Elements
         * on the both sides of Partition.l_pos is index of starting position
         * of 1 partition.r_pos is starting index of second partition and 
         * right_end is end index of second partition with the array a.
         * They are stored in tmp_array and later after merging two partitions
         * they are stored in original array.
         */
        template<typename T>
        void static merge(T a[ ], T tmp_array[ ], int l_pos, int r_pos, int right_end){
       
        int i;
        int left_end;
        int num_elements;
        int tmp_pos;
        left_end = r_pos - 1;
        tmp_pos = l_pos;
        num_elements = right_end - l_pos + 1;

        /* main loop */

        while ((l_pos <= left_end) && (r_pos <= right_end)){
            if (a[l_pos] <= a[r_pos])
                tmp_array[tmp_pos++] = a[l_pos++];
            else
                tmp_array[tmp_pos++] = a[r_pos++];
        }
        while (l_pos <= left_end){ /* copy rest of first half */
            tmp_array[tmp_pos++] = a[l_pos++];
        }
        while (r_pos <= right_end){ /* copy rest of second half */
            tmp_array[tmp_pos++] = a[r_pos++];
        }   
        /* copy tmp_array back */
        for (i = 1; i <= num_elements; i++, right_end--){
            a[right_end] = tmp_array[right_end];
        }
        
        }
        
   
};

#endif /* MERGESORT_H */

