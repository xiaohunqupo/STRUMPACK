/*
 * STRUMPACK -- STRUctured Matrices PACKage, Copyright (c) 2014, The
 * Regents of the University of California, through Lawrence Berkeley
 * National Laboratory (subject to receipt of any required approvals
 * from the U.S. Dept. of Energy).  All rights reserved.
 *
 * If you have questions about your rights to use or distribute this
 * software, please contact Berkeley Lab's Technology Transfer
 * Department at TTD@lbl.gov.
 *
 * NOTICE. This software is owned by the U.S. Department of Energy. As
 * such, the U.S. Government has been granted for itself and others
 * acting on its behalf a paid-up, nonexclusive, irrevocable,
 * worldwide license in the Software to reproduce, prepare derivative
 * works, and perform publicly and display publicly.  Beginning five
 * (5) years after the date permission to assert copyright is obtained
 * from the U.S. Department of Energy, and subject to any subsequent
 * five (5) year renewals, the U.S. Government is granted for itself
 * and others acting on its behalf a paid-up, nonexclusive,
 * irrevocable, worldwide license in the Software to reproduce,
 * prepare derivative works, distribute copies to the public, perform
 * publicly and display publicly, and to permit others to do so.
 *
 * Developers: Pieter Ghysels, Francois-Henry Rouet, Xiaoye S. Li.
 *             (Lawrence Berkeley National Lab, Computational Research
 *             Division).
 */
#include "mex.h"
#include "matrix.h"

#include "StrumpackSparseSolver.hpp"

// Aliases for input and output arguments
#define A_in  prhs[0]
#define b_in  prhs[1]
#define x_out plhs[0]

#define verbose (SPUMONI>0)
#define babble  (SPUMONI>1)
#define burble  (SPUMONI>2)

void mexFunction
(int nlhs,               // number of expected outputs
 mxArray *plhs[],        // matrix pointer array returning outputs
 int nrhs,               // number of inputs
 const mxArray *prhs[]   // matrix pointer array for inputs
 ) {
  // Check number of arguments passed from Matlab
  if (nrhs != 2)
    mexErrMsgTxt("STRUMPACK SOLVE requires 2 input arguments.");
  else if (nlhs != 1)
    mexErrMsgTxt("STRUMPACK SOLVE requires 1 output argument.");

  // Read the Sparse Monitor Flag
  mxArray *Y, *X = mxCreateString("spumoni");
  // int mexerr = mexCallMATLAB(1, &Y, 1, &X, "sparsfun");
  int mexerr = mexCallMATLAB(1, &Y, 1, &X, "spparms");
  int SPUMONI = mxGetScalar(Y);
  mxDestroyArray(Y);
  mxDestroyArray(X);

  int m = mxGetM(A_in), n = mxGetN(A_in), numrhs = mxGetN(b_in);
  if (babble)
    std::cout << "m= " << m << ", n=" << n
	      << ", numrhs=" << numrhs << std::endl;

  x_out = mxCreateDoubleMatrix(m, numrhs, mxREAL);

  if (verbose)
    mexPrintf("Call STRUMPACK SOLVE, use STRUMPACK to factor first ...\n");

  // the input matrix uses UNSIGNED integers,
  // strumpack needs SIGNED integers
  mwIndex *m_rowind = mxGetIr(A_in);
  mwIndex *m_colptr = mxGetJc(A_in);
  auto nnz = m_colptr[n];

  // the input matrix is compressed sparse COLUMN,
  // strumpack needs compressed sparse ROW
  int *rowptr = (int*)mxMalloc((n+1)*sizeof(int));
  int *colind = (int*)mxMalloc(nnz*sizeof(int));
  int *rowsums = (int*)mxMalloc(n*sizeof(int));
  std::fill(rowsums, rowsums+n, 0);
  for (mwIndex c=0; c<n; c++)
    for (mwIndex i=m_colptr[c]; i<m_colptr[c+1]; i++)
      rowsums[m_rowind[i]]++;
  rowptr[0] = 0;
  for (int r=0; r<n; r++)
    rowptr[r+1] = rowptr[r] + rowsums[r];
  std::fill(rowsums, rowsums+n, 0);
  for (mwIndex c=0; c<n; c++)
    for (mwIndex i=m_colptr[c]; i<m_colptr[c+1]; i++) {
      mwIndex r = m_rowind[i];
      colind[rowptr[r]+rowsums[r]] = c;
      rowsums[r]++;
    }

  strumpack::StrumpackSparseSolver<double,int> sp(verbose);
  sp.set_csr_matrix(m, rowptr, colind, mxGetPr(A_in));

  // static int counter = 0;
  // mexPrintf("Matrix set, static counter = %d ...\n", counter++);

  if (sp.solve(mxGetPr(b_in), mxGetPr(x_out))
      != strumpack::ReturnCode::SUCCESS) {
    std::cout << "Error during matrix factorization." << std::endl;
    mexErrMsgTxt("Error during matrix factorization.\n");
  }
}
