#define UBFlux_cxx
#include <iostream> 
#include <iomanip>
#include <string>
  
using namespace std;

#include "UBFlux.hh"
// #include "GSimpleTree/GSimpleTree.h"

void UBFlux::CalculateFlux() {

  gsimple = new GSimpleTree(cflux);
  gsimple->Loop();

}
