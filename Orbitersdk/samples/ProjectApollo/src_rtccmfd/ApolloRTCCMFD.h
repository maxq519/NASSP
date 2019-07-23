// ==============================================================
//                 ORBITER MODULE: DialogTemplate
//                  Part of the ORBITER SDK
//            Copyright (C) 2003 Martin Schweiger
//                   All rights reserved
//
// ApolloRTCCMFDe.h
//
// This module demonstrates how to build an Orbiter plugin which
// inserts a new MFD (multi-functional display) mode. The code
// is not very useful in itself, but it can be used as a starting
// point for your own MFD developments.
// ==============================================================

#ifndef __ApolloRTCCMFD_H
#define __ApolloRTCCMFD_H

#include "ARCore.h"
#include "soundlib.h"
#include "apolloguidance.h"
#include "csmcomputer.h"
#include "lemcomputer.h"
#include "saturn.h"
#include "saturnv.h"
#include "LEM.h"

class ApolloRTCCMFD: public MFD2 {
public:
	ApolloRTCCMFD (DWORD w, DWORD h, VESSEL *vessel, UINT im);
	~ApolloRTCCMFD ();
	char *ButtonLabel (int bt);
	int ButtonMenu (const MFDBUTTONMENU **menu) const;
	bool Update (oapi::Sketchpad *skp);
	bool ConsumeButton(int bt, int event);
	bool ConsumeKeyBuffered(DWORD key);
	void WriteStatus(FILEHANDLE scn) const;
	void ReadStatus(FILEHANDLE scn);
	void StoreStatus(void) const;
	void RecallStatus(void);

	void t1dialogue();
	void set_t1(double t1);
	void set_t1_PDI(double t1);
	void t2dialogue();
	void set_t2(double t2, bool t1dep);
	void set_lambertWT(double wt);
	void SPQtimedialogue();
	void set_SPQtime(double tig);
	void DHdialogue();
	void set_DH(double DH);
	void revdialogue();
	void set_rev(int rev);
	void set_target();
	//void set_offset();
	void xdialogue();
	void ydialogue();
	void zdialogue();
	void set_Xoff(double x);
	void set_Yoff(double y);
	void set_Zoff(double z);
	void menuVoid();
	void menuNextPage();
	void menuLastPage();
	void menuSetLambertPage();
	void menuSetCDHPage();
	void menuSetOffsetPage();
	void menuSetREFSMMATPage();
	void menuSetEntryPage();
	void menuSetSVPage();
	void menuSetMenu();
	void menuSetConfigPage();
	void menuSetOrbAdjPage();
	void menuSetMapUpdatePage();
	void REFSMMATTimeDialogue();
	void cycleREFSMMATHeadsUp();
	void set_REFSMMATTime(double time);
	void calcREFSMMAT();
	void menuSendREFSMMATToOtherVessel();
	void GMPInput1Dialogue();
	void set_GMPInput1(double val);
	void GMPInput2Dialogue();
	void set_GMPInput2(double val);
	void GMPInput3Dialogue();
	void set_GMPInput3(double val);
	void GMPInput4Dialogue();
	void set_GMPInput4(double val);
	void OrbAdjGETDialogue();
	void set_OrbAdjGET(double SPSGET);
	void OrbAdjRevDialogue();
	void set_OrbAdjRevs(int N);
	void GPMPCalc();
	void menuCycleGMPManeuverPoint();
	void menuCycleGMPManeuverType();
	void menuCycleGMPMarkerUp();
	void menuCycleGMPMarkerDown();
	void menuSetGMPInput();
	void menuCycleOrbAdjAltRef();
	void phasedialogue();
	void set_getbase();
	void set_TIPhaseAngle(double angdeg);
	void CDHcalc();
	void lambertcalc();
	void GET_Display(char * Buff, double time, bool DispGET = true);
	void AGC_Display(char * Buff, double time);
	char* REFSMMATName(char* Buff, int n);
	void SStoHHMMSS(double time, int &hours, int &minutes, double &seconds);
	double timetoperi();
	double timetoapo();
	void CycleREFSMMATopt();
	void UploadREFSMMAT();
	void menuP30Upload();
	void EntryAngDialogue();
	void set_entryang(double ang);
	void EntryTimeDialogue();
	void set_EntryTime(double time);
	void set_entrylat(double lat);
	void EntryLatDialogue();
	void set_entrylng(double lng);
	void EntryLngDialogue();
	void menuSetEntryDesiredInclination();
	void set_EntryDesiredInclination(double inc);
	void menuSetEntryMaxInclination();
	void set_EntryMaxInclination(double inc);
	void menuSetEntryRangeOverride();
	void set_EntryRangeOverride(double range);
	void menuSetMaxReentrySpeed();
	void set_MaxReentrySpeed(double vel);
	void CycleRTECalcMode();
	void menuEntryCalc();
	void menuEntryUpdateCalc();
	void menuDeorbitCalc();
	void menuMoonRTECalc();
	void set_entryrange(double range);
	void EntryRangeDialogue();
	void menuSVCalc();
	void menuSwitchSVSlot();
	void menuSVUpload();
	void menuEntryUpload();
	void menuEntryUpdateUpload();
	void set_spherical();
	void menuCycleTwoImpulseOption();
	void menuSwitchHeadsUp();
	void menuManDirection();
	void menuCalcManPAD();
	void menuSetManPADPage();
	void menuCalcEntryPAD();
	void menuSetEntryPADPage();
	void menuSwitchCritical();
	void menuSwitchEntryPADOpt();
	void menuManPADTIG();
	void set_ManPADTIG(double ManPADTIG);
	void menusextantstartime();
	void set_sextantstartime(double time);
	void menuManPADDV();
	void set_P30DV(VECTOR3 dv);
	void menuSwitchManPADEngine();
	void set_lambertelev(double elev);
	void menuSwitchManPADopt();
	void menuLSLat();
	void set_LSLat(double lat);
	void menuLSLng();
	void set_LSLng(double lng);
	void menuSetSVTime();
	void set_SVtime(double SVtime);
	void menuSetAGSKFactor();
	void set_AGSKFactor(double time);
	void menuCalcMapUpdate();
	void menuSwitchMapUpdate();
	void menuSetMapUpdateGET();
	void set_MapUpdateGET(double time);
	void menuSwitchUplinkInhibit();
	void menuCycleSPQMode();
	void set_CDHtimemode();
	void menuSetLaunchMJD();
	void set_launchmjd(double mjd);
	void menuSetAGCEpoch();
	void set_AGCEpoch(double mjd);
	void menuChangeVesselType();
	void menuCycleLMStage();
	void menuUpdateLiftoffTime();
	void cycleREFSMMATupl();
	void set_svtarget();
	void offvecdialogue();
	void set_offvec(VECTOR3 off);
	void GetREFSMMATfromAGC();
	void GetEntryTargetfromAGC();
	void menuCycleSVTimeMode();
	void menuCycleSVMode();
	void set_lambertaxis();
	void menuSwitchEntryNominal();
	void menuSwitchDeorbitEngineOption();
	void menuSetRTEReentryTime();
	void set_RTEReentryTime(double t);
	void EntryLongitudeModeDialogue();
	void menuSetLOIPage();
	void menuSwitchLOIManeuver();
	void menuSwitchLOIOption();
	void menuCycleLOIEllipseOption();
	void menuSwitchTLCCManeuver();
	void menuSetTLCCGET();
	void set_TLCCGET(double time);
	void menuSetTLCCPeriGET();
	void set_TLCCPeriGET(double time);
	void menuSetTLCCLat();
	void set_TLCCLat(double lat);
	void menuSetTLCCLng();
	void set_TLCCLng(double lng);
	void menuSetTLCCAlt();
	void set_TLCCAlt(double alt);
	void menuSetTLCCDesiredInclination();
	void set_TLCCDesiredInclination(double inc);
	void menuSwitchTLCCAscendingNode();
	void menuSetLOIApo();
	void set_LOIApo(double alt);
	void menuSetLOIPeri();
	void set_LOIPeri(double alt);
	void menuSetLOIAzi();
	void set_LOIAzi(double inc);
	void menuSetTLAND();
	void menuLOICalc();
	void menuSetLOIGET();
	void set_LOI2EarliestGET(double time);
	void menuRequestLTMFD();
	void menuSetLandmarkTrkPage();
	void menuSetLmkTime();
	void set_LmkTime(double time);
	void menuSetLmkLat();
	void set_LmkLat(double lat);
	void menuSetLmkLng();
	void set_LmkLng(double lng);
	void menuLmkPADCalc();
	void menuSetTargetingMenu();
	void menuSetPADMenu();
	void menuSetUtilityMenu();
	void menuSetVECPOINTPage();
	void menuTranslunarPage();
	void menuSetLunarLiftoffPage();
	void menuSetEMPPage();
	void menuSetNavCheckPADPage();
	void menuSetDeorbitPage();
	void menuSetEarthEntryPage();
	void menuSetMoonEntryPage();
	void menuSetRTEConstraintsPage();
	void menuSetEntryUpdatePage();
	void menuSetP37PADPage();
	void menuSetRendezvousPage();
	void menuSetDKIPage();
	void menuSetDKIOptionsPage();
	void menuSetLunarAscentPage();
	void cycleVECDirOpt();
	void vecbodydialogue();
	void set_vecbody(OBJHANDLE body);
	void menuVECPOINTCalc();
	void menuSetDOIGET();
	void set_DOIGET(double time);
	void menuLSAlt();
	void set_LSAlt(double alt);
	void menuSetDOIRevs();
	void set_DOIRevs(int N);
	void menuSetDOIPeriAng();
	void set_DOIPeriAng(double ang);
	void menuSetDOIPeriAlt();
	void set_DOIPeriAlt(double alt);
	void menuDOICalc();
	void menuSetDOIPage();
	void menuDOIOption();
	void menuTLANDUpload();
	void menuSetSkylabPage();
	void menuSwitchSkylabManeuver();
	void menuSetSkylabGET();
	void set_SkylabGET(double time);
	void menuSkylabCalc();
	void menuSetSkylabNC();
	void set_SkylabNC(double N);
	void menuSetSkylabDH1();
	void set_SkylabDH1(double dh);
	void menuSetSkylabDH2();
	void set_SkylabDH2(double dh);
	void menuSetSkylabEL();
	void set_SkylabEL(double E_L);
	void set_t_TPI(double time);
	void menuCyclePlaneChange();
	void menuCyclePCManeuver();
	void set_SkylabDTTPM(double dt);
	void menuSetPCPage();
	void menuPCCalc();
	void menuSetPCTIGguess();
	void set_PCTIGguess(double time);
	void menuSetPCAlignGET();
	void set_PCAlignGET(double time);
	void menuSetPCLanded();
	void menuSetLiftoffguess();
	void set_Liftoffguess(double time);
	void menuSetTPIguess();
	void menuLunarLiftoffCalc();
	void menuLunarLiftoffTimeOption();
	void menuSetLiftoffDT();
	void set_LiftoffDT(double dt);
	void set_TPIguess(double time);
	void menuSetEMPUplinkP99();
	void menuEMPUplink();
	void menuSetEMPUplinkNumber();
	void menuTMLat();
	void set_TMLat(double lat);
	void menuTMLng();
	void set_TMLng(double lng);
	void menuTMAzi();
	void set_TMAzi(double azi);
	void menuSetTerrainModelPage();
	void menuTMDistance();
	void set_TMDistance(double distance);
	void menuTMStepSize();
	void set_TMStepSize(double step);
	void menuTerrainModelCalc();
	void set_TLand(double time);
	void menuTLCCCalc();
	void menuNavCheckPADCalc();
	void menuSetNavCheckGET();
	void set_NavCheckGET(double time);
	void menuLAPCalc();
	void menuDKICalc();
	void DKITIGDialogue();
	void set_DKITIG(double time);
	void set_DKITIG_DT_PDI(double dt);
	void menuCycleDKIProfile();
	void menuCycleDKITPIMode();
	void menuSetDKIElevation();
	void set_DKIElevation(double elev);
	void menuCycleDKIManeuverLine();
	void menuCycleDKIRadialComponent();
	void DKITPIDTDialogue();
	void set_DKITPIDT(double time);
	void DKINHCDialogue();
	void set_DKINHC(int N);
	void DKINPBDialogue();
	void set_DKINPB(int N);
	void menuDKIDeltaT1();
	void set_DKIDT1(double dt);
	void menuDKIDeltaT2();
	void set_DKIDT2(double dt);
	void menuDKIDeltaT3();
	void set_DKIDT3(double dt);
	void menuSetLAPLiftoffTime();
	void set_LAPLiftoffTime(double time);
	void set_LAPLiftoffTime_DT_PDI(double dt);
	void menuSetLAPHorVelocity();
	void set_LAPHorVelocity(double vel);
	void menuSetLAPVerVelocity();
	void set_LAPVerVelocity(double vel);
	void menuSetDAPPADPage();
	void menuDAPPADCalc();
	void menuSetLVDCPage();
	void menuLaunchAzimuthCalc();
	void menuSetAGCEphemerisPage();
	void menuCycleAGCEphemOpt();
	void menuCycleAGCEphemAGCType();
	void menuSetAGCEphemMission();
	void set_AGCEphemMission(int ApolloNo);
	void menuSetAGCEphemBRCSEpoch();
	void set_AGCEphemBRCSEpoch(double mjd);
	void menuSetAGCEphemTEphemZero();
	void set_AGCEphemTEphemZero(double mjd);
	void menuSetAGCEphemTEPHEM();
	void set_AGCEphemTEPHEM(double mjd);
	void menuSetAGCEphemTIMEM0();
	void set_AGCEphemTIMEM0(double mjd);
	void menuSetAGCEphemTLAND();
	void set_AGCEphemTLAND(double get);
	void menuGenerateAGCEphemeris();
	void cycleVECPOINTOpt();
	void menuSetLMAscentPADPage();
	void menuAscentPADCalc();
	void menuSetPDAPPage();
	void menuPDAPCalc();
	void menuCyclePDAPEngine();
	void menuAP11AbortCoefUplink();
	void menuSetFIDOOrbitDigitalsPage();
	void menuUpdateFIDOOrbitDigitals();
	void menuSetFIDOOrbitDigitalsGETL();
	void set_FIDOOrbitDigitalsGETL(double getl);
	void menuSetFIDOOrbitDigitalsL();
	void set_FIDOOrbitDigitalsL(double lng);
	void menuSetFIDOOrbitDigitalsGETBV();
	void set_FIDOOrbitDigitalsGETBV(double getbv);
	void menuSetMCCDisplaysPage();
	void menuSetSpaceDigitalsPage();
	void menuUpdateSpaceDigitals();
	void menuSetSpaceDigitalsGET();
	void set_SpaceDigitalsGET(double get);
	void menuSetMPTPage();
	void menuMPTCycleActive();
	void menuMPTDeleteManeuver();
	void menuSetNextStationContactsPage();
	void menuNextStationContactLunar();
	void menuSetPredSiteAcquisitionPage();
	void menuPredSiteAcqGET();
	void set_PredSiteAcqGET(double GET);
	void menuPredSiteAcqDT();
	void set_PredSiteAcqDT(double DT);
	void PredSiteAcqCalc();
	void GMPManeuverTypeName(char *buffer, int typ);
	void GMPManeuverPointName(char *buffer, int point);
	void GMPManeuverCodeName(char *buffer, int code);

protected:
	oapi::Font *font;
	oapi::Font *font2;
	Saturn *saturn;
	LEM *lem;
	int screen;
	int marker;
	static struct ScreenData {
		int screen;
	} screenData;
private:
	ARCore* G;
	AR_GCore* GC;
	ApolloRTCCMFDButtons coreButtons;	
};

#endif // !__ApolloRTCCMFD_H
