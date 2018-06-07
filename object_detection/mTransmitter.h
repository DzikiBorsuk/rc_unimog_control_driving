//
// You received this file as part of Finroc
// A framework for intelligent robot control
//
// Copyright (C) AG Robotersysteme TU Kaiserslautern
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
//----------------------------------------------------------------------
/*!\file    projects/rc_unimog_control_group2/object_detection/mTransmitter.h
 *
 * \author  Paul Dornhof
 *
 * \date    2018-02-01
 *
 * \brief Contains mTransmitter
 *
 * \b mTransmitter
 *
 * this module collects all information about detected_objects from other moduls, puts them together and sends further
 *
 */
//----------------------------------------------------------------------
#ifndef __projects__rc_unimog_control_group2__object_detection__mTransmitter_h__
#define __projects__rc_unimog_control_group2__object_detection__mTransmitter_h__

#include "plugins/structure/tModule.h"

//----------------------------------------------------------------------
// External includes (system with <>, local with "")
//----------------------------------------------------------------------
#include "projects/rc_unimog_control_group2/libraries/tDetectedObject.h"
//----------------------------------------------------------------------
// Internal includes with ""
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// Namespace declaration
//----------------------------------------------------------------------
namespace finroc
{
namespace rc_unimog_control_group2
{
namespace object_detection
{

//----------------------------------------------------------------------
// Forward declarations / typedefs / enums
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// Class declaration
//----------------------------------------------------------------------
//! SHORT_DESCRIPTION
/*!
 * this module collects all information about detected_objects from other moduls, puts them together and sends further
 */
class mTransmitter : public structure::tModule
{

//----------------------------------------------------------------------
// Ports (These are the only variables that may be declared public)
//----------------------------------------------------------------------
public:

	tInput<std::vector<libraries::tDetectedObject>> in_lanes;
	tInput<std::vector<libraries::tDetectedObject>> in_bridge;
	tInput<std::vector<libraries::tDetectedObject>> in_pylon;
	tInput<std::vector<libraries::tDetectedObject>> in_stop_sign;
	tInput<std::vector<libraries::tDetectedObject>> in_unimog;

	tOutput<std::vector<libraries::tDetectedObject>> out_list_detected_objects;
//----------------------------------------------------------------------
// Public methods and typedefs
//----------------------------------------------------------------------
public:

  mTransmitter(core::tFrameworkElement *parent, const std::string &name = "Transmitter");

//----------------------------------------------------------------------
// Protected methods
//----------------------------------------------------------------------
protected:

  /*! Destructor
   *
   * The destructor of modules is declared protected to avoid accidental deletion. Deleting
   * modules is already handled by the framework.
   */
  ~mTransmitter();

//----------------------------------------------------------------------
// Private fields and methods
//----------------------------------------------------------------------
private:

//  Here is the right place for your variables. Replace this line by your declarations!
  std::vector<libraries::tDetectedObject> list_detected_objects;

//  virtual void OnStaticParameterChange() override;   //Might be needed to process static parameters. Delete otherwise!

//  virtual void OnParameterChange() override;   //Might be needed to react to changes in parameters independent from Update() calls. Delete otherwise!

  virtual void Update() override;

};

//----------------------------------------------------------------------
// End of namespace declaration
//----------------------------------------------------------------------
}
}
}



#endif