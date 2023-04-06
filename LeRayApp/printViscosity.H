
scalar AvgViscosity = 0.0;
scalar vol = gSum(U.mesh().V());

scalar AvgViscosityNu = 0.0;

volScalarField::Internal rhoNu = rho * (pIndicatorFunction->FilteringViscosityU());

AvgViscosity = (fvc::domainIntegrate(rhoNu).value())/runTime.deltaT().value();
AvgViscosity = AvgViscosity/vol;

AvgViscosityNu = (fvc::domainIntegrate(pIndicatorFunction->FilteringViscosityU()).value())/runTime.deltaT().value();
AvgViscosityNu = AvgViscosityNu/vol;



  std::ofstream AVfile;
  AVfile.open ("ArtificialViscosityMu.txt", std::ofstream::out | std::ofstream::app);

  std::ofstream AVfile2;
  AVfile2.open ("ArtificialViscosityNu.txt", std::ofstream::out | std::ofstream::app);

if(Pstream::master()){
  
  AVfile << runTime.timeName() << "\t" << AvgViscosity << std::endl;
  AVfile2 << runTime.timeName() << "\t" << AvgViscosityNu << std::endl;
}
