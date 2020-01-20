#!/usr/bin/env python
#

import os,sys,string, time
import ROOT 
from ROOT import TChain
ROOT.gSystem.Load("GSimpleTree_C.so")
from ROOT import GSimpleTree
from glob import glob

pattern = "/pnfs/uboone/persistent/uboonebeam/bnb_gsimple/bnb_gsimple_fluxes_02.05.2018_463/converted_beammc_000*.root"

cflux = TChain('flux')
cflux.Add(pattern)
Nfiles = cflux.GetNtrees()
print ("Number of files: ", Nfiles)
gsimple = GSimpleTree(cflux)
gsimple.Loop()

raw_input("Please press enter to exit.")