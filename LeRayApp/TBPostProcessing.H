scalar thetamax1 = max(theta).value();
scalar thetamax2 = max(theta.boundaryField());
scalar thetamax = thetamax2;
if (thetamax1 > thetamax2)
 thetamax = thetamax1;
scalar Uymax = max(U.component(1)).value();
  
file << runTime.timeName() << "\t" << thetamax << "\t" << Uymax << "\t" <<  std::endl << "\n";
       


