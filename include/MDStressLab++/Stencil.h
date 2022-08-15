/*
 * Stencil.h
 *
 *  Created on: Dec 13, 2019
 *      Author: Nikhil
 */

#ifndef SRC_STENCIL_H_
#define SRC_STENCIL_H_


#include <typedef.h>
#include <map>

class Configuration;

template<ConfigType T>
class Grid;
class GridBase;

class Stencil {
public:
	const Configuration& parent;
	std::map<int,int> particleContributingMap;

	template<ConfigType configType>
	void inline expandStencil(const Grid<configType>* pgrid, const double&, const double&);

	void inline emptyStencil();
	inline Stencil(const Configuration&);
	virtual inline ~Stencil();

};

#include "Stencil.cpp"

#endif /* SRC_STENCIL_H_ */
