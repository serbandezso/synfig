/* === S Y N F I G ========================================================= */
/*!	\file noise.h
**	\brief Template Header
**
**	$Id: random.h,v 1.1.1.1 2005/01/04 01:23:14 darco Exp $
**
**	\legal
**	Copyright (c) 2002-2005 Robert B. Quattlebaum Jr., Adrian Bentley
**
**	This package is free software; you can redistribute it and/or
**	modify it under the terms of the GNU General Public License as
**	published by the Free Software Foundation; either version 2 of
**	the License, or (at your option) any later version.
**
**	This package is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
**	General Public License for more details.
**	\endlegal
*/
/* ========================================================================= */

/* === S T A R T =========================================================== */

#ifndef __SYNFIG_RANDOM_H
#define __SYNFIG_RANDOM_H

/* === H E A D E R S ======================================================= */


/* === M A C R O S ========================================================= */

/* === T Y P E D E F S ===================================================== */

/* === C L A S S E S & S T R U C T S ======================================= */


#define POOL_SIZE	(256)
class Random
{
	int pool_[POOL_SIZE];
	int seed_;
	
	int x_mask, y_mask, t_mask;
	
public:
	
	void set_seed(int x);
	int get_seed()const { return seed_; }
	
	float operator()(int subseed,int x,int y=0, int t=0)const;	
	float operator()(int smooth,int subseed,float x,float y=0, float t=0)const;	
};

/* === E N D =============================================================== */

#endif
