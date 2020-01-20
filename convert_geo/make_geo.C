void make_geo() {

  gSystem->Load("libGeom");
  TGeoManager::Import("sbnd_v01_04_detonly.gdml");
  // gGeoManager->GetTopVolume()->Draw("ogl");
  gGeoManager->Export("SBNDGeometry.root", "SBNDGeometry");
}

