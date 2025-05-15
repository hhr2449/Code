#ifndef PALSTRING_H
#define PALSTRING_H
#include <iostream>
#include <cstring>
class PalString {
public:
    char* data_;    //A character array that stores strings

    //TODO [Optional] : define other useful variables

    //TODO: finish the constructor
    PalString(const char* pStr) {
      data_ = new char[2*strlen(pStr) + 1];//创建一个字符数组，大小为两倍字符串长度+1，并且用data_接收
      int p = 0;
      for(p = 0; p < strlen(pStr); p++) {
         data_[p] = pStr[p];
      } 
      for(int i = strlen(pStr) - 1; i >= 0; i--,p++) {
         data_[p] = pStr[i];
      }
      data_[p] = '\0';
    }

    //TODO: finish the destructor
    ~PalString(){
      delete[] data_;
    }

 	//TODO: finish the function getString
    char * getString(){
      return data_;
    }

 	//TODO: finish the function changeString
    void changeString(const char* pStr){
      delete[] data_;//先删除data_指向的字符数组，然后让data_指向新的字符数组
      data_ = new char[2*strlen(pStr) + 1];//创建一个字符数组，大小为两倍字符串长度+1，并且用data_接收
      int p = 0;
      for(p = 0; p < strlen(pStr); p++) {
         data_[p] = pStr[p];
      } 
      for(int i = strlen(pStr) - 1; i >= 0; i--,p++) {
         data_[p] = pStr[i];
      }
      data_[p] = '\0';
    }
 
 	//TODO: finish the copy constructor
	PalString(const PalString& rhs){
      data_ = new char[strlen(rhs.data_) + 1];
      for (int i = 0; i < strlen(rhs.data_); i++) {
         data_[i] = rhs.data_[i];
      }
      data_[strlen(rhs.data_)] = '\0';
	}

 	//TODO: override the operator <<
   friend std::ostream& operator<<(std::ostream& out, const PalString& rhs); 
};
   std::ostream& operator<<(std::ostream& out, const PalString& rhs) {
      out << rhs.data_;
      return out;
   }

#endif // #ifndef PALSTRING_H