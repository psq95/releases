/// \file MHit.h
/// Defines the MHit class.\n
/// \author \n Maurizio Ungaro
/// \author mail: ungaro@jlab.org\n\n\n

#ifndef MHit_H
#define MHit_H 1

// %%%%%%%%%%
// G4 headers
// %%%%%%%%%%
#include "G4ThreeVector.hh"
#include "G4VHit.hh"

// %%%%%%%%%%%%%
// gemc headers
// %%%%%%%%%%%%%
#include "detector.h"

// %%%%%%%%%%%
// C++ headers
// %%%%%%%%%%%
#include <iostream>
using namespace std;

// %%%%%%%%%%%%%%%%
// Class definition
// %%%%%%%%%%%%%%%%
class MHit : public G4VHit
{
	
	public:
		MHit();
		virtual ~MHit();
		const MHit& operator=(const MHit&){return *this;}
		
		void Draw();
		
	private:
		// all these infos are recorded 
		// in each step of the hit
		vector<G4ThreeVector>   pos;    ///< Hit Position (Global)
		vector<G4ThreeVector>  Lpos;    ///< Hit Positions (Local to the Volume)
		vector<G4ThreeVector>  vert;    ///< Primary Vertex of track in each step
		vector<double>         edep;    ///< Energy Deposited
		vector<double>           dx;    ///< Length of the step
		vector<double>         time;    ///< Time from the start of event
		vector<G4ThreeVector>   mom;    ///< Momentum of the Track
		vector<double>            E;    ///< Energy of the track
		vector<int>               q;    ///< Charge of the particle in each step
		vector<int>             PID;    ///< particle ID in each step
		vector<int>            mPID;    ///< Mother particle ID in each step
		vector<int>         trackID;    ///< G4Track ID in each step
		vector<int>        mtrackID;    ///< Mother G4Track ID in each step
		vector<G4ThreeVector> mvert;    ///< Primary Vertex of the track's mother
		
		vector<detector>  Detectors;    ///< Detectors Hit. It might be a vector if multiple detectors have the same identifier
		
		vector<identifier> identity;    ///< Identity
		double              minEdep;    ///< Energy Threshold of the sensitive detector
		
	public:
		// infos filled in Sensitive Detector
		inline void SetPos(G4ThreeVector xyz)       { pos.push_back(xyz); }
		inline vector<G4ThreeVector> GetPos()       { return pos; }
		inline G4ThreeVector GetLastPos()           { if(pos.size()) return pos[pos.size()-1];  }
		
		inline void SetLPos(G4ThreeVector xyz)      { Lpos.push_back(xyz); }
		inline vector<G4ThreeVector> GetLPos()      { return Lpos; }
		
		inline void SetVert(G4ThreeVector ver)      { vert.push_back(ver); }
		inline G4ThreeVector GetVert()              { return  vert[0]; }
		inline vector<G4ThreeVector> GetVerts()     { return  vert; }
	
		inline void SetEdep(double depe)            { edep.push_back(depe); }
		inline vector<double> GetEdep()             { return edep; }

		inline void SetDx(double Dx)                { dx.push_back(Dx); }
		inline vector<double> GetDx()               { return dx; }
		
		inline void SetTime(double ctime)           { time.push_back(ctime); }
		inline vector<double> GetTime()             { return  time; }
		
		inline void SetMom(G4ThreeVector pxyz)      { mom.push_back(pxyz); }
		inline G4ThreeVector GetMom()               { return mom[0]; }
		inline vector<G4ThreeVector> GetMoms()      { return mom; }
		
		inline void SetE(double ene)                { E.push_back(ene); }
		inline double GetE()                        { return E[0]; }
		inline vector<double> GetEs()               { return E; }
		
		inline void SetTrackId(int tid)             { trackID.push_back(tid); }
		inline int GetTId()                         { return trackID[0]; }
		inline vector<int> GetTIds()                { return trackID; }
		
		inline vector<identifier> GetId()           { return identity; }
		inline void SetId(vector<identifier> iden)  { identity = iden; }
		
		inline void SetDetector(detector det)       {Detectors.push_back(det);}
		inline vector<detector> GetDetectors()      {return Detectors;}
		inline detector GetDetector()               {return Detectors[0];}
		
		inline void SetThreshold(double E)          { minEdep = E; }
		inline double GetThreshold()                { return minEdep; }

		inline void SetPID(int pid)                 { PID.push_back(pid); }
		inline int GetPID()                         { return PID[0]; }
		inline vector<int> GetPIDs()                { return PID; }
	
		inline void SetCharge(int Q)                { q.push_back(Q); }
		inline int GetCharge()                      { return q[0]; }
		inline vector<int> GetCharges()             { return q; }

		// infos filled in MEvent Action
		inline void SetmTrackId(int tid)            { mtrackID.push_back(tid); }
		inline void SetmTrackIds(vector<int> tid)   { mtrackID = tid; }
		inline int GetmTrackId()                    { return mtrackID[0]; }
		inline vector<int> GetmTrackIds()           { return mtrackID; }
				
		inline void SetmPID(int mpid)               { mPID.push_back(mpid); }
		inline void SetmPIDs(vector<int> mpid)      { mPID = mpid; }
		inline int GetmPID()                        { return mPID[0]; }
		inline vector<int> GetmPIDs()               { return mPID; }
		
		inline void SetmVert(G4ThreeVector ver)          { mvert.push_back(ver); }
		inline void SetmVerts(vector<G4ThreeVector> ver) { mvert = ver; }
		inline G4ThreeVector GetmVert()                  { return  mvert[0]; }
		inline vector<G4ThreeVector> GetmVerts()         { return  mvert; }
		
};


#include "G4THitsCollection.hh"
typedef G4THitsCollection<MHit> MHitCollection;

#endif
