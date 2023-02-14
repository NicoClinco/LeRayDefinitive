
/* // ------------------- Filtering the velocity ------------------------- \\   */

// tmp<volScalarField> FilterViscosityStep =a.FilteringViscosityU();

fvVectorMatrix UfilteredEqn
(
 -fvm::laplacian(pIndicatorFunction->EvalViscosity(),Ufi)
);

solve( UfilteredEqn == U-fvm::Sp(dimensionedScalar("one",dimless,1),Ufi) );
U=Ufi;

/* // --------------------------------------------------------------------- \\  */


/* // ------------------- Filtering the Energy ----------------------------- \\ */


volScalarField& he = thermo.he();

fvScalarMatrix hefilteredEqn
(
 fvm::Sp(dimensionedScalar("one",dimless,1),hefi)-fvm::laplacian(pIndicatorFunction->EvalViscosity(),hefi)
);

solve ( hefilteredEqn == he );
he = hefi;

thermo.correct();

/* // ------------------------------------------------------------------------ \\ */ 
