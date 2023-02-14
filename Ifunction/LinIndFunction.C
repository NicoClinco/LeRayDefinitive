#include "LinIndFunction.H"
#include "addToRunTimeSelectionTable.H"

namespace Foam
{

defineTypeNameAndDebug(LinIndFunction, false);
addToRunTimeSelectionTable(Ifunction, LinIndFunction, dict);

tmp<volScalarField> LinIndFunction::EvalViscosity(){
   
  // Evaluating the viscosity for the linear-step
  
  return FilteringViscosityU();
  
 }

/* Add a method to filter integrally the stuffs
 *
 *
 *
 *
*/ 


}
