///////////////////////////////////////////////////////////////////////////////////////////////////
// I. LICENSE CONDITIONS
//
// Copyright (c) 2018 by Disney-Pixar
//
// Permission is hereby granted to use this software solely for non-commercial applications
// and purposes including academic or industrial research, evaluation and not-for-profit media
// production. All other rights are retained by Pixar. For use for or in connection with
// commercial applications and purposes, including without limitation in or in connection with
// software products offered for sale or for-profit media production, please contact Pixar at
// tech-licensing@pixar.com.
//
// THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT
// NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL PIXAR OR ITS AFFILIATES BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
// IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "CGInterface.h"

#include "EigenCG.h"

namespace CubeSim
{

CGInterface::~CGInterface() = default;

std::unique_ptr<CGInterface> GenerateCGSolver(const CGSolverType& solverType, const Scalar& eps, const int maxIters)
{
    std::unique_ptr<CGInterface> solver;
    switch (solverType)
    {
        // case CGSolverType::ViennaCLOpenMP:
        // {
        //     solver.reset(new ViennaCGOpenMP(DOFs, maxIters, eps));
        //     break;
        // }
        // case CGSolverType::ViennaCLOpenCL:
        // {
        //     solver.reset(new ViennaCGOpenCL(DOFs, maxIters, eps));
        //     break;
        // }
        case CGSolverType::Eigen:
        {
            solver.reset(new EigenCG(maxIters, eps));
            break;
        }
    }
    return solver;
}

}
