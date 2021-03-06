/*
 * Copyright 2016 MBARI
 *
 * Licensed under the GNU LESSER GENERAL PUBLIC LICENSE, Version 3.0
 * (the "License"); you may not use this file except in compliance 
 * with the License. You may obtain a copy of the License at
 *
 * http://www.gnu.org/copyleft/lesser.html
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * This is a program to automate detection and tracking of events in underwater 
 * video. This is based on modified version from Dirk Walther's 
 * work that originated at the 2002 Workshop  Neuromorphic Engineering 
 * in Telluride, CO, USA. 
 * 
 * This code requires the The iLab Neuromorphic Vision C++ Toolkit developed
 * by the University of Southern California (USC) and the iLab at USC. 
 * See http://iLab.usc.edu for information about this project. 
 *  
 * This work would not be possible without the generous support of the 
 * David and Lucile Packard Foundation
 */ 

#include "Image/BitObjectDrawModes.H"

#include "Util/StringConversions.H"
#include "Util/log.H"

using namespace std;

// ######################################################################
// converters for BitObjectDrawMode
// ######################################################################

string convertToString(const BitObjectDrawMode val)
{ return bitObjectDrawModeName(val); }

void convertFromString(const string& str, BitObjectDrawMode& val)
{
  // CAUTION: assumes types are numbered and ordered!
  for (int i = 0; i < NBBITOBJECTDRAWMODES; i ++)
    if (str.compare(bitObjectDrawModeName(BitObjectDrawMode(i))) == 0)
      { val = BitObjectDrawMode(i); return; }

  conversion_error::raise<BitObjectDrawMode>(str);
}
