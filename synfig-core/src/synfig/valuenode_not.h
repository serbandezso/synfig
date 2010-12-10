/* === S Y N F I G ========================================================= */
/*!	\file valuenode_not.h
**	\brief Header file for implementation of the "Not" valuenode conversion.
**
**	$Id$
**
**	\legal
**	Copyright (c) 2002-2005 Robert B. Quattlebaum Jr., Adrian Bentley
**	Copyright (c) 2009 Nikita Kitaev
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

#ifndef __SYNFIG_VALUENODE_NOT_H
#define __SYNFIG_VALUENODE_NOT_H

/* === H E A D E R S ======================================================= */

#include "valuenode.h"

/* === M A C R O S ========================================================= */

/* === C L A S S E S & S T R U C T S ======================================= */

namespace synfig {

class ValueNode_Not : public LinkableValueNode
{
	ValueNode::RHandle link_;

public:
	typedef etl::handle<ValueNode_Not> Handle;
	typedef etl::handle<const ValueNode_Not> ConstHandle;

	ValueNode_Not(const ValueBase &x);

	virtual ValueBase operator()(Time t)const;

	virtual ~ValueNode_Not();

	virtual String get_name()const;
	virtual String get_local_name()const;


	virtual ValueNode::LooseHandle get_link_vfunc(int i)const;
	virtual int link_count()const;
	virtual String link_name(int i)const;

	virtual String link_local_name(int i)const;
	virtual int get_link_index_from_name(const String &name)const;

protected:
	LinkableValueNode* create_new()const;
	virtual bool set_link_vfunc(int i,ValueNode::Handle x);

public:
	using synfig::LinkableValueNode::get_link_vfunc;

	using synfig::LinkableValueNode::set_link_vfunc;
	static bool check_type(ValueBase::Type type);
	static ValueNode_Not* create(const ValueBase &x);
	virtual Vocab get_param_vocab()const;
}; // END of class ValueNode_Not

}; // END of namespace synfig

/* === E N D =============================================================== */

#endif
