// Program Information ////////////////////////////////////////////////////////
/**
 * @file queueN.cpp
 * 
 * @details The queueN Class.
 *
 * @version 1.00 
 *          Jia Li (12 Dec. 2016)
 *          Updated with all member functions.
 *
 *
 * @Note N/A
 */

#include <iostream>
#include "queueN.h" 

using namespace std; 

/**
 * @function NodeQ parameterized constructor
 *
 * @details initialized all members with passed in values
 *          
 */
NodeQ::NodeQ(int nData, NodeQ* ptr)
{
   data = nData;
   next = ptr; 
}

/**
 * @function the default constructor.
 *
 * @details initialize all members with values.
 *          
 */
queueN::queueN()
{
   front = NULL; 
   rear = NULL; 
}

/**
 * @function destructor.
 *
 * @details deallocate memory and clear values from members.
 *          
 */
queueN::~queueN()
{
   clear(); 
}

/**
 * @function empty function.
 *
 * @details check if the queue is empty.
 *          
 */
bool queueN::empty() const 
{
   if( front == NULL )
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
bool queueN::full() const 
{
   return false; 
}

/**
 * @function enqueue function
 *
 * @details enqueue data from the rear of the queue
 *          
 */
bool queueN::enqueue(int nData)
{
   if( empty() )
   {
      front = rear = new NodeQ(nData, NULL); 
   }
   else
   {
      rear = rear->next;
      rear = new NodeQ(nData, NULL); 
   }
   return true; 
}

/**
 * @function dequeue function
 *
 * @details dequeue data from the front of the queue
 *          
 */
bool queueN::dequeue()
{
   NodeQ* tempPtr = NULL; 

   if( empty() )
   {
      return false; 
   }
   else if( front == rear )
   {
      delete front; 
      front = rear = NULL; 
   }
   else 
   {
      tempPtr = front; 
      front = front->next; 
      delete tempPtr; 
      tempPtr = NULL;
   }
   return true; 
}

/**
 * @function getFront function
 *
 * @details extract the value from the front
 *          
 */
int queueN::getFront()
{
   if( empty() )
   {
      return -1; 
   }
   else 
   {
      return front->data; 
   }
}

/**
 * @function clear function
 *
 * @details clear all data from the queue
 *          
 */
bool queueN::clear()
{
   if( empty() )
   {
      return false; 
   }
   else 
   {
      while( empty() == false )
      {
         dequeue(); 
      }
      front = rear = NULL;
      return true; 
   }
}

/**
 * @function overload equality operator function
 *
 * @details check if two queues are equal
 *          
 */
bool queueN::operator==(const queueN& src) const
{
   NodeQ* tempPtr = front; 
   NodeQ* tempSrcPtr = src.front;  

   if( ( empty() ) && ( src.empty() ) )
   {
      return true; 
   }
   else if( ( empty() ) && ( !src.empty() ) )
   {
      return false; 
   }
   else if( ( !empty() ) && ( src.empty() ) )
   {
      return false; 
   }

   while( ( tempPtr != NULL ) || ( tempSrcPtr != NULL ) )
   {
      if( tempPtr->data != tempSrcPtr->data ) 
         return false; 
      tempPtr = tempPtr->next;
      tempSrcPtr = tempSrcPtr->next;
   }
   
   if( ( tempPtr != NULL ) || ( tempSrcPtr != NULL ) )
   {
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
queueN& queueN::operator=(const queueN& src)
{
   NodeQ* tempPtr = NULL; 

   if( this != &src )
   {
      clear(); 

      if( src.empty() )
      {
         return *this; 
      }
      
      tempPtr = src.front; 
      
      while( tempPtr != NULL )
      {
         enqueue( tempPtr->data ); 
         tempPtr = tempPtr->next;
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
queueN::queueN( const queueN& src )
{
   front = NULL;
   rear = NULL; 
   *this = src; 
}

/**
 * @function overload extraction operator function
 *
 * @details extracts all data from the queue onto the output stream
 *          
 */
ostream& operator<<(ostream& output, const queueN& src)
{
   NodeQ* tempPtr = src.front; 
   
   while( tempPtr != NULL )
   {
      output << tempPtr->data << " "; 
      tempPtr = tempPtr->next;
   }
   return output; 
}

