#pragma once
#include<iostream>

using namespace std;

template <typename T>

class min_heap
{
    public:
        T arr[500];
        int size;

        min_heap()
        {
            // arr[0] = NULL;
            size = 0;
        }

        void insert( T val )
        {
            size++;
            int index = size;
            arr[index] = val;

            while( index > 1 )
            {
                int parent = index/2;

                if( arr[parent] > val )
                {
                    swap(arr[index],arr[parent]);
                    index = parent;
                }
                else
                    return;
            }
        }

        T top()
        {
            return arr[1];
        }

        bool empty()
        {
            if( size == 0 )
                return true;

            return false;
        }

        void pop()
        {
            arr[1] = arr[size];
            size--;

            int index = 1;

            while(true)
            {
                int left = 2*index;
                int right = 2*index + 1;

                if( left <= size && arr[left] < arr[index] )
                {
                    swap(arr[left],arr[index]);
                    index = left;
                }
                else if( right <= size && arr[right] < arr[index] )
                {
                    swap(arr[right],arr[index]);
                    index = right;
                }
                else
                    return;
            }
        }

        void print_heap()
        {
            cout<<endl;
            for( int i=1; i<=size; i++ )
            {
                cout<<arr[i]<<" ";
            } 
            cout<<endl;
        }
};