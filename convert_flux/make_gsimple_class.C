void make_gsimple_class() {

    TFile *f = new TFile("/pnfs/uboone/persistent/uboonebeam/bnb_gsimple/bnb_gsimple_fluxes_02.05.2018_463/converted_beammc_0000.root");
    TTree *v = (TTree*)f->Get("flux");
    v->MakeClass("gsimpletree");
}
