//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for full license information.
//

#pragma once

#include "SwapAction.h"

#ifndef CPUONLY
    #include <cuda.h>
#endif

namespace Microsoft { namespace MSR { namespace CNTK {

template <typename ElemType>
class SwapOutAction : public SwapAction<ElemType>
{

public:
    ~SwapOutAction();
    SwapOutAction(Matrix<ElemType> *GPUbuffer);
    
    //implementation of abstract method
    void BeginAction();
    void EndAction();
    cudaStream_t GetSwapSteam(){ return m_streamAsync; }
    void ReleaseMemory();
    bool m_hasDoneInitialSwap;
    bool m_isSwappedOut;

private:
    cudaStream_t m_streamAsync; 
    // this allocated the CPU memory for the GPU buffer, it is allocated upon
    // initialization of the class
    void allocatePinnedBuffer();

};

}}}

