#include "GSimpleTree.h"

void convert_flux() {

	// TString t = ".L GSimpleTree.C;";
    // gROOT->ProcessLine(t);

  	gSystem->Load("GSimpleTree_C.so");

	string pattern="/pnfs/sbnd/persistent/stash/fluxFiles/bnb/BooNEtoGSimple/configF-v1/april07/neutrinoMode/converted_beammc_sbnd_v1_000*.root";
	TChain *cflux = new TChain("flux");
	cflux->Add(pattern.c_str());
	int Nfiles = cflux->GetNtrees();
	cout << "Number of files: " << Nfiles << endl;
	GSimpleTree *gsimple = new GSimpleTree(cflux);
	gsimple->Loop();
	cout << "Done." << endl;

}
