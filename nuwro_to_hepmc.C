// After having setup nuwro, run with myroot -l nuwro_to_hepmc.C

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

void nuwro_to_hepmc(std::string nuwro_file_name = "eventsout.root", std::string outdir = "eventsout_hepmc/") {

 	// Input file
	TFile* f = new TFile(nuwro_file_name.c_str());
	TTree* t = (TTree*)f->Get("treeout");
	event *e = new event();
 	t->SetBranchAddress("e", &e);

 	// Output file
 	std::ofstream _hepmc_file;
 	_hepmc_file.open(outdir + nuwro_file_name + "_" + std::to_string(0) + ".hepmc");

 	double GlobalTimeOffset = 0.;
 	double RandomTimeOffset = 1600.;
 	srand(time(0));

 	double entries = t->GetEntries();

 	for (size_t i = 0; i < entries; i++){

    	if (i % 100000 == 0) std::cout << "At entry " << i << std::endl;
    	// if (i > 500) break;

        if (i % 50 == 0) {
          // Close and open a new file
          _hepmc_file.close();
          _hepmc_file.open(outdir + nuwro_file_name + "_" + std::to_string(i / 50) + ".hepmc");
        }

    	t->GetEntry(i);

    	// Neutrino time in the spill
    	double nu_time = rand() / double(RAND_MAX) * RandomTimeOffset + GlobalTimeOffset;

    	// Save the number of particles for this events (+1 for the neutrino)
    	_hepmc_file << i << " " << e->post.size() + 1 << std::endl;

      int ccnc = 0;
      if (e->flag.nc) ccnc = 1;

      int mode = -1;
      if (e->flag.qel) mode = 0;
      if (e->flag.res) mode = 1;
      if (e->flag.dis) mode = 2;
      if (e->flag.coh) mode = 3;
      if (e->flag.mec) mode = 10;

    	// Save the neutrino
    	_hepmc_file << 0 << " "
    				<< e->in[0].pdg << " "
    				<< -1 << " " << 0 << " " 
                                << ccnc << " "                         // Should be 1st and 2nd daugther, but putting ccnc and mode
                                << mode << " "                         // Should be 1st and 2nd daugther, but putting ccnc and mode
    				<< e->in[0].p().x / 1000. << " "       // NuWro uses MeV, we want GeV
    				<< e->in[0].p().y / 1000. << " "       // NuWro uses MeV, we want GeV
    				<< e->in[0].p().z / 1000. << " "       // NuWro uses MeV, we want GeV
    				<< e->in[0].E() / 1000. << " "         // NuWro uses MeV, we want GeV
    				<< e->in[0].m() / 1000. << " "
    				<< e->r.x << " "                       // NuWro uses cm, ok
    				<< e->r.y << " "                       // NuWro uses cm, ok
    				<< e->r.z << " "                       // NuWro uses cm, ok
    				<< nu_time << " "
    				<< std::endl;

    	// Save the final state particles
    	for (size_t j = 0; j < e->post.size(); j++) {
    		_hepmc_file << 1 << " "
    				    << e->post[j].pdg << " "
      				    << 0 << " " << 0 << " " << 0 << " " << 0 << " "
      				    << e->post[j].p().x / 1000. << " " // NuWro uses MeV, we want GeV
      				    << e->post[j].p().y / 1000. << " " // NuWro uses MeV, we want GeV
      				    << e->post[j].p().z / 1000. << " " // NuWro uses MeV, we want GeV
      				    << e->post[j].E() / 1000. << " "   // NuWro uses MeV, we want GeV
      				    << e->post[j].m() / 1000. << " "
      				    << e->r.x << " "                   // NuWro uses cm, ok
      				    << e->r.y << " "                   // NuWro uses cm, ok
      				    << e->r.z << " "                   // NuWro uses cm, ok
      				    << nu_time << " "
      				    << std::endl;
    	}
    }

  _hepmc_file.close();
}







