#pragma once

#ifndef MATRIX2DT_H
#define MATRIX2DT_H

#include "Collection2D_BaseT.h"

namespace jrl{

	template <typename T>
	class Matrix2DT:public Collection2D_BaseT<T>{
	public:

		//typedefs
		//typedef typename T::point_type point_type;
		//typedef typename std::vector<point_type>::iterator iterator;

		Matrix2DT();
		virtual ~Matrix2DT();

		void init(int cols, int rows);
		void init(int cols, int rows, T baseObject);
		std::vector<T>& getObjects();
		bool isValid(const objIt& it) const;


		bool goUp_s(objIt& it);
		bool goDown_s(objIt& it);
		bool goLeft_s(objIt& it);
		bool goRight_s(objIt& it);

		bool goUp_s(objIt& it, unsigned int positions);
		bool goDown_s(objIt& it, unsigned int positions);
		bool goLeft_s(objIt& it, unsigned int positions);
		bool goRight_s(objIt& it, unsigned int positions);

		bool verticalStep_s(objIt& it, int positions);
		bool horizontalStep_s(objIt& it, int positions);

	protected:

		std::vector<T> objects;
	};

	//Implementation
	template <typename T>
	Matrix2DT<T>::Matrix2DT()
	{
		//setCollectionLimits(objects.begin(), objects.end());
		//Collection2D_BaseT(objects.begin(), objects.end());
	}

	template <typename T>
	Matrix2DT<T>::~Matrix2DT(){
	}

	template <typename T>
	void Matrix2DT<T>::init(int cols, int rows){
		initBase(cols, rows);
		objects.clear();
		objects.insert(objects.end(), numOfObjects, T());
	}

	template <typename T>
	void Matrix2DT<T>::init(int cols, int rows, T baseObject){
		initBase(cols, rows);
		objects.clear();
		objects.insert(objects.end(), numOfObjects, baseObject);
	}
	
	template <typename T>
	inline std::vector<T>& Matrix2DT<T>::getObjects(){
		return objects;
	}

	template <typename T>
	bool Matrix2DT<T>::isValid(const objIt& it) const{
		return (it<objects.end() && it>=objects.begin());
	}


	//Modifying, Safe
	template <typename T>
	inline bool Matrix2DT<T>::goUp_s(objIt& it){
		if(it-objects.begin()>=gridCols){
			it-=gridCols;
			return true;
		}
		return false;
	}

	template <typename T>
	inline bool Matrix2DT<T>::goDown_s(objIt& it){
		if(objects.end()-it>gridCols){
			it+=gridCols;
			return true;
		}
		return false;
	}
	template <typename T>
	inline bool Matrix2DT<T>::goLeft_s(objIt& it){
		if(it-objects.begin()>=1){
			--it;
			return true;
		}
		return false;
	}

	template <typename T>
	inline bool Matrix2DT<T>::goRight_s(objIt& it){
		if(objects.end()-it>1){
		//if(std::distance(objects.end(),it)>1){
			++it;
			return true;
		}
		return false;
	}

	//Modifying with step, safe
	template <typename T>
	inline bool Matrix2DT<T>::goUp_s(objIt& it, unsigned int positions){
		unsigned int elements = positions*gridCols;
		if(it-objects.begin()>=elements){
			it-=elements;
			return true;
		}
		return false;
	}

	template <typename T>
	inline bool Matrix2DT<T>::goDown_s(objIt& it, unsigned int positions){
		int elements = positions*gridCols;
		if(objects.end()-it>elements){
			it+=elements;
			return true;
		}
		return false;
	}
	template <typename T>
	inline bool Matrix2DT<T>::goLeft_s(objIt& it, unsigned int positions){
		if(it-objects.begin()>=positions){
			it-=positions;
			return true;
		}
		return false;
	}

	template <typename T>
	inline bool Matrix2DT<T>::goRight_s(objIt& it, unsigned int positions){
		if(objects.end()-it>positions){
			it+=positions;
			return true;
		}
		return false;
	}

	template <typename T>
	inline bool Matrix2DT<T>::verticalStep_s(objIt& it, int step){
		return step>=0?goDown_s(it, step):goUp_s(it, abs(step));
	}

	template <typename T>
	inline bool Matrix2DT<T>::horizontalStep_s(objIt& it, int step){
		return step>=0?goRight_s(it, step):goLeft_s(it, abs(step));
	}
}
#endif