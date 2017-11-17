/*
Copyright (C) 2006,2007 StrmnNrmn

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#include "Base/Daedalus.h"
#include "Config/RomSettings.h"


void RomSettings::Reset()
{
	GameName = "";
	Comment = "";
	Info = "";
	ExpansionPakUsage = PAK_STATUS_UNKNOWN;
	SaveType = SAVE_TYPE_UNKNOWN;
	PatchesEnabled = true;
	SpeedSyncEnabled = 0;
	DynarecSupported = true;
	DoubleDisplayEnabled = true;
	CleanSceneEnabled = false;
	ClearDepthFrameBuffer = false;
	FogEnabled = false;
	MemoryAccessOptimisation = false;
	CheatsEnabled = false;
}

