// Program Information ////////////////////////////////////////////////////////
/**
 * @file queueA.cpp
 * 
 * @details The queueA Class.
 *
 * @version 1.00 
 *          Jia Li (12 Dec. 2016)
 *          Updated with all member functions.
 *
 *
 * @Note N/A
 */

#include <iostream> 
#include "queueA.h"

using namespace std; 

/**
 * @function the default constructor.
 *
 * @details initialize all members with values.
 *          
 */
queueA::queueA(int nMax)
{
   max = nMax; 
   front = -1; 
   rear = -1;
   data = new int[max]; 
}

/**
 * @function destructor.
 *
 * @details deallocate memory and clear values from members.
 *          
 */
queueA::~queueA()
{
   clear(); 
}

/**
 * @function empty function.
 *
 * @details check if the queue is empty.
 *          
 */
bool queueA::empty() const
{
   if( front == -1 )
   {
      return true; 
   }
   return false; 
}

/**
 * @function full function
 *
 * @details check if the queue is full.
 *          
 */
bool queueA::full() const
{
   if( rear == max - 1 )
   {
      return true; 
   }
   return false; 
}

/**
 * @function getFront function
 *
 * @details extract the value from the front
 *          
 */
int queueA::getFront()
{
   if( empty() )
   {
      return -1; 
   }
   return data[0];
}

/**
 * @function enqueue function
 *
 * @details enqueue data from the rear of the queue
 *          
 */
bool queueA::enqueue( int nData )
{
   if( full() )
   {
      return false; 
   }
   else if( empty() )
   {
      ++front;
      data[++rear] = nData; 
   }
   else
   {
      data[++rear] = nData; 
   }
   return true; 
}

/**
 * @function dequeue function
 *
 * @details dequeue data from the front of the queue
 *          
 */
bool queueA::dequeue()
{
   if( empty() )
   {
      return false; 
   }
   else if( front == rear )
   {
      delete[] data;
      data = NULL; 
      front = rear = -1;
      max = 0; 
   }
   else 
   {
      for( int index = 0; index < rear; index++ )
      {
         data[index] = data[index+1]; 
      }
      rear--; 
   }
   return true;
}

/**
 * @function clear function
 *
 * @details clear all data from the queue
 *          
 */
bool queueA::clear()
{
   if( empty() )
   {
      return false; 
   }
   delete[] data; 
   data = NULL;
   front = rear = -1; 
   max = 0; 
   
   return true; 
}

/**
 * @function overload equality operator function
 *
 * @details check if two queues are equal
 *          
 */
bool queueA::operator==(const queueA& src) const
{
   if( rear != src.rear )
   {
      return false; 
   }
   if( empty() && src.empty() )
   {
      return true; 
   }
   for( int index = 0; index <= rear; index++ )
   {
      if( data[index] != src.data[index] )
         return false;
   }
   return true; 
}

/**
 * @function overload assignment operator
 *
 * @details copies from one queue onto another
 *          
 */
queueA& queueA::operator=(const queueA& src)
{
   if( this != &src )
   {
      clear(); 
      if( src.empty() )
      {
         return *this; 
      }
   
      max = src.max; 
      front = src.front; 
      rear = src.rear; 
      data = new int[max];
    
      for( int index = 0; index <= rear; index++ )
      {
         data[index] = src.data[index]; 
      }
   }
   return *this; 
}

/**
 * @function copy constructor
 *
 * @details copies from one queue onto another
 *          
 */
queueA::queueA(const queueA& src)
{
   max = src.max; 
   front = src.front; 
   rear = src.rear; 
   data = new int[max]; 

   for( int index = 0; index <= rear; index++ )
   {
      data[index] = src.data[index]; 
   }
}

/**
 * @function overload extraction operator function
 *
 * @details extracts all data from the queue onto the output stream
 *          
 */
ostream& operator<<(ostream& output, const queueA& src)
{
   for( int index = 0; index <= src.rear; index++ )
   {
      output << src.data[index] << " "; 
   }
  
   return output; 
}
