#pragma once

#ifndef COLLECTION2D_BASET_H
#define COLLECTION2D_BASET_H

#include <vector>

namespace jrl{
	
	template <typename T>
	class Collection2D_BaseT{

	public:

		//typedefs
		typedef typename std::vector<T>::iterator objIt;

		int numOfObjects;

		void initBase(int cols, int rows);

		Collection2D_BaseT();
/*
		Collection2D_BaseT(objIt _begin, objIt _end);
		*/
		///@todo Create constructor that accepts begin and end iterators
		virtual ~Collection2D_BaseT();

		int getRows() const;
		int getCols() const;



		objIt lookUp(const objIt& it) const;
		objIt lookDown(const objIt& it) const;
		objIt lookLeft(const objIt& it) const;
		objIt lookRight(const objIt& it) const;

		objIt lookUp(const objIt& it, int positions) const;
		objIt lookDown(const objIt& it, int positions) const;
		objIt lookLeft(const objIt& it, int positions) const;
		objIt lookRight(const objIt& it, int positions) const;

		void goUp(objIt& it);
		void goDown(objIt& it);
		void goLeft(objIt& it);
		void goRight(objIt& it);

		void goUp(objIt& it, int positions);
		void goDown(objIt& it, int positions);
		void goLeft(objIt& it, int positions);
		void goRight(objIt& it, int positions);

		//bool goUp_s(objIt& it);
		//bool goDown_s(objIt& it);
		//bool goLeft_s(objIt& it);
		//bool goRight_s(objIt& it);

		//bool goUp_s(objIt& it, int positions);
		//bool goDown_s(objIt& it, int positions);
		//bool goLeft_s(objIt& it, int positions);
		//bool goRight_s(objIt& it, int positions);

		//getLineStart();
		//getLineEnd();
		//getColStart();
		//getColEnd();
	protected:

		//objIt beginIt;
		//objIt endIt;

		//void setCollectionLimits(objIt _beginIt, objIt _endIt);

		int gridCols;
		int gridRows;

	};


	//Implementation

	template <typename T>
	Collection2D_BaseT<T>::Collection2D_BaseT(){
	}

	//template <typename T>
	//Collection2D_BaseT<T>::Collection2D_BaseT(objIt _begin, objIt _end){

	//	beginIt = _begin;
	//	endIt = _end;

	//}
	
	template <typename T>
	Collection2D_BaseT<T>::~Collection2D_BaseT(){
	}

	template <typename T>
	void Collection2D_BaseT<T>::initBase(int cols, int rows){
		gridCols = cols;
		gridRows = rows;
		numOfObjects = gridCols*gridRows;
	}
	
	template <typename T>
	inline int Collection2D_BaseT<T>::getRows() const{
		return gridRows;
	}

	template <typename T>
	inline int Collection2D_BaseT<T>::getCols() const{
		return gridCols;
	}

	//Additional Iterator operations



	//Note: the objIt typedef is not working on return types, the whole definition is udsed
	//typedef typename std::vector<T>::iterator objIt

	//Non modifying
	template <typename T>
	inline typename std::vector<T>::iterator Collection2D_BaseT<T>::lookUp(const objIt& it) const{
		return it - gridCols;
	}

	template <typename T>
	inline typename std::vector<T>::iterator Collection2D_BaseT<T>::lookDown(const objIt& it) const{
		return it + gridCols;
	}
	template <typename T>
	inline typename std::vector<T>::iterator Collection2D_BaseT<T>::lookLeft(const objIt& it) const{
		return it - 1;
	}

	template <typename T>
	inline typename std::vector<T>::iterator Collection2D_BaseT<T>::lookRight(const objIt& it) const{
		return it + 1;
	}

	//Non modifying with step
	template <typename T>
	inline typename std::vector<T>::iterator Collection2D_BaseT<T>::lookUp(const objIt& it, int positions) const{
		return it - positions*gridCols;
	}

	template <typename T>
	inline typename std::vector<T>::iterator Collection2D_BaseT<T>::lookDown(const objIt& it, int positions) const{
		return it + positions*gridCols;
	}
	template <typename T>
	inline typename std::vector<T>::iterator Collection2D_BaseT<T>::lookLeft(const objIt& it, int positions) const{
		return it - positions;
	}

	template <typename T>
	inline typename std::vector<T>::iterator Collection2D_BaseT<T>::lookRight(const objIt& it, int positions) const{
		return it + positions;
	}

	//Modifying
	template <typename T>
	inline void Collection2D_BaseT<T>::goUp(objIt& it){
		it-=gridCols;
	}

	template <typename T>
	inline void Collection2D_BaseT<T>::goDown(objIt& it){
		it+=gridCols;
	}
	template <typename T>
	inline void Collection2D_BaseT<T>::goLeft(objIt& it){
		--it;
	}

	template <typename T>
	inline void Collection2D_BaseT<T>::goRight(objIt& it){
		 ++it;
	}

	//Modifying with step
	template <typename T>
	inline void Collection2D_BaseT<T>::goUp(objIt& it, int positions){
		it-=positions*gridCols;
	}

	template <typename T>
	inline void Collection2D_BaseT<T>::goDown(objIt& it, int positions){
		it+=positions*gridCols;
	}
	template <typename T>
	inline void Collection2D_BaseT<T>::goLeft(objIt& it, int positions){
		it-=positions;
	}

	template <typename T>
	inline void Collection2D_BaseT<T>::goRight(objIt& it, int positions){
		 it+=positions;
	}


	////Modifying, Safe
	//template <typename T>
	//inline bool Collection2D_BaseT<T>::goUp_s(objIt& it){
	//	if(it-beginIt>=gridCols){
	//		it-=gridCols;
	//		return true;
	//	}
	//	return false;
	//}

	//template <typename T>
	//inline bool Collection2D_BaseT<T>::goDown_s(objIt& it){
	//	if(endIt-it>gridCols){
	//		it+=gridCols;
	//		return true;
	//	}
	//	return false;
	//}
	//template <typename T>
	//inline bool Collection2D_BaseT<T>::goLeft_s(objIt& it){
	//	if(it-beginIt>=1){
	//		--it;
	//		return true;
	//	}
	//	return false;
	//}

	//template <typename T>
	//inline bool Collection2D_BaseT<T>::goRight_s(objIt& it){
	//	//if(endIt-it>1){
	//	if(std::distance(endIt,it)>1){
	//		++it;
	//		return true;
	//	}
	//	return false;
	//}

	////Modifying with step, safe
	//template <typename T>
	//inline bool Collection2D_BaseT<T>::goUp_s(objIt& it, int positions){
	//	int elements = positions*gridCols;
	//	if(it-beginIt>=elements){
	//		it-=elements;
	//		return true;
	//	}
	//	return false;
	//}

	//template <typename T>
	//inline bool Collection2D_BaseT<T>::goDown_s(objIt& it, int positions){
	//	int elements = positions*gridCols;
	//	if(endIt-it>elements){
	//		it+=elements;
	//		return true;
	//	}
	//	return false;
	//}
	//template <typename T>
	//inline bool Collection2D_BaseT<T>::goLeft_s(objIt& it, int positions){
	//	if(it-beginIt>=positions){
	//		it-=positions;
	//		return true;
	//	}
	//	return false;
	//}

	//template <typename T>
	//inline bool Collection2D_BaseT<T>::goRight_s(objIt& it, int positions){
	//	if(endIt-it>positions){
	//		it+=positions;
	//		return true;
	//	}
	//	return false;
	//}

	//template <typename T>
	//inline void Collection2D_BaseT<T>::setCollectionLimits(objIt _beginIt, objIt _endIt){
	//	beginIt = _beginIt;
	//	endIt = _endIt;
	//}
}

#endif