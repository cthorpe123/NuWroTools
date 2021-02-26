#ifndef _FV_h_
#define _FV_h_

#include "TVector3.h"

// Created by C Thorpe
// Fiducial volume filter
// Use to produce CC inclusive fiducial volume only samples

// Fiducial volume definition

const double FVxmin = 12.0;
const double FVxmax = 256.35 - 12.0;
const double FVymin = -115.53 + 35;
const double FVymax = 117.47 - 35;
const double FVzmin = 0.1 + 25;
const double FVzmax = 1036.9 - 85;

// Dead region to be cut
const double deadzmin = 675.1;
const double deadzmax = 775.1;


bool inFV(TVector3 pos){

if(pos.X() > FVxmax || pos.X() < FVxmin) return false;

if(pos.Y() > FVymax || pos.Y() < FVymin) return false;

if(pos.Z() > FVzmax || pos.Z() < FVzmin) return false;

if(pos.Z() < deadzmax && pos.Z() > deadzmin) return false;

        return true;
}

#endif
