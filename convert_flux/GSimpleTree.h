//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Nov 28 21:02:29 2019 by ROOT version 6.16/00
// from TTree flux/a simple flux n-tuple
// found on file: /pnfs/uboone/persistent/uboonebeam/bnb_gsimple/bnb_gsimple_fluxes_02.05.2018_463/converted_beammc_0000.root
//////////////////////////////////////////////////////////

#ifndef GSimpleTree_h
#define GSimpleTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

using namespace std;

// Header file for the classes stored in the TTree if any.

class GSimpleTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
 //genie::flux::GSimpleNtpEntry *entry;
   Double_t        wgt;
   Double_t        vtxx;
   Double_t        vtxy;
   Double_t        vtxz;
   Double_t        dist;
   Double_t        px;
   Double_t        py;
   Double_t        pz;
   Double_t        E;
   Int_t           pdg;
   UInt_t          metakey;
 //genie::flux::GSimpleNtpNuMI *numi;
   Double_t        tpx;
   Double_t        tpy;
   Double_t        tpz;
   Double_t        vx;
   Double_t        vy;
   Double_t        vz;
   Double_t        pdpx;
   Double_t        pdpy;
   Double_t        pdpz;
   Double_t        pppx;
   Double_t        pppy;
   Double_t        pppz;
   Int_t           ndecay;
   Int_t           ptype;
   Int_t           ppmedium;
   Int_t           tptype;
   Int_t           run;
   Int_t           evtno;
   Int_t           entryno;
 //genie::flux::GSimpleNtpAux *aux;
   vector<int>     auxint;
   vector<double>  auxdbl;

   // List of branches
   TBranch        *b_entry_wgt;   //!
   TBranch        *b_entry_vtxx;   //!
   TBranch        *b_entry_vtxy;   //!
   TBranch        *b_entry_vtxz;   //!
   TBranch        *b_entry_dist;   //!
   TBranch        *b_entry_px;   //!
   TBranch        *b_entry_py;   //!
   TBranch        *b_entry_pz;   //!
   TBranch        *b_entry_E;   //!
   TBranch        *b_entry_pdg;   //!
   TBranch        *b_entry_metakey;   //!
   TBranch        *b_numi_tpx;   //!
   TBranch        *b_numi_tpy;   //!
   TBranch        *b_numi_tpz;   //!
   TBranch        *b_numi_vx;   //!
   TBranch        *b_numi_vy;   //!
   TBranch        *b_numi_vz;   //!
   TBranch        *b_numi_pdpx;   //!
   TBranch        *b_numi_pdpy;   //!
   TBranch        *b_numi_pdpz;   //!
   TBranch        *b_numi_pppx;   //!
   TBranch        *b_numi_pppy;   //!
   TBranch        *b_numi_pppz;   //!
   TBranch        *b_numi_ndecay;   //!
   TBranch        *b_numi_ptype;   //!
   TBranch        *b_numi_ppmedium;   //!
   TBranch        *b_numi_tptype;   //!
   TBranch        *b_numi_run;   //!
   TBranch        *b_numi_evtno;   //!
   TBranch        *b_numi_entryno;   //!
   TBranch        *b_aux_auxint;   //!
   TBranch        *b_aux_auxdbl;   //!

   GSimpleTree(TTree *tree=0);
   virtual ~GSimpleTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef GSimpleTree_cxx
GSimpleTree::GSimpleTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/pnfs/uboone/persistent/uboonebeam/bnb_gsimple/bnb_gsimple_fluxes_02.05.2018_463/converted_beammc_0000.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/pnfs/uboone/persistent/uboonebeam/bnb_gsimple/bnb_gsimple_fluxes_02.05.2018_463/converted_beammc_0000.root");
      }
      f->GetObject("flux",tree);

   }
   Init(tree);
}

GSimpleTree::~GSimpleTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t GSimpleTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t GSimpleTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void GSimpleTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("wgt", &wgt, &b_entry_wgt);
   fChain->SetBranchAddress("vtxx", &vtxx, &b_entry_vtxx);
   fChain->SetBranchAddress("vtxy", &vtxy, &b_entry_vtxy);
   fChain->SetBranchAddress("vtxz", &vtxz, &b_entry_vtxz);
   fChain->SetBranchAddress("dist", &dist, &b_entry_dist);
   fChain->SetBranchAddress("px", &px, &b_entry_px);
   fChain->SetBranchAddress("py", &py, &b_entry_py);
   fChain->SetBranchAddress("pz", &pz, &b_entry_pz);
   fChain->SetBranchAddress("E", &E, &b_entry_E);
   fChain->SetBranchAddress("pdg", &pdg, &b_entry_pdg);
   fChain->SetBranchAddress("metakey", &metakey, &b_entry_metakey);
   fChain->SetBranchAddress("tpx", &tpx, &b_numi_tpx);
   fChain->SetBranchAddress("tpy", &tpy, &b_numi_tpy);
   fChain->SetBranchAddress("tpz", &tpz, &b_numi_tpz);
   fChain->SetBranchAddress("vx", &vx, &b_numi_vx);
   fChain->SetBranchAddress("vy", &vy, &b_numi_vy);
   fChain->SetBranchAddress("vz", &vz, &b_numi_vz);
   fChain->SetBranchAddress("pdpx", &pdpx, &b_numi_pdpx);
   fChain->SetBranchAddress("pdpy", &pdpy, &b_numi_pdpy);
   fChain->SetBranchAddress("pdpz", &pdpz, &b_numi_pdpz);
   fChain->SetBranchAddress("pppx", &pppx, &b_numi_pppx);
   fChain->SetBranchAddress("pppy", &pppy, &b_numi_pppy);
   fChain->SetBranchAddress("pppz", &pppz, &b_numi_pppz);
   fChain->SetBranchAddress("ndecay", &ndecay, &b_numi_ndecay);
   fChain->SetBranchAddress("ptype", &ptype, &b_numi_ptype);
   fChain->SetBranchAddress("ppmedium", &ppmedium, &b_numi_ppmedium);
   fChain->SetBranchAddress("tptype", &tptype, &b_numi_tptype);
   fChain->SetBranchAddress("run", &run, &b_numi_run);
   fChain->SetBranchAddress("evtno", &evtno, &b_numi_evtno);
   fChain->SetBranchAddress("entryno", &entryno, &b_numi_entryno);
   fChain->SetBranchAddress("auxint", &auxint, &b_aux_auxint);
   fChain->SetBranchAddress("auxdbl", &auxdbl, &b_aux_auxdbl);
   Notify();
}

Bool_t GSimpleTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void GSimpleTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t GSimpleTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef GSimpleTree_cxx
