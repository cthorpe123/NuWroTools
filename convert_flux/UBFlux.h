#ifndef UBFlux_h
#define UBFlux_h

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "TChain.h"
#include "TH1.h"
#include "TFile.h"
#include "TSystem.h"
#include "TVector3.h"

#include "GSimpleTree/GSimpleTree.h"

class UBFlux {
public :

  int Nfiles = 0;

  // static const int numu  = 56;
  // static const int anumu = 55;
  // static const int nue   = 53;
  // static const int anue  = 52;

  // int highest_evtno = 0;
  // double NominalPOT = 6e20;
  // bool debug = false;
  // double fDefaultWeightCorrection = 1./(10000. * TMath::Pi());
  // double Ntarget = 4.76e31/56.41e6*256.35*233*1036.8; //TPC active!!!
  // double AccumulatedPOT=0.;
  // int treeNumber = -1;

  // double histMin = 0;
  // double histMax = 20;
  // int histNbins = 400;

  TChain *cflux;

  GSimpleTree *gsimple;

  // TH1D* numuFluxHisto;
  // TH1D* anumuFluxHisto;
  // TH1D* nueFluxHisto;
  // TH1D* anueFluxHisto;
  // TH1D* numuCCHisto;
  // TGraph *genieXsecNumuCC;
  // TFile* f = new TFile("UBFlux.root", "RECREATE");


  UBFlux(string pattern="/pnfs/uboone/persistent/uboonebeam/bnb_gsimple/bnb_gsimple_fluxes_02.05.2018_463/converted_beammc_*.root");

  virtual ~UBFlux();

  // void CalculateFlux();
  // TVector3 RandomInTPC();
  // TVector3 FromDetToBeam(const TVector3& det);
  // double estimate_pots(int highest_potnum);
  // int calcEnuWgt( FluxNtuple* decay, const TVector3& xyz, double& enu, double& wgt_xy);

};

#endif

#ifdef UBFlux_cxx

UBFlux::UBFlux(string pattern) {

  const char* path = "/uboone/app/users/mdeltutt/special_samples/nuwro_workdir/convert_flux/";
  if ( path ) {
    TString libs = gSystem->GetDynamicPath();
    libs += ":";
    libs += path;
    //libs += "/lib";
    gSystem->SetDynamicPath(libs.Data());       
    gSystem->Load("GSimpleTree_C.so");
  }

  cflux = new TChain("flux");
  cflux->Add(pattern.c_str());

  Nfiles = cflux->GetNtrees();
  cout << "Number of files: " << Nfiles << endl;

  // //Inizialise histos
  // TString titleBase1 = "Neutrino Flux;";
  // TString titleBase2 = " Energy [GeV];";
  // TString titleBase3 = " / cm^{2} / 6e20 POT";
  // // numu
  // numuFluxHisto = new TH1D("numuFluxHisto", (titleBase1 + "#nu_{#mu}" + titleBase2 +"#nu_{#mu}" + titleBase3),histNbins,histMin,histMax);
  // // anumu
  // anumuFluxHisto = new TH1D("anumuFluxHisto", (titleBase1 + "#bar{#nu}_{#mu}" + titleBase2 +"#bar{#nu}_{#mu}" + titleBase3),histNbins,histMin,histMax);
  // // nue
  // nueFluxHisto = new TH1D("nueFluxHisto", (titleBase1 + "#nu_{e}" + titleBase2 +"#nu_{e}" + titleBase3),histNbins,histMin,histMax);
  // // anue
  // anueFluxHisto = new TH1D("anueFluxHisto", (titleBase1 + "#bar{#nu}_{e}" + titleBase2 + "#bar{#nu}_{e}" + titleBase3),histNbins,histMin,histMax);
  // numuCCHisto = new TH1D("numuCCHisto", "numu CC; #nu_{#mu} Energy [GeV]; #nu_{#mu} CC / 79 ton / 6e20 POT",histNbins,histMin,histMax);
}

UBFlux::~UBFlux() {

}

#endif // #ifdef UBFlux_cxx