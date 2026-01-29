/***************************************************************************
  This file is part of Project Apollo - NASSP
  Copyright 2004-2005

  EVA.h - astronaut code

  Project Apollo is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  Project Apollo is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Project Apollo; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

  See http://nassp.sourceforge.net/license/ for more details.

  **************************************************************************/

class Saturn;

typedef struct {

	int MissionNo;			///< Apollo mission number.

} EVASettings;

class EVA : public VESSEL3 {
public:

	EVA(OBJHANDLE hVessel, int flightmodel);
	void init();
	~EVA();
	void clbkPreStep(double SimT, double SimDT, double MJD);
	int clbkConsumeBufferedKey(DWORD key, bool down, char* kstate);
	void clbkSetClassCaps(FILEHANDLE cfg);
	void SetAstroStage();
	void clbkPostCreation();
	virtual void SetEVAStats(EVASettings &evas);
	void DoFirstTimestep();
	void SetMainState(int s);
	int GetMainState();
	void clbkLoadStateEx(FILEHANDLE scn, void* vs);
	void clbkSaveState(FILEHANDLE scn);

private:
	void ScanMotherShip();

	THRUSTER_HANDLE th_rcs[16], th_group[2];
	PROPELLANT_HANDLE hProp;
	ATTACHMENTHANDLE hAttach;

protected:
	int ApolloNo;
	OBJHANDLE hMaster;
	bool GoDock1;
	bool MotherShip;
	char CSMName[256];
	bool FirstTimestep;
	bool StateSet;
};