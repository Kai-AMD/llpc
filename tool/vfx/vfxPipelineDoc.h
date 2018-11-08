/*
 ***********************************************************************************************************************
 *
 *  Copyright (c) 2017-2018 Advanced Micro Devices, Inc. All Rights Reserved.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *
 **********************************************************************************************************************/
/**
***********************************************************************************************************************
* @file  vfxPipelineDoc.h
* @brief Contains declarations of class PipelineDocument
***********************************************************************************************************************
*/

#pragma once

#include "vfxParser.h"

namespace Vfx
{

// =====================================================================================================================
// Represents the pipeline state result of Vfx parser
class PipelineDocument : public Document
{
public:
    PipelineDocument()
    {
        memset(&m_pipelineState, 0, sizeof(m_pipelineState));
        memset(&m_vertexInputState, 0, sizeof(m_vertexInputState));
    };

    virtual uint32_t GetMaxSectionCount(SectionType type)
    {
        return m_MaxSectionCount[type];
    }

    virtual bool CheckVersion(uint32_t ver);
    VfxPipelineStatePtr GetDocument();

private:
    static uint32_t m_MaxSectionCount[SectionTypeNameNum];    // Contants max section count for each section type
    VfxPipelineState m_pipelineState;                         // Contants the render state
    VkPipelineVertexInputStateCreateInfo m_vertexInputState;
};

}

