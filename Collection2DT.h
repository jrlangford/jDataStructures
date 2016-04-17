#pragma once

#ifndef COLLECTION2DT_H
#define COLLECTION2DT_H

#include "Collection2D_BaseT.h"

namespace jrl{

	template <typename T>
	class Collection2DT:public Collection2D_BaseT<T>{
	public:

		//typedefs
		typedef typename T::point_type point_type;
		typedef typename std::vector<point_type>::iterator iterator;

		Collection2DT();
		virtual ~Collection2DT();

		void init(int cols, int rows);
		std::vector<T>& getObjects();

	protected:

		std::vector<T> objects;
	};

	//Implementation
	template <typename T>
	Collection2DT<T>::Collection2DT(){
	}

	template <typename T>
	Collection2DT<T>::~Collection2DT(){
	}

	template <typename T>
	void Collection2DT<T>::init(int cols, int rows){
		initBase(cols, rows);
		objects.clear();
		objects.insert(objects.end(), numOfObjects, T());
	}
	
	template <typename T>
	inline std::vector<T>& Collection2DT<T>::getObjects(){
		return objects;
	}

}
#endif